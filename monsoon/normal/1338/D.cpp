#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

const int N = 100100;
int n,ans;
vector<int> adj[N];
int tak[N],nie[N];

void max2(int& m1, int& m2, int x) {
  if (x >= m1) { m2 = m1; m1 = x; }
  else if (x >= m2) { m2 = x; }
}

void dfs(int v, int par) {
  int mtn=0, mn=0, s=0;
  int mtn2=0, mn2=0;
  for (auto u : adj[v]) if (u != par) {
    dfs(u, v);
    max2(mn,mn2, nie[u]);
    max2(mtn,mtn2, max(nie[u], tak[u]));
    ++s;
  }
  tak[v] = 1 + mn;
  nie[v] = max(0, s-1 + mtn);

  ans = max(ans, 1 + mn + mn2);
  ans = max(ans, mtn + mtn2 + s-2 + (par != -1));
}

int main() {
  scanf("%d",&n);
  REP(i,n-1) {
    int a,b; scanf("%d%d",&a,&b); --a; --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  dfs(0, -1);
  ans = max(ans, max(tak[0], nie[0]));
  printf("%d\n",ans);
}