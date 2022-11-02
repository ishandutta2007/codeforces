#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int v[1000001], n, m, c[100001], r[100001], cnt1, cnt2, 
a[100001], f[100001], cost, Min[100011], Max[100011];

int calc(int k, int Left, int Right, int s, int t){
     if (s > t) return 1 << 30;
     if (Left == s && Right == t) return v[k];
     int i = (Left + Right) >> 1;
     if (t <= i) return calc(k + k, Left, i, s, t);
     else if (s > i) return calc(k + k + 1, i + 1, Right, s, t);
     else return min(calc(k + k, Left, i, s, i), calc(k + k + 1, i + 1, Right, i + 1, t));
}

inline void change(int k, int Left, int Right, int x, int y){
     if (Left == Right)
     {
          v[k] = y;
          return;
     }
     int i = (Left + Right) >> 1;
     if (x <= i) change(k + k, Left, i, x, y);
     else change(k + k + 1, i + 1, Right, x, y);
     v[k] = min(v[k + k], v[k + k + 1]);
}
     
int main(){
    // freopen("b.in", "r", stdin);
    // freopen("b.out", "w", stdout);
     memset(f, 127, sizeof(f));
     memset(v, 127, sizeof(v));
     scanf("%d%d%d", &n, &cost, &m);
     for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
     cnt1 = cnt2 = 0; int Left1 = 1, Left2 = 1, Left = 1; f[0] = 0;
     change(1, 0, n, 0, 0);
     for (int i = 1; i <= n; i++)
     {
          for (; cnt1 >= Left1 && a[i] <= a[c[cnt1]]; --cnt1);
          c[++cnt1] = i;
          for (; cnt2 >= Left2 && a[i] >= a[r[cnt2]]; --cnt2);
          r[++cnt2] = i;
          for (; a[r[Left2]] - a[c[Left1]] > cost; )
          {
               if (c[Left1] == Left) ++Left1;
               if (r[Left2] == Left) ++Left2;
               ++Left;
          }
          f[i] = calc(1, 0, n, Left - 1, i - m) + 1;
          change(1, 0, n, i, f[i]);
     }
     if (f[n] < 1 << 30) 
     printf("%d\n", f[n]);else printf("-1\n");
}