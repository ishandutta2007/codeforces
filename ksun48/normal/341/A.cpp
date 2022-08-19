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
LL gcd(LL a, LL b){
  if(b > a) return gcd(b,a);
  if(b == 0) return a;
  return gcd(b,a%b);
}
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  LL n;
  cin >> n;
  LL a[n];
  LL sum = 0;
  for(int i = 0; i < n; i++){
    cin >> a[i];
    sum += a[i];
  }
  sort(a, a+n);
  for(LL i = 1; i < n; i++){
    sum += (2*i*(n-i)*(a[i] - a[i-1]));
  }
  cout << sum/gcd(sum,n)<< " " << n/gcd(sum,n) << endl;
}