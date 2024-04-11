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
int compare_dec (const void * a, const void * b) {
  if ( *(LL*)a < *(LL*)b ) return 1;
  if ( *(LL*)a > *(LL*)b ) return -1;
  return 0;
}
main(int argc, char **argv) {
  //int a;
  //scanf("%d", &a);

  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  LL n, q;
  cin >> n >> q;
  LL a[n+1];
  a[0] = 0;
  for(LL i = 1; i <= n; i++) cin >> a[i];
  LL diff[n+1];
  for(int i = 0; i <= n; i++) diff[i] = 0;
  for(LL i = 0; i < q; i++){
    LL l, r;
    cin >> l >> r;
    diff[l-1]++;
    diff[r]--;
  }
  LL num[n+1];
  num[0] = 0;
  for(LL i = 1; i <= n; i++){
    num[i] = num[i-1] + diff[i-1];
  }
  qsort(num, n+1, sizeof(LL), compare_dec);
  qsort(a, n+1, sizeof(LL), compare_dec);
  LL sum = 0;
  for(int i = 0; i <= n; i++){
    sum += num[i]*a[i];
  }
  cout << sum << endl;
  exit(0);
}