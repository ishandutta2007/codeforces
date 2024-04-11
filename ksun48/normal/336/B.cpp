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
#include <math.h>
// numeric_limits<int>::max()
using namespace std;
#define LL int64_t // 64-bit long long int, use %I64d for scan and printf
int DEBUG = 0;
main(int argc, char **argv) {
  //int a;
  //scanf("%d", &a);
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  double sqrt2 = sqrt(2.0);
  //cout << sqrt2 << endl;
  int m;
  double R;
  cin >> m >> R;
  double dm = (double)(m);
  double ans = 0;
  ans += 2/dm;
  ans += (2+sqrt2)*2*(dm-1)/dm/dm;
  for(int i = 2; i < m; i++){
    double di = (double)(i);
    ans += (2*sqrt2 + 2*di-2)*2*(m-di)/dm/dm;
  }
  printf("%.10lf\n", R*ans);
}