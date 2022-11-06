#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const ll MOD=1000000007LL;
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define DEBUG_CAT
#ifdef DEBUG_CAT

#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif

#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
 
using namespace std;
 
template<int MOD>
struct ModInt {
  static const int Mod = MOD;
  unsigned x;
  ModInt() : x(0) {}
  ModInt(signed sig) { int sigt = sig % MOD; if(sigt < 0) sigt += MOD; x = sigt; }
  ModInt(signed long long sig) { int sigt = sig % MOD; if(sigt < 0) sigt += MOD; x = sigt; }
  int get() const { return (int)x; }
 
  ModInt &operator+=(ModInt that) { if((x += that.x) >= MOD) x -= MOD; return *this; }
  ModInt &operator-=(ModInt that) { if((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
  ModInt &operator*=(ModInt that) { x = (unsigned long long)x * that.x % MOD; return *this; }
  ModInt &operator/=(ModInt that) { return *this *= that.inverse(); }
 
  ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
  ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
  ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
  ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }
 
  ModInt inverse() const {
    signed a = x, b = MOD, u = 1, v = 0;
    while(b) {
      signed t = a / b;
      a -= t * b; std::swap(a, b);
      u -= t * v; std::swap(u, v);
    }
    if(u < 0) u += Mod;
    ModInt res; res.x = (unsigned)u;
    return res;
  }
 
  bool operator==(ModInt that) const { return x == that.x; }
  bool operator!=(ModInt that) const { return x != that.x; }
  ModInt operator-() const { ModInt t; t.x = x == 0 ? 0 : Mod - x; return t; }
};
template<int MOD> ModInt<MOD> operator^(ModInt<MOD> a, unsigned long long k) {
  ModInt<MOD> r = 1;
  while(k) {
    if(k & 1) r *= a;
    a *= a;
    k >>= 1;
  }
  return r;
}
typedef ModInt<1000000007> mint;
 
int berlekampMassey(const vector<mint> &s, vector<mint> &C) {
  int N = (int)s.size();
  C.assign(N + 1, mint());
  vector<mint> B(N + 1, mint());
  C[0] = B[0] = 1;
  int degB = 0;
  vector<mint> T;
  int L = 0, m = 1;
  mint b = 1;
  for(int n = 0; n < N; ++ n) {
    mint d = s[n];
    for(int i = 1; i <= L; ++ i)
      d += C[i] * s[n - i];
    if(d == mint()) {
      ++ m;
    } else {
      if(2 * L <= n)
        T.assign(C.begin(), C.begin() + (L + 1));
      mint coeff = -d * b.inverse();
      for(int i = 0; i <= degB; ++ i)
        C[m + i] += coeff * B[i];
      if(2 * L <= n) {
        L = n + 1 - L;
        B.swap(T);
        degB = (int)B.size() - 1;
        b = d;
        m = 1;
      } else {
        ++ m;
      }
    }
  }
  C.resize(L + 1);
  return L;
}
 
void computeMinimumPolynomialForLinearlyRecurrentSequence(const vector<mint> &a, vector<mint> &phi) {
  int n2 = (int)a.size(), n = n2 / 2;
  assert(n2 % 2 == 0);
  int L = berlekampMassey(a, phi);
  reverse(phi.begin(), phi.begin() + (L + 1));
}
  
mint linearlyRecurrentSequenceValue(long long K, const vector<mint> &initValues, const vector<mint> &annPoly) {
  assert(K >= 0);
  if(K < (int)initValues.size())
    return initValues[(int)K];
  int d = (int)annPoly.size() - 1;
  assert(d >= 0);
  assert(annPoly[d].get() == 1);
  assert(d <= (int)initValues.size());
  if(d == 0)
    return mint();
  vector<mint> coeffs(d), square;
  coeffs[0] = 1;
  int l = 0;
  while((K >> l) > 1) ++ l;
  for(; l >= 0; -- l) {
    square.assign(d * 2 - 1, mint());
    for(int i = 0; i < d; ++ i)
      for(int j = 0; j < d; ++ j)
        square[i + j] += coeffs[i] * coeffs[j];
    for(int i = d * 2 - 2; i >= d; -- i) {
      mint c = square[i];
      if(c.x == 0) continue;
      for(int j = 0; j < d; ++ j)
        square[i - d + j] -= c * annPoly[j];
    }
    for(int i = 0; i < d; ++ i)
      coeffs[i] = square[i];
    if(K >> l & 1) {
      mint lc = coeffs[d - 1];
      for(int i = d - 1; i >= 1; -- i)
        coeffs[i] = coeffs[i - 1] - lc * annPoly[i];
      coeffs[0] = mint() - lc * annPoly[0];
    }
  }
  mint res;
  for(int i = 0; i < d; ++ i)
    res += coeffs[i] * initValues[i];
  return res;
}
const int mn = 301;
int fib[mn];
ll mod_pow(ll a, ll n) {ll mod=MOD; ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }
void init() {
  fib[1]=1;
  fib[2]=2;
  for (ll x=3;x<mn;x++) {
    fib[x]=fib[x-1]+fib[x-2];
    if (fib[x]>=MOD) fib[x]-=MOD;
  }
}
ll solve(ll nn, ll k) {
  init();
  vector<mint> seq;
  ll now=0;
  for (ll x=1;x<mn;x++) {
    ll got=(fib[x]*mod_pow(x,k))%MOD;
    now+=got;
    if (now>=MOD) now-=MOD;
    //printf("x:%lld now:%lld\n",x,now);
    seq.PB(mint(now));
  }
  if(seq.size() % 2 == 1) seq.pop_back();
  vector<mint> phi;
  computeMinimumPolynomialForLinearlyRecurrentSequence(seq, phi);
  //if(phi.size() >= seq.size() / 2 - 2) {
  //  cerr << "warning: maybe it is not enough terms" << endl;
  //}
  mint ans = linearlyRecurrentSequenceValue(nn-1, seq, phi);
  return ans.get();
}

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n,k; cin>>n>>k;
  ll ans =solve(n,k)%MOD;
  printf("%lld\n",ans);
}