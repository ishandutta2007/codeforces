#include <bits/stdc++.h>
using namespace std;

const int Maxn = 2005;
const int mod = 1000003;

string s;
int dp[Maxn][Maxn];

int main()
{
    cin >> s;
    dp[0][0] = 1;
    for (int i = 0; i < s.length(); i++)
        for (int j = Maxn - 1; j >= 0; j--) if (dp[i][j])
            if (isdigit(s[i])) dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % mod;
            else if (i == 0 || !isdigit(s[i - 1]))
                    if (s[i] == '+' || s[i] == '-')
                        dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j]) % mod;
                    else { printf("0\n"); return 0; }
                else {
                    dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j]) % mod;
                    if (j) dp[i][j - 1] = (dp[i][j - 1] + dp[i][j]) % mod;
                }
    if (!isdigit(s[int(s.length()) - 1])) { printf("0\n"); return 0; }
    int res = 0;
    for (int j = 0; j < Maxn; j++)
        res = (res + dp[s.length()][j]) % mod;
    printf("%d\n", res);
    return 0;
}