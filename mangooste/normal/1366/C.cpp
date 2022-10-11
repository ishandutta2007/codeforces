#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (auto &el : a) {
      for (auto &ell : el) {
        cin >> ell;
      }
    }
    int ans = 0;
    for (int i = 0; i < (n + m - 1) / 2; i++) {
      array<int, 2> cnt_up, cnt_down;
      cnt_up = cnt_down = {0, 0};
      for (int j = i; j >= 0; j--) {
        if (j < n && i - j < m) {
          cnt_up[a[j][i - j]]++;
        }
      }
      for (int j = n + m - 2 - i; j >= 0; j--) {
        if (j < n && n + m - 2 - i - j < m) {
          cnt_down[a[j][n + m - 2 - i - j]]++;
        }
      }
      ans += min(cnt_up[0] + cnt_down[0], cnt_up[1] + cnt_down[1]);
    }
    cout << ans << '\n';
  }
}