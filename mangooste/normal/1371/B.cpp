#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <functional>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

void Main();

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(10);
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  Main();
#ifdef LOCAL
  cout << "\nTime: " << (int)ceil((double)1000 * clock() / CLOCKS_PER_SEC) << " ms";
#endif
}

void Main() {
  int t;
  cin >> t;
  while (t--) {
    ll n, r;
    cin >> n >> r;
    // ll ans = 0;
    // for (int a = 1; a <= r && a <= n; a++) {
    //   if (a / n >= 1) {
    //     ans += a % n + 1;
    //   } else {
    //     ans += a;
    //   }
    // }
    // cout << ans << '\n';
    if (r >= n) {
      cout << 1 + n * (n - 1) / 2 << '\n';
    } else {
      cout << r * (r + 1) / 2 << '\n';
    }
  }
}