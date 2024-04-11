#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int MAXN = 200200;

int N;
vector<pair<int, ll>> adj[MAXN];
int sz[MAXN];

void dfs1(int v, int p) {
   sz[v] = 1;
   for (auto e : adj[v]) {
      int u;
      ll w;
      tie(u, w) = e;
      if (u != p) {
         dfs1(u, v);
         sz[v] += sz[u];
      }
   }
}

int go(int v, int p) {
   for (auto e : adj[v]) {
      if (e.first != p && sz[e.first] * 2 >= N) {
         return go(e.first, v);
      }
   }
   return v;
}

void dfs2(int v, int p, ll dist, ll& B) {
   B += dist;
   for (auto e : adj[v]) {
      if (e.first != p) {
         dfs2(e.first, v, dist + e.second, B);
      }
   }
}

void solve() {
   cin >> N;
   N *= 2;
   for (int i = 0; i < N - 1; ++i) {
      int v, u;
      ll w;
      cin >> v >> u >> w;
      adj[v].emplace_back(u, w);
      adj[u].emplace_back(v, w);
   }
   dfs1(1, -1);
   ll G = 0;
   for (int v = 1; v <= N; ++v) {
      if (sz[v] & 1) {
         for (auto e : adj[v]) {
            if (sz[e.first] > sz[v]) {
               G += e.second;
            }
         }
      }
   }
   ll B = 0;
   dfs2(go(1, -1), -1, 0LL, B);
   cout << G << " " << B << "\n";
   for (int v = 1; v <= N; ++v) {
      adj[v] = {};
   }
}

int main() {
   ios_base::sync_with_stdio(false);
   int T;
   cin >> T;
   while (T--) {
      solve();
   }
}