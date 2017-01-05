// Copyright Benoit Blanchon 2014-2016
// MIT License
//
// Arduino JSON library
// https://github.com/bblanchon/ArduinoJson
// If you like this project, please add a star!

#include <ArduinoJson.h>
#include <gtest/gtest.h>

TEST(Issue411, IsBool) {
  char json[] = "{\"field\":\"this% will error out\"}";
  DynamicJsonBuffer jsonBuffer;
  JsonObject& root = jsonBuffer.parseObject(json);
  ASSERT_TRUE(root.success());
  ASSERT_STREQ("this% will error out", root["field"]);
}
