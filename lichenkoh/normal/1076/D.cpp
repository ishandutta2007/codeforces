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
typedef vector<pii> vpii;
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
const int mn=3e5+4;
vector<pii> g[mn];
typedef pair<ll,int> pli;
vector<int> vans;
int gk;
int vw[mn];
void dij(int n, int initx) {
  vector<pli> vdist(n,MP(LLONG_MAX,INT_MAX));
  priority_queue<pli,vector<pli>,greater<pli> > pq;
  pq.push(MP(0,initx));
  vdist[initx]=MP(0,-1);
  while(!pq.empty()) {
    auto top=pq.top(); pq.pop();
    ll distx=top.fst; int x=top.snd;
    if (distx!=vdist[x].fst) continue;
    if (vdist[x].snd!=-1&&vans.size()<gk) {
      vans.PB(vdist[x].snd);
    }
    for (auto &q:g[x]) {
      int y=q.fst,e=q.snd,w=vw[e];
      ll newdist=distx+w;
      if (newdist < vdist[y].fst) {
        vdist[y]=MP(newdist,e);
        pq.push(MP(newdist,y));
      }
    }
  }
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n,m; cin>>n>>m>>gk;
  for (int i=1;i<=m;i++) {
    int x,y; cin>>x>>y;
    g[x].PB(MP(y,i));
    g[y].PB(MP(x,i));
    cin>>vw[i];
  }
  dij(n+1,1);
  printf("%d\n",(int)vans.size());
  for (auto &w:vans) {
    printf("%d ",w);
  }
}