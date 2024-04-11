#include <bits/stdc++.h>
using namespace std;

const int Maxn = 505;
const int my[3][3] = {{3, 7, 6}, {1, 2, 5}, {0, 4, 8}};

int n, m;
int pnt;
int res[Maxn][Maxn];

int main()
{
    scanf("%d", &n);
    if (n == 1 || n == 2) { printf("-1\n"); return 0; }
    bool bot = n % 2;
    int sav = n;
    while (n > 3) {
        if (bot) {
            for (int j = 1; j <= n; j++)
                res[n][j] = ++pnt;
            for (int i = n - 1; i >= 1; i--)
                res[i][n] = ++pnt;
        } else {
            for (int i = 1; i <= n; i++)
                res[i][n] = ++pnt;
            for (int j = n - 1; j >= 1; j--)
                res[n][j] = ++pnt;
        }
        n--;
        bot = !bot;
    }
    pnt++;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            res[i][j] = my[i - 1][j - 1] + pnt;
    n = sav;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            printf("%d%c", res[i][j], j + 1 <= n? ' ': '\n');
    return 0;
}