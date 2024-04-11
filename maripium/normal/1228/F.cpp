#include <bits/stdc++.h>

using namespace std;

const int N = 1 << 17;

int n, m;
vector<int> g[N];
int ds[N];
int par[N];
vector<int> diam;

void dfs1(int v, int p) {
   par[v] = p;
   ds[v] = ds[p] + 1;
   for (auto u : g[v]) {
      if (u != p) {
         dfs1(u, v);
      }
   }
}

void get1() {
   ds[0] = -1;
   dfs1(1, 0);
   int from = max_element(ds + 1, ds + m + 1) - ds;
   dfs1(from, 0);
   int to = max_element(ds + 1, ds + m + 1) - ds;
   while (to) {
      diam.emplace_back(to);
      to = par[to];
   }
}

int f[N];
vector<int> bads;

void dfs2(int v, int p) {
   // f[v]:
   // return -1 if subtree isn't full binary tree
   // return z if subtree is full binary tree with 2 ^ z - 1 nodes
   par[v] = p;
   vector<int> nxts;
   for (int u : g[v]) {
      if (u != p) {
         dfs2(u, v);
         nxts.emplace_back(f[u]);
      }
   }
   if (nxts.empty()) {
      f[v] = 1;
   } else if (nxts.size() == 2) {
      if (nxts[0] == -1 || nxts[1] == -1 || nxts[0] != nxts[1]) {
         f[v] = -1;
      } else {
         f[v] = nxts[0] + 1;
      }
   } else {
      f[v] = -1;
   }
   if (f[v] == -1) {
      bads.emplace_back(v);
   }
}

vector<int> ans;

void go(int rt) {
   bads.clear();
   dfs2(rt, 0);
   assert(bads.size());
   int cnd = bads[0];
   // cerr << cnd << "\n";
   vector<int> nxts;
   for (int u : g[cnd]) {
      if (u != par[cnd]) {
         nxts.emplace_back(f[u]);
      }
   }
   if (nxts.size() == 1) {
      // cerr << "WTF\n";
      if (nxts[0] == 1) {
         // cerr << "OK\n";
         f[cnd] = 2;
      } else {
         return;
      }
   } else if (nxts.size() == 3) {
      // x x x + 1;
      sort(nxts.begin(), nxts.end());
      if (nxts[1] == nxts[0] && nxts[2] == nxts[0] + 1) {
         f[cnd] = nxts[0] + 2;
      } else {
         return;
      }
   } else {
      return;
   }
   // cerr << "RUN\n";
   int v = par[cnd];
   // cerr << cnd << "\n";
   while (v) {
      nxts.clear();
      for (int u : g[v]) {
         if (u != par[v]) {
            nxts.emplace_back(f[u]);
         }
      }
      if (nxts.size() == 2) {
         if (nxts[0] == -1 || nxts[1] == -1 || nxts[0] != nxts[1]) {
            return;
         } else {
            f[v] = nxts[0] + 1;
         }
      } else {
         return;
      }
      v = par[v];
   }
   assert(f[rt] == n);
   ans.emplace_back(cnd);
}

int main() {
   ios_base::sync_with_stdio(false);
   cin >> n;
   m = (1 << n) - 2;
   for (int i = 0; i < m - 1; ++i) {
      int v, u;
      cin >> v >> u;
      g[v].emplace_back(u);
      g[u].emplace_back(v);
   }
   get1();
   if (diam.size() == 2 * n - 2) {
      go(diam[n - 2]);
      go(diam[n - 1]);
   } else if (diam.size() == 2 * n - 1) {
      go(diam[n - 1]);
   }
   sort(ans.begin(), ans.end());
   ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
   cout << ans.size() << "\n";
   for (int v : ans) {
      cout << v << " ";
   }
}