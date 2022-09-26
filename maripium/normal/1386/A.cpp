#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
   ios_base::sync_with_stdio(false);
   int T; cin >> T;
   while (T--) {
      ll N; cin >> N;
      // fake
      ll low = 1, high = N;
      ll cur = 0;
      ll minv = 0;
      int cnt = 0;
      while (low < high) {
         if ((high - low + 1) & 1ll) {
            ll mid = ((low + high) >> 1);
            if (cnt & 1) cur += (mid - 1);
            else cur -= (mid - 1);
            minv = min(minv, cur);
            low = mid;
            ++cnt;
         } else {
            ll mid = (low + high) >> 1;
            if (cnt & 1) cur += mid;
            else cur -= mid;
            minv = min(minv, cur);
            low = mid + 1;
            ++cnt;
         }
      }
      cur = 1 - minv;
      cout << "? " << cur << endl;
      bool useless; cin >> useless;
      low = 1, high = N;
      cnt = 0;
      while (low < high) {
         if ((high - low + 1) & 1ll) {
            ll mid = ((low + high) >> 1);
            if (cnt & 1) cur += (mid - 1);
            else cur -= (mid - 1);
            cout << "? " << cur << endl;
            bool ans; cin >> ans;
            if (ans) {
               high = mid - 1;
            } else {
               low = mid;
            }
            ++cnt;
         } else {
            ll mid = ((low + high) >> 1);
            if (cnt & 1) cur += mid;
            else cur -= mid;
            cout << "? " << cur << endl;
            bool ans; cin >> ans;
            if (ans) {
               high = mid;
            } else {
               low = mid + 1;
            }
            ++cnt;
         }
      }
      cout << "= " << low << endl;
   }
}