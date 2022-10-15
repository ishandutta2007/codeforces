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
  int n, m;
  std::string a, b;
  std::cin >> n >> m >> a >> b;
  int aaa[m + 1] = {}, bbb[n + 1] = {};
  for (int l = 0, r = 0; l < n && r < m; l++) {
    if (a[l] == b[r]) aaa[r++] = l;
  }
  for (int l = n - 1, r = m - 1; l >= 0 && r >= 0; l--) {
    if (a[l] == b[r]) bbb[r--] = l;
  }
  int ans = 0;
  for (int i = 1; i < m; i++) ans = std::max(ans, bbb[i] - aaa[i - 1]);
  std::cout << ans << "\n";
}
int32_t main() {
  int t = 1;
  // std::cin >> t;
  while (t--) eat();
}