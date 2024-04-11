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
int Abs(int i){
  if(i < 0) return -i;
  return i;
}
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int m;
  cin >> m;
  int n = 2*m-1;
  int a[n];
  for(int i = 0; i < n; i++) cin >> a[i];
  int numn = 0;
  int sum = 0;
  int min1 = 10000000;
  for(int i = 0; i < n; i++) sum += Abs(a[i]);
  for(int i = 0; i < n; i++){
    min1 = min(min1, Abs(a[i]));
    if(a[i] == 0){
      cout << sum << endl;
      exit(0);
    }
    if(a[i] < 0){
      numn++;
    }
  }
  if(numn % 2 == 1 && (n+1)/2 % 2 == 0){
    cout << sum - 2*min1 << endl;
  } else {
    cout << sum << endl;
  }
  exit(0);
}