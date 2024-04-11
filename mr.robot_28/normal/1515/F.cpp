#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define int long long
#define sz(a) (int)a.size()
int mod = 1e9 + 7;
const int N = 3e5+ 100;
int used[N];
vector <pair <int, int> > g[N];
vector <int> ans;
int a[N];
int n, m, x;
vector <int> roads;
int dfs(int v)
{
    int s = a[v];
    used[v] = 1;
    for(auto to : g[v])
    {
        if(used[to.X])
        {
            continue;
        }
        int u = dfs(to.X);
        if(u < x)
        {
            roads.push_back(to.Y);
        }
        else
        {
            ans.push_back(to.Y);
            s += u - x;
        }
    }
    return s;
}
signed main()
{
  //  ifstream cin("input1.txt.4c");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> x;
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back({b, i});
        g[b].push_back({a, i});
    }
    if(sum < (n - 1) * x)
    {
        cout << "NO";
        return 0;
    }
    dfs(0);
    while(sz(roads))
    {
        ans.push_back(roads.back());
        roads.pop_back();
    }
    cout << "YES\n";
    for(auto v : ans)
    {
        cout << v + 1 << "\n";
    }
    return 0;
}