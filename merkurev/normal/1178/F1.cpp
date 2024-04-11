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

const int MOD = 998244353;
void sadd(int &a, int b)
{
    a += b;
    if (a >= MOD)
        a -= MOD;
}
int add(int a, int b)
{
    sadd(a, b);
    return a;
}
int mul(int a, int b)
{
    return (a * 1LL * b) % MOD;
}

const int N = 505;
int a[N];

int dp[N][N];
int mn[N];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
#endif

    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (int i = 0; i <= n; i++)
    {
        mn[i] = i;
        dp[i][i] = 1;
        dp[i][i + 1] = 1;
    }

    for (int len = 2; len <= n; len++)
        for (int l = 0; l + len <= n; l++)
        {
            int r = l + len;
            if (a[r - 1] < a[mn[l]])
                mn[l] = r - 1;
            int suml = 0, sumr = 0;
            int mid = mn[l];
            for (int j = l; j <= mid; j++)
                sadd(suml, mul(dp[l][j], dp[j][mid]));
            for (int j = mid + 1; j <= r; j++)
                sadd(sumr, mul(dp[mid + 1][j], dp[j][r]));
            dp[l][r] = mul(suml, sumr);
            //eprintf("%d %d : %d = %d * %d\n", l, r, dp[l][r], suml, sumr);
        }
    printf("%d\n", dp[0][n]);

    return 0;
}