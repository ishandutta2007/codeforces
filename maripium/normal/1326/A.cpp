#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
   int T;
   cin >> T;
   while (T--) {
      int N;
      cin >> N;
      if (N == 1) {
         cout << "-1\n";
      } else {
         cout << "2";
         for (int i = 0; i < N - 1; ++i) cout << "3";
         cout << "\n";
      }
   }
}