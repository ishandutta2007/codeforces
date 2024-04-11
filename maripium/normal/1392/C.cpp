#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);
   int T; cin >> T;
   while (T--) {
      int N; cin >> N;
      vector<int> A(N);
      for (int &x : A) cin >> x;
      int64_t ans = 0;
      int cur = A[N-1];
      for (int i = N- 2 ; i >= 0; --i) {
         if (A[i] > cur) {
            ans += A[i] - cur;
         }
            cur = A[i];
      }
      cout << ans << '\n';
   }
}