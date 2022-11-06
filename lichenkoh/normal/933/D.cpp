#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,tune=native")
#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define endl "\n"
#define fst first
#define snd second
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
#ifdef ONLINE_JUDGE
#define assert(XXX) XXX
#else
#define DEBUG_CAT
#endif
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();
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

ll gn;
ll floorn[4];
mint query(ll inl, ll r, int deg) {
  // Sum l^k,(l+4)^k,(l+8)^k,...,r^k
  mint q=(r-inl)/4;
  mint l=inl;
  if (deg==0) {
    return q+1;
  }
  else if (deg==1) {
    return (q+1)*(l+mint(2)*q);
  }
  else if (deg==2) {
    return ((q + 1)*(mint(3)*l*l + mint(12)*l*q + mint(8)*q*(mint(2)*q + 1)))/3;
  }
  else {
    return  (q + 1)*(l + mint(2)*q)*(l*l + mint(4)*l*q + mint(8)*q*(q + 1));
  }
}
mint divisorContribution(int d, int otherMod4, int deg) {
  ll n=gn;
  ll lo=d+1,hi=n/d;
  while(lo%4!=otherMod4) ++lo;
  while(hi>=0&&hi%4!=otherMod4) --hi;
  if (lo>hi) return 0;
  mint dpow=1;
  for (int i=0;i<deg;i++) dpow*=d;
  return query(lo,hi,deg)*dpow;
}
mint degcoeff[4]; // Fill in from expansion.
mint solve() {
  int slim=sqrt((long double)gn)+3;
  mint sumans=0;
  for (int deg=0;deg<=3;deg++) {
    mint degans=0;
    for (int d=1;d<=slim;d++) {
      mint contrib1=divisorContribution(d,1,deg);
      mint contrib3=divisorContribution(d,3,deg);
      if (d%4==1||d%4==3) {
        mint all=contrib1+contrib3+divisorContribution(d,0,deg)+divisorContribution(d,2,deg);
        if (d%4==1) contrib1+=all;
        else if (d%4==3) contrib3+=all;
      }
      ll d2=d*(ll)d;
      if (d2<=gn) {
        mint d2pow=1;
        for (int i=0;i<deg;i++) d2pow*=mint(d2);
        if (d%4==1) contrib1+=d2pow;
        else if (d%4==3) contrib3+=d2pow;
      }
      //if(deg==1)printf("d:%d contrib1:%d contrib3:%d\n",d,contrib1.get(),contrib3.get());
      mint contrib=mint(4)*(contrib1-contrib3);
      degans+=contrib;
    }
    sumans+=degans*degcoeff[deg];
  }
  return sumans;
}
void initcoeff() {
  
  mint m=gn;
  degcoeff[0]=(m*m*m)/6+(m*m)/2+m/3;
  degcoeff[1]=m/2+mint(2)/3;
  degcoeff[2]=-m/2-1;
  degcoeff[3]=mint(1)/3;
  
  
  //degcoeff[1]=1;
}

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  //test(); return 0;
  cin>>gn;
  initcoeff();
  mint final=solve();
  final+=degcoeff[0]; // Point (0,0) is a special case
  printf("%d\n",final.get());
}