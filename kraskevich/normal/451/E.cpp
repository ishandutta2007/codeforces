#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000 * 1000 * 1000 + 7;

long long bpow(long long base, long long n) {
  if (n < 0)
    return 0;
  long long res = 1;
  for (; n > 0; n /= 2) {
    if (n & 1)
      res *= base, res %= MOD;
    base *= base;
    base %= MOD;
  }
  return res;
}


long long ways(int cnt, long long sz) {
  if (sz < 0)
    return 0;
  long long n = sz + cnt - 1;
  long long k = cnt - 1;
  long long u = 1;
  for (int f = 0; f < k; f++)
    u = u * ((n - f) % MOD) % MOD;
  long long d = 1;
  for (int f = 1; f <= k; f++)
    d = d * f % MOD;
  d = bpow(d, MOD - 2);
  return u * d % MOD;
}


int main() {
  ios_base::sync_with_stdio(0);

  int n;
  long long want;
  cin >> n >> want;
  vector<long long> f(n);
  for (int i = 0; i < n; i++)
    cin >> f[i];
  long long ans = 0;
  for (int mask = 1; mask < (1 << n); mask++) {
    long long sum = 0;
    for (int i = 0; i < n; i++)
      if (mask & (1 << i))
        sum += f[i] + 1;
    long long cur = ways(n, want - sum);
    if (__builtin_popcount(mask) & 1)
      ans += cur, ans %= MOD;
    else
      ans += MOD - cur, ans %= MOD;
  }
  cout << (ways(n, want) - ans + MOD) % MOD;

  return 0;
}