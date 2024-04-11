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
     int where, type;
} a[200001], *first[100001];

int n, l, dist[100001], c[100001], out[100001], size[100001], f[100001], in[100001];
long long ans = 0;

bool check(int now){
     for (; now; now /= 10)
          if ((now % 10) != 4 && (now % 10) != 7) return false;
     return true;
}

inline void makelist(int x, int y, int z){
     a[++l].where = y; a[l].type = check(z);
     a[l].next = first[x];
     first[x] = &a[l];
}

int main(){
     //freopen("e.in", "r", stdin);
     //freopen("e.out", "w", stdout);
     scanf("%d", &n); l = 0;
     memset(first, 0, sizeof(first));
     for (int i = 1; i < n; i++)
     {
          int x, y, z;
          scanf("%d%d%d", &x, &y, &z);
          makelist(x, y, z); makelist(y, x, z);
     }
     memset(dist, 0, sizeof(dist)); c[1] = 1; dist[1] = 1; 
     for (int k = 1, l = 1; l <= k; l++)
     {
          int m = c[l];
          for (node *x = first[m]; x; x = x->next)
               if (!dist[x->where]) dist[x->where] = dist[m] + 1,
               c[++k] = x->where;
     }
     for (int i = n; i; --i)
     {
          int m = c[i];
          size[m] = 1; f[m] = 0;
          for (node *x = first[m]; x; x = x->next)
               if (dist[x->where] == dist[m] + 1)
               {
                    size[m] += size[x->where];
                    if (x->type) f[m] += size[x->where];
                    else f[m] += f[x->where];
               }
     }
     out[1] = 0;
     for (int i = 1; i <= n; i++)
     {
          int m = c[i];
          for (node *x = first[m]; x; x = x->next)
               if (dist[x->where] == dist[m] + 1)
                    if (x->type) out[x->where] = n - size[x->where];
                    else out[x->where] = out[m] + f[m] - f[x->where];
     }
     for (int i = 1; i <= n; i++)
     {
          long long total = f[i] + out[i];
          ans += total * (total - 1);
          //printf("%d %I64d\n", i, total);
     }
     printf("%I64d\n", ans);
}