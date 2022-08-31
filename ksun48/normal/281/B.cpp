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
  int x, y, n;
  cin >> x >> y >> n;
  int mina, minb;
  double minfrac = 999;
  for(int b = 1; b <= n; b++){
    int a = (1.0*b*x/y+0.49999999999);
    //cout << a << " " << b << " ";
    double frac = 1.0*a/b - 1.0*x/y;
    if(frac < 0) frac = -frac;
    //cout << frac << endl;
    if(frac < minfrac){
      minfrac = frac;
      mina = a;
      minb = b;
    }
  }
  cout << mina << "/" << minb << endl;
}