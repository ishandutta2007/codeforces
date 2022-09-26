#include <bits/stdc++.h>

using namespace std;

const int MX = 200200;

int N, M, K;

vector<pair<int, int>> adj[MX];
int has[MX][10][10];
bool ban[10][10];
bool ban2[10][10][10][10];
int arr[10];
int ans;

bool good() {
   for (int d1 = 1; d1 <= K; ++d1) {
      for (int d2 = d1 + 1; d2 <= K; ++d2) {
         if (ban2[d1][arr[d1]][d2][arr[d2]]) return false;
      }
   }
   // for (int d = 1; d <= K; ++d) cerr << arr[d] + 1 << ' '; cerr << '\n';
   return true;
}

void dfs(int d) {
   if (d == K + 1) {
      ans += good();
      return;
   }
   for (int c = 0; c < d; ++c) {
      if (ban[d][c]) continue;
      arr[d] = c;
      dfs(d + 1);
   }
}

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);
   cin >> N >> M >> K;
   for (int i = 1; i <= M; ++i) {
      int v, u, w; cin >> v >> u >> w;
      adj[v].emplace_back(w, u);
   }
   for (int v = 1; v <= N; ++v) {
      sort(adj[v].begin(), adj[v].end());
      int d = adj[v].size();
      for (int c = 0; c < d; ++c) {
         int u = adj[v][c].second;
         ++has[u][d][c];
      }
   }
   for (int v = 1; v <= N; ++v) {
      for (int d1 = 1; d1 <= K; ++d1) {
         for (int c1 = 0; c1 < d1; ++c1) if (has[v][d1][c1]) {
            if (has[v][d1][c1] >= 2) ban[d1][c1] = true;
            for (int d2 = d1+1; d2 <= K; ++d2) {
               for (int c2 = 0; c2 < d2; ++c2) if (has[v][d2][c2]) {
                  ban2[d1][c1][d2][c2] = true;
               }
            }
         }
      }
   }
   dfs(1);
   cout << ans << '\n';
   return 0;
}