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
} *first[5001], a[100001];
struct P{
     int x, y;
     double rate;
     bool operator < (const P &A) const{
          if (x != A.x) return x < A.x;
          return y > A.y;
          
     }
} r[10001];
int l, limit, n, m, v[100001], num, c[10001];
double f[5001][10011], w[5001];
bool b[100001];

inline void makelist(int x, int y){
     a[++l].where = y;
     a[l].next = first[x];
     first[x] = &a[l];
}

inline void calc(int now){
     for (node *x = first[now]; x; x = x->next) 
     {
          calc(x->where);
          for (int i = r[x->where].x; i <= r[x->where].y; i++) b[i] = true;
     }
     int Max = 0;
     for (int i = r[now].x; i <= r[now].y; i++) 
          if (!b[i]) Max = max(Max, v[i]);
     for (int i = 0; i <= m + m + 2; i++)
     {
          f[now][i] = 1;
          for (node *x = first[now]; x; x = x->next)
               w[x->where] += f[x->where][i], f[now][i] *= w[x->where];
     }
     for (int i = m + m + 2; i; i--) f[now][i] -= f[now][i - 1]; 
     int status1, status2;
     status1 = max(Max - limit + m + 1, 0);
     for (int i = 0; i < status1; i++) f[now][status1] += f[now][i], f[now][i] = 0;
     for (int i = m + m + 1; i; --i)
     {
          f[now][i + 1] += f[now][i] * r[now].rate;
          f[now][i] *= 1.0 - r[now].rate;
     }
}

int main(){
 //    freopen("c.in", "r", stdin);
 //    freopen("c.out", "w", stdout);
     memset(f, 0, sizeof(f));
     memset(w, 0, sizeof(w));
     memset(b, false, sizeof(b));
     scanf("%d%d", &n, &m);
     for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
     limit = 0;
     for (int i = 1; i <= n; i++) limit = max(limit, v[i]);
     for (int i = 1; i <= m; i++) 
          scanf("%d%d%lf", &r[i].x, &r[i].y, &r[i].rate);
     r[0].x = 1; r[0].y = n; r[0].rate = 0;
     sort(r + 1, r + m + 1);
     memset(first, 0, sizeof(first)); l = 0;
     num = 0;
     for (int i = 1; i <= m; i++)
     {
          for (; num && r[i].x > r[c[num]].y; --num);
          makelist(c[num], i);
          c[++num] = i;         
     }
     calc(0);
     double ans = 0;
     for (int i = m + 1; i <= m + m + 1; i++) 
          ans += f[0][i] * (i - m - 1 + limit);
     printf("%.10f\n", ans);
}