#include <bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;

const int N = 3e3 + 1;
const int M = 998244353;

int dp[N][N];
string s, t;

int gp(int a, int b) {
    if (b <= 0)
        return 1;
    if (b == 1)
        return a;
    if (b % 2 == 0) {
        int res = gp(a, b / 2);
        return res * res % M;
    }
    return a * gp(a, b - 1) % M;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s >> t;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == t.back())
            dp[i][t.size() - 1] = gp(2, i - 1);
   // cout << dp[2][1] << endl;
    for (int i = 0; i < t.size(); i++)
        if (s[0] == t[i])
            dp[0][i] = 1;

    for (int i = 0; i + 1 < s.size(); i++)
        for (int l = 0; l < t.size(); l++)
            if (dp[i][l] > 0){
                char c = s[i + 1];
                if (l + i + 1 >= t.size() || c == t[l + i + 1])
                    dp[i + 1][l] += dp[i][l], dp[i + 1][l] %= M;

                if (l != 0 && c == t[l - 1])
                    dp[i + 1][l - 1] += dp[i][l], dp[i + 1][l - 1] %= M;
            }
    //cout << dp[1][0] << ' ' << dp[2][0] << ' ' << dp[3][0] << ' ' << dp[2][1] << endl;
    int ans = 0;
    for (int i = t.size() - 1; i < s.size(); i++)
        ans += dp[i][0], ans %= M;
    cout << ans * 2 % M;
    return 0;
}