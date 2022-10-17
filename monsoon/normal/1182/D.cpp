#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FORE(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
typedef pair<int,int> pii;

const int N = 100100;
int n,size[N],deg[N],degs[N],centr[N];
vector<int> adj[N];

void dfs(int v, int par) {
  size[v] = 1;
  FORE(i,adj[v]) if (*i != par) {
    dfs(*i, v);
    size[v] += size[*i];
  }
  FORE(i,adj[v]) if (*i != par) {
    if (size[*i]*2 > n) centr[v] = 0;
  }
  if ((n-size[v])*2 > n) centr[v] = 0;
}

bool test_dfs(int v, int par, int lev) {
  if (degs[lev] == 0) {
    degs[lev] = deg[v];
  } else if (degs[lev] != deg[v]) {
    return 0;
  }
  FORE(i,adj[v]) if (*i != par) {
    if (!test_dfs(*i, v, lev+1)) return 0;
  }
  return 1;
}

pii go(int v, int par, int lev) {
  if (deg[v] == 1) { return make_pair(lev, v); }
  else if (deg[v] > 2) { return make_pair(-1, -1); }
  else {
    FORE(i,adj[v]) if (*i != par) {
      return go(*i, v, lev+1);
    }
  }
}

bool test(int v) {
  REP(i,n) degs[i] = 0;
  return test_dfs(v, -1, 0);
}

int main() {
  scanf("%d",&n);
  REP(i,n-1) {
    int a,b; scanf("%d%d",&a,&b); --a; --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
    ++deg[a];
    ++deg[b];
  }

  REP(i,n) centr[i] = 1;
  dfs(0,-1);

  REP(i,n) if (centr[i] && test(i)) {
    printf("%d\n", i+1); return 0;
  }

  REP(i,n) if (centr[i]) {
    vector<pii> gos;
    FORE(j,adj[i]) {
      gos.push_back(go(*j, i, 0));
    }
    sort(gos.begin(), gos.end());
    REP(j,2) {
      int v = gos.begin()->second;
      if (v >= 0 && test(v)) { printf("%d\n", v+1); return 0; }
      reverse(gos.begin(), gos.end());
    }
  }

  printf("-1\n");
}