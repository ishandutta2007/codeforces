#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
const ll mn=1e6+2;
pll a[mn];
ll b[mn];
ll f[mn];
vector<pll>v; ll vsz;
void pre(ll n) {
  sort(a,a+n);
  ll cnt=1;
  ll lcnt=a[0].snd;
  for (ll i=1;i<n;i++) {
    if (a[i].fst!=a[i-1].fst) {
      v.PB(MP(cnt,lcnt));
      cnt=1;
      lcnt=a[i].snd;
    }
    else {
      cnt++;
      lcnt+=a[i].snd;
    }
  }
  if (cnt) v.PB(MP(cnt,lcnt));
  vsz=v.size();
  //for (ll i=0;i<n;i++) printf("%lld, ",a[i].fst);
  //printf("\n");
  //for (ll i=0;i<vsz;i++) printf("%d: %d %d\n",i,v[i].fst,v[i].snd);
}
ll go(ll klim, bool golast, ll avail) {
  //printf("klim:%d golast:%d avail:%d\n",klim,golast,avail);
  memset(f,0,sizeof f);
  ll cur=0,nxt=1;
  f[0]=1;
  ll final=0;
  for (ll k=0;k<klim;k++) {
    for (ll x=1;x<vsz;x++) {
      f[x]+=f[x-1];
      f[x]%=MOD;
    }
    ll ans=0;
    for (ll x=0;x<vsz;x++) {
      if (golast) {
        ll blah=(f[x]*(ll)v[x].snd);
        //printf("k:%d x:%d f[x]:%d blah:%lld\n",k,x,f[x],blah);
        ans+=blah;
        ans%=MOD;
      }
      f[x]=(f[x]*(ll)v[x].fst)%MOD;
      if (!golast) ans+=f[x];
    }
    ans%=MOD;
    //printf("ans:%lld\n",ans);
    if (!golast) ans=(ans*(max(0ll,avail-(k))%MOD))%MOD;
    final+=ans;
    final%=MOD;
  }
  //printf("final:%lld\n",final);
  return final;
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  ll n,l,klim; scanf("%lld%lld%lld",&n,&l,&klim);
  ll left=l%n;
  for (ll i=0;i<n;i++) {
    ll x; scanf("%lld",&x);
    a[i]=MP(x, i<left);
  }
  pre(n);
  ll final=0;
  {
    ll avail=(l-left)/n;
    final+=go(klim,false,avail);
    //printf("nolast:%lld\n",final);
  }
  if (left>0) {
    ll avail=1+((l-left)/n);
    ll nklim=min(klim,avail);
    ll got=go(nklim,true,-1);
    final+=got;
    //printf("last:%lld\n",got);
  }
  final%=MOD;
  printf("%lld\n",final);
}