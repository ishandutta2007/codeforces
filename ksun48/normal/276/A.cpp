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
  LL ans = -10000000000;
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  LL n, k;
  cin >> n >> k;
  for(LL i = 0; i < n; i++){
    LL f, t;
    cin >> f >> t;
    if(t > k) ans = max(ans, f-(t-k));
    else ans = max(ans, f);
  }
  cout << ans << endl;
  
}