#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int MX = 10000100;

int np[MX];
int pref[MX];

void precalc() {
   for (int i = 2; i < MX; ++i) if (!np[i]) {
      for (int j = 2 * i; j < MX; j += i) {
         np[j] = true;
      }
   }
}

int main() {
   ios_base::sync_with_stdio(false);
   precalc();
   int N;
   cin >> N;
   for (int i = 0; i < N; ++i) {
      int z; cin >> z; pref[z]++;
   }
   for (int i = 1; i < MX; ++i) {
      pref[i] += pref[i - 1];
   }
   ll ans = 1;
   for (int i = 2; i < MX; ++i) if (!np[i]) {
      int pw = i;
      ll cnt = 0;
      while (true) {
         for (int l = pw; l < MX; l += pw) {
            cnt += ll(l / pw) * (pref[min(l + pw, MX) - 1] - pref[l - 1]);
         }
         if (pw > (MX / i)) break;
         pw *= i;
      }
      auto get = [&](ll x) {
         ll ans = 0;
         while (x) {
            ans += (x /= i);
         }
         return ans;
      };
      ll low = ans;
      ll high = 1e13;
      while (low < high) {
         ll mid = (low + high) >> 1;
         if (get(mid) >= cnt) {
            high = mid;
         } else {
            low = mid + 1;
         }
      }
      ans = low;
   }
   cout << ans << "\n";
   return 0;
}