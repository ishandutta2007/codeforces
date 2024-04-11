#include <bits/stdc++.h>

using namespace std;

const int N = 100100;
const int mod = 1000000007;

int n, m, s, t;
vector< pair<int, int> > g[N];
int dist[N], par[N];
bool visit[N];
int pw[N];
int hs[N << 7], fz[N << 7];
int tl[N << 7], tr[N << 7];
int root0, root1;

void out(int v,int l,int r) {
   if (l == r) {
      cout << hs[v];
      return;
   }
   int md = (l + r) >> 1;
   out(tr[v], md + 1, r);
   out(tl[v], l, md);
}

void mrg(int v,int l,int r) {
   int md = (l + r) >> 1;
   hs[v] = (1LL * hs[tr[v]] * pw[md - l + 1] % mod + hs[tl[v]]) % mod;
   fz[v] = fz[tl[v]] != -1 ? fz[tl[v]] : fz[tr[v]];
}

int tot;

int build(int l,int r,int val) {
   int v = ++tot;
   if (l == r) {
      hs[v] = val;
      fz[v] = val == 0 ? l : -1;
      return v;
   }
   int md = (l + r) >> 1;
   tl[v] = build(l, md, val);
   tr[v] = build(md + 1, r, val);
   mrg(v, l, r);
   return v;
}

int nxt(int v) {
   ++tot;
   hs[tot] = hs[v], fz[tot] = fz[v];
   tl[tot] = tl[v], tr[tot] = tr[v];
   return tot;
}

int mdf(int v,int l,int r,int L,int R,int bef) {
   if (L > r || R < l) return v;
   if (L <= l && r <= R) return bef;
   int md = (l + r) >> 1;
   int u = nxt(v);
   tl[u] = mdf(tl[u], l, md, L, R, tl[bef]);
   tr[u] = mdf(tr[u], md + 1, r, L, R, tr[bef]);
   mrg(u, l, r);
   return u;
}

int cmp(int v,int u,int l,int r) {
   if (hs[v] == hs[u]) return 0;
   if (l == r) {
      if (hs[v] < hs[u]) return 1;
      return -1;
   }
   int md = (l + r) >> 1;
   if (hs[tr[v]] != hs[tr[u]]) return cmp(tr[v], tr[u], md + 1, r);
   return cmp(tl[v], tl[u], l, md);
}

int get(int v,int l,int r,int L,int R) {
   if (L > r || R < l) return -1;
   if (L <= l && r <= R) return fz[v];
   int md = (l + r) >> 1;
   int ans = get(tl[v], l, md, L, R);
   if (ans == -1) ans = get(tr[v], md + 1, r, L, R);
   return ans;
}

struct my_cmp {
   bool operator()(const pair<int, int> &u, const pair<int, int> &v) {
      int ans = cmp(u.first, v.first, 0, N);
      if (ans == 0) return u.second < v.second;
      return ans > 0;
   }
};

set< pair<int, int>, my_cmp> st;

int main() {
   ios_base::sync_with_stdio(false);

   cin >> n >> m;

   for (int i = 0; i < m; ++i) {
      int u, v, x; cin >> u >> v >> x;

      g[u].emplace_back(v, x);
      g[v].emplace_back(u, x);
   }

   cin >> s >> t;
   pw[0] = 1;
   for (int i = 1; i < N; ++i) pw[i] = pw[i - 1] * 2 % mod;
   root0 = build(0, N, 0);
   root1 = build(0, N, 1);

   for (int i = 1; i <= n; ++i) dist[i] = root1, st.insert(make_pair(dist[i], i));

   auto mv = [&](int u,int d) {
      if (cmp(d, dist[u], 0, N) > 0) {
         st.erase(make_pair(dist[u], u));
         dist[u] = d;
         st.insert(make_pair(dist[u], u));
         return true;
      }
      return false;
   };

   // cout << hs[root1] << "\n";
   mv(s, root0);
   while (!st.empty()) {
      int u = st.begin()->second;
      st.erase(st.begin());
      for (auto e : g[u]) {
         int v, x; tie(v, x) = e;
         int nw = dist[u];
         int p = get(nw, 0, N, x, N);
         nw = mdf(nw, 0, N, p, p, root1);
         if (p > x) nw = mdf(nw, 0, N, x, p - 1, root0);

         if (mv(v, nw)) {
            par[v] = u;
         }
      }
   }

   if (dist[t] == root1) return cout << -1 << '\n',0;

   cout << hs[dist[t]] << "\n";
   deque<int> path;

   for (; ; t = par[t]) {
      path.push_front(t);
      if (t == s) break;
   }
   cout << path.size() << "\n";
   for (int v : path) cout << v << ' ';
}