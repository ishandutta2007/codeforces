#include<bits/stdc++.h>
#define pb push_back
#define all(x) (x).begin(), (x).end()
using namespace std;

const int N = 3e5 + 5;

int n, m, k, used[N], is[N], r[N], down[N], up[N];
vector<int> g[N], gt[N];
vector<int> order;

void dfs_ts(int v)
{
    used[v] = 1;
    for (auto u : g[v])
        if (used[u] == 0)
            dfs_ts(u);
        else if (used[u] == 1)
        {
            cout << -1;
            exit(0);
        }
    used[v] = 2;
    order.pb(v);
}

bool cmp(int a, int b)
{
    return up[a] < up[b];
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> r[i];
        is[r[i]] = 1;
    }
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        gt[b].pb(a);
    }
    for (int i = 1; i <= n; i++)
        if (!used[i])
            dfs_ts(i);


    reverse(all(order));

    ///top first
    for (auto v : order)
    {
        up[v] = k;
        if (r[v] != 0)
            up[v] = r[v];
        for (auto u : gt[v])
            up[v] = min(up[v], up[u] - 1);
        if (up[v] < r[v] && r[v] != 0) {
            cout << -1;
            return 0;
        }
    }
    //cout << 1 << endl;

    ///bottom first
    reverse(all(order));
    for (auto v : order)
    {
        down[v] = 1;
        if (r[v] != 0)
            down[v] = r[v];
        for (auto u : g[v])
            down[v] = max(down[v], down[u] + 1);
        if (down[v] > r[v] && r[v] != 0) {
            cout << -1;
            return 0;
        }
    }
    //cout << 2 << endl;

    set<int> nouse;
    for (int i = 1; i <= k; i++)
        if (!is[i])
            nouse.insert(i);

    for (int i = 1; i <= n; i++)
    {
        if (up[i] < down[i])
        {
            cout << -1;
            return 0;
        }
    }

    sort(all(order), cmp);


    for (auto v : order)
    {
        if (!r[v])
            if (nouse.size() == 0)
            {
                r[v] = 1;
                for (auto u : g[v])
                    r[v] = max(r[v], r[u] + 1);
                if (r[v] < down[v] || r[v] > up[v])
                {
                    cout << -1;
                    return 0;
                }
            }
            else
            {
                auto it = nouse.lower_bound(down[v]);

                if (it == nouse.end() || *it > up[v] )
                {
                    r[v] = 1;
                    for (auto u : g[v])
                        r[v] = max(r[v], r[u] + 1);
                    if (r[v] < down[v] || r[v] > up[v])
                    {
                        cout << -1;
                        return 0;
                    }
                    continue;
                }

                r[v] = *it;
                nouse.erase(it);

            }
    }
    if (nouse.size() != 0) {
        cout << -1;
        return 0;
    }
    for (int i = 1; i <= n; i++)
        cout << r[i] << ' ';
    return 0;
}