#include <bits/stdc++.h>

using namespace std;

const int N = 300300;

int n;
pair<int, int> a[N];
int b[N];
vector<pair<int, int>> z;
vector<tuple<int, int, int>> ans;

int main() {
   ios_base::sync_with_stdio(false);
   cin >> n;
   for (int i = 1; i <= n; ++i) {
      cin >> a[i].first;
      a[i].second = i;
   }
   for (int i = 1; i <= n; ++i) {
      cin >> b[i];
   }
   sort(a + 1, a + n + 1);
   sort(b + 1, b + n + 1);
   for (int i = 1; i <= n; ++i) {
      int dif = b[i] - a[i].first;
      if (dif > 0) {
         z.emplace_back(a[i].second, dif);
      }
      while (dif < 0) {
         if (z.empty()) {
            cout << "NO\n";
            return 0;
         }
         int len = min(-dif, z.back().second);
         ans.emplace_back(z.back().first, a[i].second, len);
         dif += len;
         z.back().second -= len;
         if (z.back().second == 0) {
            z.pop_back();
         }
      }
   }
   if (z.size()) {
      cout << "NO\n";
      return 0;
   }
   cout << "YES\n" << ans.size() << '\n';
   for (auto p : ans) {
      cout << get<0>(p) << ' ' << get<1>(p) << ' ' << get<2>(p) << '\n';
   }
}