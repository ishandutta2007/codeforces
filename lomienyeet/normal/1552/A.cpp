#include <iostream>
#include <algorithm>
void eat() {
  int n, ans = 0;
  std::string s;
  std::cin >> n >> s;
  std::string t = s;
  std::sort(t.begin(), t.end());
  for (int i = 0; i < n; i++) ans += (s[i] != t[i]);
  std::cout << ans << "\n";
}
int32_t main() {
  int t = 1;
  std::cin >> t;
  while (t--) eat();
}