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
  int n;
  cin >> n;
  int d[n];
  int total = 0;
  for(int i = 0; i < n; i++){
    cin >> d[i];
    total += d[i];
  }
  int s, t;
  cin >> s >> t;
  s--;
  t--;
   //cout << s << " " << t << endl;
  if(s > t){
    int q = t;
    t = s;
    s = q;
  }
  //cout << s << " " << t << endl;
  int ans1 = 0;
  for(int i = s; i < t; i++){
    ans1 += d[i];
  }
  //cout << ans1 << " " << total << endl;
  cout << min(ans1, total-ans1);
  exit(0);
}