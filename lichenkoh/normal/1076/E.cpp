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
vector<int> g[mn];
vector<pii> q[mn];
ll a[mn];
ll vans[mn];
void dfs(int x, int p, int d, ll val) {
  for (auto &w:q[x]) {
    val+=w.snd;
    int nd=d+1+w.fst;
    if (nd<mn) a[nd]-=w.snd;
  }
  val+=a[d];
  vans[x]=val;
  for (auto &y:g[x]) {
    if (y!=p) dfs(y,x,d+1,val);
  }
  for (auto &w:q[x]) {
    val-=w.snd;
    int nd=d+1+w.fst;
    if (nd<mn) a[nd]+=w.snd;
  }
  val-=a[d];
}
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n; cin>>n;
  for (int i=1;i<n;i++) {
    int x,y; cin>>x>>y;
    g[x].PB(y);
    g[y].PB(x);
  }
  int m; cin>>m;
  for (int i=0;i<m;i++) {
    int v,d,x; cin>>v>>d>>x;
    q[v].PB(MP(d,x));
  }
  dfs(1,-1,0,0);
  for (int x=1;x<=n;x++) printf("%lld ",vans[x]);
}