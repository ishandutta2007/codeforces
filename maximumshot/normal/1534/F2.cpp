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

struct RangeTree {
    int n = 0; // [0, n)
    vector<int> t;

    RangeTree(int n_) {
        n = n_;
        t.resize(2 * n, inf);
    }

    void put(int pos, int val) {
        for (pos += n, t[pos] = val, pos >>= 1; pos > 0; pos >>= 1)
            t[pos] = min(t[pos << 1], t[pos << 1 | 1]);
    }

    int query(int l, int r) {
        int res = inf;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res = min(res, t[l++]);
            if (r & 1) res = min(res, t[--r]);
        }
        return res;
    }
};

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<string> mat(n);
    for (int i = 0; i < n; i++)
        cin >> mat[i];

    vector<int> a(m);
    for (int j = 0; j < m; j++)
        cin >> a[j];

    vector<vector<int>> ar(m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == '#') {
                ar[j].push_back(i);
            }
        }
    }

    vector<vector<int>> g(n * m), gr(n * m);

    auto add_edge = [&](pii fr, pii to) {
        int u = fr.first * m + fr.second;
        int v = to.first * m + to.second;
        g[u].push_back(v);
        gr[v].push_back(u);
    };

    for (int j = 0; j < m; j++) {
        for (int it = 0; it + 1 < (int) ar[j].size(); it++) {
            int curi = ar[j][it];
            int nxti = ar[j][it + 1];
            add_edge({curi, j}, {nxti, j});
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] != '#')
                continue;
            if (i > 0 && mat[i - 1][j] == '#') add_edge({i, j}, {i - 1, j});
            for (int dj : {-1, 1}) {
                int tj = j + dj;
                if (0 <= tj && tj < m) {
                    int it = lower_bound(ar[tj].begin(), ar[tj].end(), i) - ar[tj].begin();
                    if (it < (int) ar[tj].size()) {
                        it = ar[tj][it];
                        add_edge({i, j}, {it, tj});
                    }
                }
            }
        }
    }

    vector<int> imp(n * m);
    for (int j = 0; j < m; j++) {
        if (a[j] > 0) {
            int i = ar[j][(int) ar[j].size() - a[j]];
            imp[i * m + j] = 1;
        }
    }

    vector<int> used(n * m), tops, color(n * m);
    function<void(int)> dfs = [&](int v) {
        if (used[v])
            return;
        used[v] = 1;
        for (int to : g[v]) {
            dfs(to);
        }
        tops.push_back(v);
    };
    for (int v = 0; v < n * m; v++) {
        dfs(v);
    }

    reverse(tops.begin(), tops.end()); // ->

    function<void(int, int)> paint = [&](int v, int cl) {
        if (used[v])
            return;
        used[v] = 1;
        color[v] = cl;
        for (int to : gr[v])
            paint(to, cl);
    };
    used.assign(n * m, 0);
    int cur_color = 0;
    for (int v : tops) {
        if (used[v])
            continue;
        paint(v, cur_color);
        cur_color++;
    }

    vector<int> IMP(cur_color);
    for (int v = 0; v < n * m; v++) {
        if (imp[v])
            IMP[color[v]] = 1;
    }

    vector<vector<int>> G(cur_color), GR(cur_color);
    for (int v = 0; v < n * m; v++) {
        for (int to : g[v]) {
            int cv = color[v];
            int cto = color[to];
            if (cv != cto) {
                G[cv].push_back(cto);
                GR[cto].push_back(cv);
            }
        }
    }

    vector<int> TOPS;
    function<void(int)> DFS = [&](int v) {
        if (used[v])
            return;
        used[v] = 1;
        for (int to : G[v])
            DFS(to);
        TOPS.push_back(v);
    };
    used.assign(cur_color, 0);
    for (int v = 0; v < cur_color; v++)
        DFS(v);
    reverse(TOPS.begin(), TOPS.end()); // ->

    vector<int> f(cur_color);

    for (int v : TOPS) {
        for (int to : GR[v]) {
            f[v] |= f[to] | IMP[to];
        }
    }

    for (int v = 0; v < cur_color; v++) {
        if (f[v] && IMP[v])
            IMP[v] = 0;
    }

    vector<int> L(cur_color, m), R(cur_color, -1);
    reverse(TOPS.begin(), TOPS.end()); // <-

    for (int v = 0; v < n * m; v++) {
        int cv = color[v];
        if (!IMP[cv] || !imp[v])
            continue;
        L[cv] = min(L[cv], v % m);
        R[cv] = max(R[cv], v % m);
    }

    for (int v : TOPS) {
        for (int to : G[v]) {
            L[v] = min(L[v], L[to]);
            R[v] = max(R[v], R[to]);
        }
    }

    vector<vector<int>> ls(m);
    for (int v = 0; v < cur_color; v++) {
        if (L[v] <= R[v]) {
            ls[R[v]].push_back(L[v]);
        }
    }

    vector<int> imp_col(m);
    for (int v = 0; v < n * m; v++) {
        int cv = color[v];
        if (imp[v] && IMP[cv])
            imp_col[v % m] = 1;
    }

    RangeTree rt(m);

    for (int i = 0; i < m; i++) {
        int cur = inf;
        if (!imp_col[i])
            cur = i > 0 ? rt.query(i - 1, i - 1) : 0;
        for (int l : ls[i]) {
            // [l, i]
            int ql = l - 1;
            int qr = i - 1;
            if (ql < 0)
                cur = min(cur, 1), ql = 0;
            cur = min(cur, rt.query(ql, qr) + 1);
        }
        rt.put(i, cur);
    }

    cout << rt.query(m - 1, m - 1) << "\n";

    return 0;
}