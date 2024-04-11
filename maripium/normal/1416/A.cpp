#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);
   int T; cin >> T;
   while (T--) {
      int N; cin >> N;
      vector<int> ans(N+2, N);
      vector<int> last(N, -1);
      vector<int> best(N, 0);
      for (int i = 0; i < N; ++i) {
         int a; cin >> a; --a;
         best[a] = max(best[a], i - last[a]);
         last[a] = i;
      }
      for (int a = 0; a < N; ++a) {
         best[a] = max(best[a], N - last[a]);
         ans[best[a]] = min(ans[best[a]], a);
      }
      for (int i = 1; i <= N; ++i) ans[i] = min(ans[i], ans[i-1]);
      for (int i = 1; i <= N; ++i) {
         if (ans[i] == N) ans[i] = -2;
         cout << ans[i]+1 << ' ';
      }
      cout << '\n';
   }
}