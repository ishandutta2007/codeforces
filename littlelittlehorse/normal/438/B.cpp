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
} *first[100001], a[200001]; 
struct po{
     int pos, cost;
     bool operator < (const po &A) const{
          return cost < A.cost;
     }
} v[100001];
int n, f[100001], size[100001], m, l;
double ans;
bool b[100001];

int gf(int i){
     if (i == f[i]) return i;
     return f[i] = gf(f[i]);
}

inline void makelist(int x, int y){
     a[++l].where = y; a[l].next = first[x];
     first[x] = &a[l];
}

int main(){
   //  freopen("b.in", "r", stdin);
   //  freopen("b.out", "w", stdout);
     scanf("%d%d", &n, &m);
     memset(b, false, sizeof(b));
     memset(first, 0, sizeof(first)); l = 0;
     for (int i = 1; i <= n; i++)
          scanf("%d", &v[i].cost), v[i].pos = i;
     sort(v + 1, v + n + 1);
     for (int i = 1; i <= n; i++) f[i] = i, size[i] = 1;
     for (int i = 1; i <= m; i++)
     {
          int x, y;
          scanf("%d%d", &x, &y);
          makelist(x, y); makelist(y, x);
     }
     ans = 0;
     for (int i = n; i; --i)
     {
          int S = 1; b[v[i].pos] = true;
          for (node *x = first[v[i].pos]; x; x = x->next)
               if (b[x->where] && gf(x->where) != gf(v[i].pos))
               {
                    int X = gf(x->where), Y = gf(v[i].pos);
                    ans += 2.0 * size[X] * size[Y] * v[i].cost;
                    size[X] += size[Y];
                    f[Y] = X;
               }
     }
     printf("%.10f\n", ans / n / (n - 1));
}