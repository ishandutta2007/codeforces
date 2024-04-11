#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <iostream>
#include <string.h>
#include <set>
#include <queue>
#include <algorithm>
#include <complex>
#include <deque>
#include <map>
#include <utility>
#include <limits>
// numeric_limits<int>::max()
using namespace std;
#define LL int64_t // 64-bit long long int, use %I64d for scan and printf
int Min(int a, int b) {
  return (a < b ? a : b);
}
int Max(int a, int b) {
  return (a > b ? a : b);
}
int Abs(int a) {
  return (a >= 0 ? a : -a);
}
int DEBUG = 0;
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  char str[1000100];
  cin >> str;
  int len = strlen(str);
  int x = 0, y = 0;
  for(int i = 0; i < len; i++){
    if(str[i] == 'x'){
      x++;
    } else {
      y++;
    }
  }
  if(x > y){
    for(int i = 0; i < x-y; i++){
      cout << "x";
    }
    cout << endl;
  } else {
    for(int i = 0; i < y-x; i++){
      cout << "y";
    }
    cout << endl;   
  }
}