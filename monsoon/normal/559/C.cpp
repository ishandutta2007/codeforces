#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
typedef long long ll;

const int N=2100, R=100100, MOD = 1000000007;
int rows,cols,n,r[N],c[N],idx[N];
int dp[N],fact[2*R],invfact[2*R];

int binom(int n, int k) {
  return ll(fact[n]) * invfact[k] % MOD * invfact[n-k] % MOD;
}

int all_paths(int r1, int c1, int r2, int c2) {
  return binom(r2-r1 + c2-c1, c2-c1);
}

int modpow(int a, int n) {
  int r = 1;
  while (n) {
    if (n&1) { r = ll(r)*a % MOD; }
    a = ll(a)*a % MOD;
    n /= 2;
  }
  return r;
}

int modinv(int a) {
  return modpow(a, MOD-2);
}

int main() {
  scanf("%d%d%d",&rows,&cols,&n);
  REP(i,n) { scanf("%d%d",&r[i],&c[i]); }
  r[n] = c[n] = 1; n++;
  REP(i,n) { idx[i] = i; }

  fact[0] = invfact[0] = 1;
  REP(i,rows+cols) {
    fact[i+1] = ll(fact[i]) * (i+1) % MOD;
    invfact[i+1] = modinv(fact[i+1]);
  }

  sort(idx,idx+n, [](int i, int j) { return r[i]+c[i] > r[j]+c[j]; });

  REP(_i,n) {
    int i = idx[_i];
    int all = all_paths(r[i], c[i], rows, cols);

    REP(_j,_i) {
      int j = idx[_j];
      if (r[j] >= r[i] && c[j] >= c[i]) {
        all = (all + MOD - ll(all_paths(r[i], c[i], r[j], c[j])) * dp[j] % MOD) % MOD;
      }
    }

    dp[i] = all;
  }

  printf("%d\n", dp[n-1]);
}