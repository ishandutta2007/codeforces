#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <string>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

int main() {
  int N; cin >> N;

  map<int, int> sum;
  map<int, int> up;
  for(int i = 0; i < N; i++) {
    int x, y; cin >> x >> y;
    sum[x]++;
    up[x]++;
    if(x != y) {
      sum[y]++;
    }
  }

  int res = 0x7FFFFFFF;
  for(typeof(sum.begin()) it = sum.begin(); it != sum.end(); it++) {
    if(it->second * 2 < N) continue;
    res = min(res, (N + 1) / 2 - up[it->first]);
  }
  if(res < 0) res = 0;
  if(res == 0x7FFFFFFF) res = -1;
  cout << res << endl;
}