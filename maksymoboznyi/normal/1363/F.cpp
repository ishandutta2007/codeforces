#include <iostream>

using namespace std;

const int M = 27;
const int N = 2e3 + 3;

string s, t;
int n, cs[M][N], ct[M][N], dp[N][N];

int calc(int i, int j) {
    if (dp[i][j] != -1)
        return dp[i][j];
    if (i == 0)
        return (dp[i][j] = 0);
    if (j < i)
        return (dp[i][j] = n + n);
    dp[i][j] = calc(i - 1, j) + 1;
    if (s[i] == t[j])
        dp[i][j] = min(dp[i][j], calc(i - 1, j - 1));
    if (cs[t[j] - 'a'][i + 1] > ct[t[j] - 'a'][j + 1])
        dp[i][j] = min(dp[i][j], calc(i, j - 1));
    return dp[i][j];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int oo;
    cin >> oo;
    while (oo--) {
        cin >> n;
        cin >> s >> t;
        for (int i = 0; i < 26; i++)
            cs[i][n] = ct[i][n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < 26; j++)
                cs[j][i] = cs[j][i + 1], ct[j][i] = ct[j][i + 1];
            cs[s[i] - 'a'][i]++;
            ct[t[i] - 'a'][i]++;
        }
        bool can = 1;
        for (int i = 0; i < 26; i++)
            if (cs[i][0] != ct[i][0]) {
                can = 0;
                break;
            }
        if (!can) {
            cout << "-1\n";
            continue;
        }
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= n; j++)
                dp[i][j] = -1;
        cout << calc(n - 1, n - 1) << "\n";
    }
    return 0;
}