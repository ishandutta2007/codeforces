#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);

   int T; cin >> T;
   while (T--) {
      array<int, 3> A; int N; cin >> A[0] >> A[1] >> A[2] >> N;
      sort(A.begin(), A.end(), greater<int>());
      {
         int v = min(N, A[0] - A[1]);
         N -= v;
         A[0] -= v;
      }
      {
         int v = min(A[0] - A[2], N / 2);
         A[0] -= v;
         A[1] -= v;
         N -= 2 * v;
      }
      {
         int v = min(A[0] - 1, N / 3);
         A[0] -= v;
         A[1] -= v;
         A[2] -= v;
         N -= 3 * v;
      }
      bool fail = false;
      while (N-- > 0) {
         sort(A.begin(), A.end(), greater<int>());
         if (A[0] == 1) {
            fail = true;
            break;
         } 
         A[0] -= 1;
      }
      sort(A.begin(), A.end(), greater<int>());
      if (fail || (A[0] > 1 + A[1] + A[2])) {
         cout << "NO\n";
      } else {
         cout << "YES\n";
      }
   }
   return 0;
}