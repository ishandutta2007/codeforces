#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
   int n;
   cin >> n;
   vector<int> l(n);
   vector<int> r(n);
   for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      --x;
      l[x] = 2 * i;
   }
   for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      --x;
      r[x] = 2 * i + 1;
   }
   vector<pair<int, int>> ps;
   for (int i = 0; i < n; ++i) {
      ps.emplace_back(l[i], r[i]);
   }
   sort(ps.begin(), ps.end());
   int mr = -1;
   int ans = 0;
   for (auto p : ps) {
      ans += p.second < mr;
      mr = max(mr, p.second);
   }
   cout << ans << "\n";
   return 0;
}