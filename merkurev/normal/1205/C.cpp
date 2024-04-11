#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")

#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...)
#endif

const int N = 55;
int f[2][N][N];
int n;

bool inF(int x, int y)
{
    return x >= 0 && y >= 0 && x < n && y < n;
}

int ask(int x1, int y1, int x2, int y2)
{
    printf("? %d %d %d %d\n", x1 + 1, y1 + 1, x2 + 1, y2 + 1);
    fflush(stdout);
    int x;
    scanf("%d", &x);
    return x;
}

void setVal(int i, int j, int fi, int fj, int x)
{
    for (int t = 0; t < 2; t++)
        f[t][i][j] = f[t][fi][fj] ^ x;
}

bool dp[N][N];
int has(int t, int x1, int y1, int x2, int y2)
{
    for (int i = 0; i <= x2 - x1; i++)
        for (int j = 0; j <= y2 - y1; j++)
            dp[i][j] = false;
    dp[0][0] = true;
    for (int i = 0; x1 + i <= x2 - i; i++)
        for (int j = 0; y1 + j <= y2 - j; j++)
        {
            if (dp[i][j] == false)
                continue;
            if (f[t][x1 + i][y1 + j] != f[t][x2 - i][y2 - j])
                continue;
            if ((x2 - i + y2 - j) - (x1 + i + y1 + j) <= 1)
                return true;
            dp[i + 1][j] = true;
            dp[i][j + 1] = true;
        }
    return false;
}

bool tryAsk(int x1, int y1, int x2, int y2)
{
    int has0 = has(0, x1, y1, x2, y2);
    int has1 = has(1, x1, y1, x2, y2);
    if (has0 == has1)
        return false;

    int x = ask(x1, y1, x2, y2);

    int t = 0;
    if (x == has1)
        t = 1;
    printf("!\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d", f[t][i][j]);
        printf("\n");
    }
    fflush(stdout);

    return true;
}


int main()
{
    memset(f, -1, sizeof f);
    scanf("%d", &n);

    f[0][0][0] = 1;
    f[1][0][0] = 1;

    f[0][n - 1][n - 1] = 0;
    f[1][n - 1][n - 1] = 0;
    
    f[0][0][1] = 0;
    f[1][0][1] = 1;

    {
        int x = ask(0, 1, 1, 2);
        setVal(1, 2, 0, 1, x ^ 1);
        x = ask(1, 0, 1, 2);
        setVal(1, 0, 1, 2, x ^ 1);
    }
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (f[0][i][j] == -1)
            {
                if (i > 0 && j > 0)
                {
                    int x = ask(i - 1, j - 1, i, j);
                    setVal(i, j, i - 1, j - 1, x ^ 1);
                }
                else if (i > 1)
                {
                    int x = ask(i - 2, j, i, j);
                    setVal(i, j, i - 2, j, x ^ 1);
                }
                else if (j > 1)
                {
                    int x = ask(i, j - 2, i, j);
                    setVal(i, j, i, j - 2, x ^ 1);
                }
            }
        }

    int len = 5;
    while (true)
    {
        for (int li = 1; li < len; li++)
        {
            int lj = len - li;
            for (int i = 0; i + li <= n; i++)
                for (int j = 0; j + lj <= n; j++)
                {
                    if (tryAsk(i, j, i + li - 1, j + lj - 1))
                        return 0;
                }
        }
    }


    return 0;
}