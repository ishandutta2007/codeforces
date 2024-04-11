#include <bits/stdc++.h>

using namespace std;

const int N = 200200;

int a[N], b[N];
int par[N];
set<int> s[N];

int anc(int u) {
   return par[u] == u ? u : par[u] = anc(par[u]);
}

void mrg(int u,int v) {
   u = anc(u), v = anc(v);
   if (s[u].size() < s[v].size()) swap(u, v);
   while (s[v].size()) {
      s[u].insert(*s[v].begin());
      s[v].erase(s[v].begin());
   }
   par[v] = u;
}

int main() {
   int n;
   scanf("%d", &n);
   for (int i = 1; i <= n; ++i) {
      scanf("%d", a + i);
      b[a[i]] = i;
   }
   for (int i = 1; i <= n; ++i) {
      par[i] = i;
      s[i].insert(a[i]);
   }
   int ans = 0;
   for (int i = 1; i <= n; ++i) {
      int p = b[i];
      bool gl = p > 1 && a[p - 1] < a[p];
      bool gr = p < n && a[p + 1] < a[p];
      if (gl && gr) {
         int u = anc(p - 1);
         int v = anc(p + 1);
         if (s[u].size() < s[v].size()) swap(u, v);
         // printf("at %d:\n", i);
         // for (int x : s[u]) printf("%d ", x); puts("");
         // for (int x : s[v]) printf("%d ", x); puts("");
         for (int x : s[v]) {
            ans += (s[u].find(i - x) != s[u].end());
         }
      }
      if (gl) mrg(p, p - 1);
      if (gr) mrg(p, p + 1);
   }
   printf("%d\n", ans);
}