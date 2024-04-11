#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const int MOD=1000000007;
#define endl "\n"
#define fst first
#define snd second
const int UNDEF = -1;
const int INF=1<<30;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif

inline int _norm(int x) {
  if (x<0) x+=MOD;
  return x;
}
template<int MOD>
struct ModInt {
  static const int Mod = MOD;
  unsigned x;
  ModInt() : x(0) {}
  ModInt(signed sig) {sig=_norm(sig); x=sig;}
  ModInt(signed long long sig) {sig=_norm(sig); x=sig;}
  int get() const { return (int)x; }
 
  ModInt &operator+=(ModInt that) { if((x += that.x) >= MOD) x -= MOD; return *this; }
  ModInt &operator-=(ModInt that) { if((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
  ModInt &operator*=(ModInt that) { x = ((unsigned long long)x * that.x) % MOD; return *this; }
  ModInt &operator/=(ModInt that) { return *this *= that.inverse(); }

  ModInt &operator+=(int that) {that=_norm(that); if((x += that) >= MOD) x -= MOD; return *this; }
  ModInt &operator-=(int that) {that=_norm(that); if((x += MOD - that) >= MOD) x -= MOD; return *this; }
  ModInt &operator*=(int that) {that=_norm(that); x = ((unsigned long long)x * that) % MOD; return *this; }
  ModInt &operator/=(int that) {that=_norm(that); return *this *= ModInt(that).inverse(); }

  ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
  ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
  ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
  ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }

  ModInt operator+(int that) const { return ModInt(*this) += that; }
  ModInt operator-(int that) const { return ModInt(*this) -= that; }
  ModInt operator*(int that) const { return ModInt(*this) *= that; }
  ModInt operator/(int that) const { return ModInt(*this) /= that; }


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

const int MAXFACT=1002;
mint fac[MAXFACT], invfac[MAXFACT];

void init() {
  mint got(1);
  for (int x=0;x<MAXFACT;x++) {
    fac[x]=got;
    got=got*(x+1);
  }
  got=got.inverse();
  for (int x=MAXFACT-1;x>=0;x--) {
    got=got*(x+1);
    invfac[x]=got;
  }
}

const int mx=1002;
mint f[mx][mx];
mint g[mx];
void initf() {
  init();
  f[0][0]=mint(1);
  for (int n=1;n<mx;n++) {
    for (int k=1;k<mx;k++) {
      f[n][k]=(f[n-1][k]*k)+f[n-1][k-1];
    }
  }
  for (int n=0;n<mx;n++) {
    mint ans(1);
    for (int k=1;k<=n;k++) {
      ans+=f[n][k];
    }
    g[n]=ans;
  }
}

int solve(int m, vector<string> vinp) {
  map<ll,int> h;
  for (int bit=0;bit<m;bit++) {
    ll got=0;
    for (int i=0;i<vinp.size();i++) {
      if (vinp[i][bit]=='1') got|=(1LL<<i);
    }
    //printf("got:%lld\n",got);
    h[got]++;
  }
  mint final(1);
  int ones=0;
  for (auto &w:h) {
    if (w.snd==1) ones++;
  }
  for (auto &w:h) {
    final*=g[w.snd]-1;
  }
  return final.get();
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  initf();
  int m,n; cin>>m>>n;
  vector<string> a(n);
  for (int i=0;i<n;i++) {
    cin>>a[i];
  }
  int ans=solve(m,a);
  printf("%d\n",ans);
}