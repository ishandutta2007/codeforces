#include <bits/stdc++.h>

using namespace std;

int n;
int x[200100];
int y[200100];
int ft[200100];
bool added[200100];

void add(int p) {
   if (added[p]) return;
   added[p] = true;
   for (; p <= n + 1; p += p & -p) {
      ft[p]++;
   }
}

int get(int p) {
   int ans = 0;
   for (; p > 0; p -= p & -p) {
      ans += ft[p];
   }
   return ans;
}

vector<int> a[200100];

int main() {
   ios_base::sync_with_stdio(false);
   cin >> n;
   vector<int> zx;
   vector<int> zy;
   for (int i = 1; i <= n; ++i) {
      cin >> x[i] >> y[i];
      zx.push_back(x[i]);
      zy.push_back(y[i]);
   }
   sort(zx.begin(), zx.end());
   zx.resize(unique(zx.begin(), zx.end()) - zx.begin());
   sort(zy.begin(), zy.end());
   zy.resize(unique(zy.begin(), zy.end()) - zy.begin());
   for (int i = 1; i <= n; ++i) {
      int xx = upper_bound(zx.begin(), zx.end(), x[i]) - zx.begin();
      int yy = upper_bound(zy.begin(), zy.end(), y[i]) - zy.begin();
      // cout << xx << " " << yy << "\n";
      a[yy].push_back(xx);
   }
   long long ans = 0;
   for (int i = zy.size(); i > 0; --i) {
      sort(a[i].begin(), a[i].end());
      for (int j : a[i]) add(j);
      for (int j = 0; j < a[i].size(); ++j) {
         int now = a[i][j];
         int nxt = (j + 1 < a[i].size() ? a[i][j + 1] : n + 1);
         int l = get(now);
         int r = get(nxt - 1) - get(now - 1);
         // cout << l << " " << r << "\n";
         ans += (long long) l * r;
      }
   }
   cout << ans << "\n";
}