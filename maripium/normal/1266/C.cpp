#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
   int N, M;
   cin >> N >> M;
   if (N == 1 && M == 1) {
      cout << "0\n";
      return 0;
   }
   if (N == 1 || M == 1) {
      int ptr = 2;
      for (int i = 1; i <= N; ++i) {
         for (int j = 1; j <= M; ++j) {
            cout << ptr++ << " ";
         }
         cout << "\n";
      }
      return 0;
   }
   for (int i = 1; i <= N; ++i) {
      for (int j = N + 1; j <= N + M; ++j) {
         cout << i * j << " ";
      }
      cout << "\n";
   }
}