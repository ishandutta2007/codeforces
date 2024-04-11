#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);
   auto solve = [&](int A, int B) {
      if (A + B & 1) return -1;
      if (A == B) {
         if (A == 0) return 0;
         return 1;
      } 
      return 2;
   };
   int T; cin >> T;
   while (T--) {
      int A, B; cin >> A >> B;
      cout << solve(A, B) << '\n';
   }
   return 0;
}