#include <bits/stdc++.h>

using namespace std;

const string target = "codeforces";
using ll = long long;

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);
   vector<ll> ans(10, 1);
   ll K; cin >> K;
   auto tot = [&]() {
      ll r = 1;
      for (auto z : ans) {
         r *= z;
         r = min(r, K);
      }
      return r;
   };
   while (tot() < K) {
      int id = min_element(ans.begin(), ans.end()) - ans.begin();
      ++ans[id];
   }
   for (int i = 0; i < 10; ++i) {
      cout << string(ans[i], target[i]);
   }
}