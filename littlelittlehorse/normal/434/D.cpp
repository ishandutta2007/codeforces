#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

struct node{
     node *next;
     int where, ll, idx;
} *first[20001], a[1000001];

const int oo = 1 << 30, Max = 10000000;
int len, ans, n, m, l, dist[20001], pre[20001], way[20001], c[20001], e[51][3], r[51][2], init[51], fin[51], S, T;

int calc(int i, int j){
     return e[i][0] * j * j + e[i][1] * j + e[i][2];
}

inline void makelist(int x, int y, int z){
     a[++l].where = y; a[l].ll = z; a[l].idx = l;
     a[l].next = first[x]; first[x] = &a[l];
     //printf("%d %d %d\n", x, y, z);
}

bool check(int S, int T){
     memset(dist, 0, sizeof(dist));
     dist[S] = 1; c[1] = S;
     for (int k = 1, l = 1; l <= k; l++)
     {
          int m = c[l];
          if (m == T) 
          {
               len = dist[m] + 1;
               return true;
          }
          for (node *x = first[m]; x; x = x->next)
               if (!dist[x->where] && x->ll)
               {
                    dist[x->where] = dist[m] + 1;
                    c[++k] = x->where;
               }
     }
     return false;
}

inline void dinic(int now, int S, int T){
     if (now == T)
     {
          int Minflow = oo;
          for (; now != S; now = pre[now]) Minflow = min(Minflow, a[way[now]].ll);
          ans += Minflow; //printf("! %d\n", Minflow);
          for (now = T; now != S; now = pre[now])
          {
              // printf("%d ", now);
               a[way[now]].ll -= Minflow;
               if (!a[way[now]].ll) len = dist[now];
               a[way[now] ^ 1].ll += Minflow;
          }
       //   printf("\n");
          return;
     }
     for (node *x = first[now]; x; x = x->next)
          if (x->ll && dist[now] + 1 == dist[x->where])
          {
               pre[x->where] = now; way[x->where] = x->idx;
               dinic(x->where, S, T);
               if (dist[now] >= len) return;
               len = dist[T] + 1;
          }
     dist[now] = -1;
}

int main(){
    // freopen("d.in", "r", stdin);
    // freopen("d.out", "w", stdout);
     scanf("%d%d", &n, &m);
     for (int i = 1; i <= n; i++) scanf("%d%d%d", &e[i][0], &e[i][1], &e[i][2]);
     for (int i = 1; i <= n; i++) scanf("%d%d", &r[i][0], &r[i][1]), --r[i][0];
     memset(first, 0, sizeof(first)); l = 1; S = 0; T = 0;
     for (int i = 1; i <= n; i++) 
     {
          init[i] = T + 1;
          T += r[i][1] - r[i][0] + 1; 
          fin[i] = T;
     }
     ++T;
     for (int i = 1; i <= n; i++)
     {
          makelist(S, init[i], 1 << 30); makelist(init[i], S, 0);
          for (int j = init[i], k = r[i][0]; k < r[i][1]; k++, j++)
               makelist(j, j + 1, Max - calc(i, k + 1)), makelist(j + 1, j, 0);
          makelist(fin[i], T, 1 << 30); makelist(T, fin[i], 0);
     }
     for (int i = 1; i <= m; i++)
     {
          int x, y, z;
          scanf("%d%d%d", &x, &y, &z);
          for (int j = r[x][0]; j < r[x][1]; j++)
               if (j - z >= r[y][0] && j - z <= r[y][1])
                    makelist(init[x] + j - r[x][0], init[y] + j - z - r[y][0], 1 << 30),
                    makelist(init[y] + j - z - r[y][0], init[x] + j - r[x][0], 0);
     }
     ans = 0;
     for (; check(S, T); dinic(S, S, T));
     //printf("%d\n", ans);
     printf("%d\n", Max * n - ans);
}