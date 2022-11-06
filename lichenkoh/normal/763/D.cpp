#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define endl "\n"
const ll UNDEF = -1;
const ll INF=1e9;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
#define fst first
#define snd second
const ll P1=2106945901ULL;
const ll P2=2111011129ULL;
const ll MOD1=2131131137ULL;
const ll MOD2=2147483647ULL;
const ll mn=1e5+2;
ll ge=0;
ll vpar[2*mn],vchild[2*mn];
vector<ll> g[mn];
ll dp[2*mn];
void ae(ll x, ll y) {
  vpar[ge]=x; vchild[ge]=y; g[x].PB(ge);
  ge++;
  vpar[ge]=y; vchild[ge]=x; g[y].PB(ge);
  ge++;
}
ll dpfy(ll x, ll y) {
  x%=MOD1; x=(P1*x)%MOD1;
  y%=MOD2; y=(P2*y)%MOD2;
  return (x<<32)|y;
}

ll filldown(ll ei) {
  if (dp[ei]!=-1) return dp[ei];
  ll parent=vpar[ei];
  ll x=vchild[ei];
  vector<ll> v;
  for (auto &ek:g[x]) {
    if (ek==ge) continue;
    if (vchild[ek]==vpar[ei]) continue;
    v.PB(filldown(ek));
  }
  sort(v.begin(),v.end());
  ll cum1=0,cum2=0;
  ll hash1=1,hash2=1;
  for (auto &w:v) {
    cum1+=w>>32; if (cum1>=MOD1) cum1-=MOD1;
    cum2+=w&0xffffffff; if (cum2>=MOD2) cum2-=MOD2;
    hash1+=cum1;
    hash2+=cum2;
  }
  return dp[ei]=dpfy(hash1,hash2);
}
ll norm1(ll x) {
  x%=MOD1; if (x<0) x+=MOD1; return x;
}
ll norm2(ll x) {
  x%=MOD2; if (x<0) x+=MOD2; return x;
}
ll prefix[mn];
void fillup(ll x, ll p) {
  vector<pll> v;
  for (auto &ek:g[x]) {
    if (ek==ge) continue;
    ll w=dp[ek]; assert(w!=-1);
    v.PB(MP(w,ek));
  }
  sort(v.begin(),v.end());

  ll cum1=0,cum2=0;
  ll hash1=1,hash2=1;
  for (auto &got:v) {
    ll w=got.first;
    cum1+=w>>32; if (cum1>=MOD1) cum1-=MOD1;
    cum2+=w&0xffffffff; if (cum2>=MOD2) cum2-=MOD2;
    hash1+=cum1;
    hash2+=cum2;
  }

  ll vsz=v.size();
  cum1=0,cum2=0;
  prefix[0]=0;
  for (ll i=0;i<vsz;i++) {
    ll w=v[i].first;
    cum1+=w>>32; if (cum1>=MOD1) cum1-=MOD1;
    cum2+=w&0xffffffff; if (cum2>=MOD2) cum2-=MOD2;
    prefix[i+1]=(cum1<<32)|cum2;
  }

  for (ll i=0;i<vsz;i++) {
    ll ek=v[i].second;
    ll got1=norm1(hash1-(vsz-i)*(dp[ek]>>32)-(prefix[i]>>32));
    ll got2=norm2(hash2-(vsz-i)*(dp[ek]&0xffffffff)-(prefix[i]&0xffffffff));
    dp[ek^1]=dpfy(got1,got2);
  }
  for (auto &ek:g[x]) {
    if (ek==ge) continue;
    if (vchild[ek]==p) continue;
    fillup(vchild[ek],x);
  }
}
ll f(ll ei) {
  assert(dp[ei]!=-1);
  return dp[ei];
}
bool seen[mn];
map<ll,ll> h;
pll final=MP(-1ll,-1ll);
void rm(ll x) {
  auto it=h.find(x);
  if (it->second==1) h.erase(it);
  else (it->second)--;
}
void dfs(ll x) {
  seen[x]=true;
  chkmax(final, MP((ll)h.size(),x));
  //printf("x:%lld noniso nonroot subtrees:%lld\n",x,(ll)h.size());
  for (auto &ei: g[x]) {
    if (ei==ge) continue;
    ll y=vchild[ei];
    if (seen[y]) continue;
    rm(f(ei));
    h[f(ei^1)]++;
    dfs(y);
    rm(f(ei^1));
    h[f(ei)]++;
  }
}
void initdfs(ll x) {
  //printf("initdfs:%lld\n",x);
  seen[x]=true;
  for (auto &ei:g[x]) {
    if (ei==ge) continue;
    ll y=vchild[ei];
    if (seen[y]) continue;
    h[f(ei)]++;
    initdfs(y);
  }
}
int main() {
  ll n; scanf("%lld",&n);
  for (ll i=1;i<n;i++) {
    ll x,y; scanf("%lld%lld",&x,&y); ae(x,y);
  }
  vpar[ge]=-123; vchild[ge]=1;
  g[1].PB(ge);
  memset(dp,-1,sizeof dp);
  filldown(ge);
  fillup(1,-123);
  //for (ll ei=0;ei<ge;ei++) {
  //  printf("ei:%lld dp:%lld\n",ei,dp[ei]);
  //}
  //return 0;
  memset(seen,0,sizeof seen);
  initdfs(1);
  memset(seen,0,sizeof seen);
  dfs(1);
  //printf("Isomorphic nonroot subtrees:%lld. Incl root:%lld\n",final.first,final.first+1);
  printf("%lld\n",final.second);
}