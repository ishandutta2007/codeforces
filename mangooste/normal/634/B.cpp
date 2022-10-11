#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll s, x, y, ans;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> s >> x;
  if (s % 2 != x % 2 || x > s) {
    cout << "0\n";
    return 0;
  }
  y = (s - x) / 2;
  if (y & x) {
    cout << "0\n";
    return 0;
  }
  ans = (1ll << __builtin_popcountll(x)) - (s == x ? 2 : 0);
  cout << ans << '\n';
}