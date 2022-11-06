#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,tune=native")
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

class TwoSat {
public:
  vector<vector<int> > graph, rev_graph;
  vi used, comp, order, res;
  int twosat_cnt = 0;

  void dfs1(int u) { used[u] = true;
    for (auto i = 0u; i < graph[u].size(); i++) {
      int v = graph[u][i];
      if (!used[v]) dfs1(v); }
    order[twosat_cnt++] = u; }
  void dfs2(int u, int color) { comp[u] = color;
    for (auto i = 0u; i < rev_graph[u].size(); i++) {
      int v = rev_graph[u][i];
      if (comp[v] == -1) dfs2(v, color); } }
  bool twosat() { int n = graph.size();
    for (int i = 0; i < n; i++) if (!used[i]) dfs1(i);
    for (int i = 0; i < n; i++) for (auto j = 0u; j < graph[i].size(); j++)
      rev_graph[graph[i][j]].push_back(i);
    for (int i = 0, color = 0; i < n; i++) {
      int u = order[n-i-1];
      if (comp[u] == -1) dfs2(u, color++); }
    for (int i = 0; i < n; i++) if (comp[i] == comp[i^1]) return false;
    for (int i = 0; i < n; i+=2) res[i/2] = (comp[i] > comp[i^1]);
    return true; }
  //if type = 0, we add the edge x -> y, if type = 1, we add the edge ~x -> y
  //if type = 2, we add the edge x -> ~y, if type = 3, we add the edge ~x -> ~y
  //NOTE: each implication and its dual implication is also added, so NO need to
  //add twice for each implication.
  void add(int x, int y) { graph[x].push_back(y); };
  void add_edge(int x, int y, int type) {
    int a=2*x, na=2*x+1, b=2*y, nb=2*y+1;
    switch (type) {
      case 0: add(a,b); add(nb, na); break;
      case 1: add(na, b); add(nb, a); break;
      case 2: add(a, nb); add(b, na); break;
      case 3: add(na, nb); add(b,a); break; } }

  void ae(bool tx, int x, bool ty, int y) {
    // tx is True if x is True
    // ty is True if y is True
    //printf("x:%d tx:%d y:%d ty:%d\n",x,tx,y,ty);
    int a=2*x, na=2*x+1, b=2*y, nb=2*y+1;
    if (!tx) swap(a,na);
    if (!ty) swap(b,nb);
    add(a,b); add(nb, na);
  }

  void init(int n) {
      graph.clear(); rev_graph.clear();
      graph.resize(2*n);
      rev_graph.resize(2*n);
      used.resize(2*n); fill(used.begin(),used.end(),0);
      comp.resize(2*n); fill(comp.begin(),comp.end(),-1);
      order.resize(2*n); fill(order.begin(),order.end(),0);
      res.resize(2*n);
      twosat_cnt=0;
  }
};


class IdAllocator {
public:
  int n=0;
  int getid() {
    return n++;
  }
  int size() {
    return n;
  }
  void clear() {
    n=0;
  }
};

template <typename LST> struct LimitedVec  {
  vector<LST> a;
  int n=0;
  void init(int needsize) {
    a.resize(needsize);
  }
  void push_back(LST val) {
    if (n+1>=a.size()) a.resize(2*n);
    a[n++]=val;
  }
  LST * begin()
  {
    return &a[0];
  }
  LST * end()
  {
    return &a[n];
  }
  void clear() {
    n=0;
  }
  int size() {
    return n;
  }
};


class HeavyLight2NoRecursion {
public:
  LimitedVec<int> ret;
  // true - values on vertices, false - values on edges
  bool VALUES_ON_VERTICES = false;

