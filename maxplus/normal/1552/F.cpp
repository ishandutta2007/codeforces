#include <algorithm>
#include <iostream>

using namespace std;

constexpr int N = 2e5, mod = 998244353;

uint32_t x[N], r[N];

int main()
{
  cin.tie(0), ios::sync_with_stdio(0);
  uint32_t n, y, p = 0, lx = 0, s, ans = 1;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y >> s;
    ans += x[i] - lx;
    r[i] = (p + x[i] - lx) % mod, lx = x[i];
    auto jt = upper_bound(x, x + i, y) - x;
    p = (2 * r[i] + mod - r[jt] + x[jt] - y) % mod;
    if (s) {
      ans += p + mod - r[i];
    }
    ans %= mod;
  }
  cout << ans;
  return 0;
}