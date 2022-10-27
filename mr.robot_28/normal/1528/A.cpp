#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define int long long
#define sz(a) (int)a.size()
#define ll long long
const int N = 2e5 + 100;
int L[N], R[N];
vector <int> g[N];
int dp1[N], dp2[N];
void dfs(int v, int p = -1)
{
    int c = 0;
    for(auto to : g[v])
    {
        if(to == p)
        {
            continue;
        }
        c++;
        dfs(to, v);
    }
    if(c == 0)
    {
        dp1[v] = dp2[v] = 0;
        return;
    }
    dp1[v] = dp2[v] = 0;
    for(auto to : g[v])
    {
        if(to == p)
        {
            continue;
        }
        dp1[v] += max(dp1[to] + abs(L[to] - L[v]), dp2[to] + abs(L[v] - R[to]));
        dp2[v] += max(dp2[to] + abs(R[to] - R[v]), dp1[to] + abs(L[to] - R[v]));
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
        for(int i = 0; i < n; i++)
        {
            g[i].clear();
        }
        for(int i = 0; i < n; i++)
        {
            cin >> L[i] >> R[i];
        }
        for(int i = 0;i < n- 1; i++)
        {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        dfs(0);
        cout << max(dp1[0], dp2[0]) << "\n";
    }
    return 0;
}