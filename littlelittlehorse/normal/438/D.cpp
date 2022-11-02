#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

struct tree{
     long long sum;
     int Max;
} f[400001];

int n, m, a[100001];

int read(){
     char ch;
     for (ch = getchar(); ch < '0' || ch > '9'; ch = getchar());
     int cnt = 0;
     for (; ch >= '0' && ch <= '9'; ch = getchar()) cnt = cnt * 10 + ch - '0';
     return cnt;
}

inline void buildtree(int k, int Left, int Right){
     if (Left == Right)
     {
          f[k].sum = f[k].Max = a[Left];
          return;
     }
     int i = (Left + Right) >> 1;
     buildtree(k + k, Left, i);
     buildtree(k + k + 1, i + 1, Right);
     f[k].sum = f[k + k].sum + f[k + k + 1].sum;
     f[k].Max = max(f[k + k].Max, f[k + k + 1].Max);
}

inline void change(int k, int Left, int Right, int x, int y){
     if (Left == Right)
     {
          f[k].sum = f[k].Max = y;
          return;
     }
     int i = (Left + Right) >> 1;
     if (x <= i) change(k + k, Left, i, x, y);
     else change(k + k + 1, i + 1, Right, x, y);
     f[k].sum = f[k + k].sum + f[k + k + 1].sum;
     f[k].Max = max(f[k + k].Max, f[k + k + 1].Max);
}

long long calc(int k, int Left, int Right, int s, int t){
     if (Left == s && Right == t) return f[k].sum;
     int i = (Left + Right) >> 1;
     if (t <= i) return calc(k + k, Left, i, s, t);
     else if (s > i) return calc(k + k + 1, i + 1, Right, s, t);
     else return calc(k + k, Left, i, s, i) + calc(k + k + 1, i + 1, Right, i + 1, t);
}

inline void work(int k, int Left, int Right, int s, int t, int x){
     if (f[k].Max < x) return;
     if (Left == Right)
     {
          f[k].sum = f[k].Max = f[k].Max % x;
          return;
     }
     int i = (Left + Right) >> 1;
     if (t <= i) work(k + k, Left, i, s, t, x);
     else if (s > i) work(k + k + 1, i + 1, Right, s, t, x);
     else work(k + k, Left, i, s, i, x), work(k + k + 1, i + 1, Right, i + 1, t, x);
     f[k].sum = f[k + k].sum + f[k + k + 1].sum;
     f[k].Max = max(f[k + k].Max, f[k + k + 1].Max);
}

int main(){
   //  freopen("d.in", "r", stdin);
   //  freopen("d.out", "w", stdout);
     n = read(); m = read();
     for (int i = 1; i <= n; i++) a[i] = read();
     buildtree(1, 1, n);
     for (; m--; )
     {
          int type = read();
          if (type == 1)
          {
               int x = read(), y = read();
               printf("%I64d\n", calc(1, 1, n, x, y));
          }
          else
          if (type == 2)
          {
               int x = read(), y = read(), z = read();
               work(1, 1, n, x, y, z);
          }
          else
          {
               int x = read(), y = read();
               change(1, 1, n, x, y);
          }
     }
}