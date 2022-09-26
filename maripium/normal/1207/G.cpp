#include <bits/stdc++.h>

using namespace std;

const int N = 400400;

int n, m;
vector<pair<int, int>> g[N];
vector<pair<int, int>> qs[N];
// Aho Corasick

int cnt;
int link[N];
int nxt[N][26];
int go[N][26];

int add(string s) {
   int cur = 0;
   for (char& c : s) {
      c -= 'a';
      if (nxt[cur][c] == 0) {
         nxt[cur][c] = ++cnt;
      }
      cur = nxt[cur][c];
   }
   return cur;
}

vector<int> ga[N];

void bfs() {
   queue<int> q;
   q.emplace(0);
   while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (int c = 0; c < 26; ++c) {
         go[v][c] = go[link[v]][c];
         int u = nxt[v][c];
         if (u) {
            link[u] = go[v][c];
            go[v][c] = u;
            q.emplace(u);
         }
      }
   }
   for (int i = 1; i <= cnt; ++i) {
      ga[link[i]].emplace_back(i);
   }
}

int tin[N], tout[N], tt;

void dfsa(int v) {
   tin[v] = ++tt;
   for (int u : ga[v]) {
      dfsa(u);
   }
   tout[v] = tt;
}

// fenwick tree

int ft[N];

void add(int p, int v) {
   for (; p < N; p += p & -p) {
      ft[p] += v;
   }
}

int get(int p) {
   int ans = 0;
   for (; p > 0; p -= p & -p) {
      ans += ft[p];
   }
   return ans;
}

int get(int l, int r) {
   return get(r) - get(l - 1);
}

int ans[N];

void dfs_ans(int v, int cur) {
   add(tin[cur], +1);
   for (auto p : qs[v]) {
      int u, id;
      tie(u, id) = p;
      ans[id] = get(tin[u], tout[u]);
   }
   for (auto p : g[v]) {
      int u, c;
      tie(u, c) = p;
      dfs_ans(u, go[cur][c]);
   }
   add(tin[cur], -1);
}

int main() {
   ios_base::sync_with_stdio(false);
   cin >> n;
   for (int i = 1; i <= n; ++i) {
      int op;
      cin >> op;
      int par;
      if (op == 1) {
         par = 0;
      } else {
         cin >> par;
      }
      char c;
      cin >> c;
      g[par].emplace_back(i, c - 'a');
   }
   cin >> m;
   for (int i = 1; i <= m; ++i) {
      int id;
      string t;
      cin >> id >> t;
      qs[id].emplace_back(add(t), i);
   }
   bfs();
   dfsa(0);
   dfs_ans(0, 0);
   for (int i = 1; i <= m; ++i) {
      cout << ans[i] << "\n";
   }
}