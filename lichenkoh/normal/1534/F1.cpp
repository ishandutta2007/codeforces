#ifdef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx,avx2")
#pragma GCC optimize("Ofast")
#endif
#include "bits/stdc++.h"
#ifndef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
#pragma GCC optimize("Ofast")
#endif
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
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;typedef vector<pii> vpii;typedef vector<pll> vpll;
template<typename T> void makeunique(vector<T> &vx) {sort(vx.begin(),vx.end());auto it=unique(vx.begin(),vx.end());vx.resize(std::distance(vx.begin(),it));}
#ifdef ONLINE_JUDGE
#define assert(...) /* nothing */
#endif
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
// mt19937 rng; rng.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());
// template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=(int)v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}

class SCC {
public:
// Kosaraju from e-maxx https://cp-algorithms.com/graph/strongly-connected-components.html
// Vertices MUST be 0-indexed
  static const bool MAKE_CONDENSATION_GRAPH=true;
  static const bool STORE_VCOMPONENT=false;
  vector<vector<int> > adj, adjrev;
  vector<bool> used;
  vector<int> order, component;

  // Condensed/Contracted SCC graph
  // condensed is the adjacency list of the root_nodes.
  // We can now traverse on condensed as our condensation graph, using only those nodes which belong to root_nodes.
  vector<vector<int> > condensed;
  // component contains the vertex IDs of this component.
  vector<vector<int> > vcomponent;
  // roots[v] indicates the root node for the SCC to which node v belongs.
  vector<int> roots;
  // root_nodes is the list of all root nodes (one per component) in the condensation graph.
  vector<int> root_nodes;

  void dfs1(int v) {
    used[v] = true;

    for (auto u : adj[v]) {
      if (!used[u]) {
        dfs1(u);
      }
    }
    order.push_back(v);
  }

  void dfs2(int v) {
    used[v] = true;
    component.push_back(v);
    for (auto u : adjrev[v]) {
      if (!used[u]) {
        dfs2(u);
      }
    }
  }
  void makeSCCHelper(int n) {
    used.resize(n);
    used.assign(n, false);
    order.clear();
    component.clear();
    vcomponent.clear();
    condensed.clear();
    roots.clear();
    root_nodes.clear();

    // Function dfs1 fills the list order with vertices in increasing order of their exit times
    // (actually, it is making a topological sort).
    for (int i = 0; i < n; i++) {
      if (!used[i]) {
        dfs1(i);
      }
    }

    used.assign(n, false);
    reverse(order.begin(), order.end());

    if (MAKE_CONDENSATION_GRAPH) {
      roots.resize(n);
      condensed.resize(n);
    }

    // Function dfs2 stores all reached vertices in list component,
    // that is going to store next strongly connected component after each run.
    for (auto v : order) {
      if (!used[v]) {
        dfs2 (v);
        // ... processing next component ...
        if (MAKE_CONDENSATION_GRAPH) {
          int root = component.front();
          for (auto u : component) roots[u] = root;
          root_nodes.push_back(root);
        }
        if (STORE_VCOMPONENT) {
          vcomponent.PB(component);
        }
        component.clear();
      }
    }
    if (MAKE_CONDENSATION_GRAPH) {
      for (int v = 0; v < n; v++) {
        for (auto u : adj[v]) {
          int root_v = roots[v],
              root_u = roots[u];
          if (root_u != root_v) {
            condensed[root_v].push_back(root_u);
          }
        }
      }
      for (int v = 0; v < n; v++) {
        makeunique(condensed[v]);
      }
    }
  }

  void makeSCC(vvi const& g) {
    adj.clear(); adjrev.clear();
    adj=g;
    int n=g.size(); adjrev.resize(n);
    for (int x=0;x<n;x++) {
      for (auto &y:g[x]) {
        adjrev[y].PB(x);
      }
    }
    makeSCCHelper(n);
  }

  void makeSCC(int n, vpii const& edges) {
    adj.clear(); adjrev.clear();
    adj.resize(n); adjrev.resize(n);
    for (auto &w:edges) {
      int x=w.fst,y=w.snd;
      adj[x].PB(y);
      adjrev[y].PB(x);
    }
    makeSCCHelper(n);
  }
};


using vvpii=vector<vpii>;
int rlim,clim;
int dr[]={1,0,-1,0};
int dc[]={0,1,0,-1};

bool valid(int r, int c) {
  return 0<=r&&r<rlim && 0<=c&&c<clim;
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin>>rlim>>clim;
  vector<string> a(rlim);
  vi vneed(clim);
  for (int r=rlim-1;r>=0;r--) cin>>a[r];
  for (int c=0;c<clim;c++) cin>>vneed[c];

  vvpii vc(clim);
  vvi rcid(rlim);
  for (int r=0;r<rlim;r++) {rcid[r].resize(clim, -1);}

  int ncomp=0;
  for (int r=0;r<rlim;r++) {
    for (int c=0;c<clim;c++) {
      if (a[r][c]=='.') continue;
      rcid[r][c]=ncomp;
      vc[c].PB(MP(r,ncomp));
      ncomp++;
    }
  }
  vpii g(ncomp);
  for (int r=0;r<rlim;r++) {
    for (int c=0;c<clim;c++) {
      if (a[r][c]=='.') continue;
      for (int t=0;t<4;t++) {
        int nr=r+dr[t],nc=c+dc[t];
        if (valid(nr,nc)&&a[nr][nc]=='#') {
          g.PB(MP(rcid[r][c],rcid[nr][nc]));
        }
      }
    }
  }
  for (int c=0;c<clim;c++) {
    sort(vc[c].begin(),vc[c].end());
  }
  for (int xc=0;xc<clim;xc++) {
    auto &X=vc[xc];
    for (int yc=max(0,xc-1);yc<=min(clim-1,xc+1);yc++) {
      auto &Y=vc[yc];
      int yp=0;
      for (int xp=0;xp<X.size();xp++) {
        assert(yp>=0);
        int xcomp=X[xp].snd;
        int xrow=X[xp].fst;
        while(yp<Y.size()&&Y[yp].fst < xrow) yp++;
        int newyp=yp;
        assert(yp==Y.size()||Y[yp].fst>=xrow);
        yp--;
        if (yp>=0) {
          assert (yp<Y.size());
          assert(Y[yp].fst<xrow);
          while(yp>=0 && Y[yp].snd==xcomp) yp--;
          if (0<=yp&&yp<Y.size() && Y[yp].fst<xrow) {
            int ycomp=Y[yp].snd;
            int yrow=Y[yp].fst;
            assert(xcomp!=ycomp);
            assert(yrow<xrow);
            g.PB(MP(xcomp,ycomp));
          }
        }
        yp=newyp;
      }
    }
  }
  makeunique(g);
  SCC scc;
  scc.makeSCC(ncomp, g);
  vector<bool> hasin(ncomp);
  for (auto &x: scc.root_nodes) {
    for (auto &y:scc.condensed[x]) {
      hasin[y]=true;
    }
  }
  int final=0;
  for (auto &comp: scc.root_nodes) {
    if (!hasin[comp]) {
      final++;
    }
  }
  printf("%d\n",final);
}