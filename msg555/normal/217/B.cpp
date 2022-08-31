#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <numeric>

using namespace std;

int main() {
  int N, R; cin >> N >> R;
  int best = N;
  int bestx = -1;
  for(int xx = 1; xx <= R; xx++) {
    int x = xx;
    int y = R;
    int tot = 0;
    int mis = 0;
    while(x != y) {
      int m = (y - 1) / x;
      tot += m;
      mis += m - 1;
      y -= x * m;
      swap(x, y);
    }
    if(x == 1 && tot + 1 == N && mis < best) {
      best = mis;
      bestx = xx;
    }
  }
  if(bestx == -1) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }

  string res;
  int x = bestx;
  int y = R;
  char ch = (N - best) % 2 ? 'T' : 'B';
  while(x != y) {
    int m = y == x ? 1 : (y - 1) / x;
    res += string(m, ch);
    ch = ch == 'T' ? 'B' : 'T';
    y -= x * m;
    swap(x, y);
  }
  res += 'T';
  reverse(res.begin(), res.end());
  cout << best << endl << res << endl;
  return 0;
}