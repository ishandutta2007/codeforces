#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);
   int N;
   cin >> N;
   int cur = 0;
   vector< pair<int, int>> ans;
   ans.emplace_back(0, 0);
   ++N;
   while (N--) {
      ans.emplace_back(cur, cur + 1);
      ans.emplace_back(cur, cur + 2);
      ans.emplace_back(cur + 1, cur);
      ans.emplace_back(cur + 1, cur + 2);
      ans.emplace_back(cur + 2, cur);
      ans.emplace_back(cur + 2, cur + 1);
      ans.emplace_back(cur + 2, cur + 2);
      cur += 2;
   }
   cout << ans.size() << "\n";
   for (auto p : ans) {
      cout << p.first << " " << p.second << "\n";
   }
}