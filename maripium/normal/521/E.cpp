#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200200;

int N, M;
vector<int> adj[MAXN];
vector<int> tree[MAXN];
int par[MAXN];
int tin[MAXN], tout[MAXN], tt;
int cnt[MAXN];

void dfs1(int v, int p) {
   tin[v] = ++tt;
   for (int u : adj[v]) {
      if (u == p) continue;
      if (!tin[u]) {
//         cerr << "tree edge : " << v << " -> " << u << "\n";
         par[u] = v;
         tree[v].emplace_back(u);
         dfs1(u, v);
      } else if (tin[u] < tin[v]) {
//         cerr << "back edge : " << v << " -> " << u << "\n";
         ++cnt[v];
         --cnt[u];
      }
   }
   tout[v] = tt;
}

bool isAnc(int v, int u) {
   return tin[v] <= tin[u] && tout[u] <= tout[v];
}

vector<int> path(int s, int t) {
   bool flip = false;
   if (isAnc(s, t)) {
      flip = true;
      swap(s, t);
   }
   assert(isAnc(t, s));
   vector<int> ans;
   while (true) {
      ans.emplace_back(s);
      if (s == t) break;
      s = par[s];
   }
   if (flip) reverse(ans.begin(), ans.end());
   return ans;
}

void finish(int v) {
   int p = par[v];
   assert(p);
   vector<pair<int, int>> edges;
   for (int x = 1; x <= N; ++x) {
      for (int y : adj[x]) {
         if (x == p && y == v) continue;
         if (isAnc(x, p) && isAnc(v, y)) {
            edges.emplace_back(x, y);
         }
      }
   }
   assert(edges.size() >= 2);
   edges.resize(2);
   if (isAnc(edges[0].first, edges[1].first)) swap(edges[0], edges[1]);
   vector<int> ans[3];
   ans[0] = path(v, edges[0].first);
   ans[1] = path(v, edges[0].second); ans[1].emplace_back(edges[0].first);
   ans[2] = path(v, edges[1].second);
   for (int u : path(edges[1].first, edges[0].first)) {
      ans[2].emplace_back(u);
   }
   cout << "YES\n";
   for (int z = 0; z < 3; ++z) {
      cout << int(ans[z].size()) << " ";
      for (int v : ans[z]) cout << v << " ";
      cout << "\n";
   }
   exit(0);
}

int dfs2(int v) {
   int ans = cnt[v];
   for (int u : tree[v]) ans += dfs2(u);
   if (ans >= 2) finish(v);
   return ans;
}

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);
   cin >> N >> M;
   for (int i = 0; i < M; ++i) {
      int v, u;
      cin >> v >> u;
      adj[v].emplace_back(u);
      adj[u].emplace_back(v);
   }
   for (int v = 1; v <= N; ++v) if (!tin[v]) dfs1(v, 0);
   for (int v = 1; v <= N; ++v) if (!par[v]) dfs2(v);
   cout << "NO\n";
   return 0;
}