  vector<vector<int> > tree;
  int* size;
  int* parent;
  int* tin;
  int* tout;
  int time=0;
  int* path;
  int* pathSize;
  int* pathPos;
  int* pathRoot;
  int pathCount=0;
  IdAllocator ida;
  vvi val;
  int *parentId, *childId[2];
  HeavyLight2NoRecursion() {}
  void init(vector<vector<int> > tree) {
    this->tree = tree;
    int n = tree.size();

    size = new int[n];
    parent = new int[n];
    tin = new int[n]; 
    tout = new int[n]; 
    calcSizeParentTinTout(0);

    path = new int[n]; 
    pathSize = new int[n]; fill(pathSize,pathSize+n,0);
    pathPos = new int[n]; 
    pathRoot = new int[n]; 
    buildPaths(0);

    val.resize(pathCount);
    for (int p = 0; p < pathCount; p++) {
      int m = pathSize[p];
      val[p].resize(2*m);
      for (int j=0;j<2*m;j++) val[p][j]=ida.getid();
    }
    int nid=ida.size();
    ret.init(nid);
    parentId=new int[nid]; memset(parentId,-1,sizeof(int)*nid);
    for (int t=0;t<2;t++) {childId[t]=new int[nid]; memset(childId[t],-1,sizeof(int)*nid);}
    for (int p = 0; p < pathCount; p++) {
      int m = pathSize[p];
      for (int x=m-1;x>=0;x--) {
        int parent=val[p][x];
        int c1=val[p][(x<<1)];
        int c2=val[p][(x<<1)|1];
        parentId[c1]=parent;
        parentId[c2]=parent;
        childId[0][parent]=c1;
        childId[1][parent]=c2;
      }
    }
  }

  void calcSizeParentTinTout(int root) {
    int n = tree.size();
    int* curEdge = new int[n]; fill(curEdge,curEdge+n,0);
    int* _stack = new int[n];
    _stack[0] = root;
    parent[root] = -1;
    for (int top = 0; top >= 0; ) {
      int u = _stack[top];
      if (curEdge[u] == 0) {
        tin[u] = time++;
        size[u] = 1;
      }
      if (curEdge[u] < tree[u].size()) {
        int v = tree[u][curEdge[u]++];
        if (curEdge[v] == 0) {
          _stack[++top] = v;
          parent[v] = u;
        }
      } else {
        --top;
        if (parent[u] != -1)
          size[parent[u]] += size[u];
        tout[u] = time++;
      }
    }
  }

  int newPath(int u) {
    pathRoot[pathCount] = u;
    return pathCount++;
  }

  void buildPaths(int root) {
    int n = tree.size();
    int* curEdge = new int[n]; fill(curEdge,curEdge+n,0);
    int* _stackPath = new int[n];
    int* _stack = new int[n];
    _stack[0] = root;
    _stackPath[0] = newPath(root);
    for (int top = 0; top >= 0; ) {
      int u = _stack[top];
      int path = _stackPath[top];
      if (curEdge[u] == 0) {
        this->path[u] = path;
        pathPos[u] = pathSize[path]++;
      }
      if (curEdge[u] < tree[u].size()) {
        int v = tree[u][curEdge[u]++];
        if (curEdge[v] == 0) {
          _stack[++top] = v;
          _stackPath[top] = 2 * size[v] >= size[u] ? path : newPath(v);
        }
      } else {
        --top;
      }
    }
  }

  void buildPaths(int u, int path) {
    this->path[u] = path;
    pathPos[u] = pathSize[path]++;
    for (int v : tree[u]) {
      if (v != parent[u])
        buildPaths(v, 2 * size[v] >= size[u] ? path : newPath(v));
    }
  }

  void queryPath(int path, int l, int r) {
    r++;
    int n=pathSize[path];
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l&1) ret.PB(val[path][l++]);
      if (r&1) ret.PB(val[path][--r]);
    }
  }

  bool isAncestor(int p, int ch) {
    return tin[p] <= tin[ch] && tout[ch] <= tout[p];
  }

  void query(int a, int b) {
    ret.clear();
    for (int root; !isAncestor(root = pathRoot[path[a]], b); a = parent[root])
      queryPath(path[a], 0, pathPos[a]);
    for (int root; !isAncestor(root = pathRoot[path[b]], a); b = parent[root])
      queryPath(path[b], 0, pathPos[b]);
    if (!(!VALUES_ON_VERTICES && a == b)) {
      queryPath(path[a], min(pathPos[a], pathPos[b]) + (VALUES_ON_VERTICES ? 0 : 1),
              max(pathPos[a], pathPos[b]));
    }
  }
};

