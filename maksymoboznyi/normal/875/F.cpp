#include <iostream>
#include <algorithm>
using namespace std;
const int N = 2e5+5;

int n, m, par[N], a[N], b[N], w[N], r[N];
bool cycle[N];

bool cmp(int a, int b)
{
    return w[a] > w[b];
}

int fin(int v)
{
    if (par[v] == v)
        return v;
    else
    {
        par[v] = fin(par[v]);
        return par[v];
    }
}

bool unit(int u, int v)
{
    int up = fin(u), vp = fin(v);
    if (up == vp)
        if (cycle[up])
        {
            cycle[up] = false;
            return true;
        }else
            return false;
    else
    {
        if (!cycle[up] && !cycle[vp])
            return false;
        par[up] = vp;
        cycle[vp] = cycle[up] && cycle[vp];
        return true;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i] >> b[i] >> w[i];
        r[i] = i;
    }
    sort(r+1, r+m+1, cmp);
    //cout << 1 << endl;
    for (int i = 1; i <= n; i++)
        par[i] = i, cycle[i] = 1;
    long long ans = 0;
    for (int i = 1; i <= m; i++)
    {
        int j = r[i], u = a[j], v = b[j];
        if (unit(u, v)) ans += w[j];
        //cout << ans << endl;
    }
    cout << ans;
    return 0;
}