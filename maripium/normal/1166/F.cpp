#include <bits/stdc++.h>

using namespace std;

const int N = 100100;

struct Val {
   map<int, int> par;
   map<int, int> color;
   map<int, array< vector<int>, 2> > comp;
   void add(int u) {
      if (par.count(u)) return;
      par[u] = u;
      color[u] = 0;
      comp[u][0].push_back(u);
   }
   int anc(int u) {
      return par[u] == u ? u : par[u] = anc(par[u]);
   }
   vector< pair<int, int> > mrg(int u,int v) {
      add(u), add(v);
      vector< pair<int, int> > ans;
      int uu = anc(u), vv = anc(v);
      if (uu == vv) {
         // printf("\n%d %d\n", uu, vv);
         if (color[u] == color[v]) {
            assert(comp[uu][0].size() && comp[uu][1].size());
            ans.emplace_back(comp[uu][0].back(), comp[uu][1].back());
         }
         return ans;
      }
      int rot = color[u] ^ color[v] ^ 1;
      if (comp[uu][0].size() + comp[uu][1].size() < comp[vv][0].size() + comp[vv][1].size()) swap(uu, vv);
      if (comp[uu][0].size() && comp[vv][rot].size()) ans.emplace_back(comp[uu][0].back(), comp[vv][rot].back());
      if (comp[uu][1].size() && comp[vv][rot ^ 1].size()) ans.emplace_back(comp[uu][1].back(), comp[vv][rot ^ 1].back());
      par[vv] = uu;
      for (int w : comp[vv][rot]) {
         color[w] = 0;
         comp[uu][0].push_back(w);
      }
      for (int w : comp[vv][rot ^ 1]) {
         color[w] = 1;
         comp[uu][1].push_back(w);
      }
      return ans;
   }
   void dbg() {
      for (auto p : color) {
         printf("color of %d is : %d\n", p.first, p.second);
      }
   }
};

Val a[N];
int par[N];
set<int> comp[N];
set<int> go[N];

int anc(int u) {
   return par[u] == u ? u : par[u] = anc(par[u]);
}

void mrg(int u,int v) {
   // printf("\n%d %d\n", u, v);
   u = anc(u), v = anc(v);
   if (u == v) return;
   if (comp[u].size() + go[u].size() < comp[v].size() + go[v].size()) swap(u, v);
   par[v] = u;
   for (int w : comp[v]) {
      comp[u].insert(w);
      if (go[u].count(w)) go[u].erase(w);
   }
   for (int w : go[v]) {
      go[u].insert(w);
      if (comp[u].count(w)) comp[u].erase(w);
   }
}

void add(int x,int y,int z) {
   auto cur = a[z].mrg(x, y);
   // a[z].dbg();
   for (auto p : cur) mrg(p.first, p.second);
   if (anc(x) != anc(y)) {
      go[anc(x)].insert(y);
      go[anc(y)].insert(x);
   }
}

int main() {
   int n, m, c, q;
   scanf("%d %d %d %d", &n, &m, &c, &q);
   for (int i = 1; i <= n; ++i) {
      par[i] = i;
      comp[i].insert(i);
   }
   for (int i = 1; i <= m; ++i) {
      int x, y, z;
      scanf("%d %d %d", &x, &y, &z);
      add(x, y, z);
   }
   while (q--) {
      char t; scanf(" %c", &t);
      if (t == '?') {
         int x, y;
         scanf("%d %d", &x, &y);
         x = anc(x);
         puts(comp[x].count(y) || go[x].count(y) ? "Yes" : "No");
      } else {
         int x, y, z;
         scanf("%d %d %d", &x, &y, &z);
         add(x, y, z);
      }
   }
}