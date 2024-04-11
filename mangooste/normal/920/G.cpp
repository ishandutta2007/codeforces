#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll x, p, k;
    cin >> x >> p >> k;
    if (p == 1) {
      cout << x + k << '\n';
      continue;
    }
    vector<int> primes;
    for (int i = 2; i * i <= p; i++) {
      if (p % i == 0) {
        primes.push_back(i);
        while (p % i == 0) {
          p /= i;
        }
      }
    }
    if (p != 1) {
      primes.push_back(p);
    }
    int sz = primes.size();
    vector<ll> dp;
    dp.assign(1 << sz, 1);
    for (int mask = 1; mask < (1 << sz); mask++) {
      int one = __builtin_ctz(mask);
      dp[mask] = dp[mask - (1 << one)] * primes[one];
    }
    ll L = x, R = 1e18;
    while (R - L > 1) {
      ll mid = (L + R) / 2;
      ll cnt = 0;
      for (int mask = 1; mask < (1 << sz); mask++) {
        ll p = dp[mask];
        ll now = (mid - mid / p) - (x - x / p);
        cnt += (__builtin_popcount(mask) % 2 ? now : -now);
      }
      (cnt < k ? L : R) = mid;
    }
    cout << R << '\n';
  }
}