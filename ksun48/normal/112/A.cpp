#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <iostream>
using namespace std;
int Max(int a, int b) {
  return (a > b ? a : b);
}

main(int argc, char **argv) {
  char str[120];
  cin >> str;
  char str2[120];
  cin >> str2;
  int len = strlen(str);
  for(int i = 0; i < len; i++){
    if(str[i] >= 'a' && str[i] <= 'z'){
    } else {
      str[i] -= ('A'-'a');
    }
  }
  for(int i = 0; i < len; i++){
    if(str2[i] >= 'a' && str2[i] <= 'z'){
    } else {
      str2[i] -= ('A'-'a');
    }
  }
  for(int i = 0; i < len; i++){
    if(str[i] < str2[i]){
      cout << -1 << endl;
      exit(0);
    }
    if(str[i] > str2[i]){
      cout << 1 << endl;
      exit(0);
    }
  }
  cout << 0 << endl;
  exit(0);
}