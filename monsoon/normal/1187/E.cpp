#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FORE(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
typedef long long ll;

const int N = 210000;
int n,siz[N];
ll dp[N],Dp[N];
vector<int> adj[N];

void dfs(int v, int par) {
  siz[v] = 1;
  dp[v] = 0;
  FORE(i,adj[v]) if (*i != par) {
    dfs(*i, v);
    siz[v] += siz[*i];
    dp[v] += dp[*i];
  }
  dp[v] += siz[v];
}

void dfs2(int v, int par) {
  FORE(i,adj[v]) if (*i != par) {
    Dp[*i] = Dp[v] + n - 2*siz[*i];
    dfs2(*i, v);
  }
}

int main() {
  scanf("%d",&n);
  REP(i,n-1) {
    int a,b; scanf("%d%d",&a,&b); --a; --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(0, -1);
  Dp[0] = dp[0];
  dfs2(0, -1);
  ll ans = *max_element(Dp, Dp+n);
  printf("%lld\n",ans);
}