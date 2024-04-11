#include <bits/stdc++.h>

struct Node {
   int sum;
   int pref;
   void fix() {
      pref = std::min(0, sum);
   }
};

Node operator + (const Node &l, const Node &r) {
   return Node{l.sum + r.sum, std::min(l.pref, l.sum + r.pref)};
}

const int MX = 1 << 20;

Node tree[MX << 1];

void init() {
   for (int v = MX; v < 2 * MX; ++v) {
      tree[v].sum = -1;
      tree[v].fix();
   }
   for (int v = MX - 1; v >= 1; --v) {
      tree[v] = tree[v << 1] + tree[v << 1 | 1];
   }
}

void upd(int x, int d) {
   x += MX;
   tree[x].sum += d;
   tree[x].fix();
   for (x >>= 1; x > 0; x >>= 1) {
      tree[x] = tree[x << 1] + tree[x << 1 | 1];
   }
}

int query(int r) {
   Node lv = {0, 0};
   Node rv = {0, 0};
   r += MX;
   for (int l = MX; l <= r; l >>= 1, r >>= 1) {
      if (l & 1) lv = lv + tree[l++];
      if (!(r & 1)) rv = tree[r--] + rv;
   }
   Node tot = lv + rv;
   return tot.sum - tot.pref; // return tot.sum == tot.pref;
}


int main() {
   std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
   int N, K, M; std::cin >> N >> K >> M;
   std::set<std::pair<int, int>> st;
   std::multiset<int> bnd;
   bnd.insert(N);
   init();
   while (M--) {
      int x, y; std::cin >> x >> y;
      int d;
      if (st.count({x, y})) {
         d = -1;
         st.erase(std::pair<int, int>(x, y));
      } else {
         st.emplace(x, y);
         d = +1;
      }
      int z = y + abs(x - K);
      upd(z, d);
      if (d == +1) bnd.insert(z);
      else bnd.erase(bnd.find(z));
      int last = *(--bnd.end());
      std::cout << last - N + query(last) << "\n";
   }
}