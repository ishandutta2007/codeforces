#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      ++c[--x];
    }
    vector<int> b;
    for (int i = 0; i < n; ++i) {
      if (c[i]) {
        b.push_back(c[i]);
      }
    }
    int m = *min_element(b.begin(), b.end());
    int ans = n;
    for (int s = 2; s <= m + 1; ++s) {
      bool valid = true;
      int sum = 0;
      for (int x : b) {
        int almost = (s - x % s) % s;
        int full = (x + almost) / s - almost;
        if (full < 0) {
          valid = false;
          break;
        }
        sum += almost + full;
      }
      if (valid) {
        ans = min(ans, sum);
      }
    }
    cout << ans << "\n";
  }
  return 0;
}