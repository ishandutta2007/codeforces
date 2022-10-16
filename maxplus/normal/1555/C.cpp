#include <iostream>

using namespace std;

constexpr int M = 1e5 + 1, K = 2;

int a[K][M];

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int t, m;
  cin >> t;
  while (t--) {
    cin >> m;
    for (auto i: {0, 1})
    for (int j = 1; j <= m; ++j) {
      cin >> a[i][j];
      a[i][j] += a[i][j - 1];
    }
    int ans = 1e9;
    for (int j = 1; j <= m; ++j) {
      ans = min(ans, max(a[1][j - 1], a[0][m] - a[0][j]));
    }
    cout << ans << '\n';
  }
  return 0;
}