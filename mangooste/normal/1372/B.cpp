#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define int ll

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n % 2 == 0) {
      cout << n / 2 << ' ' << n / 2 << '\n';
    } else {
      int ans = -1;
      auto relax = [&](int g) {
        if (n % g == 0 && g != n && g != 0) {
          if (ans == -1 || ans * (n - ans) / __gcd(ans, n - ans) > g * (n - g) / __gcd(g, n - g)) {
            ans = g;
          }
        }
      };
      for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
          relax(i);
          relax(n / i);
        }
      }
      cout << ans << ' ' << n - ans << '\n';
    }
  }
}