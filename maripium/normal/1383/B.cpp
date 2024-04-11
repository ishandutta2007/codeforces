#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);
   int T; cin >> T;
   while (T--) {
      int N; cin >> N;
      vector<int> A(N);
      for (int i = 0; i < N; ++i) cin >> A[i];
      int largest = -1;
      for (int b = 29; b >= 0; --b) {
         int cnt = 0;
         for (int i = 0; i < N; ++i) cnt += (A[i] >> b & 1);
         if (cnt % 2 == 0) {
            for (int i = 0; i < N; ++i) if (A[i] & (1 << b)) {
               A[i] ^= (1 << b);
            }
         } else {
            largest = b;
            break;
         }
      }
      if (largest == -1) {
         cout << "DRAW\n";
      } else {
         int cnt = 0;
         for (int i = 0; i < N; ++i) cnt += (A[i] >> largest) & 1;
         if (cnt % 4 == 3 && (N - cnt) % 2 == 0) {
            cout << "LOSE\n";
         } else {
            cout << "WIN\n";
         }
      }
   }
}