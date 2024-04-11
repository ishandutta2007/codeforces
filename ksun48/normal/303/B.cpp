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
int gcd(int a, int b){
  if(b > a) return gcd(b,a);
  if(a % b == 0) return b;
  return gcd(b,a % b);
}
int Abs(int a){
  if(a < 0) return -a;
  return a;
}
#define LL int64_t // 64-bit long long int, use %I64d for scan and printf
int DEBUG = 0;
main(int argc, char **argv) {
  //int a;
  //scanf("%d", &a);

  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int n, m, x, y, a, b;
  cin >> n >> m >> x >> y >> a >> b;
  //cout << gcd(a,b) << endl;
  int c = gcd(a,b);
  a = a/c;
  b = b/c;
  // cout << a << " " << b << endl;
  int k = min((n)/a, (m)/b);
  //cout << k*a << " " << k*b << endl;
  int ax, by;
  if(2*x >= (k*a) && 2*x <= n-k*a+n){
    ax = x-k*a+k*a/2;
  } else if(Abs(2*x-(k*a)) <= Abs(2*x - (n-k*a+n))){
    ax = 0;
  } else {
    ax = n - k*a;
  }
  if(2*y >= (k*b) && 2*y <= m-k*b+m){
    by = y-k*b+k*b/2;
  } else if(Abs(2*y-(k*b)) <= Abs(2*y - (m-k*b+m))){
    by = 0;
  } else {
    by = m - k*b;
  }
  cout << ax << " " << by << " " << ax + k*a << " " << by + k*b << endl;
}