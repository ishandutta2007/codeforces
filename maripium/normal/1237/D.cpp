#include <bits/stdc++.h>

using namespace std;

const int N = 300300;
const int inf = 1e9 + 123;

struct Node {
   int mn, mx;
   bool bad;
   Node() {
      mn = inf;
      mx = -inf;
      bad = false;
   }
   Node(int x) :
      mn(x), mx(x), bad(false) {}
};

Node operator + (const Node &l, const Node &r) {
   Node ans;
   ans.mn = min(l.mn, r.mn);
   ans.mx = max(l.mx, r.mx);
   ans.bad = (l.bad || r.bad || (r.mn * 2 < l.mx));
   return ans;
}

int n;
int a[N];
Node T[N << 2];

void build(int v, int l, int r) {
   if (l == r) {
      T[v] = Node(a[l]);
   } else {
      int md = (l + r) >> 1;
      build(v << 1, l, md);
      build(v << 1 | 1, md + 1, r);
      T[v] = T[v << 1] + T[v << 1 | 1];
   }
}

Node get(int v, int l, int r, int L, int R) {
   if (L > r || R < l) return Node();
   if (L <= l && r <= R) {
      return T[v];
   }
   int md = (l + r) >> 1;
   return get(v << 1, l, md, L, R) + get(v << 1 | 1, md + 1, r, L, R);
}

int solve(int p) {
   int l = p, r = 3 * n - 1;
   while (l < r) {
      int md = (l + r) >> 1;
      if (get(1, 0, 3 * n - 1, p, md).bad) {
         r = md;
      } else {
         l = md + 1;
      }
   }
   return l - p;
}

int main() {
   ios_base::sync_with_stdio(false);
   cin >> n;
   for (int i = 0; i < n; ++i) {
      cin >> a[i];
      a[i + n] = a[i + 2 * n] = a[i];
   }
   build(1, 0, 3 * n - 1);
   if (T[1].mn * 2 >= T[1].mx) {
      while (n--) {
         cout << "-1 ";
      }
      return 0;
   }
   for (int i = 0; i < n; ++i) {
      cout << solve(i) << " ";
   }
}