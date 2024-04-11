#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdint.h>
#include <iostream>
#include <set>
#include <math.h>
#define LL int64_t
using namespace std;
int Max(int a, int b) {
  return (a > b ? a : b);
}

int compare_dec (const void * a, const void * b) {
  if ( *(int*)a < *(int*)b ) return 1;
  if ( *(int*)a > *(int*)b ) return -1;
  return 0;
}
main(int argc, char **argv) {
  char str[110];  
  cin >> str;
  int len = strlen(str);
  int l = 0, u = 0;
  for(int i = 0; i < len; i++){
    if(str[i] >= 'a' && str[i] <= 'z'){
      l++;
    } else {
      u++;
    }
  }
  if(l >= u){
    for(int i = 0; i < len; i++){
      if(str[i] >= 'A' && str[i] <= 'Z'){
	str[i] -= ('A'-'a');
      }
      cout << str[i];
    }
  } else {
    for(int i = 0; i < len; i++){
      if(str[i] >= 'a' && str[i] <= 'z'){
	str[i] += ('A'-'a');
      }
      cout << str[i];
    }

  }
  cout << endl;
  exit(0);
}