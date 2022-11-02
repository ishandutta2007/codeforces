#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

struct node{
     node *next;
     int where;
} *first[300001], a[1000001];
int f[300001], l, n, m, Q, ans[300001], c[300001], dist[300001];

int gf(int i){
     if (f[i] == i) return i;
     return f[i] = gf(f[i]);
}

inline void makelist(int x, int y){
     a[++l].where = y;
     a[l].next = first[x];
     first[x] = &a[l];
}

pair<int, int> bfs(int S){
     dist[S] = 1; c[1] = S; int Max = 0, position = 0;
     int k = 1;
     for (int l = 1; l <= k; l++)
     {
          int m = c[l];
          if (dist[m] > Max) Max = dist[m], position = m;
          for (node *x = first[m]; x; x = x->next)
               if (!dist[x->where]) dist[x->where] = dist[m] + 1, c[++k] = x->where;
     }
     for (int i = 1; i <= k; i++) dist[c[i]] = 0;
     return make_pair(position, Max);
}
     
inline void work(int now){
     ans[now] = bfs(bfs(now).first).second - 1;
}

int main(){
     //freopen("c.in", "r", stdin);
     //freopen("c.out", "w", stdout);
     scanf("%d%d%d", &n, &m, &Q);
     memset(first, 0, sizeof(first));
     l = 0;
     for (int i = 1; i <= n; i++) f[i] = i, ans[i] = 0;
     for (int i = 1; i <= m; i++)
     {
          int x, y;
          scanf("%d%d", &x, &y);
          makelist(x, y); makelist(y, x);
          f[gf(x)] = gf(y);
     }
     memset(dist, 0, sizeof(dist));
     for (int i = 1; i <= n; i++)
          if (f[i] == i) work(i);
     for (;Q--;)
     {
          int type;
          scanf("%d", &type);
          int x, y;
          if (type == 1)
          {
               scanf("%d", &x);
               printf("%d\n", ans[gf(x)]);
          }
          else
          {
               scanf("%d%d", &x, &y);
               if (gf(x) != gf(y))
               {
                    int value1 = ans[gf(x)], value2 = ans[gf(y)];
                    ans[gf(x)] = max(value1, value2);
                    ans[gf(x)] = max(ans[gf(x)], (value1 + 1) / 2 + (value2 + 1) / 2 + 1);
                    f[gf(y)] = gf(x);
               }
          }
     }
}