/*
reading problem: 21:15 - 21:18
thinking: 21:18 - 21:35
coding: 21:35 - 21:46
debugging: 21:46 - 22:02 (hopefully)
*/

#include <iostream>
#include <map>
#include <algorithm>
void solve() {
  int n, k;
  std::string s;
  std::cin >> n >> k >> s;
  for (auto &i : s) i = (i == '0' ? '1' : '0');
  int ps[n] = {};
  for (int i = 0; i < n; i++) {
    if (i) ps[i] = ps[i - 1];
    ps[i] += (s[i] == '1');
  }
  std::map<int, int> mp;
  int msk = 0;
  for (int i = 0; i < k; i++) {
    if (i < 20) (msk *= 2) += (s[i] == '1');
    else {
      if (s[i - 20] == '1') msk -= (1 << 19);
      (msk *= 2) += (s[i] == '1');
    }
  }
  int uwu = 0;
  if (k <= 20 || (k > 20 && !ps[k - 21])) {
    if (!mp[msk]) {
      uwu++;
      mp[msk] = 1;
    }
  }
  for (int i = k; i < n; i++) {
    int lb = std::min(k, 20);
    if (s[i - lb] == '1') msk -= (1 << (lb - 1));
    (msk *= 2) += (s[i] == '1');
    if (k <= 20 || (k > 20 && !(ps[i - lb] - ps[i - k]))) {
      if (!mp[msk]) {
        uwu++;
        mp[msk] = 1;
      }
    }
  }
  if (k <= 20 && uwu == (1 << k)) std::cout << "NO\n";
  else {
    int z;
    for (int i = 0; i <= 2000000; i++) {
      if (!mp[i]) {
        z = i;
        break;
      }
    }
    std::string ans(k, '0');
    for (int i = 0; i < std::min(k, 20); i++) {
      if (z & (1 << i)) ans[i] = '1';
    }
    std::reverse(ans.begin(), ans.end());
    std::cout << "YES\n" << ans << "\n";
  }
}
int32_t main() {
  int t;
  std::cin >> t;
  while (t--) solve();
}