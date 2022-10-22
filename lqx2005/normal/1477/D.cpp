#include <bits/stdc++.h>

using namespace std;
const int N = 5e5 + 10;
vector<int> g[N], e[N], flower[N];
int p[N], q[N], gp[N];
set<int> id;
int n, m;

void init(int n) {
  id.clear();
  for(int i = 1; i <= n; i++) gp[i] = 0, e[i].clear(), g[i].clear(), id.insert(i), flower[i].clear();
}

void adde(int u, int v) {
  g[u].push_back(v);
}

void addt(int u, int v) {
  e[u].push_back(v);
}

void Dfs(int u) {
  vector<int> del, exa;
  for(auto v : g[u]) {
    if(id.count(v)) {
      id.erase(v), del.push_back(v);
    }
  }
  for(auto v : id) exa.push_back(v);
  id.clear();
  for(auto v : del) id.insert(v);
  for(auto v : exa) {
    Dfs(v);
    addt(u, v), addt(v, u);
  }
  return;
}

void dfs(int u, int fa) {
  gp[u] = 0;
  vector<int> star, non, lef;
  for(auto v : e[u]) {
    if(v == fa) continue;
    dfs(v, u);
    if(gp[v] == 0) non.push_back(v);
    else if(gp[v] == v) star.push_back(v);
    else lef.push_back(v);
  }
  if(!non.empty()) {
    gp[u] = u;
    for(auto v : non) gp[v] = u;
  } else if(!star.empty()) {
    gp[u] = star[0];
  } else if(!lef.empty()){
    gp[u] = u;
    gp[lef[0]] = u;
  }
  return;
}

void work() {
  scanf("%d%d", &n, &m);
  init(n);
  int u, v;
  for(int i = 1; i <= m; i++) {
    scanf("%d%d", &u, &v);
    adde(u, v), adde(v, u);
  }
  for(int i = 1; i <= n; i++) {
    if(g[i].size() >= n - 1) continue;
    if(!id.count(i)) continue;
    id.erase(i);
    Dfs(i);
    dfs(i, 0);
  }
  for(int u = 1; u <= n; u++) {
    if(gp[u] && gp[u] != u) flower[gp[u]].push_back(u);
  }
  int now = 0;
  for(int u = 1; u <= n; u++) {
    if(flower[u].empty()) continue;
    p[u] = ++now;
    for(auto v : flower[u]) {
      q[v] = now, p[v] = ++now;
    }
    q[u] = now;
  }
  int cnt = now;
  for(int u = 1; u <= n; u++) if(!gp[u]) p[u] = q[u] = ++cnt;
  for(int u = 1; u <= n; u++) printf("%d ", p[u]);
  printf("\n");
  for(int u = 1; u <= n; u++) printf("%d ", q[u]);
  printf("\n");
  return;
}

int main() {
  int T;
  scanf("%d", &T);
  for(; T--; ) work();
  return 0;
}