#include <iostream>
#include <vector>
#include <queue>
#define int long long
#define double long double
#define ff first
#define ss second
void eat() {
  int n, m;
  std::cin >> n >> m;
  int deg[n + 1] = {}, dist[n + 1];
  std::vector<int> adj[n + 1];
  for (int i = 1, u, v; i <= m; i++) {
    std::cin >> u >> v;
    adj[v].push_back(u);
    deg[u]++;
  }
  for (int i = 1; i <= n; i++) dist[i] = 1e18;
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int> >, std::greater<std::pair<int, int> > > pq;
  pq.push({0, n});
  while (pq.size()) {
    auto x = pq.top();
    pq.pop();
    if (dist[x.ss] < 1e18) continue;
    dist[x.ss] = x.ff;
    for (auto i : adj[x.ss]) {
      pq.push({x.ff + deg[i], i});
      deg[i]--;
    }
  }
  std::cout << dist[1] << "\n";	
}
int32_t main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  int t = 1;
  // std::cin >> t;
  while (t--) eat();
  return 0;
}