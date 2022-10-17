#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

const int N = 100100;
int n,lev[N],sas[N];
vector<int> adj[N];

void dfs(int v, int par, int l) {
  lev[v] = l;
  for (auto u : adj[v]) if (u != par) {
    dfs(u, v, l+1);
  }
}

int main() {
  scanf("%d",&n);
  REP(i,n-1) {
    int a,b; scanf("%d%d",&a,&b); --a; --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(0,-1,0);
  int x[2] = {0,0};
  REP(i,n) if (adj[i].size() == 1) {
    x[ lev[i] % 2 ]++;
  }
  bool odd = x[0] && x[1];
  int min_ans = odd ? 3 : 1;
  int max_ans = n-1;

  REP(i,n) if (adj[i].size() == 1) {
    sas[adj[i][0]]++;
  }
  REP(i,n) if (sas[i]) {
    max_ans -= sas[i]-1;
  }

  printf("%d %d\n",min_ans,max_ans);
}