#include <bits/stdc++.h>

using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    int n, m, q; cin >> n >> m >> q;
    vector< vector<int> > g(n);
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y; x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<char> used(n, false);
    vector<int> tin(n), fup(n);
    int timer = 0;

    function<void(int, int)> dfs = [&](int v, int p) {
        tin[v] = fup[v] = timer++;
        used[v] = true;
        for (int to: g[v]) {
            if (to == p) {
                continue;
            }
            if (used[to]) {
                fup[v] = min(fup[v], tin[to]);
            } else {
                dfs(to, v);
                fup[v] = min(fup[v], fup[to]);
            }
        }
    };
    dfs(0, -1);

    used.assign(n, 0);

    vector<int> w(n, 0);
    vector< vector<int> > t(n);
    set< pair<int, int> > st;

    auto addEdge = [&](int a, int b) {
        if (a > b) {
            swap(a, b);
        }
        if (!st.count({a, b})) {
            t[a].push_back(b);
            t[b].push_back(a);
            st.emplace(a, b);
        }
    };

    function<void(int, int, int)> go = [&](int v, int p, int color) {
        used[v] = 1;
        for (int to: g[v]) {
            if (to == p || used[to] == 2) {
                continue;
            }
            if (used[to]) {
                addEdge(v, color);
                addEdge(to, color);
            } else {
                int col = color;
                if (fup[to] >= tin[v]) {
                    col = t.size();
                    t.emplace_back();
                    w.push_back(1);
                }
                addEdge(v, col);
                addEdge(to, col);
                go(to, v, col);
            }
        }
        used[v] = 2;
    };
    go(0, -1, -1);

    int k = w.size();
    int l = 20;
    vector< vector<int> > up(k, vector<int>(l));
    vector<int> lin(k), lout(k);
    int limer = 0;
    vector<int> dist(k);

    function<void(int, int)> lfs = [&](int v, int p) {
        lin[v] = limer++;
        up[v][0] = p;
        dist[v] = dist[p];
        dist[v] += w[v];
        for (int i = 1; i < l; i++) {
            up[v][i] = up[up[v][i-1]][i-1];
        }
        for (int to: t[v]) {
            if (to != p) {
                lfs(to, v);
            }
        }
        lout[v] = limer++;
    };
    lfs(0, 0);

    auto upper = [&](int a, int b) {
        return lin[a] <= lin[b] && lout[b] <= lout[a];
    };

    auto lca = [&](int a, int b) {
        if (upper(b, a)) {
            return b;
        }
        if (upper(a, b)) {
            return a;
        }
        for (int i = l-1; i >= 0; i--) {
            if (!upper(up[a][i], b)) {
                a = up[a][i];
            }
        }
        return up[a][0];
    };

    for (int i = 0; i < q; i++) {
        int a, b; cin >> a >> b; a--; b--;
        int l = lca(a, b);
        cout << w[l] + dist[a] + dist[b] - 2*dist[l] << "\n";
    }

    return 0;
}