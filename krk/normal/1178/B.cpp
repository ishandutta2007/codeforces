#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 1000005;

string s;
ll dp[Maxn][4];

int main()
{
    cin >> s;
    dp[0][0] = 1;
    for (int i = 0; i < s.length(); i++) {
        dp[i + 1][0] += dp[i][0];
        dp[i + 1][1] += dp[i][1];
        dp[i + 1][2] += dp[i][2];
        dp[i + 1][3] += dp[i][3];
        if (i + 1 < s.length() && s[i] == 'v' && s[i + 1] == 'v') {
            dp[i + 2][1] += dp[i][0];
            dp[i + 2][3] += dp[i][2];
        }
        if (s[i] == 'o')
            dp[i + 1][2] += dp[i][1];
    }
    cout << dp[s.length()][3] << endl;
    return 0;
}