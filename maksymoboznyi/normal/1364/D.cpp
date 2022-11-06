#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define all(x) (x).begin(), (x).end()
#define pi pair<int, int>
#define int long long
using namespace std;

const int N = 3e5 + 5;

int n, par[N], used[N], m, k, p1 = 0, p2 = 0;
vector<int> g[N];
int col[N], c[N];

void dfs(int v, int p, int kol = 0) {
    par[v] = p;
    col[v] = kol;
    c[kol]++;
    //cout << v << endl;
    used[v] = 1;
    for (auto u: g[v])
        if (u != p && p1 == 0)
            if (used[u]) {
                //cout << v << ' ' << u << endl;
                p1 = v;
                p2 = u;
                return;
            }
            else
                dfs(u, v, !kol);
}

int sz[N];

signed main()
{
/*
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);*/
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1, 0);
    //cout << '!' << p1 << ' ' << p2 << endl;
    if (p1 == 0) {
        if (c[0] >= (k + 1) / 2) {
            int x = (k + 1) / 2;
            cout << "1\n";
            for (int i = 1; i <= n && x > 0; i++)
                if (col[i] == 0)
                    x--, cout << i << ' ';
            return 0;
        } else {
            int x = (k + 1) / 2;
            cout << "1\n";
            for (int i = 1; i <= n && x > 0; i++)
                if (col[i] == 1)
                    x--, cout << i << ' ';
            return 0;

        }
    }
    for (int i = 1; i <= n; i++)
        sz[i] = -1;
    vector<int> cycle;
    while (p1 != p2)
        cycle.pb(p1), p1 = par[p1];
    cycle.pb(p2);
    for (int i = 0; i < cycle.size(); i++)
        sz[cycle[i]] = i;
    int pos1 = 0, pos2 = cycle.size() - 1, bsz = cycle.size();
    for (auto v: cycle)
        for (auto u: g[v])
            if (sz[u] != -1 && sz[u] < sz[v] && sz[u] + 1 != sz[v] && (sz[v] != cycle.size() - 1 || sz[u] != 0)) {
                int l1 = sz[v] - sz[u] + 1;
                int l2 = cycle.size() - l1 + 2;
                if (l1 < bsz)
                    bsz = l1, pos1 = sz[u], pos2 = sz[v];
                if (l2 < bsz)
                    bsz = l2, pos1 = sz[v], pos2 = sz[u];
            }
    //cout << pos1 << ' ' << pos2 << endl;
    vector<int> nc;
    for (int i = pos1; i != pos2; i = (i + 1) % cycle.size())
        nc.pb(cycle[i]);
    nc.pb(cycle[pos2]);
    if (nc.size() <= k) {
        cout << "2\n";
        cout << nc.size() << "\n";
        for (auto x: nc)
            cout << x << ' ';
        return 0;
    }
    int x = (k + 1) / 2;
    cout << "1\n";
    for (int i = 0; i < cycle.size() && x > 0; i += 2)
        x--, cout << cycle[i] << ' ';
    return 0;
}