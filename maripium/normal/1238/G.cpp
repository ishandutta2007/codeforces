#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
   ios_base::sync_with_stdio(false);
   int tt;
   cin >> tt;
   while (tt--) {
      int n, m, c, c0;
      cin >> n >> m >> c >> c0;
      vector<tuple<int, int, int>> frs;
      frs.emplace_back(0, c0, 0);
      for (int i = 0; i < n; ++i) {
         int t, a, b;
         cin >> t >> a >> b;
         frs.emplace_back(t, a, b);
      }
      frs.emplace_back(m, 0, 0);
      sort(frs.begin(), frs.end());
      ll ans = 0;
      int tot_opts = 0;
      map<int, int> opts;
      bool fail = false;
      for (int i = 0; i <= n; ++i) {
         int t, a, b;
         tie(t, a, b) = frs[i];
         opts[b] += a;
         tot_opts += a;
         while (tot_opts > c) {
            auto z = (--opts.end());
            int rm = min(tot_opts - c, z->second);
            tot_opts -= rm;
            z->second -= rm;
            if (z->second == 0) {
               opts.erase(z);
            }
         }
         int diff = get<0>(frs[i + 1]) - t;
         while (diff > 0) {
            if (opts.empty()) {
               fail = true;
               break;
            }
            auto z = opts.begin();
            int ad = min(diff, z->second);
            ans += (ll) ad * z->first;
            diff -= ad;
            tot_opts -= ad;
            z->second -= ad;
            if (z->second == 0) {
               opts.erase(z);
            }
         }
         if (fail) break;
      }
      if (fail) {
         cout << "-1\n";
      } else {
         cout << ans << "\n";
      }
   }
}