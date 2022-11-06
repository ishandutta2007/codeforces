#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx,tune=native")
#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const ll MOD=1000000007;
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
const ll INF=1<<30;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<ll,ll> pii;
#ifdef ONLINE_JUDGE
#define assert(...) /* nothing */
#endif
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
ll rint();char rch();long long rlong();
// mt19937 rng; rng.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());
// template<typename T> ll bins(vector<T> &v, T key) {ll imin=0,imax=v.size();while(imin<imax) {ll imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}
const ll mn=(3e5)+4;
ll n;
pii p[mn];
ll pdist(pii pa, pii pb) {
  return abs(pa.fst-pb.fst)+abs(pa.snd-pb.snd);
}
ll dist(ll a, ll b) {
  return abs(p[a].fst-p[b].fst)+abs(p[a].snd-p[b].snd);
}
pii trans(pii q, ll z) {
  if (z&4) swap(q.fst,q.snd);
  if (z&2) q.fst=-q.fst;
  if (z&1) q.snd=-q.snd;
  return q;
}
pii invtrans(pii q, ll z) {
  if (z&1) q.snd=-q.snd;
  if (z&2) q.fst=-q.fst;
  if (z&4) swap(q.fst,q.snd);
  return q;
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin>>n;
  for (ll i=0;i<n;i++) {
    ll x,y; cin>>x>>y;
    p[i]=MP(x,y);
  }
  {
    pll b[8];
    for (ll z=0;z<8;z++) {
      b[z]=MP(INT_MIN,INT_MIN);
    }
    for (ll i=0;i<n;i++) {
      for (ll z=0;z<8;z++) {
        chkmax(b[z],trans(p[i],z));
      }
    }
    for (ll z=0;z<8;z++) {
      b[z]=invtrans(b[z],z);
    }
    ll best=0;
    for (ll z=0;z<(1<<8);z++) {
      if (__builtin_popcountll(z)==3) {
        vector<pll> v;
        for (ll i=0;i<8;i++) {
          if (z&(1<<i)) v.PB(b[i]);
        }
        ll cand=0;
        for (ll a=0;a<3;a++) {
          cand+=pdist(v[a],v[(a+1)%3]);
        }
        chkmax(best,cand);
      }
      if (__builtin_popcountll(z)==2) {
        vector<pll> v;
        for (ll i=0;i<8;i++) {
          if (z&(1<<i)) v.PB(b[i]);
        }
        ll base=pdist(v[0],v[1]);
        for (int i=0;i<n;i++) {
          if (p[i]!=v[0]&&p[i]!=v[1]) {
            ll cand=base+pdist(v[0],p[i])+pdist(v[1],p[i]);
            chkmax(best,cand);
          }
        }
      }
    }
    printf("%lld ",best);
  }
  {
    ll ans=0;
    for (ll a=0;a<n;a++) {
      ans+=dist(a,(a+1)%n);
    }
    for (ll i=4;i<=n;i++) printf("%lld ",ans);
  }
  printf("\n");
}