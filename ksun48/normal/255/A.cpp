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
  int n;
  cin >> n;
  int k[3];
  k[0] = 0;
  k[1] = 0;
  k[2] = 0;
  int c;
  for(int i = 0; i < n; i++){
    cin >> c;
    k[i%3]+= c;
  }
  if(k[0] > k[1] && k[0] > k[2]){
    cout << "chest" << endl;
  } else if(k[1] > k[2]){
    cout << "biceps" << endl;
  } else {
    cout << "back" << endl;
  }
}