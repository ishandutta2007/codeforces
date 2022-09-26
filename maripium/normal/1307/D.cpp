#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200200;

int N, M, K;
vector<int> adj[MAXN];
int dist[MAXN];
bool special[MAXN];
int distTo1[MAXN];
int distToN[MAXN];

void bfs(int src, int *dist) {
   for (int z = 1; z <= N; ++z) {
      dist[z] = -1;
   }
   dist[src] = 0;
   queue<int> q;
   q.emplace(src);
   while (!q.empty()) {
      int v = q.front(); q.pop();
      for (int u : adj[v]) {
         if (dist[u] == -1) {
            dist[u] = dist[v] + 1;
            q.emplace(u);
         }
      }
   }
}

int main() {
   ios_base::sync_with_stdio(false);
   cin >> N >> M >> K;
   for (int i = 1; i <= K; ++i) {
      int z;
      cin >> z;
      special[z] = true;
   }
   for (int i = 1; i <= M; ++i) {
      int x, y;
      cin >> x >> y;
      adj[x].emplace_back(y);
      adj[y].emplace_back(x);
   }
   bfs(1, distTo1);
   bfs(N, distToN);
   vector<pair<int, int>> diffs;
   for (int z = 1; z <= N; ++z) {
      if (special[z]) diffs.emplace_back(distTo1[z] - distToN[z], z);
   }
   sort(diffs.begin(), diffs.end());
   int maxDist = -MAXN;
   int ans = 0;
   for (auto p : diffs) {
      int z = p.second;
      ans = max(ans, min(distTo1[N], maxDist + 1 + distToN[z]));
      maxDist = max(maxDist, distTo1[z]);
   }
   cout << ans << "\n";
   return 0;
}