vvi id2vtx;
HeavyLight2NoRecursion hl;
vvi g;
TwoSat sat;
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(); g.resize(n);
  for (int i=1;i<n;i++) {
    int x=rint()-1,y=rint()-1;
    g[x].PB(y); g[y].PB(x);
  }
  hl.init(g);
  
  int m=rint();
  int hls=hl.ida.size();
  int ANT=0;
  int UPLINK=ANT+2*m;
  int DOWNLINK=UPLINK+hls;
  int LIST=DOWNLINK+hls;

  id2vtx.resize(hls);
  int req=0;
  for (int s=0;s<m;s++) {
    for (int t=0;t<2;t++) {
      int st=(s<<1)|t;
      int a=rint()-1;int b=rint()-1;
      hl.query(a,b);
      //printf("a:%d b:%d\n",a,b);
      for (auto &w:hl.ret) {
        //printf("w:%d\n",w);
        id2vtx[w].PB(st);
      }
      req+=hl.ret.size();
    }
  }

  sat.init(LIST+2*req);

  for (int s=0;s<m;s++) {
    sat.ae(false, ANT+(s<<1),true,ANT+((s<<1)|1)); // Ant must have at least one colored path.
  }
  for (int w=0;w<hls;w++) {
    for (auto &st:id2vtx[w]) {
      sat.ae(true, DOWNLINK+w, false, ANT+st); // Another ant prevents ant s from using path t.
      sat.ae(true, UPLINK+w, false, ANT+st); // Another ant prevents ant s from using path t.
      // Ant s using path t prevents other ants from using edges
      if (hl.parentId[w]!=-1) sat.ae(true, ANT+st, true, UPLINK+hl.parentId[w]);
      for (int k=0;k<2;k++) if(hl.childId[k][w]!=-1) sat.ae(true, ANT+st, true, DOWNLINK+hl.childId[k][w]);
    }
  }
  for (int id=0;id<hls;id++) {
    int pid=hl.parentId[id];
    if (pid!=-1) {
      sat.ae(true,UPLINK+id,true,UPLINK+pid);
      sat.ae(true,DOWNLINK+pid,true,DOWNLINK+pid);
    }
  }
  IdAllocator ida; ida.n=LIST;
  for (int id=0;id<hls;id++) {
    int vtxsz=id2vtx[id].size();
    {
      int lastnid=-1;
      for (int i=vtxsz-2;i>=0;i--) {
        int nid=ida.getid(); // [0...i]
        int cid=ANT+id2vtx[id][i];
        int rid=ANT+id2vtx[id][i+1];
        if (lastnid!=-1) sat.ae(true,lastnid,true,nid);
        sat.ae(true,nid,false,cid);
        sat.ae(true,rid,true,nid);
        lastnid=nid;
      }
    }
    {
      int lastnid=-1;
      for (int i=1;i<vtxsz;i++) {
        int nid=ida.getid(); // [i...vtsz-1]
        int cid=ANT+id2vtx[id][i];
        int lid=ANT+id2vtx[id][i-1];
        if (lastnid!=-1) sat.ae(true,lastnid,true,nid);
        sat.ae(true,nid,false,cid);
        sat.ae(true,lid,true,nid);
        lastnid=nid;
      }
    }
  }
  bool final=sat.twosat();
  if (final) {
    printf("YES\n");
    for (int s=0;s<m;s++) {
      int st=s<<1;
      if (sat.res[st]) printf("1\n");
      else {assert(sat.res[st^1]); printf("2\n");}
    }
  }
  else printf("NO\n");
}



int rint()
{
  int x; scanf("%d",&x); return x;
}
char rch()
{
  char x; scanf("%c",&x); return x;
}
long long rlong()
{
  long long x; scanf("%lld",&x); return x;
}