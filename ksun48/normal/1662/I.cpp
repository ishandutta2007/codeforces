/**
 *    author:  tourist
 *    created: 24.04.2022 15:20:23       
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  vector<int> x(m);
  for (int i = 0; i < m; i++) {
    cin >> x[i];
  }
  sort(x.begin(), x.end());
  vector<pair<int, int>> ev;
  for (int i = 0; i < n; i++) {
    auto it = lower_bound(x.begin(), x.end(), 100 * i);
    int dist = (int) 1e9;
    if (it != x.end()) {
      dist = min(dist, (*it) - 100 * i);
    }
    if (it != x.begin()) {
      dist = min(dist, 100 * i - (*prev(it)));
    }
    ev.emplace_back(100 * i - dist, +p[i]);
    ev.emplace_back(100 * i + dist, -p[i]);
  }
  sort(ev.begin(), ev.end());
  long long cur = 0;
  long long ans = 0;
  for (auto& e : ev) {
    cur += e.second;
    ans = max(ans, cur);
  }
  cout << ans << '\n';
  return 0;
}