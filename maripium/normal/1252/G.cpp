#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
   ll N;
   cin >> N;
   ll ans = 1;
   int cnt = 0;
   for (ll i = 2; i * i <= N; ++i) {
      if (N % i == 0) {
         ans = i;
         ++cnt;
         while (N % i == 0) {
            N /= i;
         }
      }
   }
   if (N > 1) {
      ++cnt;
      ans = N;
   }
   if (cnt == 1) {
      cout << ans << "\n";
   } else {
      cout << 1 << "\n";
   }
}