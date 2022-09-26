#include <bits/stdc++.h>

using namespace std;

const int N = 200200;

int n, m;
int cnt[N], cnt2[N];
vector<int> a[N];

void yes() {
   cout << "YES\n"; exit(0);
}

void no() {
   cout << "NO\n"; exit(0);
}

int get(vector<int> a) {
   int sz = a.size();
   sort(a.begin(), a.end());
   auto check = [&](int d) {
      if (n % d) return false;
      vector<int> b;
      for (int x : a) b.push_back((x + d) % n);
      sort(b.begin(), b.end());
      return b == a;
   };
   for (int i = 1; i < sz; ++i) {
      if (sz % i == 0) {
         int d = a[i] - a[0];
         if (check(d)) return d;
      }
   }
   return -1;
}

void check() {
   if (n % 2) return;
   for (int d = 1; d <= n / 2; ++d) {
      sort(a[d].begin(), a[d].end());
      vector<int> b;
      for (int x : a[d]) b.push_back((x + (n / 2)) % n);
      sort(b.begin(), b.end());
      if (a[d] != b) return;
   }
   yes();
}

int main() {
   ios_base::sync_with_stdio(false);
   cin >> n >> m;
   for (int i = 0; i < m; ++i) {
      int u, v; cin >> u >> v;
      --u, --v;
      if (u > v) swap(u, v);
      int d = v - u;
      // cout << d << ' ' << u << ' ' << v << '\n';
      if (2 * d == n) {
         a[d].push_back(u);
         a[d].push_back(v);
         continue;
      }
      if (2 * d > n) swap(u, v), d = n - d;
      a[d].push_back(u);
   }
   check();
   for (int d = 1; d <= n / 2; ++d) if (a[d].size()) {
      int g = get(a[d]);
      if (g == -1) no();
      cnt[g] += a[d].size();
   }
   for (int i = 1; i <= n; ++i) {
      for (int j = i; j <= n; j += i) cnt2[j] += cnt[i];
   }
   for (int i = 1; i < n; ++i) if (cnt2[i] == m) yes();
   no();
}