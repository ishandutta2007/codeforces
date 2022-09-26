#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
   int T;
   cin >> T;
   while (T--) {
      int N, K1, K2;
      cin >> N >> K1 >> K2;
      bool win = false;
      while (K1--) {
         int x;
         cin >> x;
         win |= (x == N);
      }
      while (K2--) {
         int x;
         cin >> x;
      }
      cout << (win ? "YES" : "NO") << "\n";
   }
}