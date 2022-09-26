#include <bits/stdc++.h>
using namespace std;

const int N = 4e5 + 5;

int n;
long long t;
long long a[N];
int p[N][2];
int fw[N];
vector<long long> z;

void upd(int p,int v) {
   for (; p <= n + n; p += p & -p) fw[p] += v;
}

int get(int p) {
   int ret = 0;
   for (; p > 0; p -= p & -p) ret += fw[p];
   return ret;
}

int main() {
   ios_base::sync_with_stdio(false);
   cin >> n >> t;
   z.push_back(0ll);
   for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      a[i] += a[i - 1];
      z.push_back(a[i]);
      z.push_back(a[i] - t);
   }
   sort(z.begin(), z.end());
   z.resize(unique(z.begin(), z.end()) - z.begin());
   for (int i = 1; i <= n; ++i) {
      p[i][0] = lower_bound(z.begin(), z.end(), a[i]) - z.begin() + 1;
      p[i][1] = lower_bound(z.begin(), z.end(), a[i] - t) - z.begin() + 1;
   }
   int p0 = lower_bound(z.begin(), z.end(), 0ll) - z.begin() + 1;
   upd(p0, 1);
   long long ans = 0;
   for (int i = 1; i <= n; ++i) {
      ans += 1ll * get(p[i][1]);
      upd(p[i][0], 1);
   }
   ans = 1ll * n * (n + 1) / 2 - ans;
   cout << ans << '\n';
}