#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
typedef long long ll;

const int N = 200100;
int n,k,lev[N],siz[N];
vector<int> adj[N];

void dfs(int v, int par, int l) {
  for (auto u : adj[v]) if (u != par) {
    dfs(u, v, l+1);
    siz[v] += siz[u];
  }
  lev[v] = l - siz[v];
  siz[v] += 1;
}

int main() {
  scanf("%d%d",&n,&k);
  REP(i,n-1) {
    int a,b; scanf("%d%d",&a,&b); --a;--b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(0,-1,0);
  sort(lev,lev+n,greater<int>());
  ll ans = 0;
  REP(i,k) { ans += lev[i]; }
  printf("%lld\n",ans);
}