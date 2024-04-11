#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (auto &el : a) {
      cin >> el;
    }
    sort(a.rbegin(), a.rend());
    int ans = 0;
    for (int i = 0, cnt = 1; i < n; i++, cnt++) {
      if (1ll * a[i] * cnt >= x) {
        ans++;
        cnt = 0;
      }
    }
    cout << ans << '\n';
  }
}