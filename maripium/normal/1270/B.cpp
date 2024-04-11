#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
   int T;
   cin >> T;
   while (T--) {
      int N;
      cin >> N;
      vector<int> A(N);
      for (int i = 0; i < N; ++i) {
         cin >> A[i];
      }
      for (int i = 0; i < N - 1; ++i) {
         if (abs(A[i] - A[i + 1]) >= 2) {
            cout << "YES\n";
            cout << i + 1 << " " << i + 2 << "\n";
            goto next_test;
         }
      }
      cout << "NO\n";
      next_test:;
   }
}