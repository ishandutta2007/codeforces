#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);
   int T;
   cin >> T;
   while (T--) {
      ll A, B, N;
      cin >> A >> B >> N;
      if (A > B) swap(A, B);
      int ans = 0;
      while (B <= N) {
            ++ans;
         ll C = A + B;
         A = B;
         B = C;
      }
      cout << ans << "\n";
   }
}