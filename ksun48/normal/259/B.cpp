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
  
  int a, b, c, d, e, f, g, h, i;
  cin >> a >> b >> c >> d >> e >> f >> g >> h >> i;
  a = (f+h)/2;
  i = (b+d)/2;
  e = a+b-g;
  cout << a << " " << b << " " << c << endl;
  cout << d << " " << e << " " << f << endl;
  cout << g << " " << h << " " << i << endl;
  exit(0);
}