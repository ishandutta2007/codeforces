#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <iostream>
#include <string.h>
using namespace std;
#define LL int64_t // 64-bit long long int, use %I64d for scan and printf
int n; char str[1000010];
LL array[1000010];
int DEBUG = 0;
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  cin >> n >> str;
  int len = strlen(str);
  for(int i = 0; i < len; i++){
    array[i] = 0;
  }
  int c0 = 0;
  for(int i = 0; i < len; i++){
    if(str[i] == '1'){
      c0++;
    } else {
      array[c0]++; 
    }
  }
  //cout << c0 << endl;
  LL numstr = 0;
  if(n == 0){
    for(int i = 0; i <= c0; i++){
      numstr += (LL)((LL)(array[i])*(LL)(array[i]+1))/2;
    }
  } else {
    for(int i = 0; i+n <= c0; i++){
      numstr += (1+array[i])*(array[i+n]+1);
    }
  }
  cout << numstr << endl;
}