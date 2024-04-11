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
LL Abs(LL k){
  LL m = k;
  if(m < 0) m = -m;
  return m;
}
main(int argc, char **argv) {
  //int a;
  //scanf("%d", &a);

  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  LL n;
  cin >> n;
  LL a[n];
  for(LL i = 0; i < n; i++){
    cin >> a[i];
    a[i]--;
  }
  sort(a, a+n);
  LL k = 0;
  for(LL i = 0; i < n; i++){
    k += Abs(i-a[i]);
  }
  cout << k << endl;
}