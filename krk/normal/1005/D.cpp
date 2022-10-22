#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
const int mod = 3;

string s;
int dp[Maxn][mod];

int main()
{
    cin >> s;
    fill((int*)dp, (int*)dp + Maxn * mod, -Maxn);
    dp[0][0] = 0;
    for (int i = 0; i < s.length(); i++)
        for (int j = 0; j < mod; j++) if (dp[i][j] >= 0) {
            int nj = (int(s[i] - '0') + j) % mod;
            dp[i + 1][nj] = max(dp[i + 1][nj], dp[i][j]);
            dp[i + 1][0] = max(dp[i + 1][0], dp[i][j] + (nj == 0));
        }
    int res = 0;
    for (int j = 0; j < mod; j++)
        res = max(res, dp[s.length()][j]);
    printf("%d\n", res);
    return 0;
}