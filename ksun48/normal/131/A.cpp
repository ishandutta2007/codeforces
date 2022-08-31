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
  int len = strlen(str);
  int iscaps = 1;
  for(int i = 1; i < len; i++){
    if(str[i] >= 'a' && str[i] <= 'z'){
      iscaps = 0;
      break;
    }
  }
  if(iscaps == 1){
    for(int i = 0; i < len; i++){
      if(str[i] >= 'a' && str[i] <= 'z'){
	str[i] += ('A'-'a');
	cout << str[i];
      } else {
	str[i] -= ('A'-'a');
	cout << str[i];
      }
    }
  } else {
    for(int i = 0; i < len; i++){
      cout << str[i];
    }
  }
  cout << endl;  
  exit(0);
}