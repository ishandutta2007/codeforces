#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, a[1001], v[1001], c[1001];
bool b[1001];

int main(){
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);
     scanf("%d%d", &n, &m);
     for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
     for (int i = 1; i <= m; i++) scanf("%d", &v[i]);
     memset(b, false, sizeof(b));
     int cnt = 0;
     for (int i = 1; i <= m; i++) 
          if (!b[v[i]]) b[v[i]] = true, c[++cnt] = v[i];
     int ans = 0;
     for (int i = 1; i <= m; i++)
     {
          int pos = 0;
          for (int j = 1; j <= cnt; j++)
               if (c[j] == v[i])
               {
                    pos = j;
                    break;
               }
          for (int j = pos; j; --j) c[j] = c[j - 1], ans += a[c[j]];
          c[1] = v[i];
     }
     printf("%d\n", ans);
}