#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

const int N = 2e5 + 5;
const long long inf = 2e18;
const long long M = 1e9 + 7;

vector<int> go[N], g[N];
int m[N], m2[N], is[N], n, a[N], dep[N], par[N];

void dfs(int v, int p = 0) {
    dep[v] = dep[p] + 1;
    par[v] = p;
    for (int i = 0; i < g[v].size(); i++)
        if (!dep[g[v][i]])
            dfs(g[v][i], v);
}

bool cmp(int a, int b) {
    return dep[a] > dep[b];
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    vector<int> pr;
    for (int i = 2; i <= 200000; i++)
        if (!is[i])
        {
            pr.pb(i);
            for (int j = i; 1ll*j*i <= 200000; j++)
                is[j*i] = 1;
        }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        int p = 2;
        int q = a[i];
        while (p * p <= q) {
            //p++;
            if (a[i] % p == 0) {
                go[p].pb(i);
                while(a[i] % p == 0)
                    a[i] /= p;
            }
            p++;
        }
        if (a[i] != 1)
            go[a[i]].pb(i);
    }
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(1);
    int ans = 0;
    for (int i = 0; i < pr.size(); i++) {
        sort(go[pr[i]].begin(), go[pr[i]].end(), cmp);
        int p = pr[i];
        for (int j = 0; j < go[p].size(); j++)
            m[go[p][j]] = m2[go[p][j]] = 0;
        for (int j = 0; j < go[p].size(); j++) {
            int pos = go[p][j];
            //cout << p << ' ' << pos << ' ' << m[pos] << ' ' << m2[pos] << endl;
            ans = max(ans, m[pos] + 1 + m2[pos]);
            int x = m[pos] + 1;
            if (x >= m[par[pos]]) {
                m2[par[pos]] = m[par[pos]];
                m[par[pos]] = x;
            } else if (x > m2[par[pos]])
                m2[par[pos]] = x;
        }
    }
    cout << ans << endl;
    return 0;
}