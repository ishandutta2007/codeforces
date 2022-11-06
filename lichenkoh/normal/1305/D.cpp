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
const int mn=1004;

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

  void init(vector<vector<int> > &tree, int n, int root) {
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

  pair<int,int> lca(int oa, int ob) {
    // Returns make_pair(LCA, number of edges on shortest path from a to b)
    int a=oa,b=ob;
    if (isParent(a, b))
      return MP(a, vdepth[b] - vdepth[a]);
    if (isParent(b, a))
      return MP(b, vdepth[a] - vdepth[b]);
    for (int i = len - 1; i >= 0; i--)
      if (!isParent(up[i][a], b))
        a = up[i][a];
    int ancestor=up[0][a];
    return MP(ancestor, vdepth[oa] + vdepth[ob] - (2 * vdepth[ancestor]));
  }
};

LcaSparseTable L;


vvi g;
bitset<mn> seen;
bitset<mn> bad;
int lim;
int asked=0;
int ask(int x, int y) {
  /*asked++;
  int ans=L.lca(x,y).fst;
  printf("x:%d y:%d ans:%d\n",x,y,ans); fflush(stdout);
  if (asked > lim) assert(0);
  return ans;*/
  printf("? %d %d\n",x,y); fflush(stdout);
  int ans;
  scanf("%d",&ans);
  return ans;
}

void markBad(int x, int p) {
  bad[x]=true;
  for (auto &y:g[x]) {
    if (y!=p) {
      markBad(y,x);
    }
  }
}

bool hasDest(int x, int p, int d1, int d2) {
  if (x==d1||x==d2) {
    return true;
  }
  for (auto &y:g[x]) {
    if (y!=p) {
      if (hasDest(y,x,d1,d2)) return true;
    }
  }
  return false;
}

void markGen(int x, int d1, int d2) {
  for (auto &y:g[x]) {
    if (hasDest(y,x,d1,d2)) {
      markBad(y,x);
    }
  }
}

int main() 
{
  int n; scanf("%d",&n);
  lim=n/2;
  g.resize(n+1);
  for (int i=1;i<n;i++) {
    int x,y; scanf("%d %d",&x,&y);
    g[x].PB(y); g[y].PB(x);
  }

  //int root=1+(1%n);
  
  //L.init(g,n+1,root);

  queue<int> q; for (int x=1;x<=n;x++) if(g[x].size()==1) {q.push(x); seen[x]=true;}
  /*srand(time(0));
  {
    int k=v.size();
    for (int i=0;i<k;i++) swap(v[i],v[rand()%k]);
  }*/
  while(!q.empty()) {
    vi v;
    while(v.size()<2 && !q.empty()) {
      int x=q.front(); q.pop();
      if (!bad[x]) v.PB(x);
    }
    if (v.size()<2) {
      //assert(v[0]==root);
      printf("! %d\n",v[0]);
      return 0;
    }
    int x=v[0],y=v[1];
    int r=ask(x,y);
    if (!bad[r]) {
      markGen(r,x,y); bad[r]=false;
      if (x==r||y==r||!seen[r]) {
        seen[r]=true;
        q.push(r);
      }
    } else {
      markGen(r,x,y);
    }
  }
  assert(0);
  return 0;
}