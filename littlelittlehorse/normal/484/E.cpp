#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

struct tree{
     int ls, rs, l, r, value;
} f[5000001];

struct node{
     int x, position;
     bool operator < (const node &A) const{
          return x > A.x;
     }
} a[100001];

struct dhh{
     int l, r, value;
};

int n, num, root[100001], m;

inline void buildtree(int k, int Left, int Right){
     f[k].l = f[k].r = f[k].value = 0;
     if (Left == Right) return;
     int i = (Left + Right) >> 1;
     f[k].ls = ++num; f[k].rs = ++num;
     buildtree(f[k].ls, Left, i);
     buildtree(f[k].rs, i + 1, Right);
}

inline void change(int k1, int k2, int Left, int Right, int x){
     if (Left == Right)
     {
          f[k1].l = f[k1].r = f[k1].value = 1;
          return;
     }
     int i = (Left + Right) >> 1;
     if (x <= i) 
     {
          f[k1].ls = ++num; f[k1].rs = f[k2].rs;
          change(f[k1].ls, f[k2].ls, Left, i, x);
     }
     else
     {
          f[k1].ls = f[k2].ls; f[k1].rs = ++num;
          change(f[k1].rs, f[k2].rs, i + 1, Right, x);
     }
     if (f[f[k1].ls].l != i - Left + 1) f[k1].l = f[f[k1].ls].l;
     else f[k1].l = f[f[k1].ls].l + f[f[k1].rs].l;
     if (f[f[k1].rs].r != Right - i) f[k1].r = f[f[k1].rs].r;
     else f[k1].r = f[f[k1].rs].r + f[f[k1].ls].r;
     f[k1].value = max(f[f[k1].ls].value, f[f[k1].rs].value);
     f[k1].value = max(f[f[k1].ls].r + f[f[k1].rs].l, f[k1].value);
}

dhh calc(int k, int Left, int Right, int s, int t){
     if (Left == s && Right == t)
     {
          dhh now; now.l = f[k].l; now.r = f[k].r; now.value = f[k].value;
          return now;
     }
     int i = (Left + Right) >> 1;
     if (t <= i) return calc(f[k].ls, Left, i, s, t);
     else if (s > i) return calc(f[k].rs, i + 1, Right, s, t);
     else
     {
          dhh A = calc(f[k].ls, Left, i, s, i), B = calc(f[k].rs, i + 1, Right, i + 1, t), C;
          if (A.l != i - s + 1) C.l = A.l;
          else C.l = A.l + B.l;
          if (B.r != t - i) C.r = B.r;
          else C.r = B.r + A.r;
          C.value = max(A.value, B.value);
          C.value = max(A.r + B.l, C.value);
          return C;
     }
}

int main(){
     //freopen("e.in", "r", stdin);
     //freopen("e.out", "w", stdout);
     scanf("%d", &n);
     for (int i = 1; i <= n; i++)
          scanf("%d", &a[i].x), a[i].position = i;
     sort(a + 1, a + n + 1);
     root[0] = num = 1;
     buildtree(1, 1, n);
     for (int i = 1; i <= n; i++)
     {
          root[i] = ++num;
          change(root[i], root[i - 1], 1, n, a[i].position);
     }
     scanf("%d", &m);
     for (int i = 1; i <= m; i++)
     {
          int x, y, z;
          scanf("%d%d%d", &x, &y, &z);
          int Left = 0, Right = n, Mid = (Left + Right) >> 1;
          for (; Left + 1 < Right; Mid = (Left + Right) >> 1)
          {
               if (calc(root[Mid], 1, n, x, y).value >= z) Right = Mid;
               else Left = Mid;
          }
          printf("%d\n", a[Right].x);
     }
}