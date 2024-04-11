#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1000 * 1000 * 1000 + 7;

int main() {
  ios_base::sync_with_stdio(0);
  long long a, b;
  cin >> a >> b;
  long long res = 0;
  for (long long r = 1; r < b; r++) {
    res += a * r + a * (a + 1) / 2 % MOD * r % MOD * b;
    res %= MOD;
  }
  cout << res;
  return 0;
}