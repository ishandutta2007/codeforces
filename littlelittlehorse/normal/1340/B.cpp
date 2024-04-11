#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, f[2001][2001], a[11], v[501][10], pre[2001][2001][2], c[4000001][2], r[2001], u[2001];
char str[111];

int calc(int y) {
    for (int i = n; i; --i) {
        u[i] = pre[i][y][1];
        y = pre[i][y][0];
    }
    for (int i = 1; i <= n; i++)
        printf("%d", u[i]);
    printf("\n");
}

int main() {
    a[0] = (1 << 7) - 1 - (1 << 3);
    a[1] = (1 << 2) + (1 << 5);
    a[2] = (1 << 7) - 1 - (1 << 1) - (1 << 5);
    a[3] = (1 << 7) - 1 - (1 << 1) - (1 << 4);
    a[4] = (1 << 7) - 1 - (1 << 0) - (1 << 4) - (1 << 6);
    a[5] = (1 << 7) - 1 - (1 << 2) - (1 << 4);
    a[6] = (1 << 7) - 1 - (1 << 2);
    a[7] = (1 << 0) + (1 << 2) + (1 << 5);
    a[8] = (1 << 7) - 1;
    a[9] = (1 << 7) - 1 - (1 << 4);
    
    for (int i = 0; i < 1 << 7; i++) 
        for (int j = 0; j < 10; j++) {
            v[i][j] = 0;
            if ((a[j] & i) != i)
                v[i][j] = -1;
            else {
                int x = a[j] - i;
                for (int k = 0; k < 7; k++)
                    if ((1 << k) & x)
                        ++v[i][j];
            }
        }
    
    memset(f, 0, sizeof(f));
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", str);
        int status = 0;
        for (int j = 0; j < 8; j++)
            if (str[j] == '1')
                status += 1 << j;
        r[i] = status;
    }
    
    f[0][0] = 0;
    c[1][0] = 0; c[1][1] = 0;
    for (int l = 1, k = 1; l <= k; l++) {
        int x = c[l][0], y = c[l][1];
        if (x == n && y == m) {
            calc(y);
            return 0;
        }
        if (x == n)
            continue;
        for (int i = 9; i >= 0; --i) {
            if (v[r[x + 1]][i] != -1 && y + v[r[x + 1]][i] <= m &&
            ! f[x + 1][y + v[r[x + 1]][i]])
                f[x + 1][y + v[r[x + 1]][i]] = 1,
                pre[x + 1][y + v[r[x + 1]][i]][0] = y,
                pre[x + 1][y + v[r[x + 1]][i]][1] = i,
                c[++k][0] = x + 1, c[k][1] = y + v[r[x + 1]][i];
        }
    }
    
    printf("-1\n");
}