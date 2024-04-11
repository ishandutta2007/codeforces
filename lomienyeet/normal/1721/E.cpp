#include <iostream>
#include <map>
int32_t main() {
  std::string s;
  std::cin >> s;
  int n = s.length(), lps[n + 10] = {};
  lps[0] = -1;
  for (int l = 0, r = -1; l < n; l++) {
    while (r >= 0 && s[l] != s[r]) r = (r ? lps[r - 1] + 1 : -1);
    lps[l] = r++;
  }
  for (int i = 0; i < 10; i++) {
    s += ' ';
    lps[n + i] = -1;
  }
  int q;
  std::cin >> q;
  std::map<std::string, int> mp;
  while (q--) {
    std::string t, ok = "";
    std::cin >> t;
    int m = t.length();
    for (int i = 0; i < m; i++) s[n + i] = t[i];
    for (int l = n, r = lps[n - 1] + 1; l < n + m; l++) {
      ok += s[l];
      if (mp.contains(ok)) r = (lps[l] = mp[ok]) + 1;
      else {
        while (r >= 0 && s[l] != s[r]) r = (r ? lps[r - 1] + 1 : -1);
        mp[ok] = (lps[l] = r++);
      }
      std::cout << r << " ";
    }
    std::cout << "\n";
  }
}