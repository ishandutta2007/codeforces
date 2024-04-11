#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll get(ll a, ll b) {
  if (b == 0) {
    return 0;
  }
  ll g = __gcd(a, b);
  ll x = a / g, y = b / g;
  ll mom = 0;
  for (ll i = 1; i * i <= x && i <= y; i++) {
    if (x % i == 0) {
      if (i != 1) {
        mom = max(mom, (y / i) * i);
      }
      if (x / i != 1) {
        mom = max(mom, (y / (x / i)) * (x / i));
      }
    }
  }
  return y - mom + get(a, g * mom);
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  ll a, b;
  cin >> a >> b;
  cout << get(a, b) << '\n';
}