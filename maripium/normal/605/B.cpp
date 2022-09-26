#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

struct data {
   int w, id; bool sp;
   bool operator < (const data &rhs) const {
      return (w < rhs.w) || (w == rhs.w && sp > rhs.sp);
   }
};

struct edge {
   int from, to;
};

int n, m;
data d[N];
edge e[N];
int l[N];

int main() {
   ios_base::sync_with_stdio(false);
   cin >> n >> m;
   for (int i = 1; i <= m; ++i) {
      cin >> d[i].w >> d[i].sp;
      d[i].id = i;
   }
   int r = 3, ptr = 2;
   sort(d + 1, d + 1 + m);
   for (int i = 1; i <= m; ++i) {
      if (d[i].sp == 0) {
         if (!l[r]) {
            cout << -1 << '\n';
            return 0;
         }
         e[d[i].id] = {r, l[r]++};
         if (l[r] == r) r++;
      }
      else {
         e[d[i].id] = {1, ptr};
         l[ptr++] = 2;
      }
   }
   for (int i = 1; i <= m; ++i) cout << e[i].from << ' ' << e[i].to << '\n';
}