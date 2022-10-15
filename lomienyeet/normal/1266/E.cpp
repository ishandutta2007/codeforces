#include <iostream>
#include <map>
#define int long long
#pragma GCC optimize ("Ofast")
void solve() {
  int n, ans = 0;
  std::cin >> n;
  int arr[n + 1] = {};
  for (int i = 1; i <= n; i++) {
    std::cin >> arr[i];
    ans += arr[i];
  }
  int q;
  std::cin >> q;
  std::map<std::pair<int, int>, int> mp;
  while (q--) {
    int a, b, c;
    std::cin >> a >> b >> c;
    if (mp.find({a, b}) != mp.end()) {
      arr[mp[{a, b}]]++;
      if (arr[mp[{a, b}]] > 0) ans++;
    }
    mp[{a, b}] = c;
    if (!c) {
      mp.erase(mp.find({a, b}));
      std::cout << ans << "\n";
      continue;
    }
    ans -= (arr[c] > 0);
    arr[c]--;
    std::cout << ans << "\n";
  }
}
int32_t main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  int t = 1;
  // std::cin >> t;
  while (t--) solve();
}