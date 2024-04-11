#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>
#include <cmath>

using namespace std;

constexpr int N = 1e5 + 1;

int tm[N], tm2[N];
vector<int> as[N];

int change(int& a, int b) {
  int t = a;
  return (a = b) - t;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  for (int t = (cin >> t, t + 1); --t; ) {
    int n, k; cin >> n >> k;
    int mn = 1e5, mx = 0;
    priority_queue<int> rs;
    for (int i = 0; i < n; ++i) {
      int a; cin >> a;
      if (!change(tm[a], t)) {
        continue;
      }
      if (change(tm2[a], t)) {
        rs.push(a);
      }
      mn = min(mn, a);
      mx = max(mx, a);
      as[a].push_back(a);
    }
    int ans = 1e5, done = 0;
    while (rs.size()) {
      int mr = rs.top(); rs.pop();
      if (!done) {
        ans = min(ans, mr - mn);
        for (auto a: as[mr]) {
          int r = mr, p = a / r;
          if (p >= k) {
            done = 1;
            break;
          } else {
            r = a / (p + 1);
            mn = min(mn, r);
            if (r * (uint64_t)r >= a || r && a == mx) {
              as[r].push_back(a);
              if (change(tm2[r], t)) {
                rs.push(r);
              }
            }
          }  
        }
      }
      vector<int>{}.swap(as[mr]);
    }
    cout << ans << '\n';
  }
}