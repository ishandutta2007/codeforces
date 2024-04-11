#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);
   int N;
   cin >> N;
   vector<ll> cnt(20);
   for (int i = 0; i < N; ++i) {
      ll z;
      cin >> z;
      for (int b = 0; b < 20; ++b) {
         if (z & (1 << b)) ++cnt[b];
      }
   }
   vector<ll> A(N);
   for (int b = 0; b < 20; ++b) {
      for (int z = 0; z < cnt[b]; ++z) A[z] |= (1 << b);
   }
   ll ans = 0;
   for (int i = 0; i < N; ++i) {
      ans += A[i] * A[i];
   }
   cout << ans;
}