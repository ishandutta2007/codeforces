#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

namespace cp {

struct tree {
  int n;
  vector<vector<int> > adj;

  vector<int> par;
  vector<int> lev;
  vector<int> siz;
  vector<int> hld, heavy;

  void create(int _n) {
    n = _n;
    adj.resize(n);
    par.resize(n);
    lev.resize(n);
    siz.resize(n);
    hld.resize(n);
    heavy.resize(n, -1);
  }

  void add_edge(int a, int b) {
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  void dfs(int v, int p, int l) {
    par[v] = p;
    lev[v] = l;
    siz[v] = 1;
    if (p != -1) {
      adj[v].erase(find(adj[v].begin(), adj[v].end(), p));
    }
    for (auto& i : adj[v]) {
      dfs(i, v, l+1);
      siz[v] += siz[i];
      if (heavy[v] == -1 || siz[i] > siz[heavy[v]]) {
        heavy[v] = i;
      }
    }
  }

  void init() {
    dfs(0, -1, 0);

    REP(i,n) if (par[i] == -1 || heavy[par[i]] != i) {
      for (int j = i; j != -1; j = heavy[j]) {
        hld[j] = i;
      }
    }
  }

  int lca(int va, int vb) {
    while (hld[va] != hld[vb]) {
      if (lev[hld[va]] < lev[hld[vb]]) swap(va, vb);
      va = par[hld[va]];
    }
    return lev[va] < lev[vb] ? va : vb;
  }

  int dist(int va, int vb) {
    return lev[va] + lev[vb] - 2*lev[lca(va, vb)];
  }
};

}


int n,q;
cp::tree t;

int main() {
  scanf("%d%d",&n,&q);
  t.create(n);
  REP(i,n-1) {
    int a; scanf("%d",&a); --a;
    t.add_edge(a, i+1);
  }
  t.init();

  REP(i,q) {
    int a,b,c; scanf("%d%d%d",&a,&b,&c); --a;--b;--c;
    int lcas[3] = { t.lca(a,b), t.lca(b,c), t.lca(c,a) };
    int v = *max_element(lcas,lcas+3,
        [](int i, int j) { return t.lev[i] < t.lev[j]; });
    int ans[3] = { t.dist(a,v), t.dist(b,v), t.dist(c,v) };
    int answer = *max_element(ans,ans+3);
    printf("%d\n",answer+1);
  }
}