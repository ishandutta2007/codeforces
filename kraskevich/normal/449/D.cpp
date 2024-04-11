#include <bits/stdc++.h>

using namespace std;

const int MASK = 1 << 20;
const int MOD = 1000 * 1000 * 1000 + 7;

int dp[MASK];
int f[MASK][21];
long long p2[MASK];

int main() {
  ios_base::sync_with_stdio(0);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    f[a][20]++;
  }
  for (int mask = MASK - 1; mask >= 0; mask--)
    for (int bit = 0; bit < 20; bit++)
      if (mask & (1 << bit)) {
        int nmask = (mask ^ (1 << bit));
        for (int nbit = 20; nbit >= bit; nbit--)
          f[nmask][bit] += f[mask][nbit];
      }
  for (int mask = 0; mask < MASK; mask++)
    for (int bit = 0; bit <= 20; bit++)
      dp[mask] += f[mask][bit];
  p2[0] = 1;
  for (int i = 1; i < MASK; i++)
    p2[i] = p2[i - 1] * 2 % MOD;
  long long tot = (p2[n] - 1 + MOD) % MOD;
  long long bad = 0;
  for (int mask = 1; mask < MASK; mask++) {
    long long cur = p2[dp[mask]] - 1;
    cur += MOD;
    cur %= MOD;
    if (__builtin_popcount(mask) % 2 == 1)
      bad += cur, bad %= MOD;
    else
      bad -= cur, bad += MOD, bad %= MOD;
  }
  cout << (tot - bad + MOD) % MOD;

  return 0;
}