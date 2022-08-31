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

int Min(int a, int b) {
  return (a < b ? a : b);
}
int Max(int a, int b) {
  return (a > b ? a : b);
}
int DEBUG = 0;
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  char entrance[350];
  cin >> entrance;
  int len = strlen(entrance);
  int minp = 0;
  int maxp = 0;
  int curr = 0;
  for(int i = 0; i < len; i++){
    if(entrance[i] == '+'){
      curr++;
    } else {
      curr--;
    }
    minp = Min(minp, curr);
    maxp = Max(maxp, curr);
  }
  cout << maxp-minp << endl;
}