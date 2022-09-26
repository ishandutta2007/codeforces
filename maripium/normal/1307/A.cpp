#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
   int T;
   cin >> T;
   while (T--) {
      int N, D;
      cin >> N >> D;
      vector<int> A(N);
      for (int i = 0; i < N; ++i) cin >> A[i];
      for (int i = 1; i < N; ++i) {
         int add = min(D / i, A[i]);
         D -= add * i;
         A[0] += add;
      }
      cout << A[0] << "\n";
   }
}