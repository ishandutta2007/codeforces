#include <bits/stdc++.h>

using namespace std;

#define int long long
const int MAXN = 300300;

int N, M;
char S[MAXN];
int par[MAXN];
int cnt[MAXN][2];
bool color[MAXN];
int totCost;
vector<int> comp[MAXN];
vector<int> At[MAXN];

int getPar(int v) {
   if (par[v] != v) {
      par[v] = getPar(par[v]);
   }
   return par[v];
}

void update(int v, int delta) {
   // cerr << delta << " " << min(cnt[v][0], cnt[v][1]) << "\n";
   totCost += delta * min(cnt[v][0], cnt[v][1]);
}

void merg(int v, int u, bool f) {
   int fv = getPar(v);
   int fu = getPar(u);
   if (fv == fu) {
      return;
   }
   update(fv, -1);
   update(fu, -1);
   if (comp[fv].size() < comp[fu].size()) {
      swap(fv, fu);
   }
   if (color[v] ^ color[u] ^ f) {
      swap(cnt[fu][0], cnt[fu][1]);
      for (int z : comp[fu]) {
         color[z] ^= 1;
      }
   }
   cnt[fv][0] += cnt[fu][0];
   cnt[fv][1] += cnt[fu][1];
   update(fv, +1);
   par[fu] = fv;
   while (comp[fu].size()) {
      comp[fv].emplace_back(comp[fu].back());
      comp[fu].pop_back();
   }
}

int32_t main() {
   ios_base::sync_with_stdio(false);
   cin >> N >> M >> (S + 1);
   for (int i = 1; i <= M; ++i) {
      int sz;
      cin >> sz;
      while (sz--) {
         int v;
         cin >> v;
         At[v].emplace_back(i);
      }
      par[i] = i;
      cnt[i][0] = 1;
      color[i] = 0;
      comp[i].emplace_back(i);
   }
   for (int i = 1; i <= N; ++i) {
      // cerr << S[i] << "#\n";
      assert(At[i].size() <= 2);
      if (At[i].size() == 2) {
         merg(At[i][0], At[i][1], S[i] == '0');
      } else if (At[i].size() == 1) {
         int v = At[i][0];
         int fv = getPar(v);
         update(fv, -1);
         if (S[i] == '0') {
            cnt[fv][color[v] ^ 1] += MAXN;
         } else {
            cnt[fv][color[v]] += MAXN;
         }
         update(fv, +1);
      }
      cout << totCost << "\n";
   }
}