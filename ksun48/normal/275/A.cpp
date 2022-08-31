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
  int a, b, c, d, e, f, g, h, i;
  cin >> a >> b >> c >> d >> e >> f >> g >> h >> i;
  cout << (1+a+b+d) % 2 << (1+a+b+c+e) % 2 << (1+b+c+f) % 2 << endl;
  cout << (1+a+d+e+g) % 2 << (1+b+d+e+f+h) % 2 << (1+c+e+f+i) % 2 << endl;
  cout << (1+d+g+h) % 2 << (1+e+g+h+i) % 2 << (1+f+h+i) % 2 << endl;
  exit(0);
}