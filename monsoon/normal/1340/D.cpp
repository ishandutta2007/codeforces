#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
typedef pair<int,int> pii;

const int N = 110000;
int n,T;
vector<pii> ans;
vector<int> adj[N];

inline void put(int v, int t) {
  ans.push_back(make_pair(v, t));
}

void dfs(int v, int par, int t) {
  int orig_t = t;
  int m = (int)adj[v].size() - (par != -1);
  put(v, t);

  if (m == 0) {
    assert(t != 0);
    put(v, t-1);
    return;
  }

  if (t == T && par != -1) { put(v, t = T-1-m); }
  for (auto u : adj[v]) if (u != par) {
    dfs(u, v, t+1);
    t++; put(v, t);
    if (t == T && par != -1) { put(v, t = T-1-m); }
  }
  if (t != orig_t-1 && par != -1) put(v, orig_t-1);

}

int main() {
  scanf("%d",&n);
  REP(i,n-1) {
    int a,b; scanf("%d%d",&a,&b); --a; --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  if (n == 1) { put(0, 0); }
  else {
    REP(i,n) T = max(T, (int)adj[i].size());

    dfs(0, -1, 0);
  }

  printf("%d\n",(int)ans.size());
  for (auto x : ans) {
    printf("%d %d\n",x.first+1,x.second);
  }

}