#include <cstdio>
#include <cstring>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

const int S=210, A=26, MOD = 10007;
char str[S];
int n,s;
int COEF[S][S],COEF2[S][S];
int DYNO[S][S][S];
int COUNT[S][S],COUNT2[S][S];

int modpow(int a, int n) {
  a %= MOD;
  int w = 1;
  while (n) {
    if (n&1) { w = w*a % MOD; }
    a = a*a % MOD;
    n /= 2;
  }
  return w;
}

int modinv(int n) {
  return modpow(n, MOD-2);
}

int binom(int n, int k) {
  n %= MOD;
  int w = 1;
  REP(i,k) {
    w = w*(n-i) % MOD;
    w = w*modinv(i+1) % MOD;
  }
  return w;
}

void modadd(int& a, int b) {
  a = (a + b) % MOD;
}

int main() {
  scanf("%s%d",str,&n);
  s = strlen(str);
  n += s;

  int n2 = (n+1)/2;

  REP(i,s) COEF[i+1][0] = binom(n2, i) * modpow(A-1, n2-i) % MOD;
  REP(i,s) COEF[0][i+1] = binom(n2, i) * modpow(A-2, n2-i) % MOD;
  REP(i,s) REP(j,s) COEF[i+1][j+1] = (COEF[i+1][j] + MOD - COEF[i][j+1]) % MOD;

  if (n%2) {
    int n22 = n/2;
    REP(i,s) COEF2[i+1][0] = binom(n22, i) * modpow(A-1, n22-i) % MOD;
    REP(i,s) COEF2[0][i+1] = binom(n22, i) * modpow(A-2, n22-i) % MOD;
    REP(i,s) REP(j,s) COEF2[i+1][j+1] = (COEF2[i+1][j] + MOD - COEF2[i][j+1]) % MOD;
  }

  DYNO[0][s-1][0] = 1;

  for(int len=s; len>=1; --len) REP(i,s) REP(aa,s+1) {
    int j = i + len-1;
    if (j >= s) continue;
    int bb = i + s-1-j - 2*aa;
    if (bb < 0 || bb > s) continue;

    int D = DYNO[i][j][aa];

    if (str[i] == str[j]) {
      if (i < j) {
        modadd(DYNO[i+1][j-1][aa+1], D);
      }

      modadd(COUNT[aa+1][bb], D);

      if (i+1 == j) {
        modadd(COUNT2[aa+1][bb], D);
      }
    } else {
      modadd(DYNO[i+1][j][aa], D);
      modadd(DYNO[i][j-1][aa], D);

      modadd(COUNT[aa][bb+1], D);
    }
  }

  int ans = modpow(A, n2);

  REP(aa,s+1) REP(bb,s+1) {
    ans = (ans + MOD*MOD - COUNT[aa][bb] * COEF[aa][bb]) % MOD;
  }

  if (n%2) {
    REP(aa,s+1) REP(bb,s+1) {
      ans = (ans + MOD*MOD - COUNT2[aa][bb] * COEF2[aa][bb]) % MOD;
    }
  }

  printf("%d\n", ans);
}