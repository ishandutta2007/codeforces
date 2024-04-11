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
  int stuff[101];
  for(int i = 0; i < 101; i++) stuff[i] = 0;
  for(int i = 0; i < n; i++){
    int a;
    cin >> a;
    stuff[a]++;
  }
  int k = 0;
  for(int i = 0; i < 101; i++){
    k += (stuff[i]/2);
  }
  int m = k/2;
  cout << m << endl;
  exit(0);
}