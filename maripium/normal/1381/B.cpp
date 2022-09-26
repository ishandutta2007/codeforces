#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);
   int T; cin >> T;
   while (T--) {
      int N; cin >> N;
      vector<int> A(2 * N);
      for (int &v : A) cin >> v;
      int mx = -1;
      int cur = 0;
      vector<bool> dp(2 * N + 1);
      dp[0] = true;
      for (int v : A) {
         if (v > mx) {
            mx = v;
            if (cur) {
               for (int i = 2 * N; i >= cur; --i) if (dp[i - cur]) dp[i] = true;
            }
            cur = 1;
         } else ++cur;
      }
      for (int i = 2 * N; i >= cur; --i) if (dp[i - cur]) dp[i] = true;
      if (dp[N]) cout << "YES\n";
      else cout << "NO\n";
   }
}