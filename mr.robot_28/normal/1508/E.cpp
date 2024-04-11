#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
const int N = 3e5 + 100;
int n;
int a[N], par[N], pos[N];
int tin[N], tout[N], ex[N];
int tin1[N];
ll ans = 0;
vector <int> g[N];
int bor;
int timer = 0;
int timer1 = 0;
int timer2 = 0;
bool cmp(int u, int v)
{
    return a[u] < a[v];
}
void dfs(int v, int h = 0)
{
    tin[v] = ++timer;
    if(a[v] >= bor)
    {
        tin1[v] = ++timer1 + bor - 1;
    }
    sort(g[v].begin(), g[v].end(), cmp);
    for(auto to : g[v])
    {
        dfs(to, h + 1);
    }
    tout[v] = ++timer2;
    if(a[v] < bor)
    {
        ans += h;
    }
    ex[v] = timer;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pos[a[i]] = i;
    }
    for(int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        par[b] = a;
    }
    bor = max(1, a[1] - 1);
    int cur_node = pos[bor];
    for(int u = cur_node; u != 1; u = par[u])
    {
        swap(pos[a[u]], pos[a[par[u]]]);
        swap(a[u], a[par[u]]);
        ans++;
    }
    dfs(1);
    for(int i = 1;i <= n; i++)
    {
        if(a[i] < bor && a[i] != tout[i])
        {
            cout << "NO\n";
            exit(0);
        }
        if(a[i] >= bor && a[i] != tin1[i])
        {
            cout << "NO\n";
            exit(0);
        }
    }
    for(int i = 1; i <= n; i++)
    {
        if(tout[i] == bor && !(tin[i] >= tin[cur_node] && ex[i] <= ex[cur_node]))
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES\n";
    cout << ans << "\n";
    for(int i = 1; i <= n; i++)
    {
        cout << tin[i] << " ";
    }
    return 0;
}