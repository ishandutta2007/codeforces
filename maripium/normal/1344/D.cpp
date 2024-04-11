#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
   ios_base::sync_with_stdio(false);
   int N; ll K;
   cin >> N >> K;
   vector<ll> A(N);
   for (int i = 0; i < N; ++i) {
      cin >> A[i];
   }
   ll low = -4e18, high = 4e18;
   while (low < high) {
      // cerr << low << " " << high << "\n";
      ll mid = (low + high) >> 1;
      ll sum = 0;
      for (int i = 0; i < N; ++i) {
         ll l = 0, r = A[i];
         while (l < r) {
            ll md = (l + r) >> 1;
            ll cur = A[i] - 3 * md * md - 3 * md - 1;
            if (cur <= mid) r = md;
            else l = md + 1;
         }
         sum += l;
      }
      if (sum <= K) {
         high = mid;
      } else {
         low = mid + 1;
      }
   }
   ll sum = 0;
   vector<ll> B(N);
   for (int i = 0; i < N; ++i) {
      ll l = 0, r = A[i];
         while (l < r) {
            ll md = (l + r) >> 1;
            ll cur = A[i] - 3 * md * md - 3 * md - 1;
            if (cur <= low) r = md;
            else l = md + 1;
         }
         sum += l;
         B[i] = l;
   }
   K -= sum;
   // cerr << low << "\n";
   // cerr << 4 * (-11) - 3*(-4) << "\n";
   for (int i = 0; i < N; ++i) {
      if (K && B[i] < A[i] && A[i] - 3 * B[i] * B[i] - 3 * B[i] - 1 == (low)) {
         K--;
         B[i]++;
      }
   }
   // assert(K == 0);
   for (ll z : B) cout << z << " ";
}