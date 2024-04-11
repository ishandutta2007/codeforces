#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);
   int T;
   cin >> T;
   while (T--) {
      int nr, ng, nb;
      cin >> nr >> ng >> nb;
      vector<int> R(nr), G(ng), B(nb);
      auto sq = [&](int x) -> ll {
         return ll(x) * x;
      };
      auto eval = [&](int x, int y, int z) -> ll{
         return sq(x - y) + sq(y - z) + sq(z - x);
      };
      ll ans = 4e18;
      for (int &r : R) cin >> r;
      for (int &g : G) cin >> g;
      for (int &b : B) cin >> b;
      sort(R.begin(), R.end());
      sort(G.begin(), G.end());
      sort(B.begin(), B.end());
      auto solve = [&](int x) {
         int ir = lower_bound(R.begin(), R.end(), x) - R.begin();
         int ig = lower_bound(G.begin(), G.end(), x) - G.begin();
         int ib = lower_bound(B.begin(), B.end(), x) - B.begin();
         for (int jr = ir - 1; jr <= ir + 1; ++jr) {
            for (int jg = ig - 1; jg <= ig + 1; ++jg) {
               for (int jb = ib - 1; jb <= ib + 1; ++jb) {
                  if (jr >= 0 && jr < nr && jg >= 0 && jg < ng && jb >= 0 && jb < nb) {
                     ans = min(ans, eval(R[jr], G[jg], B[jb]));
                  }
               }
            }
         }
      };
      for (int v : R) solve(v);
      for (int v : G) solve(v);
      for (int v : B) solve(v);
      cout << ans << "\n";
   }
}