#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FORE(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
typedef long long ll;

const int N = 300100;
int n,w[N];
vector<pair<int,int> > adj[N];
ll ans,dp[N];

void dfs(int v, int par) {
  FORE(i,adj[v]) if (i->first != par) dfs(i->first, v);
  ll H = w[v];
  ans = max(ans, H);
  FORE(i,adj[v]) if (i->first != par) {
    ans = max(ans, H - i->second + dp[i->first]);
    H = max(H, w[v] - i->second + dp[i->first]);
  }
  dp[v] = H;
}

int main() {
  scanf("%d",&n);
  REP(i,n) scanf("%d",&w[i]);
  REP(i,n-1) {
    int a,b,c; scanf("%d%d%d",&a,&b,&c); --a; --b;
    adj[a].push_back(make_pair(b,c));
    adj[b].push_back(make_pair(a,c));
  }
  dfs(0, -1);
  printf("%lld\n", ans);
}