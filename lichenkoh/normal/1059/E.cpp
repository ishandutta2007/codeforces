#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,tune=native")
#include "bits/stdc++.h"
 
using namespace std;
#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>
#include <assert.h>
typedef long long ll;
typedef double ld;
#define PB push_back
#define MP make_pair
const int MOD=1000000007;
#define endl "\n"
#define fst first
#define snd second
const int UNDEF = -1;
const int INF=1<<29;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
int rint() {int x;scanf("%d",&x);return x;}
ll rlong() {ll x;scanf("%lld",&x);return x;}

// Decreasing map
ll hquery(map<int,ll> &h, int key) {
  //Queries the largest (k,v) pair where k<=key
  auto it=h.upper_bound(key);
  if (it==h.begin()) {
    return -INF;
  }
  --it;
  return it->snd;
}

void hins(map<int,ll> &h, int key, ll val) {
  //Inserts (key,val) into h.
  //Maintains the invariant that if key1<key2, then val1>val2.
  auto it=h.upper_bound(key);
  if (it==h.begin()) {
    it=h.insert(MP(key,val)).fst;
  }
  else {
    --it;
    if (it->snd <= val) return;
    if (it->fst==key) it->snd = val;
    else it=h.insert(MP(key,val)).fst;
  }
  ++it;
  while(it!=h.end()) {
    if (it->snd >= val) it=h.erase(it);
    else return;
  }
}
const int mn=1e5+4;
vi g[mn];
int c[mn],q[mn];
map<int,ll> *f[mn];
int bv[mn]; ll bw[mn];
int V; ll W;
void dfs(int x, int p) {
  vector<pii> vec;
  int qsum=0;
  for (auto &y:g[x]) {
    if (y!=p) {
      dfs(y,x);
      vec.PB(MP(f[y]->size(), y));
      qsum+=q[y];
    }
  }
  if (vec.size()==0) { // Optimization, we don't actually need this.
    f[x]=new map<int,ll>;
    auto &h=*f[x];
    h[1]=c[x];
    q[x]=1;
    bv[x]=0; bw[x]=0;
    //printf("no children:%d\n",x);
    //printf("x:%d q:%d\n",x,q[x]);
    //for (auto it:h) printf("v:%d w:%lld\n",bv[x]+it.fst,bw[x]+it.snd);
    //printf("\n");
    return;
  }
  sort(vec.begin(),vec.end(),greater<pii>());
  int r=vec[0].snd;
  f[x]=f[r];
  map<int,ll> &h=*f[x];
  bv[x]=bv[r]+1;
  bw[x]=bw[r]+c[x];
  { // Prune front which has too high W
    for (auto it=h.cbegin();it!=h.cend();) {
      int v=bv[x]+it->fst; ll w=bw[x]+it->snd;
      if (w>W) {
        it=h.erase(it);
      }
      else ++it;
    }
  }
  if (!h.empty()) { // Prune back which has too high V
    auto it=h.end(); --it;
    int v=bv[x]+it->fst;
    ll w=bw[x]+it->snd;
    if (v>V) {
      h.erase(it);
    }
  }
  // Perform merge
  for (int i=1;i<vec.size();i++) {
    int y=vec[i].snd;
    auto &hy=*f[y];
    for (auto it:hy) {
      int v=bv[y]+it.fst+1;
      ll  w=bw[y]+it.snd+c[x];
      if (v<=V&&w<=W) {
        hins(h,v-bv[x],w-bw[x]);
      }
    }
  }
  q[x]=qsum;
  if (h.empty()) {
    //printf("h is empty x:%d\n",x);
    h[1]=c[x];
    ++q[x];
    bv[x]=0; bw[x]=0;
  }
  //printf("x:%d q:%d\n",x,q[x]);
  //for (auto it:h) printf("v:%d w:%lld\n",bv[x]+it.fst,bw[x]+it.snd);
  //printf("\n");
}

int main()
{
  int n=rint(); V=rint(); W=rlong();
  for (int i=1;i<=n;i++) {c[i]=rint();}
  for (int i=1;i<=n;i++) if (c[i]>W) {printf("-1\n"); exit(0);}
  if (V==1) {printf("%d\n",n); exit(0);}
  for (int i=2;i<=n;i++) {
    int x=i,y=rint();
    g[x].PB(y); g[y].PB(x);
  }
  dfs(1,-1);
  int ans=q[1];
  printf("%d\n",ans);
}