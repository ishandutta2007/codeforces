#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
   int n;
   cin >> n;
   auto is_p = [&](int x) {
      for (int i = 2; i < x; ++i) {
         if (x % i == 0) {
            return false;
         }
      }
      return true;
   };
   int m = n;
   while (!is_p(m)) {
      m++;
   }
   vector<pair<int, int>> ans;
   for (int i = 0; i < n; ++i) {
      ans.emplace_back(i, (i + 1) % n);
   }
   int h = n / 2;
   for (int i = 0; i < m - n; ++i) {
      ans.emplace_back(i, i + h);
   }
   cout << ans.size() << "\n";
   for (auto p : ans) {
      cout << p.first + 1 << " " << p.second + 1 << "\n";
   }
}