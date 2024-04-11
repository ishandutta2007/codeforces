#include <iostream>
#include <cstring>
#define int long long
const int mod = 1e9 + 7;
int bm(int b, int p, int m = mod) {
  int ans = 1;
  b %= m;
  while (p) {
    if (p & 1) (ans *= b) %= m;
    (b *= b) %=m;
    p >>= 1;
  }
  return ans;
}
void eat() {
  int n;
  std::cin >> n;
  int arr[n], pp[n][n], dp[1 << n], ans = 0;
  memset(dp, 0, sizeof dp);
  for (int i = 0; i < n; i++) std::cin >> arr[i];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i != j) pp[i][j] = (arr[i] * bm(arr[i] + arr[j], mod - 2)) % mod;
      else pp[i][j] = 0;
    }
  }
  for (int msk = 1; msk < (1 << n); msk++) {
    int aaa = 0;
    for (int po = (msk - 1) & msk; po; po = (po - 1) & msk) {
      int nom = 1;
      for (int i = 0; i < n; i++) {
        if ((po >> i) & 1) {
          for (int j = 0; j < n; j++) {
            if (((msk ^ po) >> j) & 1) (nom *= pp[i][j]) %=mod;
          }
        }
      }
      (aaa += (nom * dp[po]) % mod) %=mod;
    }
    dp[msk] = (aaa = (mod - aaa + 1) % mod);
    int qwq = 1;
    for (int i = 0; i < n; i++) {
      if ((msk >> i) & 1) {
        for (int j = 0; j < n; j++) {
          if (!((msk >> j) & 1)) (qwq *= pp[i][j]) %= mod;
        }
      }
    }
    (ans += ((aaa * qwq) % mod * __builtin_popcount(msk)) % mod) %= mod;
  }
  std::cout << ans << "\n";
}
int32_t main() {
  int t = 1;
  // std::cin >> t;
  while (t--) eat();
}