#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

struct people{
       int value, cnt, position;
       bool operator < (const people &A) const{
            return cnt < A.cnt;
       }
} a[1001], c[1001];
int n, m, f[1001][1001], number[1001][1001], len, ans[1001][2];

int main(){
    //freopen("c.in", "r", stdin);
    //freopen("c.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &a[i].cnt, &a[i].value), a[i].position = i;
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) scanf("%d", &c[i].cnt), c[i].position = i;
    sort(a + 1, a + n + 1);
    sort(c + 1, c + m + 1);
    memset(f, 255, sizeof(f));
    f[0][0] = 0;
    for (int i = 0; i <= n; i++) 
        for (int j = 0; j <= m; j++)
            if (f[i][j] != -1)
            {
               if (i < n && f[i][j] > f[i + 1][j]) f[i + 1][j] = f[i][j], number[i + 1][j] = 1;
               if (j < m && f[i][j] > f[i][j + 1]) f[i][j + 1] = f[i][j], number[i][j + 1] = 2;
               if (i < n && j < m && c[j + 1].cnt >= a[i + 1].cnt && f[i][j] + a[i + 1].value > f[i + 1][j + 1])
                  f[i + 1][j + 1] = f[i][j] + a[i + 1].value, number[i + 1][j + 1] = 3;
            }
    len = 0;
    int x = n, y = m;
    for (; x || y;)
    {
        if (number[x][y] == 3) ans[++len][0] = a[x].position, ans[len][1] = c[y].position, --x, --y;
        if (number[x][y] == 2) --y;
        if (number[x][y] == 1) --x;
    }
    printf("%d %d\n", len, f[n][m]);
    for (int i = 1; i <= len; i++) printf("%d %d\n", ans[i][0], ans[i][1]);
}