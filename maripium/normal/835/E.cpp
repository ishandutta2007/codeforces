#include <bits/stdc++.h>

int main() {
   std::ios_base::sync_with_stdio(false);
   int N, X, Y; std::cin >> N >> X >> Y;
   int xr = 0;
   for (int b = 0; (1 << b) < N; ++b) {
      std::vector<int> ps;
      for (int i = 0; i < N; ++i) {
         if (i & (1 << b)) ps.emplace_back(i);
      }
      std::cout << "? " << int(ps.size());
      for (int v : ps) std::cout << " " << v + 1;
      std::cout << std::endl;
      int val = (ps.size() & 1 ? X : 0);
      int ans; std::cin >> ans;
      if (ans != val) xr ^= (1 << b);
   }
   std::vector<int> ps;
   for (int i = 0; i < N; ++i) {
      int j = i ^ xr;
      if (j < N && i < j) ps.emplace_back(i);
   }
   int l = 0, r = int(ps.size()) - 1;
   while (l < r) {
      int md = (l + r) >> 1;
      std::cout << "? " << md + 1;
      for (int i = 0; i <= md; ++i) std::cout << " " << ps[i] + 1;
      std::cout << std::endl;
      int val = ((md + 1) & 1 ? X : 0);
      int ans; std::cin >> ans;
      if (ans != val) r = md;
      else l = md + 1;
   }
   std::cout << "! " << ps[l] + 1 << " " << (ps[l] ^ xr) + 1 << std::endl;
}