#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> p(n);
    for (auto &el : p) {
      cin >> el;
    }
    int ans = -1;
    for (int i = 1; i < n - 1; i++) {
      if (p[i] > p[i - 1] && p[i] > p[i + 1]) {
        ans = i;
        break;
      }
    }
    if (ans == -1) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
      cout << ans << ' ' << ans + 1 << ' ' << ans + 2 << '\n';
    }
  }
}