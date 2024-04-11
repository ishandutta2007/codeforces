#include <iostream>

using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  for (int t = (cin >> t, t); t--; ) {
    int n; cin >> n;
    int a[7], s = 0;
    for (auto& i: a) {
      cin >> i;
      s += i;
    }
    int ans = 0, tans = 1e9;
    if (n / s > 2) {
      int r = n / s - 2;
      ans += r * 7, n -= r * s;
    }
    for (int l = 0; l < 7; ++l)
    for (int r = 0, sr = 0; ; sr += a[(l + r++) % 7]) {
      if (sr == n) {
        tans = min(tans, r);
        break;
      }
    }
    cout << ans + tans << '\n';
  }
}