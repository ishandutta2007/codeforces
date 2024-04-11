/* 


WACF


dp

HLDGCD



code
OI




code

 fast io afo
pragmaavx



OI

rp
*/

#include <iostream>
#include <algorithm>
int mod = 1e9 + 7;
void m998() { mod = 998244353; } // 
void eat() {
  std::string s, t;
  std::cin >> s >> t;
  int n = s.length(), m = t.length(), pp[m + 1] = {};
  pp[0] = -1; // no
  for (int l = 0, r = 0; l < n && r < m; l++) {
    if (s[l] == t[r]) pp[++r] = l;
  }
  int ans = 0;
  s += "_";
  t += "_";
  for (int l = n, r = m; l >= 0 && r >= 0; l--) {
    if (s[l] == t[r]) ans = std::max(ans, l - pp[r--] - 1);
  }
  std::cout << ans << "\n";
}
int32_t main() {
  int t = 1;
  // std::cin >> t;
  while (t--) eat();
}