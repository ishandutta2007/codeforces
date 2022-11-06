#include <bits/stdc++.h>
#define pb push_back

using namespace std;

struct circle
{
    double x, y, r;
};

circle a[1005];
int par[1001], n;
double help_arr[2][2], dp[1001][2][2];
vector<int> g[1001];
bool used[1001];

bool u_in_v(int u, int v)
{
    return (a[u].x - a[v].x)*(a[u].x - a[v].x) + (a[u].y - a[v].y)*(a[u].y - a[v].y) <= (a[u].r - a[v].r)*(a[u].r - a[v].r) && a[u].r < a[v].r;
}

void dfs(int v)
{
    double help_arr[2][2];
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            help_arr[i][j] = 0;
    for (int k = 0; k < g[v].size(); k++)
    {
        dfs(g[v][k]);
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
            {
                help_arr[i][j] += dp[g[v][k]][i][j];
            }
    }
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
        {
            double val1 = help_arr[i ^ 1][j], val2 = help_arr[i][j ^ 1];
         if (i == 0)
                val1 += a[v].r*a[v].r;
            else
                val1 -= a[v].r*a[v].r;
            if (j == 0)
                val2 += a[v].r*a[v].r;
            else
                val2 -= a[v].r*a[v].r;
            dp[v][i][j] = max(val1, val2);
        }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].x >> a[i].y >> a[i].r;
    int pr;
    for (int i = 1; i <= n; i++)
    {
        pr = 0;
        for (int j = 1; j <= n; j++)
            if (u_in_v(i, j) && (pr == 0 || a[j].r < a[pr].r))
                pr = j;
        g[pr].pb(i);
        par[i] = pr;
    }
    double ans = 0;
    for (int i = 1; i <= n; i++)
        if (par[i] == 0)
        {
            dfs(i);
            ans += dp[i][0][0]*acos(-1.0);
        }
    cout << fixed << setprecision(8) << ans;
    return 0;
}