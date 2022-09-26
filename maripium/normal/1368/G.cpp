#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200200;

bool isRoot[MAXN];
vector<int> adj[MAXN];
vector<tuple<int, int, int>> events[MAXN];
int tin[MAXN], tout[MAXN], timer[2];

void dfs(int v, int z) {
   tin[v] = timer[z]++;
   for (int u : adj[v]) {
      dfs(u, z);
   }
   tout[v] = timer[z] - 1;
}

pair<int, int> tr[MAXN << 2];
int lazy[MAXN << 2];

void add(int v, int delta) {
   tr[v].first += delta;
   lazy[v] += delta;
}

void push(int v) {
   if (lazy[v]) {
      add(v << 1, lazy[v]);
      add(v << 1 | 1, lazy[v]);
      lazy[v] = 0;
   }
}

void pop(int v) {
   tr[v].first = min(tr[v << 1].first, tr[v << 1 | 1].first);
   tr[v].second = 0;
   if (tr[v].first == tr[v << 1].first) tr[v].second += tr[v << 1].second;
   if (tr[v].first == tr[v << 1 | 1].first) tr[v].second += tr[v << 1 | 1].second;
}

void build(int v, int l, int r) {
   if (l == r) {
      tr[v] = {0, 1};
   } else {
      int md = (l + r) >> 1;
      build(v << 1, l, md);
      build(v << 1 | 1, md + 1, r);
      pop(v);
   }
}

void modify(int v, int l, int r, int L, int R, int delta) {
   if (L <= l && r <= R) {
      add(v, delta);
      return;
   }
   push(v);
   int mid = (l + r) >> 1;
   if (L <= mid) modify(v << 1, l, mid, L, R, delta);
   if (mid < R) modify(v << 1 | 1, mid + 1, r, L, R, delta);
   pop(v);
}

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);
   int N, M; cin >> N >> M;
   vector<string> G(N);
   for (int i = 0; i < N; ++i) cin >> G[i];
   for (int x = 0; x < N; ++x) {
      for (int y = 0; y < M; ++y) {
         int nx = x, ny = y;
         if (G[x][y] == 'U') nx += 2;
         if (G[x][y] == 'D') nx -= 2;
         if (G[x][y] == 'L') ny += 2;
         if (G[x][y] == 'R') ny -= 2;
         if (0 <= nx && nx < N && 0 <= ny && ny < M) {
            adj[nx * M + ny].emplace_back(x * M + y);
         } else {
            isRoot[x * M + y] = true;
         }
      }
   }
   for (int v = 0; v < N * M; ++v) {
      if (isRoot[v]) dfs(v, ((v / M) + (v % M)) & 1);
   }
   for (int x = 0; x < N; ++x) {
      for (int y = x & 1; y < M; y += 2) {
         int nx = x, ny = y;
         if (G[x][y] == 'U') ++nx;
         if (G[x][y] == 'D') --nx;
         if (G[x][y] == 'L') ++ny;
         if (G[x][y] == 'R') --ny;
         int v = x * M + y;
         int u = nx * M + ny;
         // cerr << v << " " << u << "\n";
         events[tin[v]].emplace_back(tin[u], tout[u], +1);
         events[tout[v] + 1].emplace_back(tin[u], tout[u], -1);
      }
   }
   build(1, 0, timer[1] - 1);
   long long ans = 0;
   for (int i = 0; i < timer[0]; ++i) {
      // cerr << "at " << i << "\n";
      for (auto q : events[i]) {
         // cerr << "update " << get<0>(q) << " " << get<1>(q) << " " << get<2>(q) << "\n";
         modify(1, 0, timer[1] - 1, get<0>(q), get<1>(q), get<2>(q));
      }
      // cerr << "root data :" << tr[1].first << " " << tr[1].second << "\n";
      ans += timer[1] - (tr[1].first == 0 ? tr[1].second : 0);
   }
   cout << ans << "\n";
   return 0;
}