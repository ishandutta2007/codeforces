#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FORE(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

const int N = 500100;
int n,T,ans;
vector<int> adj[N], depths;

void dfs(int v, int par, int dep) {
  if (adj[v].size() == 1) {
    depths.push_back(dep);
  } else {
    FORE(i,adj[v]) if (*i != par) {
      dfs(*i, v, dep+1);
    }
  }
}

int main() {
  scanf("%d",&n);
  REP(i,n-1) {
    int a,b; scanf("%d%d",&a,&b); --a; --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  FORE(i,adj[0]) {
    depths.clear();
    dfs(*i, 0, 1);
    sort(depths.begin(), depths.end());
    int t = 0;
    FORE(j,depths) {
      t = max(t+1, *j);
    }
    ans = max(ans, t);
  }
  printf("%d\n",ans);
}