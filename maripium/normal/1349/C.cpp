#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const ll INF = 2e18;

vector<int> xd = {-1, 0, 0, +1};
vector<int> yd = {0, -1, +1, 0};

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);
   int N, M, Q;
   cin >> N >> M >> Q;
   vector<string> S(N);
   for (int i = 0; i < N; ++i) {
      cin >> S[i];
   }
   auto inside = [&](int x, int y) {
      return x >= 0 && x < N && y >= 0 && y < M;
   };
   vector<vector<pair<ll, int>>> dist(N, vector<pair<ll, int>>(M, pair<ll, int>(INF, -1)));
   queue<pair<int, int>> q;
   for (int x = 0; x < N; ++x) {
      for (int y = 0; y < M; ++y) {
         bool good = false;
         for (int d = 0; d < 4; ++d) {
            int nx = x + xd[d];
            int ny = y + yd[d];
            if (inside(nx, ny) && S[nx][ny] == S[x][y]) good = true;
         }
         if (good) {
            dist[x][y] = {0, S[x][y] -  '0'};
            q.emplace(x, y);
         }
      }
   }
   while (!q.empty()) {
      int x, y; tie(x, y) = q.front(); q.pop();
      for (int d = 0; d < 4; ++d) {
         int nx = x + xd[d];
         int ny = y + yd[d];
         if (!inside(nx, ny)) continue;
         if (dist[nx][ny].first > dist[x][y].first + 1) {
            dist[nx][ny] = dist[x][y];
            dist[nx][ny].first++;
            q.emplace(nx, ny);
         }
      }
   }
   while (Q--) {
      int x, y; ll T;
      cin >> x >> y >> T;
      --x, --y;
      bool ans;
      if (T < dist[x][y].first) {
         ans = (S[x][y] - '0') ^ (T & 1);
      } else {
         ans = dist[x][y].second;
      }
      if (T & 1) ans ^= 1;
      cout << ans << "\n";
   }
}