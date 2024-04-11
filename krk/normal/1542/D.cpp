#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 505;
const int mod = 998244353;

int n;
char typ[Maxn];
int x[Maxn];
int dp[Maxn][Maxn];
int res;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %c", &typ[i]);
        if (typ[i] == '+') scanf("%d", &x[i]);
    }
    for (int i = 0; i < n; i++) if (typ[i] == '+') {
        dp[0][0] = 1;
        for (int r = 0; r < n; r++)
            for (int c = 0; c <= n; c++) if (dp[r][c] != 0) {
                int ways = dp[r][c]; dp[r][c] = 0;
                if (r != i) dp[r + 1][c] = (dp[r + 1][c] + ways) % mod;
                if (typ[r] == '-')
                    dp[r + 1][max(c - 1, 0)] = (dp[r + 1][max(c - 1, 0)] + ways) % mod;
                else if (x[r] > x[i] || x[r] == x[i] && r > i || c == 0 && r > i)
                        dp[r + 1][c] = (dp[r + 1][c] + ways) % mod;
                    else dp[r + 1][c + 1] = (dp[r + 1][c + 1] + ways) % mod;
            }
        int all = 0;
        for (int c = 0; c <= n; c++) {
            int ways = dp[n][c]; dp[n][c] = 0;
            if (c > 0) all = (all + ways) % mod;
        }
        res = (res + ll(all) * x[i]) % mod;
    }
    cout << res << endl;
    return 0;
}