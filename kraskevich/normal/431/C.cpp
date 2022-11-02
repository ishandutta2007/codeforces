#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long LL;
typedef long double ld;
#define MP make_pair
#define F first
#define S second

const int MOD = 1000 * 1000 * 1000 + 7;
const int N = 222;

int dp[N][N][N];

int main()
{
    ios_base::sync_with_stdio(0);
    #ifdef TEST
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n, k, d;
    cin >> n >> k >> d;
    for (int len = 0; len <= n; len++)
        for (int sum = 0; sum <= n; sum++)
            for (int lim = 0; lim <= k; lim++)
                    dp[len][sum][lim] = 0;
    dp[0][0][0] = 1;
    for (int len = 0; len < n; len++)
        for (int sum = 0; sum < n; sum++)
            for (int lim = 0; lim <= k; lim++)
                for (int now = 1; now <= k; now++)
                {
                    dp[len + 1][sum + now][max(lim, now)] += dp[len][sum][lim];
                    dp[len + 1][sum + now][max(lim, now)] %= MOD;
                }
    LL res = 0;
    for (int len = 0; len <= n; len++)
        for (int lim = d; lim <= k; lim++)
            res += dp[len][n][lim], res %= MOD;
    cout << res;

    return 0;
}