#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 1000010
#define MOD 1000000007

int N, K;
int FACT[MAXN];
int IFACT[MAXN];

int madd(int x, int y) {
  x += y;
  if (x >= MOD) x -= MOD;
  return x;
}

int msub(int x, int y) {
  x -= y;
  if (x < 0) x += MOD;
  return x;
}

int mmul(int x, int y) {
  return (1ll * x * y) % MOD;
}

int mexp(int x, int e) {
  if (e == 0) return 1;

  int r = 1;
  for (int i = 31 - __builtin_clz(e); i >= 0; i--) {
    r = mmul(r, r);
    if (e & 1 << i) r = mmul(r, x);
  }
  return r;
}

int mdiv(int x, int y) {
  return mmul(x, mexp(y, MOD - 2));
}

/*
int solve(int n) {
  if (n == N) {
    return 1;
  }

  int ref = 0;
  if (n > 0) {
    ref = mmul(FACT[N - 1], IFACT[n - 1]);
  }

  ref = madd(ref, solve(n + 1));

  int mul = 1;
  for (int k = 1; k < K && n + k + 1 <= N; k++) {
    mul = mmul(mul, n + k - 1);
    ref = madd(ref, mmul(mul, solve(n + k + 1)));
  }

  return ref;
}
*/

int DP[MAXN];

int main() {
  for (int i = IFACT[0] = FACT[0] = 1; i < MAXN; i++) {
    FACT[i] = mmul(i, FACT[i - 1]);
    IFACT[i] = mexp(FACT[i], MOD - 2);
  }
  cin >> N >> K;

  DP[N] = 1;

  int runres = 0;
  for (int n = N - 1; n > 0; n--) {
    int& ref = DP[n];

    ref = mmul(FACT[N - 1], IFACT[n - 1]);

    ref = madd(ref, DP[n + 1]);

    if (n + 2 <= N) {
      runres = mmul(n, madd(DP[n + 2], runres));

      if (n + K + 1 <= N) {
        runres = msub(runres, 
            mmul(mmul(FACT[n + K - 1], IFACT[n - 1]), DP[n + K + 1]));
      }
      ref = madd(ref, runres);
    }
  }
  cout << msub(FACT[N], DP[1]) << endl;

  return 0;
}