#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FORE(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

const int N = 100100;
int n,m,ans,vis[N],qe,qb,q[N],deg[N];
vector<int> adj[N],adjT[N],lst;

void dfs(int v) {
  vis[v] = 1;
  lst.push_back(v);
  FORE(i,adj[v]) if (!vis[*i]) dfs(*i);
  FORE(i,adjT[v]) if (!vis[*i]) dfs(*i);
}

int main() {
  scanf("%d%d",&n,&m);
  REP(i,m) {
    int a,b; scanf("%d%d",&a,&b); --a; --b;
    adj[a].push_back(b);
    adjT[b].push_back(a);
    deg[b]++;
  }

  ans = n;
  REP(i,n) if (!vis[i]) {
    dfs(i); --ans;

    qe=qb=0; FORE(i,lst) if (deg[*i] == 0) q[qe++] = *i;
    while (qe != qb) {
      int v = q[qb++];
      FORE(i,adj[v]) if (--deg[*i] == 0) q[qe++] = *i;
    }
    if (qe != lst.size()) { ++ans; }
    lst.clear();
  }

  printf("%d\n", ans);
}