#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
   int n, m;
   cin >> n >> m;
   m *= 8;
   m /= n;
   m = min(m, 20);
   m = 1 << m;
   map<int, int> cnt;
   for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      cnt[x]++;
   }
   vector<int> a;
   for (auto p : cnt) {
      a.push_back(p.second);
   }
   // for (int v : a) cout << v << " "; cout << "\n";
   n = a.size();
   vector<int> pref(n + 1);
   for (int i = 0; i < n; ++i) {
      pref[i + 1] = pref[i] + a[i];
   }
   int ans = 0;
   for (int i = 0; i < n; ++i) {
      ans = max(ans, pref[min(n, i + m)] - pref[i]);
   }
   cout << pref[n] - ans << "\n";
   return 0;
}