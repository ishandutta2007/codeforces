#include <bits/stdc++.h>

using namespace std;

mt19937 rng(58);

int main() {
   ios_base::sync_with_stdio(false);
   int N;
   cin >> N;
   int curX, curY;
   cin >> curX >> curY;
   auto add = [&](int x) {
      cout << "+ " << x + 1 << endl;
      int newX, newY;
      cin >> newX >> newY;
      pair<int, int> ans = {newX - curX, newY - curY};
      curX = newX, curY = newY;
      return ans;
   };
   auto get = [&](int x) {
      int z = 2;
      while ((z - 1) * (z - 2) < 2 * x) z++;
      return z;
   };
   vector<int> ans(N);
   auto p0 = add(0);
   auto p1 = add(1);
   auto p2 = add(2);
   auto p3 = add(0);
   ans[0] = get(p3.first);
   if (p1.second) ans[2] = get(p2.first);
   else ans[2] = 1;
   ans[1] = p3.second / ans[2];
   int cur = p2.second - (ans[0] - 1) * ans[1];
   for (int i = 3; i < N; ++i) {
      if (i == N - 1) ans[i] = cur / ans[i - 2];
      else {
         auto p = add(i);
         if (cur) ans[i] = get(p.first);
         else ans[i] = 1;
         cur = p.second - ans[i - 2] * ans[i - 1];
      }
   }
   ans[0] -= 2;
   for (int i = 1; i + 1 < N; ++i) --ans[i];
   cout << "!";
   for (int v : ans) cout << " " << v;
   cout << endl;
   return 0;
}