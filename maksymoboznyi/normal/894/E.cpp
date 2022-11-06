#include <bits/stdc++.h>
#define pb push_back
#define int unsigned long long
using namespace std;

const int N = 1e6 + 6;

int n, m, used[N], col[N];
unsigned long long st[N], dp[N], pref[N], val[N];
vector<pair<int, int> > gn[N], g[N], gt[N];
vector<int> order, comp;

void dfs1(int v) {
    used[v] = 1;
    for (int i = 0; i < g[v].size(); i++)
        if (!used[g[v][i].first])
            dfs1(g[v][i].first);
    order.pb(v);
}

void dfs2(int v) {
    used[v] = 1;
    comp.pb(v);
    for (int i = 0; i < gt[v].size(); i++)
        if (!used[gt[v][i].first])
            dfs2(gt[v][i].first);
}

long long get_val(long long x) {
    long long d = 1 + 8 * x;
    long long c = sqrt(d);
    for (int i = 1; i <= 5; i++) {
    if (c * c > d)
        c--;
    if ((c + 1) * (c + 1) <= d)
        c++;
    }

    long long n = (c - 1) / 2;
    return x * (n + 1) - pref[n];
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 1; i <= 100000; i++)
        val[i] = val[i - 1] + i;
    for (int i = 1; i <= 100000; i++)
        pref[i] = pref[i - 1] + val[i];
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].pb({b, c});
        gt[b].pb({a, c});
    }
    for (int i = 1; i <= n; i++)
        if (!used[i])
            dfs1(i);
    for (int i = 1; i <= n; i++)
        used[i] = 0;
    int c = 0;
    for (int i = 0; i < n; i++) {
        int v = order[n - i - 1];
        if (!used[v]) {
            dfs2(v);
            c++;
            for (int j = 0; j < comp.size(); j++)
                col[comp[j]] = c;
            comp.clear();
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < g[i].size(); j++) {
            int v = g[i][j].first, s = g[i][j].second;
            if (col[v] == col[i])
                st[col[v]] += get_val(s);
            else
                gn[col[i]].pb({col[v], s});
        }
    for (int i = c; i > 0; i--) {
        dp[i] = st[i];
        for (int j = 0; j < gn[i].size(); j++) {
            int v = gn[i][j].first, s = gn[i][j].second;
            //cout << i << ' ' << v << ' ' << s << ' ' << get_val(s) << endl;
            dp[i] = max(dp[i], st[i] + dp[v] + s);
        }
    }
    int s;
    cin >> s;
    cout << dp[col[s]];
    return 0;
}