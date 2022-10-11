#include <iostream>
#include <cstdio>
using namespace std;

const int N = 100005, MX = 305;

int n, q, u, a[3], dp[MX][MX][MX], nxt[N][26];
char t, pat[3][MX];
string s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q >> s;
    for (int i = 0; i < 26; i++)
        nxt[n + 1][i] = nxt[n + 2][i] = n + 1;
    for (int i = n; i >= 0; i--)
    {
        for (int j = 0; j < 26; j++)
            nxt[i][j] = nxt[i + 1][j];
        if (i > 0)
            nxt[i][s[i - 1] - 'a'] = i;
    }
    while (q--)
    {
        cin >> t >> u;
        --u;
        if (t == '-')
            --a[u];
        else
        {
            ++a[u];
            cin >> pat[u][a[u]];
            for (int i = (u == 0 ? a[0] : 0); i <= a[0]; i++)
                for (int j = (u == 1 ? a[1] : 0); j <= a[1]; j++)
                    for (int k = (u == 2 ? a[2] : 0); k <= a[2]; k++)
                        if (i != 0 || j != 0 || k != 0)
                        {
                            dp[i][j][k] = n + 1;
                            if (i > 0)
                                dp[i][j][k] = min(dp[i][j][k], nxt[dp[i - 1][j][k] + 1][pat[0][i] - 'a']);
                            if (j > 0)
                                dp[i][j][k] = min(dp[i][j][k], nxt[dp[i][j - 1][k] + 1][pat[1][j] - 'a']);
                            if (k > 0)
                                dp[i][j][k] = min(dp[i][j][k], nxt[dp[i][j][k - 1] + 1][pat[2][k] - 'a']);
                        }
        }
        cout << (dp[a[0]][a[1]][a[2]] == n + 1 ? "NO\n" : "YES\n");
    }
}