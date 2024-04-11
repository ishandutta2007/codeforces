// ""

#include <iostream>
#include <cmath>
#include <algorithm>
const int mxN = 1e3 + 5;
int freq[mxN], sum[mxN];
int32_t main() {
  int n, m, k;
  std::cin >> n >> m >> k;
  if (abs(n - m) & 1) {
    std::cout << "0\n";
    return 0;
  }
  bool o = (n > m);
  if (n > m) std::swap(n, m);
  for (int i = 0, a, b, c; i < k; i++) {
    std::cin >> a >> b >> c;
    a--;
    b--;
    if (o) std::swap(a, b);
    freq[b]++;
    sum[b] += (c == -1);
  }
  int mod; // cursed?
  std::cin >> mod;
  for (int i = 0; i < m; i++) {
    if (freq[i] == n) {
      if (!(sum[i] & 1)) {
        std::cout << "0\n";
        return 0;
      }
      k--;
    }
  }
  int ans = 1;
  for (int i = 0; i < (n - 1) * (m - 1) - k; i++) (ans <<= 1) %= mod;
  std::cout << ans << "\n";
}