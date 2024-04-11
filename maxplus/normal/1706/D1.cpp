#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>

using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  for (int t = (cin >> t, t); t--; ) {
    int n, k; cin >> n >> k;
    int mn = 1e5, mx = 0;
    priority_queue<array<int, 2>> pq;
    for (int i = 0; i < n; ++i) {
      int a; cin >> a;
      mn = min(mn, a);
      pq.push({a, a});
    }
    int ans = 1e5;
    while (pq.size()) {
      auto [r, a] = pq.top(); pq.pop();
      ans = min(ans, max(mx, r) - mn);
      int p = a / r;
      if (p >= k) {
        mx = max(mx, r);
      } else {
        r = a / (p + 1);
        mn = min(mn, r);
        if (r) {
          pq.push({r, a});
        }
      }
    }
    cout << ans << '\n';
  }
}