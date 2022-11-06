#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
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
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;typedef vector<pii> vpii;
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


vector<vector<int> > g;

// Answering LCA queries in O(1) with O(n*log(n)) preprocessing
class LcaSparseTable {
public:
  int len=0;
  int** up;
  int* tin;
  int* tout;
  int timestamp=0;
  int* vdepth;

  void dfs(vector<vector<int> > &tree, int u, int p, int depth) {
    vdepth[u] = depth;
    tin[u] = timestamp++;
    up[0][u] = p;
    for (int i = 1; i < len; i++)
      up[i][u] = up[i - 1][up[i - 1][u]];
    for (int v : tree[u])
      if (v != p)
        dfs(tree, v, u, depth+1);
    tout[u] = timestamp++;
  }

  void init(vector<vector<int> > &tree, int root) {
    int n = tree.size();
    len = 1;
    while ((1 << len) <= n) ++len;
    up = new int*[len];
    for (int i=0;i<len;i++) {up[i]=new int[n]; memset(up[i],0,sizeof(up[i][0])*n);}
    tin = new int[n]; memset(tin,0, sizeof(tin[0])*n);
    tout = new int[n]; memset(tout,0,sizeof(tout[0]*n));
    vdepth = new int[n]; memset(vdepth,0,sizeof(vdepth[0]*n));
    dfs(tree, root, root, 0);
  }

  bool isParent(int parent, int child) {
    return tin[parent] <= tin[child] && tout[child] <= tout[parent];
  }

  pair<int,pii> lca(int oa, int ob) {
    // Returns (dist, (par[a], par[b]))
    int a=oa,b=ob;
    if (a==b) {
      return MP(0, MP(-1,-1));
    }
    if (isParent(a, b)) {
      int x=b;
      int dist=vdepth[b] - vdepth[a] - 1;
      for (int i = len - 1; i >= 0; i--) {
        if (dist & (1<<i)) x=up[i][x];
      }
      return MP(
        dist+1,
        MP(x,up[0][ob])
        );
    }
    if (isParent(b, a)) {
      int dist=vdepth[a] - vdepth[b] - 1;
      int x=a;
      for (int i = len - 1; i >= 0; i--) {
        if (dist & (1<<i)) x=up[i][x];
      }
      return MP(
        dist+1,
        MP(up[0][a],x));
    }
    for (int i = len - 1; i >= 0; i--)
      if (!isParent(up[i][a], b))
        a = up[i][a];
    int ancestor=up[0][a];
    return MP(
      vdepth[oa] + vdepth[ob] - (2 * vdepth[ancestor]),
      MP(up[0][oa],up[0][ob])
      );
  }
};

LcaSparseTable l;
const int mn=3004;
int cnt[mn];
int vp[mn];
int go(int x, int p) {
  vp[x]=p;
  int ans=1;
  for (auto &y:g[x]) {
    if (y==p) continue;
    ans+=go(y,x);
  }
  return cnt[x]=ans;
}
int gn;
int h(int x, int p) {
  assert(p!=-1);
  if (vp[p]==x) {
    return gn - cnt[p];
  } else {
    return cnt[x];
  }
}
ll dp[mn][mn];
ll f(int x, int y) {
  ll dpv=dp[x][y]; if (dpv!=-1) return dpv;
  pair<int,pii> got = l.lca(x,y);
  int dist=got.fst;
  int px=got.snd.fst,py=got.snd.snd;
  ll final=0;
  for (auto &z:g[x]) {
    if (z==px) continue;
    ll plus=((ll)h(z,x)) * ((ll)h(y,py==-1?z:py));
    ll prevf=max(f(y,z),f(z,y));
    ll cand=plus+prevf;
    //printf("x:%d y:%d px:%d py:%d dist:%d z:%d cand:%lld\n",x,y,px,py,dist,z,cand);
    chkmax(final,cand);
  }
  dp[x][y]=final;
  //printf("x:%d y:%d px:%d py:%d dist:%d final:%lld\n",x,y,px,py,dist,final);
  return final;
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  memset(dp,-1,sizeof dp);
  int n=rint();
  gn=n;
  g.resize(n);
  for (int i=1;i<n;i++) {
    int x=rint()-1,y=rint()-1;
    g[x].PB(y); g[y].PB(x);
  }
  go(0,-1);
  l.init(g,0);
  ll final=0;
  for (int x=0;x<n;x++) {
    chkmax(final,f(x,x));
  }
  printf("%lld\n",final);
}




static char stdinBuffer[1024];
static char* stdinDataEnd = stdinBuffer + sizeof (stdinBuffer);
static const char* stdinPos = stdinDataEnd;

void readAhead(size_t amount)
{
  size_t remaining = stdinDataEnd - stdinPos;
  if (remaining < amount) {
     memmove(stdinBuffer, stdinPos, remaining);
     size_t sz = fread(stdinBuffer + remaining, 1, sizeof (stdinBuffer) - remaining, stdin);
     stdinPos = stdinBuffer;
     stdinDataEnd = stdinBuffer + remaining + sz;
     if (stdinDataEnd != stdinBuffer + sizeof (stdinBuffer))
     *stdinDataEnd = 0;
  }
}

int rint()
{
  readAhead(16);

  int x = 0;
  bool neg = false;
  while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
  if (*stdinPos == '-') {
     ++stdinPos;
     neg = true;
  }

  while (*stdinPos >= '0' && *stdinPos <= '9') {
     x *= 10;
     x += *stdinPos - '0';
     ++stdinPos;
  }

  return neg ? -x : x;
}
char rch()
{
  readAhead(16);
  while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
  char ans=*stdinPos;
  ++stdinPos;
  return ans;
}
long long rlong()
{
  readAhead(32);

  long long x = 0;
  bool neg = false;
  while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
  if (*stdinPos == '-') {
     ++stdinPos;
     neg = true;
  }

  while (*stdinPos >= '0' && *stdinPos <= '9') {
     x *= 10;
     x += *stdinPos - '0';
     ++stdinPos;
  }

  return neg ? -x : x;
}