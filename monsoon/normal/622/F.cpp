#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
typedef long long ll;

template<int MOD>
struct modint_t {
  int x;
  modint_t(int x = 0) : x(x) { }
  void operator+=(modint_t y) { x = (x + y.x) % MOD; }
  void operator*=(modint_t y) { x = ll(x) * y.x % MOD; }
};

template<int MOD>
inline modint_t<MOD> operator+(modint_t<MOD> x, modint_t<MOD> y) { x += y; return x; }
template<int MOD>
inline modint_t<MOD> operator*(modint_t<MOD> x, modint_t<MOD> y) { x *= y; return x; }

const int MOD = 1000000007;
typedef modint_t<MOD> modint;

const int N = 1000100;
int n,k,sieve[N];
modint p[N],psum[N],facinv[N];

modint modpow(modint x, int n) {
  modint ans = 1;
  while (n) {
    if (n&1) ans *= x;
    x *= x;
    n /= 2;
  }
  return ans;
}

int main() {
  scanf("%d%d",&n,&k);

  p[1] = 1;
  for (int i=2; i<=k+1; ++i) if (!sieve[i]) {
    sieve[i] = i;
    p[i] = modpow(i, k);
    for (int j=i; j<=k+1; j += i) if (!sieve[j]) {
      sieve[j] = i;
    }
  }
  for (int i=2; i<=k+1; ++i) {
    p[i] = p[sieve[i]] * p[i/sieve[i]];
  }

  REP(i,k+1) { psum[i+1] = psum[i] + p[i+1]; }

  modint fac = 1;
  REP(i,k+1) fac *= i+1;
  fac = modpow(fac, MOD-2);
  REP(i,k+1) {
    facinv[k+1-i] = fac;
    fac *= k+1-i;
  }
  facinv[0] = 1;

  modint sum, prod=1;
  REP(i,k+2) {
    modint val = MOD + n - i;
    modint val_y = psum[i] * facinv[i] * facinv[k+1-i] * modint((k+1-i)%2 ? MOD-1 : 1);
    sum = sum*val + prod*val_y;
    prod *= val;
  }
  printf("%d\n", sum.x);
}