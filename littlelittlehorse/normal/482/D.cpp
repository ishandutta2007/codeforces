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
const int P = 1000000007;
long long f[100001][2], v[2], g[2];
int n, l, c[100001], dist[100001], r[100001], len;

inline void makelist(int x, int y){
     a[++l].where = y;
     a[l].next = first[x];
     first[x] = &a[l];
}

inline void inc(long long &x, long long y){
     y %= P;
     x += y; 
     if (x >= P) x -= P;
}

inline void dec(long long &x, long long y){
     y %= P;
     x -= y;
     if (x < 0) x += P;
}

inline void mul(long long &x, long long y){
     x *= y; 
     x %= P;
}

int main(){
     //freopen("d.in", "r", stdin);
     //freopen("d.out", "w", stdout);
     memset(first, 0, sizeof(first)); l = 0;
     scanf("%d", &n);
     for (int i = 2; i <= n; i++)
     {
          int x;
          scanf("%d", &x);
          makelist(x, i);
     }    
     memset(dist, 0, sizeof(dist));
     dist[1] = 1; c[1] = 1;
     for (int k = 1, l = 1; l <= k; l++)
     {
          int m = c[l];
          for (node *x = first[m]; x; x = x->next)
               c[++k] = x->where;
     }
     for (int i = n; i; --i)
     {
          int m = c[i];
          f[m][1] = 1; f[m][0] = 0;
          long long even = 1;
          g[0] = 1; g[1] = 0; len = 0;
          for (node *x = first[m]; x; x = x->next)
          {
               r[++len] = x->where;
               v[0] = (f[m][0] * (f[x->where][0] + 1) % P + f[m][1] * f[x->where][1] % P) % P,
               v[1] = (f[m][1] * (f[x->where][0] + 1) % P + f[m][0] * f[x->where][1] % P) % P;
               f[m][0] = v[0]; f[m][1] = v[1];
               mul(even, f[x->where][0] + 1);
               v[0] = (g[0] + g[1] * f[x->where][1] % P) % P;
               v[1] = (g[1] + g[0] * f[x->where][1] % P) % P;
               g[0] = v[0]; g[1] = v[1];
          }
          long long value1 = f[m][0], value2 = f[m][1];
          f[m][1] = 1; f[m][0] = 0;
          for (int i = len; i; --i)
          {
               v[0] = (f[m][0] * (f[r[i]][0] + 1) % P + f[m][1] * f[r[i]][1] % P) % P,
               v[1] = (f[m][1] * (f[r[i]][0] + 1) % P + f[m][0] * f[r[i]][1] % P) % P;
               f[m][0] = v[0]; f[m][1] = v[1];
          }
          inc(f[m][0], value1); inc(f[m][1], value2);
          dec(f[m][1], even);
          dec(f[m][0], g[1]);
     }
     inc(f[1][0], f[1][1]);
     printf("%d\n", f[1][0]);
}