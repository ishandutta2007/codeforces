#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
   int N, M;
   cin >> N >> M;
   vector<vector<int>> adj(N);
   vector<vector<int>> radj(N);
   for (int i = 0; i < M; ++i) {
      int v, u;
      cin >> v >> u;
      --v, --u;
      adj[v].emplace_back(u);
      radj[u].emplace_back(v);
   }
   int K;
   cin >> K;
   vector<int> paths(K);
   for (int i = 0; i < K; ++i) {
      cin >> paths[i];
      --paths[i];
   }
   int T = paths.back();
   vector<int> dist(N, -1);
   queue<int> q;
   dist[T] = 0;
   q.emplace(T);
   while (!q.empty()) {
      int v = q.front(); q.pop();
      for (int u : radj[v]) {
         if (dist[u] == -1) {
            dist[u] = dist[v] + 1;
            q.emplace(u);
         }
      }
   }
   int mn = 0;
   int mx = 0;
   for (int i = 0; i + 1 < K; ++i) {
      int v = paths[i];
      int u = paths[i + 1];
      mn += (dist[v] != dist[u] + 1);
      for (int z : adj[v]) {
         if (dist[v] == dist[z] + 1 && z != u) {
            mx++;
            break;
         }
      }
   }
   cout << mn << " " << mx;
}