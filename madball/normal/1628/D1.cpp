#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <random>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <tuple>
using namespace std;

typedef long long lint;
#define For(i, n) for (int i = 0; i < (n); ++i)
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)((v).size())

const int MOD = (int)1e9 + 7;
int add(int a, int b)
{
    a += b;
    if (a >= MOD)
        a -= MOD;
    return a;
}
int div2(int a)
{
    if (a % 2 == 0)
        return a / 2;
    else
        return (a + MOD) / 2;
}

int dp[2001][2001];
void solve()
{
    For(i, 2001) For(j, i + 1)
        dp[i][j] = j == 0 ? 0 : j == i ? i : div2(add(dp[i - 1][j - 1], dp[i - 1][j]));
    int t;
    scanf("%d", &t);
    For(i, t)
    {
        int m, n, k;
        scanf("%d %d %d", &n, &m, &k);
        printf("%d\n", ((lint)dp[n][m] * k) % MOD);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solve();
#ifdef LOCAL
    printf("\n\n%.3f s", (double)clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}