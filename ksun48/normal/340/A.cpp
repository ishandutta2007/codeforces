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
  //int a;
  //scanf("%d", &a);

  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int x, y, a, b;
  cin >> x >> y >> a >> b;
  int l = x*y/gcd(x,y);
  int c = (a-1)/l;
  int d = b/l;
  cout << d - c << endl;
}