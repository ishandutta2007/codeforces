#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <iostream>
#include <string.h>
#include <set>
#include <queue>
#include <complex>
#include <deque>
#include <map>
using namespace std;
#define LL int64_t // 64-bit long long int, use %I64d for scan and printf

int DEBUG = 0;
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  char address[55];
  cin >> address;
  int len = strlen(address);
  int c;
  if(address[0] == 'h'){
    cout << "http://";
    c = 4;
  } else {
    cout << "ftp://";
    c = 3;
  }
  int d;
  for(int i = c+1; i < len-1; i++){
    if(address[i] == 'r' && address[i+1] == 'u'){
      d = i;
    }
  }
  for(int i = c; i < d; i++){
    cout << address[i];
  }
  cout << ".ru";
  if(d == len-2){
  } else {
    cout << "/";
    for(int i = d+2; i < len; i++){
      cout << address[i];
    }
  }
  cout << endl;
}