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
#include <vector>
// numeric_limits<int>::max()
using namespace std;
#define LL int64_t // 64-bit long long int, use %I64d for scan and printf
int DEBUG = 0;
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int n;
  cin >> n;
  int a[n];
  int stuff[2];
  stuff[0] = stuff[1] = 0;
  for(int i = 0; i < n; i++){
    cin >> a[i];
    stuff[a[i] % 2]++;
  }
  if(stuff[0] == 1){
    for(int i = 0; i < n; i++){
      if(a[i] % 2 == 0){
    cout << i + 1 << endl;
    exit(0);
      }
    }
  } else {
    for(int i = 0; i < n; i++){
      if(a[i] % 2 == 1){
    cout << i + 1 << endl;
    exit(0);
      }
    }
  }
  exit(0);
}