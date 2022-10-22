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
int dp[1001][1001];

int doit(int n, int k)
{
    memset(dp, 0, sizeof(dp));
    dp[0][1] = 1;
    For(i, k) for (int j = 1 + i * 2; j <= n - (k - i) * 2; ++j)
    {
        int cur = dp[i][j];
        for (int j2 = j + 2; j2 <= n - (k - i - 1) * 2; ++j2)
        {
            dp[i + 1][j2] += cur;
            if (dp[i + 1][j2] >= MOD)
                dp[i + 1][j2] -= MOD;
            cur += dp[i][j];
            if (cur >= MOD)
                cur -= MOD;
        }
    }
    int res = 0;
    For(i, n + 1)
    {
        res += dp[k][i];
        if (res >= MOD)
            res -= MOD;
    }
    return res;
}

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    cout << ((lint)doit(n, k) * doit(m, k)) % MOD << '\n';
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