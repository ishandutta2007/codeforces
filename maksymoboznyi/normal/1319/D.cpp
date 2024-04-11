#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;

const int N = 5e5 + 5;

int n, d[N], p[N], m, k, mn[N], mx[N];
vector<int> g[N], pr[N];

int f[N], lst[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        g[b].pb(a);
    }
    cin >> k;
    for (int i = 1; i <= k; i++)
        cin >> p[i];
    for (int i = 1; i <= n; i++)
        d[i] = 1e9;
    d[p[k]] = 0;
    queue<int> q;
    q.push(p[k]);
    pr[p[k]].pb(-1);
    while (!q.empty()) {
        int v = q.front();
        //cout << v << endl;
        q.pop();
        for (auto u: g[v])
            if (pr[u].size() == 0)
                d[u] = d[v] + 1, q.push(u), pr[u].pb(v);
            else
                if (d[u] == d[v] + 1)
                    pr[u].pb(v);
    }
    for (int i = 1; i <= n; i++)
        sort(pr[i].begin() , pr[i].end());
    for (int i = 2; i <= k; i++) {
        int u = p[i - 1];
        int v = p[i];
        if(d[u] - 1 != d[v])
            mx[i] = mx[i - 1] + 1;
        else {
            mx[i] = mx[i - 1];
            if (pr[u].size() > 0 && pr[u][0] != v)
                mx[i] = mx[i - 1] + 1;
            if (pr[u].size() > 1 && pr[u][1] != v)
                mx[i] = mx[i - 1] + 1;
        }
        //cout << u << ' ' << v << ' ' << d[u] << ' ' << d[v] << endl;
        if (d[u] - 1 != d[v])
            mn[i] = mn[i - 1] + 1;
        else {
            mn[i] = mn[i - 1] + 1;
            int pos = lower_bound(pr[u].begin(), pr[u].end(), v)- pr[u].begin();
            //cout << pos << ' ' << pr[u][pos] << endl;
            if (pos < pr[u].size() && pr[u][pos] == v)
                mn[i] = mn[i - 1];
        }
        //cout << i << ' ' << mn[i] << ' ' << mx[i] << endl;
    }
    cout << mn[k] << ' ' << mx[k];
    return 0;
}