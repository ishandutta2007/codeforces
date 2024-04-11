#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
typedef long long ll;

const int S = 5, MOD = 1000000007, MODQ = MOD-1;

struct mat_t {
  int m[S][S];
};

mat_t mat_mult(const mat_t& a, const mat_t& b) {
  mat_t c;
  REP(i,S) REP(j,S) c.m[i][j] = 0;
  REP(i,S) REP(k,S) REP(j,S) {
    c.m[i][j] = (c.m[i][j] + ll(a.m[i][k]) * b.m[k][j] % MODQ) % MODQ;
  }
  return c;
}

mat_t mat_pow(mat_t a, ll n) {
  mat_t w;
  REP(i,S) REP(j,S) w.m[i][j] = i==j;
  while (n) {
    if (n&1) w = mat_mult(w, a);
    a = mat_mult(a, a);
    n /= 2;
  }
  return w;
}

int mod_pow(int a, ll n) {
  int w = 1;
  while (n) {
    if (n&1) w = ll(w) * a % MOD;
    a = ll(a) * a % MOD;
    n /= 2;
  }
  return w;
}

ll n;
int f[3],c;

int main() {
  scanf("%lld%d%d%d%d",&n,&f[0],&f[1],&f[2],&c);
  --n;

  mat_t m;
  REP(i,S) REP(j,S) m.m[i][j] = 0;
  m.m[0][0] = m.m[0][1] = m.m[0][2] = 1;
  m.m[1][0] = m.m[2][1] = 1;

  mat_t mp = mat_pow(m, n);
  int ans = 1;

  REP(i,3) {
    ans = ll(ans) * mod_pow(f[2-i], mp.m[2][i]) % MOD;
  }

  m.m[0][3] = 2;
  m.m[3][3] = m.m[3][4] = m.m[4][4] = 1;

  mp = mat_pow(m, n);
  ans = ll(ans) * mod_pow(c, mp.m[1][4]) % MOD;

  printf("%d\n", ans);
}