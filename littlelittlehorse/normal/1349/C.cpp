#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

struct node {
    node *next;
    int where;
} *first[1000001], a[4000001];
int n, m, cnt, Q, size[1000001], w[1001][1001], t[1000001], c[1000001], e[1001][1001], f[1000001], v[1000001], l, d[1000001];
char str[1011];
int D[4][2] = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };

inline void makelist(int x, int y) {
    a[++l].where = y;
    a[l].next = first[x];
    first[x] = &a[l];
}

inline void soso(int x, int y, int cur) {
   e[x][y] = cur; size[cur]++;
   for (int i = 0; i < 4; i++) {
       int X = x + D[i][0], Y = y + D[i][1];
       if (X < 1 || X > n || Y < 1 || Y > m || w[X][Y] != w[x][y] || e[X][Y])
           continue;
       soso(X, Y, cur);
   }
}
   
int main() {
    scanf("%d%d%d", &n, &m, &Q);
    for (int i = 1; i <= n; i++) {
        scanf("%s", str + 1);
        for (int j = 1; j <= m; j++)
           w[i][j] = str[j] - '0';
    }
    memset(e, 0, sizeof(e)); cnt = 0; l = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (!e[i][j]) {
                soso(i, j, ++cnt);
                t[cnt] = w[i][j];
            }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; ++j) {
            if (i + 1 <= n && e[i][j] != e[i + 1][j])
                makelist(e[i][j], e[i + 1][j]), makelist(e[i + 1][j], e[i][j]);
            if (j + 1 <= m && e[i][j] != e[i][j + 1])
                makelist(e[i][j], e[i][j + 1]), makelist(e[i][j + 1], e[i][j]);
        }
    int k = 0;
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= cnt; i++) 
        if (size[i] != 1)
            c[++k] = i, f[i] = 1;
    for (int l = 1; l <= k; l++) {
        int m = c[l];
        for (node *x = first[m]; x; x = x->next)
            if (!f[x->where])
                f[x->where] = f[m] + 1, c[++k] = x->where;
    }
    
    for (; Q--; ) {
        int x, y;
        long long z;
        scanf("%d%d%lld", &x, &y, &z);
        if (!f[e[x][y]])
            printf("%d\n", w[x][y]);
        else
            if (z < f[e[x][y]])
                printf("%d\n", w[x][y]);
            else
                if ((z - f[e[x][y]]) & 1)
                    printf("%d\n", w[x][y]);
                else
                    printf("%d\n", 1 - w[x][y]);
    }
}