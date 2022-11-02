#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, a[10011], g, r, f[10011][1011], c[2][10000011][2];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
        scanf("%d", &a[i]);
    scanf("%d%d", &g, &r);
    sort(a + 1, a + m + 1);
    memset(f, 0, sizeof(f));
    f[1][g] = 1; c[0][0][0] = 1; c[0][1][0] = 1; c[0][1][1] = g;
    for (int x = 0; c[x][0][0]; x = 1 - x) {
        int k = c[x][0][0]; c[x^1][0][0] = 0;
        for (int l = 1; l <= k; l++) {
            int i = c[x][l][0], j = c[x][l][1];
            if (i && j >= a[i] - a[i - 1] && !f[i - 1][j - (a[i] - a[i - 1])])
                f[i - 1][j - (a[i] - a[i - 1])] = f[i][j],
                c[x][++k][0] = i - 1,
                c[x][k][1] = j - (a[i] - a[i - 1]);
            if (i < m && j >= a[i + 1] - a[i] && !f[i + 1][j - (a[i + 1] - a[i])])
                f[i + 1][j - (a[i + 1] - a[i])] = f[i][j],
                c[x][++k][0] = i + 1,
                c[x][k][1] = j - (a[i + 1] - a[i]);
        }
        for (int i = 1; i <= k; i++)
            if (!c[x][i][1] && !f[c[x][i][0]][g])
                f[c[x][i][0]][g] = f[c[x][i][0]][0] + 1,
                c[x^1][++c[x^1][0][0]][0] = c[x][i][0],
                c[x^1][c[x^1][0][0]][1] = g;
    }
    int ans = 1 << 30;
    for (int i = 1; i <= m; i++)
        for (int j = 0; j <= g; j++)
            if (f[i][j]&& j >= a[m] - a[i])
                ans = min(ans, (f[i][j] - 1) * (g + r) + a[m] - a[i] + g - j);
    if (ans == 1 << 30)
        printf("-1\n");
    else
        printf("%d\n", ans);
}