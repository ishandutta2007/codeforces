#include <iostream>

using namespace std;

constexpr int N = 2e5 + 1, K = 3;

int a[K][K][N];

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n, q, l, r;
  string s;
  cin >> n >> q >> s;
  for (auto c1: {0, 1, 2})
  for (auto c2: {(c1 + 1) % K, (c1 + 2) % K}) {
    auto c3 = K - c1 - c2;
    char c[3]{c1, c2, c3};
    for (int i = 0; i < n; ++i) {
      a[c1][c2][i + 1] = a[c1][c2][i] + (s[i] - 'a' != c[i % 3]);
    }
  }
  while (q--) {
    cin >> l >> r;
    int ans = 1e9;
    for (auto c1: {0, 1, 2})
    for (auto c2: {(c1 + 1) % K, (c1 + 2) % K}) {
      ans = min(ans, a[c1][c2][r] - a[c1][c2][l - 1]);
    }
    cout << ans << '\n';
  }
  return 0;
}