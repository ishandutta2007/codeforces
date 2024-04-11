#include <bits/stdc++.h>

using namespace std;

const int N = 300300;
const int mod = 998244353;

vector<int> g[N];
int f[N][3];

void add(int &x,int y) {
   x += y;
   if (x >= mod) x -= mod;
}

int mul(int x,int y) {
   return (long long) x * y % mod;
}

void dfs(int u,int p) {
   f[u][0] = 1;
   for (int v : g[u]) if (v != p) {
      dfs(v, u);
      f[u][2] = mul(f[u][2], mul(f[v][2], 2) + f[v][0]);
      add(f[u][2], mul(f[u][1], f[v][1] + f[v][0]));
      add(f[u][2], mul(f[u][0], f[v][1] + f[v][0]));
      f[u][1] = mul(f[u][1], mul(f[v][2], 2) + f[v][0]);
      add(f[u][1], mul(f[u][0], f[v][2]));
      f[u][0] = mul(f[u][0], f[v][2] + f[v][0]);
   }
}

int main() {
   int n;
   scanf("%d", &n);
   for (int i = 1; i < n; ++i) {
      int u, v;
      scanf("%d %d", &u, &v);
      g[u].push_back(v), g[v].push_back(u);
   }
   dfs(1, -1);
   printf("%d\n", (f[1][2] + f[1][0]) % mod);
}