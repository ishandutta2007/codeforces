#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

struct node {
     long long lmax, rmax, tmax;
} f[800001], ans;

int n, m, a[200001], h[200001];
long long v[200001];

inline void merge(node *x, node *y, node *z, long long m, long long l, long long r) {
     x->tmax = max(max(y->tmax, z->tmax), y->rmax + z->lmax + m);
     x->lmax = max(y->lmax, z->lmax + l + m);
     x->rmax = max(z->rmax, y->rmax + r + m);
}

inline void buildtree(int k, int Left, int Right) {
     if (Left == Right) {
          f[k].lmax = f[k].rmax = f[k].tmax = h[Left] << 1;
          return;
     }
     int i = (Left + Right) >> 1;
     buildtree(k + k, Left, i);
     buildtree(k + k + 1, i + 1, Right);
     //printf("%d %d\n", Left, Right);
     merge(&f[k], &f[k + k], &f[k + k + 1], a[i], v[i - 1] - v[Left - 1], v[Right - 1] - v[i]);
}

node calc(int k, int Left, int Right, int s, int t) {
     //printf("%d %d\n", s, t);
     if (Left == s && Right == t) return f[k];
     int i = (Left + Right) >> 1;
     if (t <= i) return calc(k + k, Left, i, s, t);
     else if (s > i) return calc(k + k + 1, i + 1, Right, s, t);
     else {
          node will, l = calc(k + k, Left, i, s, i), r = calc(k + k + 1, i + 1, Right, i + 1, t);
          //printf("%d %d %d %d %I64d %I64d\n", s, t, i, a[i], v[i - 1] - v[s - 1], v[t - 1] - v[i]);
          merge(&will, &l, &r, a[i], v[i - 1] - v[s - 1], v[t - 1] - v[i]);
          return will;
     }
}

int main() {
     //freopen("c.in", "r", stdin);
     //freopen("c.out", "w", stdout);
     scanf("%d%d", &n, &m);
     for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), a[i + n] = a[i];
     for (int i = 1; i <= n; ++i) scanf("%d", &h[i]), h[i + n] = h[i];
     n <<= 1;
     v[0] = 0;
     for (int i = 1; i <= n; ++i) v[i] = v[i - 1] + a[i];
     buildtree(1, 1, n);
     for (int i = 1; i <= m; i++) {
          int x, y;
          scanf("%d%d", &x, &y);
          if (x <= y)
               printf("%I64d\n", calc(1, 1, n, y + 1, x + n / 2 - 1).tmax);
          else printf("%I64d\n", calc(1, 1, n, y + 1, x - 1).tmax);
     }
}