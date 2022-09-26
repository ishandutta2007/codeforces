#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);
   int N; cin >> N;
   int B = __lg(N);
   int M = 1 << B;
   cout << M*B << '\n';
   for (int b = 0; b < B; ++b) {
      for (int i = 0; i < M; ++i) if (!(i & (1<<b))) {
         cout << i+1 << ' ' << (i | (1 << b))+1 << '\n';
      }
   }
   for (int b = 0; b < B; ++b) {
      for (int i = 0; i < M; ++i) if (!(i & (1<<b))) {
         cout << N-i << ' ' << N-(i | (1 << b)) << '\n';
      }
   }
   return 0;
}