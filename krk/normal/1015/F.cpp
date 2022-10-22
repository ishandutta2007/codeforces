#include <bits/stdc++.h>
using namespace std;

const int Maxn = 205;
const int mod = 1000000007;

int n;
string s;
int my[Maxn][2];
int dp[Maxn][Maxn][Maxn];

int Get(const string &t)
{
    for (int j = int(t.length()); j > 0; j--)
        if (s.substr(0, j) == t.substr(int(t.length()) - j))
            return j;
    return 0;
}

int main()
{
    cin >> n; n *= 2;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        my[i][0] = Get(s.substr(0, i) + string(1, ')'));
        my[i][1] = Get(s.substr(0, i) + string(1, '('));
    }
    my[s.length()][0] = my[s.length()][1] = s.length();
    dp[0][0][0] = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++)
            for (int k = 0; k <= s.length(); k++) if (dp[i][j][k]) {
                if (j > 0)
                    dp[i + 1][j - 1][my[k][0]] = (dp[i + 1][j - 1][my[k][0]] + dp[i][j][k]) % mod;
                dp[i + 1][j + 1][my[k][1]] = (dp[i + 1][j + 1][my[k][1]] + dp[i][j][k]) % mod;
            }
    printf("%d\n", dp[n][0][s.length()]);
    return 0;
}