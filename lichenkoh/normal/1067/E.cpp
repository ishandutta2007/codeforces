#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx,tune=native")
#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const int MOD=998244353;
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
const int mn=5e5+4;

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

mint p2[mn];
int gn;
vi g[mn];
bool valid[mn];
int vsz[mn];
mint dp[mn][2];
int getsz(int x, int p) {
  int sz=1;
  for (auto &y:g[x]) if (y!=p) sz+=getsz(y,x);
  return vsz[x]=sz;
}

mint gmatch=0;

mint f(int x, int p, int asku) {
  if (valid[x]) return dp[x][asku];
  valid[x]=true;
  mint h[2][2];
  int cur=0,nxt=1;
  h[0][0]=1; h[0][1]=0;
  int preve=0;
  for (auto &y:g[x]) {
    if (y==p) continue;
    h[nxt][0]=0;h[nxt][1]=0;
    preve+=vsz[y];
    for (int used=0;used<=1;used++) {
      mint now=h[cur][used];
      for (int e=0;e<=1;e++) {
        if (used==0&&e==1) {
          // Special
          h[nxt][0]+=now*f(y,x,1);
          h[nxt][1]+=now*f(y,x,0);
          gmatch+=now*f(y,x,0)*p2[gn-1-preve];
        }
        else {
          h[nxt][used]+=now*(f(y,x,0)+f(y,x,1));
        }
      }
    }
    swap(cur,nxt);
  }
  for (int u=0;u<2;u++) {
    dp[x][u]=h[cur][u];
    //printf("p:%d x:%d u:%d ans:%d\n",p,x,u,dp[x][u].get());
  }
  return dp[x][asku];
}

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n; cin>>n;
  for (int i=1;i<n;i++) {
    int x,y;cin>>x>>y; g[x].PB(y); g[y].PB(x);
  }
  gn=n;
  p2[0]=1;
  for (int i=1;i<mn;i++) p2[i]=p2[i-1]+p2[i-1];
  getsz(1,-1);
  f(1,-1,0);
  mint final=gmatch*2;
  printf("%d\n",final.get());
}