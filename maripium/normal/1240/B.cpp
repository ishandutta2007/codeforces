#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
   int tt;
   cin >> tt;
   while (tt--) {
      int n;
      cin >> n;
      vector<int> a(n);
      vector<vector<int>> ps(n);
      for (int i = 0; i < n; ++i) {
         cin >> a[i];
         --a[i];
         ps[a[i]].emplace_back(i);
      }
      int ans = 0;
      int cur = 0;
      int lst = -1;
      int cnt = 0;
      for (int i = 0; i < n; ++i) {
         if (ps[i].size()) {
            ++cnt;
            if (ps[i].front() > lst) {
               cur++;
            } else {
               cur = 1;
            }
            ans = max(ans, cur);
            lst = ps[i].back();
         }
      }
      // cerr << "\n";
      cout << cnt - ans << "\n";
   }
}