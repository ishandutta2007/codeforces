#include<bits/stdc++.h>
using namespace std;
 
const int N = 205;
int mod;
 
int power(long long n, long long k) {
  int ans = 1 % mod; n %= mod; if (n < 0) n += mod;
  while (k) {
    if (k & 1) ans = (long long) ans * n % mod;
    n = (long long) n * n % mod;
    k >>= 1;
  }
  return ans;
}
int dp[N][N][40], fac[N], ifac[N];
int vis[N][N][40];
int n, a1;
/*
number of solutions to the equation b1 + b2 + ... bn <= a1
s.t. 0<=bi<=n+1-a1 
and there is at least 1 number >= n + 1 - a1, 
at least 2 numbers >= (n - a1), ..., at least (n - a1) numbers >= 2
*/
int yo(int i, int sum, int k) { // k <= 2 * sqrt(n)
  if (i == n) return fac[n];
  if (k == 0) return 1LL * fac[n] * ifac[n - i] % mod;
  if (vis[i][sum][k] == a1) return dp[i][sum][k];
  vis[i][sum][k] = a1;
  int &ans = dp[i][sum][k];
  ans = 0;
  int r = (a1 - sum) / k;
  for (int cnt = r; cnt >= 0; cnt--) {
    if (k > 1 and i + cnt < n - a1 + 1 - k + 1) continue;
    ans += 1LL * yo(i + cnt, sum + cnt * k, k - 1) * ifac[cnt] % mod;
    ans %= mod;
  }
  return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> mod;
  fac[0] = 1;
  ifac[0] = 1;
  for (int i = 1; i < N; i++) {
    fac[i] = 1LL * fac[i - 1] * i % mod;
    ifac[i] = power(fac[i], mod - 2);
  }
  int ans = 0;
  int lim = 2 * sqrt(n) + 1;
  for (a1 = max(1, n - lim); a1 <= n; a1++) {
    ans += yo(0, 0, n + 1 - a1);
    ans %= mod;
  }
  ans %= mod;
  cout << ans << '\n';
  return 0;
}