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
     int where, cost;
} *first[200001], a[200001];

const int P = 1000000007;
int n, m, l, c[200001], father[200001][21], dist[200001];
long long f[200001], size[200001], v[200001], W[200001], F[200001], V[200001];

inline void makelist(int x, int y, int z){
     a[++l].where = y;
     a[l].next = first[x];
     a[l].cost = z;
     first[x] = &a[l];
}

int lca(int x, int y){
     if (dist[x] < dist[y]) swap(x, y);
     int will = dist[x] - dist[y];
     for (int step = 0; will;step++, will >>= 1)
          if (will & 1) x = father[x][step];
     if (x == y) return x;
     for (int i = 20; i >= 0; --i)
          if (father[x][i] != father[y][i]) x = father[x][i], y = father[y][i];
     return father[x][0];
}

inline void add(long long &x, long long y){
     y %= P;
     x += y;
     if (x >= P) x -= P;
}

inline void dec(long long &x, long long y){
     y %= P;
     x -= y;
     if (x < 0) x += P;
}

int main(){
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);
     scanf("%d", &n);
     memset(first, 0, sizeof(first));
     l = 0;
     memset(father, 0, sizeof(father));
     for (int i = 1; i < n; i++)
     {
          int x, y, z;
          scanf("%d%d%d", &x, &y, &z);
          makelist(x, y, z);
          makelist(y, x, z);
     }
     memset(dist, 0, sizeof(dist)); 
     memset(W, 0, sizeof(W));
     W[1] = 0; c[1] = 1; dist[1] = 1;
     for (int k = 1, l = 1; l <= k; l++)
     {
          int m = c[l];
          //printf("%d %d\n", l, m);
          for (node *x = first[m]; x; x = x->next)
               if (!dist[x->where])
               dist[x->where] = dist[m] + 1,
               W[x->where] = (W[m] + x->cost) % P,
               c[++k] = x->where, father[x->where][0] = m;
     }
     for (int i = 0; i < 20; i++) 
          for (int j = 1; j <= n; j++)
               if (father[j][i])
                    father[j][i + 1] = father[father[j][i]][i];
     for (int i = n; i; --i)
     {
          int m = c[i];
          size[m] = 1; f[m] = 0; v[m] = 0;
          for (node *x = first[m]; x; x = x->next)
          if (dist[x->where] == dist[m] + 1)
               size[m] += size[x->where],
               add(f[m], f[x->where]), add(f[m], 1LL * x->cost * x->cost % P * size[x->where]),
               add(f[m], 2LL * v[x->where] % P * x->cost),
               add(v[m], v[x->where]), add(v[m], 1LL * x->cost * size[x->where]);
          //printf("%d %I64d %I64d\n", m, f[m], v[m]);
     }
     memset(F, 0, sizeof(F));
     memset(V, 0, sizeof(V));
     for (int i = 1; i <= n; i++)
     {
          int m = c[i];
          long long A = (F[m] + f[m]) % P, B = (V[m] + v[m]) % P;
          for (node *x = first[m]; x; x = x->next)
          if (dist[x->where] == dist[m] + 1)
          {
               long long C = A, D = B;
               dec(C, f[x->where]);
               dec(C, 1LL * x->cost * x->cost % P * size[x->where]);
               dec(C, 2LL * v[x->where] % P * x->cost),
               dec(D, v[x->where]); dec(D, 1LL * x->cost * size[x->where]);
               F[x->where] = 0; add(F[x->where], C);
              // printf("%I64d\n", C);
               add(F[x->where], 1LL * x->cost * x->cost % P * (n - size[x->where]));
             //  printf("%I64d\n", F[x->where]);
               add(F[x->where], 2LL * D * x->cost);
               V[x->where] = D; add(V[x->where], 1LL * (n - size[x->where]) * x->cost);
              // printf("%d %I64d %I64d %I64d\n", x->where, D, F[x->where], V[x->where]);
          }
     }
     scanf("%d", &m);
     for (; m--;)
     {
          int x, y;
          scanf("%d%d", &x, &y);
          int L = lca(x, y);
          if (L != y)
          {
               long long Q = W[x] + W[y]; Q %= P;
               dec(Q, W[L] * 2LL);
               long long ans = f[y];
               add(ans, 1LL * Q * Q % P * size[y]);
               add(ans, 2LL * Q % P * v[y]);
            //   printf("%I64d %I64d %d %d %I64d %I64d\n", Q, ans, x, y, F[x], f[x]);
               long long sx = (F[x] + f[x]) % P; dec(sx, ans);
            //   printf("%I64d\n", sx);
               dec(ans, sx);
               printf("%I64d\n", ans);
          }
          else
          {
               long long Q = W[x] + W[y]; Q %= P;
               dec(Q, W[L] * 2LL);
               //printf("!! %d %d %d\n", x, y, Q);
               long long ans = F[y];
               //printf("%I64d\n", ans);
               add(ans, 1LL * Q * Q % P * (n - size[y]));
               add(ans, 2LL * Q % P * V[y]);
               long long sx = (F[x] + f[x]) % P; dec(sx, ans);
               dec(sx, ans);
               printf("%I64d\n", sx);
          }
     }
}