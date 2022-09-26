#include <bits/stdc++.h>

using namespace std;

const int MX = 100100;

int N;
vector<int> adj[MX];
int ans[MX];
int sz[MX];
long long tot = 0;

void calcSz(int v, int p) {
   sz[v] = 1;
   for (int u : adj[v]) if (u != p) {
      calcSz(u, v);
      sz[v] += sz[u];
   }
   tot += 2 * min(sz[v], N - sz[v]);
}

int findCent(int v, int p) {
   for (int u : adj[v]) if (u != p && sz[u] * 2 >= N) {
      return findCent(u, v);
   }
   return v;
}

vector<int> ord;

void dfs(int v, int p) {
   ord.emplace_back(v);
   for (int u : adj[v]) if (u != p) {
      dfs(u, v);
   }
}

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);
   cin >> N;
   for (int i = 1; i < N; ++i) {
      int v, u; cin >> v >> u;
      adj[v].emplace_back(u);
      adj[u].emplace_back(v);
   }
   calcSz(1, -1);
   int root = findCent(1, -1);
   dfs(root, -1);
   int H = N / 2;
   for (int i = 0; i < N; ++i) ans[ord[i]] = ord[(i+H)%N];
   cout << tot << '\n';
   for (int i = 1; i <= N; ++i) cout << ans[i] << ' '; cout << '\n';
   return 0;
}