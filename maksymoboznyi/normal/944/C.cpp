#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ull unsigned long long

using namespace std;

const int N = 1e5+5;
const ll inf = 2e18;
int n, ml = N;
struct cell
{
    int level, num;
};
cell l[N];
vector<int> g[N], p[N];

void dfs(int v, int c = 1)
{
    l[v].level = c;
    p[c].pb(v);
    for (int i = 0; i < int(g[v].size()); i++)
        dfs(g[v][i], c+1);
}

bool cmp(cell a, cell b)
{
    return a.level > b.level;
}

signed main()
{
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        int y;
        cin >> y;
        g[y].pb(i);
    }
    int ans = 0;
    dfs(1);
    for (int i = 1; i <= n; i++)
    {
        int k = 0;
        for (int j = 0; j < p[i].size(); j++)
        {
            k += 1;
        }
        ans += k%2;
    }
    cout << ans;
    return 0;
}