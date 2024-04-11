// giving up is cringe.
// please can someone teach me oi.

#include <iostream>
#include <numeric>
#include <vector>
#define int long long
#define double long double
#define ff first
#define ss second
void eat() {
  int n;
  std::cin >> n;
  int freq[32] = {};
  for (int i = 1, x; i <= n; i++) {
    std::cin >> x;
    for (int j = 0; j < 31; j++) {
      if (x & (1ll << j)) freq[j]++;
    }
  }
  int z = -1;
  for (int i = 0; i < 31; i++) {
    if (freq[i]) {
      if (z == -1) z = freq[i];
      else z = std::gcd(z, freq[i]);
    }
  }
  if (z == -1) {
    for (int i = 1; i <= n; i++) std::cout << i << " \n"[i == n];
    return;
  }
  std::vector<int> ans;
  for (int i = 1; i * i <= z; i++) {
    if (!(z % i)) {
      ans.push_back(i);
      if (i < z / i) ans.push_back(z / i);
    }
  }
  std::sort(ans.begin(), ans.end());
  for (int i = 0; i < ans.size(); i++) std::cout << ans[i] << " \n"[i == ans.size() - 1];
}
int32_t main() {
  int t = 1;
  std::cin >> t;
  while (t--) eat();
}