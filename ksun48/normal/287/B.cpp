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
  //int a;
  //scanf("%d", &a);

  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  LL n, k;
  cin >> n >> k;
  n--; k--;
  if(n > k*(k+1)/2){
    cout << -1 << endl;
    exit(0);
  }
  n = k*(k+1)/2 - n;
  LL s = 0;
  LL e = k+1;
  while(e-s > 1){
    LL m = (e+s)/2;
    if(m*(m+1)/2 <= n){
      s = m;
    } else {
      e = m;
    }
  }
  cout << k-s << endl;
}