#include <bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;

const int N = 1e5 + 5;

struct edge {
    int u, w, v, c;
};
vector<edge> e;
int a1[20*N], a2[20*N], n1, n2;

int n, S, sz[N], d[N];
int cur = 0;
vector<pair<int, int> > g[N];

void dfs(int v, int p, int go = 0) {
    d[v] = d[p] + go;
    sz[v] = 0;
    for (auto [u, c]: g[v])
        if (u != p)
            dfs(u, v, c), sz[v] += sz[u];
    if (sz[v] == 0) {
        sz[v] = 1;
        cur += d[v];
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
    cin >> n >> S;
    e.clear();
    for (int i = 1; i <= n; i++)
        g[i].clear();
    n1 = n2 = 0;
    cur = 0;
    for (int i = 1; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c;
        d = 1;
        e.pb({a, b, c, d});
        g[a].pb({b, c});
        g[b].pb({a, c});
    }
    dfs(1, 0);
    for (auto [u, v, w, c]: e)
        while (w > 0)
            if (c == 1) {
                n1++;
                a1[n1] = (w + 1) / 2 * min(sz[u], sz[v]);
                w /= 2;
            } else {
                n2++;
                a2[n2] = (w + 1) / 2 * min(sz[u], sz[v]);
                w /= 2;
            }
    sort(a1 + 1, a1 + n1 + 1);
    reverse(a1 + 1, a1 + n1 + 1);
    sort(a2 + 1, a2 + n2 + 1);
    reverse(a2 + 1, a2 + n2 + 1);
    for (int i = 1; i <= n1; i++)
        a1[i] = a1[i - 1] + a1[i];
    for (int i = 1; i <= n2; i++)
        a2[i] = a2[i - 1] + a2[i];
    int ans = 1e18;
    for (int i = 0; i <= n1; i++) {
        int need = cur - a1[i] - S;
        while (n2 > 0 && a2[n2 - 1] >= need)
            n2--;
        if (a2[n2] >= need)
            ans = min(ans, i + n2 * 2);
    }
    cout << ans << "\n";
}
    return 0;
}