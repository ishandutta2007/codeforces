#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
   ios_base::sync_with_stdio(false);
   int T;
   cin >> T;
   while (T--) {
      int N;
      cin >> N;
      vector<int> cnt(N);
      vector<vector<int>> opts(N);
      for (int i = 0; i < N; ++i) {
         int M, P;
         cin >> M >> P;
         cnt[M]++;
         opts[M].emplace_back(P);
      }
      for (int i = 1; i < N; ++i) {
         cnt[i] += cnt[i - 1];
      }
      multiset<int> ms;
      int cur = 0;
      ll ans = 0;
      for (int i = N - 1; i >= 0; --i) {
         for (int v : opts[i]) {
            ms.emplace(v);
         }
         int want = max(0, i - (i ? cnt[i - 1] : 0));
         while (cur < want && ms.size()) {
            ans += *ms.begin();
            cur++;
            ms.erase(ms.begin());
         }
      }
      cout << ans << "\n";
   }
}