#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<ll>> g(n, vector<ll>(n, inf64));
    for (int v = 0; v < n; v++)
        g[v][v] = 0;

    vector<tuple<int, int, ll>> edges;
    for (int i = 0; i < m; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--, v--;
        g[u][v] = g[v][u] = w;
        edges.emplace_back(u, v, w);
    }

    vector<vector<ll>> h(n, vector<ll>(n));
    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int u, v;
        ll l;
        cin >> u >> v >> l;
        u--, v--;
        h[u][v] = h[v][u] = l;
    }

    for (int w = 0; w < n; w++) {
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                g[u][v] = min(g[u][v], g[u][w] + g[w][v]);
            }
        }
    }

    for (int w = 0; w < n; w++) {
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
//                g[u][v] = min(g[u][v], g[u][w] + g[w][v]);
                h[u][w] = max(h[u][w], h[u][v] - g[w][v]);
                h[w][v] = max(h[w][v], h[u][v] - g[u][w]);
            }
        }
    }



    int res = 0;
    for (auto [u, v, w] : edges) {
        if (w <= h[u][v])
            res++;
    }

    cout << res << "\n";

    return 0;
}