#include <bits/stdc++.h>

using namespace std;

const int N = 505;
const int M = 1000100;
const int mod = 998244353;

void add(int &x, int y) {
   x += y;
   if (x >= mod) x -= mod;
}

int mul(int x, int y) {
   return (long long) x * y % mod;
}

int n, m;
int p[N];
int revp[N];
int a[M];
int le[N], ri[N];
vector<int> locs[N];
vector<int> g[N];
int go[N];
int f[N][N], sf[N][N];
int T[M << 2];
bool in[N];

void build(int v, int l, int r) {
   if (l == r) {
      T[v] = a[l];
      return;
   }
   int md = (l + r) >> 1;
   build(v << 1, l, md);
   build(v << 1 | 1, md + 1, r);
   T[v] = min(T[v << 1], T[v << 1 | 1]);
}

int get(int v, int l, int r, int L, int R) {
   if (L > r || R < l) return M;
   if (L <= l && r <= R) {
      return T[v];
   }
   int md = (l + r) >> 1;
   return min(get(v << 1, l, md, L, R), get(v << 1 | 1, md + 1, r, L, R));
}

int main() {
   ios_base::sync_with_stdio(false);
   cin >> n >> m;
   for (int i = 1; i <= m; ++i) {
      cin >> a[i];
      locs[a[i]].push_back(i);
   }
   build(1, 1, m);
   for (int i = 1; i <= n; ++i) {
      le[i] = locs[i].front();
      ri[i] = locs[i].back();
      p[i] = i;
   }
   sort(p + 1, p + n + 1, [&](int x, int y) {
      return le[x] < le[y];
   });
   for (int i = 1; i <= n; ++i) {
      for (int j = 1; j < i; ++j) {
         auto il = lower_bound(locs[j].begin(), locs[j].end(), le[i]);
         auto ir = lower_bound(locs[j].begin(), locs[j].end(), ri[i]);
         if (il != ir) {
            cout << "0\n";
            return 0;
         }
      }
   }
   for (int i = 1; i <= n; ++i) {
      for (int j = i + 1; j <= n; ++j) {
         auto il = lower_bound(locs[j].begin(), locs[j].end(), le[i]);
         auto ir = lower_bound(locs[j].begin(), locs[j].end(), ri[i]);
         if (il != ir) {
            g[i].push_back(j);
         }
      }
   }
   for (int i = 1; i <= n; ++i) {
      revp[p[i]] = i;
   }
   for (int i = 1; i <= n; ++i) {
      for (int j : g[i]) {
         go[revp[i]] = max(go[revp[i]], revp[j]);
      }
   }
   for (int l = n; l > 0; --l) {
      for (int r = l; r <= n; ++r) {
         bool fail = false;
         int lg = M, rg = 0;
         for (int i = l; i <= r; ++i) {
            int id = p[i];
            lg = min(lg, le[id]);
            rg = max(rg, ri[id]);
         }
         int md = M;
         for (int i = l; i <= r; ++i) {
            md = min(md, p[i]);
         }
         md = revp[md];
         if (get(1, 1, m, lg, rg) < p[md]) {
            fail = true;
         }
         if (go[md] > r) {
            fail = true;
         }
         f[l][r] = 1;
         if (l < md) {
            f[l][r] = mul(f[l][r], sf[l][md - 1]);
         }
         if (md < r) {
            f[l][r] = mul(f[l][r], sf[md + 1][r]);
         }
         if (fail) f[l][r] = 0;
         // cout << l << " " << r << " " << f[l][r] << "\n";
         add(sf[l][r], f[l][r]);
         for (int r2 = r + 1; r2 <= n; ++r2) {
            add(sf[l][r2], mul(f[l][r], sf[r + 1][r2]));
         }
      }
   }
   cout << sf[1][n] << "\n";
}