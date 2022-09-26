#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
   int N;
   cin >> N;
   vector<int> zid(11, -1);
   map< pair<int, int>, int> mem;
   auto ask = [&](int i, int j) {
      if (i > j) swap(i, j);
      if (mem.count({i, j})) return mem[{i, j}];
      cout << "? " << i + 1 << " " << j + 1 << endl;
      int ans;
      cin >> ans;
      return mem[{i, j}] = ans;
   };
   mt19937 rng(1403);
   while (count(zid.begin(), zid.end(), -1)) {
      int x = -1, y = -1;
      while (x == y) {
         x = rng() % N;
         y = rng() % N;
      }
      int cur = ask(x, y);
      for (int b = 0; b < 11; ++b) {
         if (zid[b] == -1 && !(cur & (1 << b))) {
            zid[b] = x;
         }
      }
   }
   auto val = [&](int i) {
      int ans = ~0;
      for (int b = 0; b < 11; ++b) {
         int cur;
         if (i == zid[b]) cur = ~(1 << b);
         else cur = ask(i, zid[b]);
         ans &= cur;
      }
      return ans;
   };
   int id = 0;
   int cur = val(0);
   for (int i = 1; i < N; ++i) {
      if (ask(i, id) == cur) {
         id = i;
         cur = val(id);
      }
   }
   vector<int> ans(N);
   for (int i = 0; i < N; ++i) {
      if (i == id) ans[i] = 0;
      else ans[i] = ask(i, id);
   }
   cout << "! ";
   for (int v : ans) cout << v << " ";
   cout << endl;
}