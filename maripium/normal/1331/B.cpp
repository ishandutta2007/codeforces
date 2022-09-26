#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
   int N;
   cin >> N;
   for (int i = 2; i < N; ++i) {
      if (N % i == 0) {
         cout << i << N / i << "\n";
         return 0;
      }
   }
}