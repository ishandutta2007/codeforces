#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()  {
   ios_base::sync_with_stdio(false);
   int T;
   cin >> T;
   while (T--) {
      int N;
      cin >> N;
      vector<ll> A(N);
      ll sm = 0;
      ll xr = 0;
      for (int i = 0; i < N; ++i) {
         cin >> A[i];
         sm += A[i];
         xr ^= A[i];
      }
      assert((sm + xr + sm + xr) == 2LL * (xr ^ xr ^ (sm + xr)));
      cout << "2\n" << sm + xr << " " << xr << "\n";
   }
}