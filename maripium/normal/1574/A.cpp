#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);

   int T; cin >> T;
   while (T--) {
      int N; cin >> N;
      for (int z = 0; z < N; ++z) {
         for (int i = 0; i < z; ++i) cout << "()";
         for (int i = 0; i < N-z; ++i) cout << "(";
         for (int i = 0; i < N-z; ++i) cout << ")";
         cout << '\n';
      }
   }
   return 0;
}