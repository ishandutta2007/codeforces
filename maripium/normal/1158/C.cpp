#include <bits/stdc++.h>

using namespace std;

const int N = 500500;

int n;
int nxt[N];
vector<int> g[5 * N];
vector<int> topo;
int pos[N * 5];

void build(int v,int l,int r) {
   if (l == r) {
      g[v + n + 1].push_back(l);
      return;
   }
   int md = (l + r) >> 1;
   g[v + n + 1].push_back((v << 1) + n + 1);
   g[v + n + 1].push_back((v << 1 | 1) + n + 1);
   build(v << 1, l, md);
   build(v << 1 | 1, md + 1, r);
}

void add(int v,int l,int r,int L,int R,int from) {
   if (L > r || R < l) return;
   if (L <= l && r <= R) {
      g[from].push_back(n + v + 1);
      return;
   }
   int md = (l + r) >> 1;
   add(v << 1, l, md, L, R, from);
   add(v << 1 | 1, md + 1, r, L, R, from);
}

int t[N << 2];

void build2(int v,int l,int r) {
   if (l == r) {
      t[v] = pos[l];
      return;
   }
   int md = (l + r) >> 1;
   build2(v << 1, l, md);
   build2(v << 1 | 1, md + 1, r);
   t[v] = min(t[v << 1], t[v << 1 | 1]);
}

int get(int v,int l,int r,int L,int R) {
   if (L > r || R < l) return N << 4;
   if (L <= l && r <= R) return t[v];
   int md = (l + r) >> 1;
   return min(get(v << 1, l, md, L, R), get(v << 1 | 1, md + 1, r, L, R));
}

bool visit[N * 5];

void dfs(int u) {
   visit[u] = true;
   for (int v : g[u]) if (!visit[v]) {
      dfs(v);
   }
   topo.push_back(u);
}

int main() {
   ios_base::sync_with_stdio(false);

   int tt; cin >> tt;
   while (tt--) {
      cin >> n;
      for (int i = 1; i <= n; ++i) {
         cin >> nxt[i];
      }
      topo.clear();
      for (int i = 1; i <= 5 * n; ++i) g[i].clear(), visit[i] = false;
      build(1, 1, n);
      for (int i = 1; i <= n; ++i) {
         if (nxt[i] == -1) continue;
         g[nxt[i]].push_back(i);
         if (nxt[i] > i + 1) add(1, 1, n, i + 1, nxt[i] - 1, i);
      }
      for (int i = 1; i <= 5 * n; ++i) if (!visit[i]) dfs(i);
      reverse(topo.begin(), topo.end());
      for (int i = 0; i < topo.size(); ++i) pos[topo[i]] = i;
      build2(1, 1, n);
      bool fl = false;
      for (int i = 1; i <= n; ++i) {
         if (nxt[i] == -1) continue;
         if (pos[nxt[i]] > pos[i]) fl = true;
         if (nxt[i] > i + 1 && pos[i] > get(1, 1, n, i + 1, nxt[i] - 1)) fl = true;
      }
      if (fl) { cout << -1 << endl; continue; }
      vector<int> topo2;
      for (int v : topo) if (v <= n) topo2.push_back(v);
      vector<int> ans(n);
      // for (int v : topo2) cout << v << ' '; cout << endl;
      for (int i = 0; i < n; ++i) {
         ans[topo2[i] - 1] = n - i;
      }
      for (int v : ans) cout << v << ' '; cout << endl;
   }
}