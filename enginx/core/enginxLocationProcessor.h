//
//  enginxLocationProcessor.h
//  enginx
//
//  Created by stephenw on 2017/3/17.
//  Copyright © 2017年 stephenw.cc. All rights reserved.
//

#ifndef enginxLocationProcessor_h
#define enginxLocationProcessor_h
#include "enginxDefinitions.h"
#include "enginxWorker.h"
#include <map>
#include <regex>

ENGINX_NAMESPACE_BEGIN
using namespace std;

class EnginxLocation {
public:
  EnginxLocation(rapidjson::Value& location_config, map<string, string>& vars, EnginxURL const url);
  string rewrited_url;
  EnginxURL current_url;
private:
  rapidjson::Document location_config;
  std::map<string, string> internal_vars;
  std::map<string, string> server_vars;
  bool resolveInstruction(string instruction);
  void computeInternalVars(std::smatch m);
  void compileTemplates(string& template_str);
};

void EnginxLocationDispatcher(EnginxURL const url, rapidjson::Value& locations, map<string, string>& server_vars, string& rewrited_url);

ENGINX_NAMESPACE_END

#endif /* enginxLocationProcessor_h */