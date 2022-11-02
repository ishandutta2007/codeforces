#include <cstdio>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, a[251][251], c[1000001][2], b[251][251], mr[251], mc[251];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &a[i][j]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            mr[i] = max(mr[i], a[i][j]),
            mc[j] = max(mc[j], a[i][j]);
    sort(mr + 1, mr + n + 1);
    sort(mc + 1, mc + m + 1);
    int lr = n, lc = m; 
    int k = 0, l = 0, x = 0, y = 0;
    for (int i = n * m; i; --i) {
        int status = 0;
        if (lr && mr[lr] == i)
            --lr, ++x, status += 1;
        if (lc && mc[lc] == i)
            --lc, ++y, status += 2;
        if (status)
            b[x][y] = i;
        else 
            b[c[++l][0]][c[l][1]] = i;
        if (status & 1)
            for (int j = y - 1; j; --j)
                c[++k][0] = x, c[k][1] = j;
        if (status & 2)
            for (int j = x - 1; j; --j)
                c[++k][0] = j, c[k][1] = y;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            printf("%d ", b[i][j]);
        printf("\n");
    }
}