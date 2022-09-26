#include <bits/stdc++.h>

using namespace std;

const int N = 300300;
const int mod = 998244353;

int n;
pair<int, int> a[N];

int calc(int sw) {
   if (sw) {
      for (int i = 1; i <= n; ++i) {
         swap(a[i].first, a[i].second);
      }
   }
   map<int, int> cnt;
   for (int i = 1; i <= n; ++i) {
      cnt[a[i].first]++;
   }
   int ans = 1;
   for (auto p : cnt) {
      for (int i = 1; i <= p.second; ++i) {
         ans = (long long) ans * i % mod;
      }
   }
   if (sw) {
      for (int i = 1; i <= n; ++i) {
         swap(a[i].first, a[i].second);
      }
   }
   return ans;
}

int calc2() {
   sort(a + 1, a + n + 1);
   for (int i = 1; i < n; ++i) {
      if (a[i].second > a[i + 1].second) {
         return 0;
      }
   }
   map<pair<int, int>, int> cnt;
   for (int i = 1; i <= n; ++i) {
      cnt[a[i]]++;
   }
   int ans = 1;
   for (auto p : cnt) {
      for (int i = 1; i <= p.second; ++i) {
         ans = (long long) ans * i % mod;
      }
   }
   return ans;
}

int main() {
   ios_base::sync_with_stdio(false);
   cin >> n;
   int ans = 1;
   for (int i = 1; i <= n; ++i) {
      cin >> a[i].first >> a[i].second;
      ans = (long long) ans * i % mod;
   }
   ans -= calc(0);
   if (ans < 0) ans += mod;
   ans -= calc(1);
   if (ans < 0) ans += mod;
   ans += calc2();
   if (ans >= mod) ans -= mod;
   cout << ans << "\n";
}