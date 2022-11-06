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

const int mn=62;
ll valueshift[mn];
ll nodeshift[mn];
ll ilog2(ll x) {
  for (ll i=62;i>=0;i--) {
    if (x&(1LL<<i)) return i;
  }
  return -1;
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int q; cin>>q;
  for (int qi=0;qi<q;qi++) {
    int t; cin>>t;
    if (t==1||t==2) {
      ll inp,k; cin>>inp>>k;
      ll d=ilog2(inp);
      ll mod=1LL<<d;
      if (k<0) k+=mod;
      //printf("t:%lld k:%lld\n",t,k);
      k&=(mod-1);
      if (t==1) {
        valueshift[d]+=k;
        valueshift[d]&=(mod-1);
      }
      else {
        for (ll x=d;x<mn;x++) {
          nodeshift[x]+=k;
          nodeshift[x]&=(mod-1);
          k*=2; mod*=2;
        }
      }
    }
    else {
      ll inp; cin>>inp;
      ll dlim=ilog2(inp);
      ll modlim=1LL<<dlim;
      ll pos=(inp+nodeshift[dlim]+valueshift[dlim])&(modlim-1);
      //printf("inp:%lld Origpos:%lld\n",inp,pos+modlim);
      for (ll d=dlim;d>=0;d--) {
        ll mod=1LL<<d;
        ll A=(mod-valueshift[d])&(mod-1);
        ll B=(mod-nodeshift[d])&(mod-1);
        ll AB=(A+B)&(mod-1);
        ll ans=((pos+AB)&(mod-1))+mod;
        printf("%lld ",ans);
        pos>>=1;
      }
      printf("\n");
    }
  }
}