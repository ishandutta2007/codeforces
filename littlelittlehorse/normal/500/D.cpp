#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

struct node{
     node *next;
     int where;
} *first[100001], a[1000001];

int l, n, m, v[1000001][3], c[100001], dist[100001], size[100001];

inline void makelist(int x, int y){
     a[++l].where = y;
     a[l].next = first[x];
     first[x] = &a[l];
}

int main(){
     //freopen("a.in", "r", stdin);
     //freopen("a.out", "w", stdout);
     scanf("%d", &n);
     memset(first, 0, sizeof(first)); l = 0;
     for (int i = 1; i < n; i++) 
     {
          scanf("%d%d%d", &v[i][0], &v[i][1], &v[i][2]);
          makelist(v[i][0], v[i][1]);
          makelist(v[i][1], v[i][0]);
     }
     memset(dist, 0, sizeof(dist));
     dist[1] = 1; c[1] = 1;
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
          size[m] = 1;
          for (node *x = first[m]; x; x = x->next)
               if (dist[x->where] == dist[m] + 1)
                    size[m] += size[x->where];
     }
     double init = 0;
     for (int i = 1; i < n; i++)
     {
          int x = v[i][0], y = v[i][1];
          if (dist[x] < dist[y]) swap(x, y);
          init += 1.0 * size[x] * (n - size[x]) * (n - 2) * v[i][2];
     }
     scanf("%d", &m);
     for (;m--;)
     {
          int x, y;
          scanf("%d%d", &x, &y);
          int X = v[x][0], Y = v[x][1];
          if (dist[X] < dist[Y]) swap(X, Y);
          init += 1.0 * size[X] * (n - size[X]) * (n - 2) * (y - v[x][2]);
          v[x][2] = y;
          printf("%.10f\n", init / n / (n - 1) / (n - 2) * 6);
     }
}