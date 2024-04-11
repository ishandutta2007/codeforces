#include <bits/stdc++.h>

using namespace std;

const uint64_t INF = 1ull << 63;

bool mnm(uint64_t &x, uint64_t y) {
   if (x > y) {
      x = y;
      return true;
   }
   return false;
}

vector<array<int, 2>> ch;
vector<array<int, 2>> go;
vector<int> link;
vector<bool> terminal;
int newNode() {
   int v = ch.size();
   ch.emplace_back();
   go.emplace_back();
   link.emplace_back();
   terminal.emplace_back();
   return v;
}
void add(vector<int> str) {
   int v = 0;
   for (int c : str) {
      if (ch[v][c] == 0) {
         int nv = newNode();
         ch[v][c] = nv;
      }
      v = ch[v][c];
   }
   terminal[v] = true;
}

void build() {
   queue<int> bfs;
   link[0] = 0;
   bfs.emplace(0);
   while (!bfs.empty()) {
      int v = bfs.front(); bfs.pop();
      if (terminal[link[v]]) terminal[v] = true;
      for (int c = 0; c < 2; ++c) {
         go[v][c] = go[link[v]][c];
         if (ch[v][c]) {
            link[ch[v][c]] = go[v][c];
            go[v][c] = ch[v][c];
            bfs.emplace(ch[v][c]);
         }
      }
   }
}

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);
   int G, N, M; cin >> G >> N >> M;
   vector<vector<int>> singles(G);
   vector<vector<tuple<int, int, int>>> doubles(G);
   for (int i = 0; i < N; ++i) {
      int a, K; cin >> a >> K;
      if (K == 1) {
         int b; cin >> b;
         singles[b].emplace_back(a);
      } else {
         for (int i = 0; i < K - 2; ++i) {
            int na = singles.size();
            singles.emplace_back();
            doubles.emplace_back();
            // a = b, na;
            int b; cin >> b;
            doubles[b].emplace_back(a, na, 0);
            doubles[na].emplace_back(a, b, 1);
            a = na;
         }
         int b1, b2; cin >> b1 >> b2;
         doubles[b1].emplace_back(a, b2, 0);
         doubles[b2].emplace_back(a, b1, 1);
      }
   }
   newNode();
   for (int i = 0; i < M; ++i) {
      int L; cin >> L;
      vector<int> str(L);
      for (int &c : str) cin >> c;
      add(str);
   }
   build();
   int H = singles.size();
   int V = ch.size();
   vector<vector<vector<uint64_t>>> dp(H);
   for (auto &z : dp) z = vector<vector<uint64_t>>(V, vector<uint64_t>(V, INF));
   using T = tuple<uint64_t, int, int, int>;
   priority_queue<T, vector<T>, greater<T>> q;
   for (int c = 0; c < 2; ++c) {
      for (int v = 0; v < V; ++v) {
         if (!terminal[v] && !terminal[go[v][c]]) {
            dp[c][v][go[v][c]] = 1;
            q.emplace(1, c, v, go[v][c]);
         }
      }
   }
   while (!q.empty()) {
      uint64_t d, x, y, z; tie(d, x, y, z) = q.top(); q.pop();
      if (dp[x][y][z] != d) continue;
      for (int nx : singles[x]) {
         if (mnm(dp[nx][y][z], dp[x][y][z])) {
            q.emplace(dp[nx][y][z], nx, y, z);
         }
      }
      for (auto db : doubles[x]) {
         int px, nx, dir;
         tie(px, nx, dir) = db;
         if (dir == 0) {
            for (int nz = 0; nz < V; ++nz) if (!terminal[nz]) {
               if (mnm(dp[px][y][nz], dp[x][y][z] + dp[nx][z][nz])) {
                  q.emplace(dp[px][y][nz], px, y, nz);
               }
            }
         } else {
            for (int ny = 0; ny < V; ++ny) if (!terminal[ny]) {
               if (mnm(dp[px][ny][z], dp[nx][ny][y] + dp[x][y][z])) {
                  q.emplace(dp[px][ny][z], px, ny, z);
               }
            }
         }
      }
   }
   for (int g = 2; g < G; ++g) {
      uint64_t ans = INF;
      for (int v = 0; v < V; ++v) if (!terminal[v]) ans = min(ans, dp[g][0][v]);
      if (ans == INF) {
         cout << "YES\n";
      } else {
         cout << "NO " << ans << '\n';
      }
   }
}