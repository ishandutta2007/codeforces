#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 200200;

int n, m, s;
ll w[N];
vector<int> g[N];
vector<int> ng[N];
int deg[N];
bool was[N];
ll ds[N];
ll ans;
int par[N];

void dfs1(int v, int p) {
   ds[v] = ds[p] + w[v];
   ans = max(ans, ds[v]);
   for (int u : g[v]) {
      if (u != p) {
         dfs1(u, v);
      }
   }
}

void solve1() {
   dfs1(s, 0);
   cout << ans << "\n";
}

void dfs2(int v) {
   ds[v] = ds[par[v]] + w[v];
   ans = max(ans, ds[v]);
   for (int u : ng[v]) {
      if (u != par[v]) {
         par[u] = v;
         dfs2(u);
      }
   }
}

void dfs3(int v) {
   ans = max(ans, ds[v] - ds[s] + w[s]);
   for (int u : ng[v]) {
      if (u != par[v]) {
         dfs3(u);
      }
   }
}

ll cans;

void dfs4(int v) {
   ds[v] = ds[par[v]] + w[v];
   cans = max(cans, ds[v]);
   for (int u : ng[v]) {
      if (u != par[v]) {
         dfs4(u);
      }
   }
}

int main() {
   ios_base::sync_with_stdio(false);
   cin >> n >> m;
   for (int i = 1; i <= n; ++i) {
      cin >> w[i];
   }
   for (int i = 0; i < m; ++i) {
      int v, u;
      cin >> v >> u;
      g[v].emplace_back(u);
      g[u].emplace_back(v);
   }
   cin >> s;
   if (m == n - 1) {
      solve1();
      return 0;
   }
   queue<int> q;
   for (int i = 1; i <= n; ++i) {
      deg[i] = g[i].size();
      if (deg[i] == 1) {
         was[i] = true;
         q.push(i);
      }
   }
   while (!q.empty()) {
      int v = q.front();
      q.pop();
      int nv = 0;
      for (int u : g[v]) {
         if (!was[u]) {
            nv = u;
            break;
         }
      }
      assert(nv);
      if (--deg[nv] == 1) {
         was[nv] = true;
         q.push(nv);
      }
   }
   for (int i = 1; i <= n; ++i) {
      if (!was[i]) {
         w[n + 1] += w[i];
         w[i] = 0;
      }
   }
   for (int v = 1; v <= n; ++v) {
      int nv = was[v] ? v : n + 1;
      for (int u : g[v]) {
         int nu = was[u] ? u : n + 1;
         if (nv == n + 1 && nu == n + 1) continue;
         ng[nv].emplace_back(nu);
      }
   }
   int ns = was[s] ? s : n + 1;
   if (ns == n + 1) {
      dfs2(ns);
      cout << ans << "\n";
      return 0;
   }
   dfs2(n + 1);
   dfs3(s);
   ll add = 0;
   for (int v = s; v; v = par[v]) {
      add += w[v];
      w[v] = 0;
   }
   dfs4(n + 1);
   ans = max(ans, cans + add);
   cout << ans << "\n";
}