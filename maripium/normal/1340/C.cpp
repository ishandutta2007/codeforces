#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int N, M, G, R;
int X[10010];
int dist[10010][1010];
bool visited[10010][1010];

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);
   cin >> N >> M;
   for (int i = 0; i < M; ++i) {
      cin >> X[i];
   }
   sort(X, X + M);
   cin >> G >> R;
   memset(dist, -1, sizeof dist);
   dist[0][0] = 0;
   deque<pair<int, int>> dq;
   dq.push_back({0, 0});
   while (!dq.empty()) {
      int i, r;
      tie(i, r) = dq.front(); dq.pop_front();
      if (visited[i][r]) continue;
      visited[i][r] = true;
      if (i > 0) {
         int nr = r + X[i] - X[i - 1];
         if (nr <= G) {
            if (dist[i - 1][nr] == -1) {
               dist[i - 1][nr] = dist[i][r];
               dq.push_front({i - 1, nr});
            }
         }
      }
      if (i + 1 < M) {
         int nr = r + X[i + 1] - X[i];
         if (nr <= G) {
            if (dist[i + 1][nr] == -1) {
               dist[i + 1][nr] = dist[i][r];
               dq.push_front({i + 1, nr});
            }
         }
      }
      if (r == G) if (dist[i][0] == -1 || dist[i][0] > dist[i][G] + 1) {
         dist[i][0] = dist[i][G] + 1;
         dq.push_back({i, 0});
      }
   }
   ll ans = 1e18;
   for (int i = 0; i <= G; ++i) if (dist[M - 1][i] != -1) {
      ans = min(ans, ll(dist[M - 1][i]) * (R + G) + i);
   }
   if (ans > 1e17) ans = -1;
   cout << ans << "\n";
   return 0;
}