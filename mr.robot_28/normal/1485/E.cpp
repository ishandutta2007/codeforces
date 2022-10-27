#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define ld long double
#define int long long
#define sz(s) (int)s.size()

const int N = 2e5 + 100;
int h[N], p[N];
vector <int> g[N];
void dfs(int v, int p = -1)
{
    for(auto to : g[v])
    {
        h[to] = h[v] + 1;
        dfs(to, v);
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector <int> mind(n, 1e9), maxd(n);
        vector <pair <int, int> > mass;
        for(int i = 1; i < n; i++)
        {
            cin >> p[i];
            p[i]--;
            g[p[i]].push_back(i);
        }
        dfs(0);
        for(int i = 1; i < n; i++)
        {
            mass.push_back({h[i], i});
        }
        sort(mass.begin(), mass.end());
        vector <int> a(n);
        for(int i = 1; i < n; i++)
        {
            cin >> a[i];
        }
        vector <int> dp(n, 0);
        vector <int> maxh(n), minh(n, 1e9);
        for(int i = 0; i < n; i++)
        {
            maxh[h[i]] = max(maxh[h[i]], a[i]);
            minh[h[i]] = min(minh[h[i]], a[i]);
        }
        int ans = 0;
        for(int i = 0; i < n - 1; i++)
        {
            int j = i;
            int mx1 = -1e9, mx2 = -1e9;
            while(j < mass.size() && mass[j].X == mass[i].X)
            {
                int ind = mass[j].Y;
                dp[ind] = dp[p[ind]] + max(abs(minh[h[ind]] - a[ind]), abs(maxh[h[ind]] - a[ind]));
                mx1 = max(mx1, dp[p[ind]] - a[ind]);
                mx2 = max(mx2, dp[p[ind]] + a[ind]);
                j++;
            }
            for(int k = i; k < j; k++)
            {
                dp[mass[k].Y] = max(dp[mass[k].Y], mx1 + a[mass[k].Y]);
                dp[mass[k].Y] = max(dp[mass[k].Y], mx2 - a[mass[k].Y]);
                ans = max(ans, dp[mass[k].Y]);
            }
            i = j - 1;
        }
        for(int i = 0; i < n; i++)
        {
            g[i].clear();
        }
        cout << ans << "\n";
    }
    return 0;
}