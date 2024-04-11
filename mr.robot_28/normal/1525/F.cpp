#include<bits/stdc++.h>
#define X first
#define Y second
#define int long long
#define ll long long
#define sz(a) (int)a.size()
using namespace std;
const int maxn = 500;
const ll INF = 2e18 + 100;
vector <int> g[maxn];
bool blocked[maxn];
int used[maxn];
int mt[maxn];
bool dfs(int v, int col)
{
    if(used[v] == col)
    {
        return 0;
    }
    used[v] = col;
    for(auto to : g[v])
    {
        if(blocked[to])
        {
            continue;
        }
        if(mt[to] == -1 || dfs(mt[to], col))
        {
            mt[v] = to;
            mt[to] = v;
            return 1;
        }
    }
    return 0;
}

signed main()
{
   // ifstream cin("rt.txt.txt");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b + n);
        g[b + n].push_back(a);
    }
    fill(mt, mt + n * 2, -1);
    vector <int> x(k), y(k);
    for(int i = 0; i < k; i++)
        cin >> x[i] >> y[i];
    int cur = 0;
    for(int i = 0; i < n; i++)
    {
        if(dfs(i, i + 1))
        {
            cur++;
        }
    }
    int d = n - cur;
    vector <vector <ll> > dp(k + 1, vector <ll> (n + 1, -INF));
    vector <vector <int> > p(k + 1, vector <int> (n + 1, -1));
    dp[0][d] = 0;
    for(int i = 1; i <= k; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            if(dp[i - 1][j] == -INF)
            {
                continue;
            }
            for(int current = max(j, i + 1); current <= n; current++)
            {
                int add = current - j;
                ll value = dp[i - 1][j] + max(0LL, x[i - 1] - 1LL * y[i - 1] * add);
                if(value > dp[i][current])
                {
                    dp[i][current] = value;
                    p[i][current] = j;
                }
            }
        }
    }
    vector <int> path;
    int z = max(k + 1, d);
    for(int i = k; i >= 1; i--)
    {
        path.push_back(z - p[i][z]);
        z = p[i][z];
    }
    reverse(path.begin(), path.end());
    vector <int> ans;
    int sz = n + 1;
    for(auto &z : path)
    {
        for(int ft = 0; ft < z; ft++)
        {
            for(int i = 0; i < n; i++)
            {
                if(blocked[i])
                {
                    continue;
                }
                if(mt[i] == -1)
                {
                    continue;
                }
                int a = i;
                int b = mt[i];
                mt[a] = mt[b] = -1;
                blocked[a] = 1;
                if(!dfs(b, sz++))
                {
                    ans.push_back(a + 1);
                    break;
                }
                blocked[a] = 0;
                a = b;
                b = mt[a];
                mt[a] = mt[b] = -1;
                blocked[a] = 1;
                ans.push_back(-(a - n + 1));
                break;
            }
        }
        ans.push_back(0);
    }
    cout << sz(ans) << "\n";
    for(auto v : ans)
    {
        cout << v << " ";
    }
    return 0;
}