#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
#define MP make_pair
#define F first
#define S second

const int N = 2222;
const int MOD = 1000 * 1000 * 1000 + 7;
vector<int> d[N];
int dp[N][N];
int n, k;

int main()
{
    ios_base::sync_with_stdio(0);
    #ifdef TEST
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cin >> n >> k;
    for (int i = 0; i < k; i++)
        for (int j = 0; j <= n; j++)
            dp[i][j] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i % j == 0)
                d[i].push_back(j);
    for (int i = 1; i <= n; i++)
        dp[0][i] = 1;
    for (int l = 1; l < k; l++)
        for (int x = 1; x <= n; x++)
            for (int dv : d[x])
                dp[l][x] += dp[l - 1][dv], dp[l][x] %= MOD;
    int res = 0;
    for (int i = 1; i <= n; i++)
        res += dp[k - 1][i], res %= MOD;
    cout << res;

    return 0;
}