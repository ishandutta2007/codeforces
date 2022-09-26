#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);
   int T; cin >> T;
   while (T--) {
      int N; cin >> N;
      string A, B; cin >> A >> B;
      vector<int> ans;
      for (int i = N - 1; i >= 0; --i) {
         if (A[i] != B[i]) {
            ans.emplace_back(i + 1);
            ans.emplace_back(1);
            ans.emplace_back(i + 1);
         }
      }
      cout << int(ans.size());
      for (int v : ans) cout << " " << v; cout << "\n";
   }
}