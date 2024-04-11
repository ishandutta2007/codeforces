#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int N = 100100;

int n, m, k;
int pr[N], d[N], w[N];
map<int, ll> f[N];

void debug(map<int, ll> f) {
   for (auto p : f) {
      cout << p.first << " " << p.second << "\n";
   }
}

int main() {
   ios_base::sync_with_stdio(false);
   cin >> n >> m >> k;
   for (int i = 2; i <= n; ++i) {
      cin >> pr[i];
   }
   for (int i = 0; i < m; ++i) {
      int v;
      cin >> v;
      cin >> d[v] >> w[v];
   }
   for (int v = n; v > 1; --v) {
      if (w[v]) {
         int cw = w[v];
         auto it = f[v].insert({d[v], 0}).first;
         auto rit = next(it);
         while (cw) {
            if (rit == f[v].end()) {
               it->second += cw;
               break;
            } else if (cw < rit->second) {
               it->second += cw;
               rit->second -= cw;
               break;
            }
            cw -= rit->second;
            it->second += rit->second;
            f[v].erase(rit++);
         }
      }
      if (f[v].size() > f[pr[v]].size()) {
         f[pr[v]].swap(f[v]);
      }
      for (auto p : f[v]) {
         f[pr[v]][p.first] += p.second;
      }
   }
   ll ans = 0;
   for (auto p : f[1]) {
      ans += p.second;
   }
   cout << ans << "\n";
}