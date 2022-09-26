#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int N = 100100;
const int mod = 1000000007;

ll gcd(ll x, ll y) {
   if (x == 0) {
      return y;
   } else if (y == 0) {
      return x;
   } else {
      return __gcd(x, y);
   }
}

void add(int &x, int y) {
   x += y;
   if (x >= mod) x -= mod;
}

int mul(ll x, int y) {
   x %= mod;
   return (ll) x * y % mod;
}

int n;
ll a[N];
vector<int> g[N];
int ans;

void dfs(int v, int p, map<ll, int> cnt) {
   for (auto g : cnt) {
      add(ans, mul(g.first, g.second));
   }
   for (int u : g[v]) {
      if (u != p) {
         map<ll, int> ncnt;
         ncnt[a[u]] = 1;
         for (auto g : cnt) {
            add(ncnt[gcd(g.first, a[u])], g.second);
         }
         dfs(u, v, ncnt);
      }
   }
}

int main() {
   ios_base::sync_with_stdio(false);
   cin >> n;
   for (int i = 1; i <= n; ++i) {
      cin >> a[i];
   }
   for (int i = 0; i < n - 1; ++i) {
      int v, u;
      cin >> v >> u;
      g[v].emplace_back(u);
      g[u].emplace_back(v);
   }
   map<ll, int> cnt;
   cnt[a[1]] = 1;
   dfs(1, -1, cnt);
   cout << ans << "\n";

}