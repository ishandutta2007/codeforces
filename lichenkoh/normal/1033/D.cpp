#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,tune=native")
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
const int mn=504;
ll a[mn];
map<ll,ll> h;
ld rec[10];
ll ipow(ll x, int e) {
  ll ans=x;
  for (int i=1;i<e;i++) {
    ll res;
    bool ovf=__builtin_smulll_overflow(ans,x,&res);
    if (ovf) return -1;
    ans=res;
  }
  return ans;
}

pll f(ll x) {
    for (int e=4;e>=2;e--) {
      ll y=(ll)round(pow((ld)x,rec[e]));
      for (ll z=max(1LL,y-2);z<=y+2;z++) {
        if (ipow(z,e)==x) {
          return MP(z,e);
        }
      }
    }  
  return MP(-1LL,-1LL);
}

bitset<mn> s;

pll fac[mn];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n; cin>>n;
  for (int i=0;i<n;i++) cin>>a[i];
  for (int e=2;e<=4;e++) rec[e]=1/((ld)e);
  for (int i=0;i<n;i++) {
    ll x=a[i];
    pll got=f(x);
    if (got.snd==-1LL) {
      s[i]=false;
    }
    else {
      h[got.fst]+=got.snd;
      s[i]=true;
    }
  }
  for (int i=0;i<mn;i++) fac[i]=MP(-1LL,-1LL);
  for (int x=0;x<n;x++) {
    if (s[x]) continue;
    for (int y=0;y<n;y++) {
      if (a[x]==a[y]) continue;
      ll g=__gcd(a[x],a[y]);
      if (g!=1) {
        fac[x].fst=g; fac[x].snd=a[x]/g;
        break;
      }
    }
  }
  for (int x=0;x<n;x++) {
    if (fac[x].snd!=-1LL) {
      s[x]=true;
      ++h[fac[x].fst];
      ++h[fac[x].snd];
    }
  }
  map<ll,ll> g;
  for (int x=0;x<n;x++) {
    if (!s[x]) ++g[a[x]];
  }
  ll ans=1;
  for (auto &w:h) {
    ans=(ans*(w.snd+1LL))%MOD;
  }
  for (auto &w:g) {
    ans=(ans*(w.snd+1LL))%MOD;
    ans=(ans*(w.snd+1LL))%MOD;
  }
  ans%=MOD;
  printf("%lld\n",ans);
}