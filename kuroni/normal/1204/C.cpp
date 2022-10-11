#include <bits/stdc++.h>
using namespace std;

const int INF = 1E9 + 7, N = 105;

int n, m, u, prv, lst = 0, dis = 0, dp[N][N];
vector<int> ans;
char s[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> (s + 1);
        for (int j = 1; j <= n; j++)
            dp[i][j] = (s[j] == '0' ? INF : 1);
        dp[i][i] = 0;
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
    cin >> m;
    while (m--)
    {
        cin >> u;
        dis++;
        if (lst == 0 || dp[lst][u] < dis)
        {
            dis = (lst == 0 ? 0 : 1);
            lst = (lst == 0 ? u : prv);
            ans.push_back(lst);
        }
        prv = u;
    }
    ans.push_back(u);
    cout << ans.size() << '\n';
    for (int &v : ans)
        cout << v << " ";
}