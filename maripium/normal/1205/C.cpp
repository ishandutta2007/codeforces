#include <bits/stdc++.h>

using namespace std;

int qs;
int ask(int xl, int yl, int xr, int yr) {
   ++qs;
   cout << "? " << xl + 1 << " " << yl + 1 << " " << xr + 1 << " " << yr + 1 << "\n";
   cout.flush();
   int ans;
   cin >> ans;
   return ans;
}

int main() {
   int n;
   cin >> n;
   vector<vector<int>> ans(n, vector<int>(n));
   ans[0][0] = 1;
   auto inside = [&](int x, int y) {
      return x >= 0 && x < n && y >= 0 && y < n;
   };
   for (int x = 0; x < n; ++x) {
      for (int y = 0; y < n; ++y) {
         if (x == 0 && y == 0) continue;
         if (x == n - 1 && y == n - 1) continue;
         if (x + y & 1) continue;
         int xx, yy;
         if (inside(x - 2, y)) xx = x - 2, yy = y;
         else if (inside(x - 1, y - 1)) xx = x - 1, yy = y - 1;
         else xx = x, yy = y - 2;
         ans[x][y] = ans[xx][yy] ^ ask(xx, yy, x, y) ^ 1;
      }
   }
   vector<vector<pair<int, int>>> g(n * n);
   auto conv = [&](int x, int y) {
      return x * n + y;
   };
   auto add_edge = [&](int x, int y, int xx, int yy) {
      int cur = ask(x, y, xx, yy);
      int v = conv(x, y);
      int u = conv(xx, yy);
      cur ^= 1;
      g[v].emplace_back(u, cur);
      g[u].emplace_back(v, cur);
   };
   for (int x = 0; x < n; ++x) {
      for (int y = x & 1 ^ 1; y + 2 < n; y += 2) {
         add_edge(x, y, x, y + 2);
      }
   }
   for (int y = 0; y < 2; ++y) {
      for (int x = y & 1 ^ 1; x + 2 < n; x += 2) {
         add_edge(x, y, x + 2, y);
      }
   };
   add_edge(0, 1, 1, 2);
   vector<int> color(n * n, -1);
   function<void(int)> dfs = [&](int v) {
      for (auto e : g[v]) {
         int u = e.first;
         int w = e.second;
         if (color[u] == -1) {
            color[u] = color[v] ^ w;
            dfs(u);
         }
      }
   };
   color[1] = 0;
   dfs(1);
   for (int x = 0; x < n; ++x) {
      for (int y = x & 1 ^ 1; y < n; y += 2) {
         ans[x][y] = color[conv(x, y)];
      }
   }
   int px = -1, py = -1, qx = -1, qy = -1;
   for (int x = 0; x < n; ++x) {
      for (int y = 0; y < n; ++y) {
         if (x < n - 1 && ans[x][y] == ans[x + 1][y]) {
            vector<pair<int, int>> befs = {{x - 1, y}, {x, y - 1}};
            vector<pair<int, int>> afts = {{x + 2, y}, {x + 1, y + 1}};
            for (auto p : befs) {
               int xx, yy;
               tie(xx, yy) = p;
               if (!inside(xx, yy)) continue;
               for (auto q : afts) {
                  int xxx, yyy;
                  tie(xxx, yyy) = q;
                  if (!inside(xxx, yyy)) continue;
                  if (ans[xx][yy] == ans[xxx][yyy]) {
                     px = xx, py = yy, qx = xxx, qy = yyy;
                  }
               }
            }
            if (y < n - 1 && ans[x][y] == ans[x][y + 1]) {
               vector<pair<int, int>> befs = {{x - 1, y}, {x, y - 1}};
               vector<pair<int, int>> afts = {{x + 1, y + 1}, {x, y + 2}};
               for (auto p : befs) {
                  int xx, yy;
                  tie(xx, yy) = p;
                  if (!inside(xx, yy)) continue;
                  for (auto q : afts) {
                     int xxx, yyy;
                     tie(xxx, yyy) = q;
                     if (!inside(xxx, yyy)) continue;
                     if (ans[xx][yy] == ans[xxx][yyy]) {
                        px = xx, py = yy, qx = xxx, qy = yyy;
                     }
                  }
               }
            }
         }
      }
   }
   if (px != -1) {
      bool q = ask(px, py, qx, qy);
      if (!q) {
         for (int x = 0; x < n; ++x) {
            for (int y = x & 1 ^ 1; y < n; y += 2) {
               ans[x][y] ^= 1;
            }
         }
      }
      cout << "! " << "\n";
      for (auto vv : ans) {
         for (int v : vv) {
            cout << v;
         }
         cout << "\n";
      }
      return 0;
   }
   for (int x = 0; x < n; ++x) {
      for (int y = x & 1 ^ 1; y < n; y += 2) {
         ans[x][y] ^= 1;
      }
   }
   for (int x = 0; x < n; ++x) {
      for (int y = 0; y < n; ++y) {
         if (x < n - 1 && ans[x][y] == ans[x + 1][y]) {
            vector<pair<int, int>> befs = {{x - 1, y}, {x, y - 1}};
            vector<pair<int, int>> afts = {{x + 2, y}, {x + 1, y + 1}};
            for (auto p : befs) {
               int xx, yy;
               tie(xx, yy) = p;
               if (!inside(xx, yy)) continue;
               for (auto q : afts) {
                  int xxx, yyy;
                  tie(xxx, yyy) = q;
                  if (!inside(xxx, yyy)) continue;
                  if (ans[xx][yy] == ans[xxx][yyy]) {
                     px = xx, py = yy, qx = xxx, qy = yyy;
                  }
               }
            }
            if (y < n - 1 && ans[x][y] == ans[x][y + 1]) {
               vector<pair<int, int>> befs = {{x - 1, y}, {x, y - 1}};
               vector<pair<int, int>> afts = {{x + 1, y + 1}, {x, y + 2}};
               for (auto p : befs) {
                  int xx, yy;
                  tie(xx, yy) = p;
                  if (!inside(xx, yy)) continue;
                  for (auto q : afts) {
                     int xxx, yyy;
                     tie(xxx, yyy) = q;
                     if (!inside(xxx, yyy)) continue;
                     if (ans[xx][yy] == ans[xxx][yyy]) {
                        px = xx, py = yy, qx = xxx, qy = yyy;
                     }
                  }
               }
            }
         }
      }
   }
   bool q = ask(px, py, qx, qy);
      if (!q) {
         for (int x = 0; x < n; ++x) {
            for (int y = x & 1 ^ 1; y < n; y += 2) {
               ans[x][y] ^= 1;
            }
         }
      }
      cout << "! " << "\n";
      for (auto vv : ans) {
         for (int v : vv) {
            cout << v;
         }
         cout << "\n";
      }
      return 0;
}