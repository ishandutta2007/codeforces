#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);
   int T;
   cin >> T;
   while (T--) {
      int N, K;
      cin >> N >> K;
      vector<int> A(N);
      bool has = false;
      for (int i = 0; i < N; ++i) {
         cin >> A[i];
         if (A[i] == K) has = true;
      }
      if (!has) {
         cout << "no\n";
         continue;
      }
      bool ans = false;
      for (int i = 0; i + 1 < N; ++i) {
         if (A[i] >= K && A[i + 1] >= K) {
            ans = true;
         }
      }
      for (int i = 0; i + 2 < N; ++i) {
         if (A[i] >= K && A[i + 2] >= K) {
            ans = true;
         }
      }
      if (N == 1) ans = true;
      if (ans) cout << "yes\n";
      else cout << "no\n";
   }
}