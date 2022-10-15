/* 


WACF


dp

HLDGCD



code
OI




code

 fast io afo
pragmaavx



OI

rp
*/

#include <iostream>
#include <vector>
#include <queue>
int mod = 1e9 + 7;
void m998() { mod = 998244353; } // 
void eat() {
  int n, m, s, t;
  std::cin >> n >> m >> s >> t;
  std::vector<int> adj[n + 1];
  bool eee[n + 1][n + 1];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) eee[i][j] = 0;
  }
  for (int i = 1, u, v; i <= m; i++) {
    std::cin >> u >> v;
    eee[u][v] = eee[v][u] = 1;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int dist[n + 1][n + 1];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j) dist[i][j] = 0;
      else dist[i][j] = 122690412;
    }
  }
  std::queue<int> bfs;
  for (int i = 1; i <= n; i++) {
    bfs.push(i);
    while (bfs.size()) {
      auto x = bfs.front();
      bfs.pop();
      for (auto j : adj[x]) {
        if (dist[i][j] > dist[i][x] + 1) {
          dist[i][j] = dist[i][x] + 1;
          bfs.push(j);
        }
      }
    }
  }
  int z = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) z += (!eee[i][j] && dist[s][i] + dist[j][t] + 1 >= dist[s][t] && !eee[j][i] && dist[s][j] + dist[i][t] + 1 >= dist[s][t]);
  }
  std::cout << z << "\n";
}
int32_t main() {
  int t = 1;
  // std::cin >> t;
  while (t--) eat();
}