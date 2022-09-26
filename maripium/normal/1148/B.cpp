#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
   int n, m, ta, tb, k;
   cin >> n >> m >> ta >> tb >> k;
   vector<int> a(n), b(m);
   for (int i = 0; i < n; ++i) cin >> a[i];
   for (int i = 0; i < m; ++i) cin >> b[i];
   if (k >= n) return cout << -1,0;
   for (int i = 0; i < n; ++i) {
      int id = lower_bound(b.begin(), b.end(), a[i] + ta) - b.begin();
      if (i + m - id <= k) return cout << -1,0;
   }
   int ans = 0;
   for (int i = 0; i < n; ++i) {
      if (i > k) continue;
      int id = lower_bound(b.begin(), b.end(), a[i] + ta) - b.begin();
      if (id == m) continue;
      id = id + (k - i);
      ans = max(ans, b[id] + tb);
   }
   cout << ans << '\n';
}