#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector <vector <ll> > dp(n, vector <ll> (n, 1e18));
    vector <vector <pair <int, int> > > g(n);
    for(int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
    }
    for(int i = 0; i < n; i++)
    {
        vector <bool> used(n, 0);
        dp[i][i] = 0;
        vector <ll> adds(n);
        for(int it = 0; it < n; it++)
        {
            int stx = -1;
            for(int p = 0; p < n; p++)
            {
                adds[p] = 1e18;
            }
            for(int p = 0; p < n; p++)
            {
                if(!used[p] && (stx == -1 || dp[i][p] < dp[i][stx]))
                {
                    stx = p;
                }
            }
            int k, p1, p2;
            int f = dp[i][stx] % n;
            used[stx] = 1;
            for(auto pr : g[stx])
            {
                k = (pr.X + f);
                if(k >= n)
                {
                    k -= n;
                }
                adds[k] = min(adds[k], 1LL * pr.Y);
            }
            for(int p = 1; p < n * 2; p++)
            {
                p1 = p;
                if(p1 >= n)
                {
                    p1 -= n;
                }
                p2 = p - 1;
                if(p2 >= n)
                {
                    p2 -= n;
                }
                adds[p1] = min(adds[p1], adds[p2] + 1);
            }
            for(int p = 0; p < n; p++)
            {
                dp[i][p] = min(dp[i][p], dp[i][stx] + adds[p]);
            }
        }
        for(int j = 0; j < n; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}