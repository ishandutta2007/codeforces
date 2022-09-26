#include <bits/stdc++.h>

using namespace std;

mt19937 rng(10072002);

int main() {
   ios_base::sync_with_stdio(false);
   int n, m;
   cin >> n >> m;
   int l = 1, r = m;
   vector<pair<int, int>> ans;
   ans.emplace_back(1, 1);
   while (l < r) {
      if (ans.back() == make_pair(l, 1)) {
         ans.pop_back();
         int ul = 1, dr = n;
         for (int i = 1; i <= n; ++i) {
            ans.emplace_back(l, ul);
            ans.emplace_back(r, dr);
            ul++, dr--;
         }
         ans.emplace_back(l + 1, 1);
      } else if (ans.back() == make_pair(l, n)) {
         ans.pop_back();
         int dl = n, ur = 1;
         for (int i = 1; i <= n; ++i) {
            ans.emplace_back(l, dl);
            ans.emplace_back(r, ur);
            dl--, ur++;
         }
         ans.emplace_back(l + 1, n);
      } else if (ans.back() == make_pair(r, 1)) {
         ans.pop_back();
         int ur = 1, dl = n;
         for (int i = 1; i <= n; ++i) {
            ans.emplace_back(r, ur);
            ans.emplace_back(l, dl);
            ur++; dl--;
         }
         ans.emplace_back(r - 1, 1);
      } else {
         ans.pop_back();
         int dr = n, ul = 1;
         for (int i = 1; i <= n; ++i) {
            ans.emplace_back(r, dr);
            ans.emplace_back(l, ul);
            dr--, ul++;
         }
         ans.emplace_back(r - 1, n);
      }
      l++, r--;
   }
   if (l == r) {
      int u = 1, d = n;
      if (ans.back() == make_pair(l, 1)) {
         ans.pop_back();
         int u = 1, d = n;
         while (u < d) {
            ans.emplace_back(l, u);
            u++;
            ans.emplace_back(l, d);
            d--;
         }
         if (u == d) {
            ans.emplace_back(l, u);
         }
      } else {
         ans.pop_back();
         int u = 1, d = n;
         while (u < d) {
            ans.emplace_back(l, d);
            d--;
            ans.emplace_back(l, u);
            u++;
         }
         if (u == d) {
            ans.emplace_back(l, u);
         }
      }
   }
   ans.resize(n * m);
   for (auto p : ans) {
      cout << p.second << ' ' << p.first << '\n';
   }
}