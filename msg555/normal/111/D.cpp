#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <algorithm>

#define MOD 1000000007

using namespace std;

long long P[1010];
long long PP[1010];
long long NCR[2010];
long long NCR2[2010][2010];

long long mexp(long long x, long long p) {
  long long ret = 1;
  for(int i = 63 - __builtin_clzll(p); i >= 0; i--) {
    ret = (ret * ret) % MOD;
    if(p & 1ll << i) ret = (ret * x) % MOD;
  }
  return ret;
}

int main() {
  int N, M, K; cin >> N >> M >> K;

  P[0] = 0;
  for(int i = 1; i < 1010; i++) {
    P[i] = 1;
    for(int j = 0; j < N; j++) {
      P[i] = (P[i] * i) % MOD;
    }
  }
  for(int i = 0; i < 1010; i++) {
    PP[i] = 1;
    for(int j = 2; j < M; j++) {
      PP[i] = (PP[i] * P[i]) % MOD;
    }
  }
  for(int i = NCR2[0][0] = 1; i < 2010; i++) {
    for(int j = NCR2[i][0] = NCR2[i][i] = 1; j < 2010; j++) {
      NCR2[i][j] = (NCR2[i - 1][j - 1] + NCR2[i - 1][j]) % MOD;
    }
  }

  for(int i = NCR[0] = 1; i <= K && i < 2010; i++) {
    NCR[i] = (NCR[i - 1] * (K - i + 1)) % MOD;
    NCR[i] = (NCR[i] * mexp(i, MOD - 2)) % MOD;
  }

  if(M == 1) {
    long long res = 1;
    for(int i = 0; i < N; i++) res = (res * K) % MOD;
    cout << res << endl;
    return 0;
  }

  long long res = 0;
  for(int i = 1; i <= K && i <= N; i++) {
    long long base = 0;
    for(int j = 1; j <= i; j++) {
      long long v = (P[j] * NCR2[i][j]) % MOD;
      if((i - j) % 2 == 0) base = (base + v) % MOD;
      else base = (base + MOD - v) % MOD;
    }
    for(int olp = 0; olp <= i; olp++) {
      if(2 * i - olp > K) continue;

      //long long num = ((P[i] - P[i - 1] * i) % MOD + MOD) % MOD;
      long long num = base;
      num = (num * num) % MOD;
      num = (num * PP[olp]) % MOD;
      num = (num * NCR[2 * i - olp]) % MOD;
      num = (num * NCR2[2 * i - olp][i]) % MOD;
      num = (num * NCR2[i][olp]) % MOD;

      res = (res + num) % MOD;
    }
  }

  cout << res << endl;
}