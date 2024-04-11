#ifdef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx,avx2")
#pragma GCC optimize("Ofast")
#endif
#include "bits/stdc++.h"
#ifndef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
#pragma GCC optimize("Ofast")
#endif
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
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;typedef vector<pii> vpii;typedef vector<pll> vpll;
template<typename T> void makeunique(vector<T> &vx) {sort(vx.begin(),vx.end());auto it=unique(vx.begin(),vx.end());vx.resize(std::distance(vx.begin(),it));}
#ifdef ONLINE_JUDGE
#define assert(...) /* nothing */
#endif
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   ////printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
// mt19937 rng; rng.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());
// template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=(int)v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}


struct mint {
  unsigned x;
  inline int _norm(int x) {
    if (x<0) x+=MOD;
    return x;
  }
  mint() : x(0) {}
  mint(signed sig) {sig=_norm(sig); x=sig;}
  mint(signed long long sig) {sig=_norm(sig%MOD); x=sig;}
  int get() const { return (int)x; }
 
  mint &operator+=(mint that) { if((x += that.x) >= MOD) x -= MOD; return *this; }
  mint &operator-=(mint that) { if((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
  mint &operator*=(mint that) { x = ((unsigned long long)x * that.x) % MOD; return *this; }
  mint &operator/=(mint that) { return *this *= that.inverse(); }

  mint &operator+=(int that) {that=_norm(that); if((x += that) >= MOD) x -= MOD; return *this; }
  mint &operator-=(int that) {that=_norm(that); if((x += MOD - that) >= MOD) x -= MOD; return *this; }
  mint &operator*=(int that) {that=_norm(that); x = ((unsigned long long)x * that) % MOD; return *this; }
  mint &operator/=(int that) {that=_norm(that); return *this *= mint(that).inverse(); }

  mint operator+(mint that) const { return mint(*this) += that; }
  mint operator-(mint that) const { return mint(*this) -= that; }
  mint operator*(mint that) const { return mint(*this) *= that; }
  mint operator/(mint that) const { return mint(*this) /= that; }

  mint operator+(int that) const { return mint(*this) += that; }
  mint operator-(int that) const { return mint(*this) -= that; }
  mint operator*(int that) const { return mint(*this) *= that; }
  mint operator/(int that) const { return mint(*this) /= that; }


  mint inverse() const {
    signed a = x, b = MOD, u = 1, v = 0;
    while(b) {
      signed t = a / b;
      a -= t * b; std::swap(a, b);
      u -= t * v; std::swap(u, v);
    }
    if(u < 0) u += MOD;
    mint res; res.x = (unsigned)u;
    return res;
  }
 
  bool operator==(mint that) const { return x == that.x; }
  bool operator!=(mint that) const { return x != that.x; }
  mint operator-() const { mint t; t.x = x == 0 ? 0 : MOD - x; return t; }
  mint operator^(long long k) const {
    // 0^0 is 1. k must be taken modulo phi(MOD) (MOD-1 if prime) and NOT MOD itself
    mint a=(*this);
    if (k<0) {
      k=-k;
      a=a.inverse();
    }
    mint r = 1;
    while(k) {
      if(k & 1) r *= a;
      a *= a;
      k >>= 1;
    }
    return r;
  }
};

vll a;
vll pre,pra;
ll getsum(ll l, ll r) {
  if (l>r) return 0;
  return pre[r+1]-pre[l];
}
ll getparsum(ll l, ll r) {
  assert((l+r)%2==0);
  if (l>r) return 0;
  return pra[r+2]-pra[l];
}
void go() {
  a.clear(); pre.clear();
  ll n; cin>>n;
  a.resize(n+1);
  for (ll i=0;i<n;i++) cin>>a[i];
  pre.resize(n+1);
  pre[0]=0;
  for (ll x=0;x<n;x++) pre[x+1]=pre[x]+a[x];
  pra.resize(n+2);
  pra[0]=pra[1]=0;
  for (ll x=0;x<n;x++) pra[x+2]=pra[x]+a[x];
  mint final=0;
  if (n==1) {
    final=1;
  } else {
    for (ll endp=1;endp<=n-3;endp++) {
      if (getsum(0,endp)-getsum(endp+1,n-1)>0) {
        //printf("endp:%lld\n",endp);
        final+=1;
      }
    }
    ll l=1,r=n-2;
    for (ll sc=0;sc<2;sc++) { // 0 is C
      for (ll ec=0;ec<2;ec++) { // n-1 is C
        ll ssum=0,esum=0;
        if (sc) ssum-=a[0]; else ssum+=a[0];
        if (ec) esum-=a[n-1]; else esum+=a[n-1];
        ll outer=ssum+esum;
        if (l>r) {
          if (outer>0) final+=1;
        } else {
          ll middle=getsum(l,r);
          if (outer+middle>0) {
            //printf("sc:%lld ec:%lld outer:%lld middle:%lld middleP\n",sc,ec,outer,middle);
            final+=1;
          }
          if (outer-middle>0) {
            //printf("sc:%lld ec:%lld outer:%lld middle:%lld middleC\n",sc,ec,outer,middle);
            final+=1;
          }
        }

        for (ll mid=l;mid<=r;mid++) { // C is [l,mid], P is [mid+1,r]
          if (mid==r&&ec) continue;
          ll ans=0;
          ll csum=-getsum(l,mid);
          ll psum=getsum(mid+1,r);
          ll total=ssum+esum+csum+psum;
          if (total>0 && mid!=r) ans++;
          ll phi=mid-1;
          ll plo=l;
          if (sc==0) plo++;
          plo+=(plo+phi)%2;
          if (plo<=phi) {
            ll allways=((phi-plo)/2)+1;
            ll imin=0,imax=allways;
            while(imin<imax) {
              ll imid=(imin+imax)/2;
              ll myl=phi-(imid)*2;
              ll gotp=getparsum(myl,phi);
              //printf("imid:%lld myl:%lld phi:%lld total:%lld gotp:%lld\n",imid,myl,phi,total,gotp);
              if (total+(2*gotp)<=0) imin=imid+1;
              else imax=imid;
            }
            //printf("allways:%lld imin:%lld\n",allways, imin);
            ll ways=allways-imin;
            ans+=ways;
          }
          if (ans) {
            //printf("sc:%lld ec:%lld mid:%lld total:%lld ans:%lld plo:%lld phi:%lld\n",sc,ec,mid,total,ans,plo,phi);
          }
          ans%=MOD;
          final+=ans;
        }
      }
    }
  }
  printf("%d\n",final.get());
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int t; cin>>t; for (int i=0;i<t;i++) go();
}