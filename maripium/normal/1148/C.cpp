#include <bits/stdc++.h>

using namespace std;

const int N = 300300;

int n;
int a[N];
int p[N];
vector<pair<int, int>> ans;

void debug() {
   for (int i = 1; i <= n; ++i) cout << a[i] << ' '; cout << '\n';
}

void mv(int x,int y) {
   if (x == y) return;
   ans.emplace_back(x, y);
   swap(a[x], a[y]);
   swap(p[a[x]], p[a[y]]);
}

int main() {
   ios_base::sync_with_stdio(false);
   cin >> n;
   for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      p[a[i]] = i;
   }
   int m = n / 2;
   for (int i = 1; i <= n; ++i) {
      if (p[i] == i) continue;
      int to = p[i];
      if (i + (n / 2) <= to) mv(i, to);
      else if (i <= (n / 2) && to <= (n / 2)) {
         mv(to, n);
         mv(i, n);
         mv(to, n);
      } else if (i > (n / 2) && to > (n / 2)) {
         mv(1, to);
         mv(1, i);
         mv(1, to);
      } else if (i <= (n / 2) && to > n / 2) {
         mv(to, 1);
         mv(1, n);
         mv(n, i);
         mv(1, n);
         mv(to, 1);
      }
   }
   for (int i = 1; i <= n; ++i) assert(a[i] == i);
   cout << ans.size() << '\n';
   for (auto p : ans) {
      cout << p.first << ' ' << p.second << '\n';
   }
}