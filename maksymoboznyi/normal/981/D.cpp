#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;

const int N = 100;
const long long inf = 2e18;

int n, a[N], sum[N], kk, dp[N][N];

bool can(int ans, int l, int r)
{
    int s = sum[r] - sum[l-1];
    if ((s&ans)==ans)
        return 1;
    return 0;
}

bool check(int ans)
{
    vector<pair<int, int> > v;
    v.clear();
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            if (can(ans, i, j))
                v.pb({i, j});
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= kk; j++)
            dp[i][j] = 0;
    dp[0][0] = 1;

    for (int i = 0; i < v.size(); i++)
        for (int kol = 1; kol <= kk; kol++)
            dp[v[i].second][kol] = max(dp[v[i].first-1][kol-1], dp[v[i].second][kol]);
    if (dp[n][kk] == 1)
        return 1;
    else
        return 0;
}
int st[100];
signed main()
{
    cin >> n >> kk;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];
    }
    int ans = 0;
    st[0] = 1;
    for (int i = 1; i <= 60; i++)
        st[i] = st[i-1]*2;
    int pos = 60;
    while (pos >= 0)
    {
        while (pos >= 0 && !check(ans+st[pos]))
            pos--;
        if (pos >= 0)
            ans += st[pos];
    }
    cout << ans;
    return 0;
}