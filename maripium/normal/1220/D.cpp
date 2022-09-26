#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int get(ll x) {
   int cnt = 0;
   while (x % 2 == 0) {
      cnt++;
      x /= 2;
   }
   return cnt;
}

int main() {
   ios_base::sync_with_stdio(false);
   int n;
   cin >> n;
   vector<ll> a(n);
   vector<int> cnt(60);
   for (int i = 0; i < n; ++i) {
      cin >> a[i];
      cnt[get(a[i])]++;
   }
   int mb = max_element(cnt.begin(), cnt.end()) - cnt.begin();
   vector<ll> ans;
   for (int i = 0; i < n; ++i) {
      if (get(a[i]) != mb) {
         ans.emplace_back(a[i]);
      }
   }
   cout << ans.size() << "\n";
   for (ll v : ans) cout << v << " ";
}