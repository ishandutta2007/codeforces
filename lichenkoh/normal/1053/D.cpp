#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx,tune=native")
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
#ifdef ONLINE_JUDGE
#define assert(...) /* nothing */
#endif
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();
// mt19937 rng; rng.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());
// template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}

const int MAXN=2e6+4;
const int MAXP=MAXN;
bool sieve_array[MAXP+1];
int ap[MAXP+1];
vector<int> gpv;

void sieve() {
  for (int i = 0; i <= MAXP; i++) {
    sieve_array[i] = true;
    ap[i]=1<<30;
  }
  sieve_array[0] = false; sieve_array[1] = false;
  int lim = (int)(ceil(sqrt(MAXP)))+2;
  for (int i = 2; i <= lim; i++) {
    if(sieve_array[i]) {
      for (int j = i*i; j <= MAXP; j+=i) {
        sieve_array[j] = false;
        ap[j]=i;
      }
    }
  }
  for (int i = 2; i <= MAXP; i++) {
    if(sieve_array[i]) {
      gpv.PB(i);
      ap[i]=i;
    }
  }
}

pair<int,int> factorize_dest[500];
int factorize_tmp[500];
int factorize(int x) {
  int tsz=0;
  while(x>1) {
    int p=ap[x];
    x/=p;
    factorize_tmp[tsz++]=p;
  }
  if (x>1) factorize_tmp[tsz++]=x;
  sort(factorize_tmp,factorize_tmp+tsz);
  int didx=0;
  for (int tidx=0;tidx<tsz;tidx++) {
    int p=factorize_tmp[tidx];
    if (tidx==0||p!=factorize_tmp[tidx-1]) {
      factorize_dest[didx++]=MP(p,1);
    }
    else factorize_dest[didx-1].snd++;
  }
  return didx;
}
vector<pii> vfactorize(int x) {
  int ox=x;
  int tsz=0;
  while(x>1) {
    int p=ap[x];
    x/=p;
    factorize_tmp[tsz++]=p;
  }
  if (x>1) factorize_tmp[tsz++]=x;
  sort(factorize_tmp,factorize_tmp+tsz);
  vector<pii> dest;
  for (int tidx=0;tidx<tsz;tidx++) {
    int p=factorize_tmp[tidx];
    if (tidx==0||p!=factorize_tmp[tidx-1]) {
      dest.PB(MP(p,1));
    }
    else dest.back().snd++;
  }

  /*
  Checker
  */
  int ans=1;
  for (auto &w:dest) {
    assert(sieve_array[w.fst]);
    for (int i=0;i<w.snd;i++) ans*=w.fst;
  }
  for (int i=1;i<dest.size();i++) assert(dest[i-1].fst<dest[i].fst);
  assert(ans==ox);


  return dest;
}

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
typedef ModInt<MOD> mint;

const int mn=MAXN;
int c[mn];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  sieve();
  int inpn; cin>>inpn;
  for (int i=0;i<inpn;i++) {
    int inp; cin>>inp;
    ++c[inp];
  }
  int extra=0;
  vector<vector<pii> > a;
  map<int,int> hi;
  for (int inp=mn-1;inp>=0;inp--) {
    if (c[inp]==0) continue;
    if (hi[inp]==0) {
      if (c[inp]>0) {
        a.PB(vfactorize(inp));
        for (auto &w:a.back()) chkmax(hi[w.fst],w.snd);
      }
      if (c[inp]>1) {
        a.PB(vfactorize(inp-1));
        for (auto &w:a.back()) chkmax(hi[w.fst],w.snd);
      }
      if (c[inp]>2) extra=1;
    }
    else {
      if (c[inp]>0) {
        a.PB(vfactorize(inp-1));
        for (auto &w:a.back()) chkmax(hi[w.fst],w.snd);
      }
      if (c[inp]>1) extra=1;
    }
  }
  map<int,int> sel;
  for (auto &v:a) {
    for (auto &w:v) {
      if (w.snd==hi[w.fst]) {
        ++sel[w.fst];
      }
    }
  }
  for (auto &v:a) {
    bool critical=false;
    for (auto &w:v) {
      if (w.snd==hi[w.fst]&&sel[w.fst]==1) {
        critical=true;
      }
    }
    if (!critical) extra=1;
  }
  int ans=1;
  for (auto &w:hi) {
    for (int i=0;i<w.snd;i++) ans=(ans*(ll)w.fst)%MOD;
  }
  if (extra>0) ans++;
  ans%=MOD;
  printf("%d\n",ans);
  /*
  mint ans=1;
  for (auto &w:hi) {
    ans*=(mint(w.fst)^w.snd);
  }
  if (extra>0) ans+=1;
  printf("%d\n",ans.get());
  */
}