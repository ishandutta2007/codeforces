#include <bits/stdc++.h>

using namespace std;

const int N = 2020;
const int mod = 998244353;

void add(int &x,int y) {
   x += y;
   if (x >= mod) x -= mod;
}

char s[N];
vector<pair<int, int>> g[N];

void add(int u,int v,int t) {
   g[u].push_back({v, t});
   g[v].push_back({u, t});
}

int color[N];

bool dfs(int u) {
   for (auto e : g[u]) {
      int v = e.first, t = e.second;
      if (~color[v]) {
         if (color[u] ^ color[v] ^ t) {
            return false;
         }
         continue;
      }
      color[v] = color[u] ^ t;
      if (!dfs(v)) return false;
   }
   return true;
}

int main() {
   scanf("%s", s + 1);
   int n = strlen(s + 1);
   int ans = 0;
   for (int len = 1; len < n; ++len) {
      for (int i = 1; i <= 2 * n + 2; ++i) {
         g[i].clear();
         color[i] = -1;
      }
      add(2 * n + 1, 2 * n + 2, 1);
      add(2 * n + 2, 1, 0);
      add(2 * n + 2, n + n - len + 1, 0);
      for (int i = 1; i <= n - len; ++i) {
         add(2 * n + 1, n + i, 0);
      }
      for (int i = 1; i <= n; ++i) {
         int j = n + 1 - i;
         if (i < j) add(i, j, 0);
      }
      for (int i = n - len + 1; i <= n; ++i) {
         int j = n - len + 1 + n - i;
         if (i < j) add(n + i, n + j, 0);
      }
      for (int i = 1; i <= n; ++i) {
         if (s[i] != '?') add(i, n + i, s[i] - '0');
      }
      int comp = 0;
      bool ok = true;
      for (int i = 1; i <= 2 * n + 2; ++i) {
         if (color[i] == -1) {
            color[i] = 0;
            if (!dfs(i)) { ok = false; break; }
            ++comp;
         }
      }
      if (!ok) continue;
      --comp;
      int cur = 1;
      for (int i = 0; i < comp; ++i) add(cur, cur);
      add(ans, cur);
   }
   printf("%d\n", ans);
}