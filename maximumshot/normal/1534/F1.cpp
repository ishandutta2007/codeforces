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

    vector<int> color(n * m), tops, used;

    function<void(int)> dfs = [&](int v) {
        if (used[v])
            return;
        used[v] = 1;
        for (int to : g[v]) {
            dfs(to);
        }
        tops.push_back(v);
    };
    used.assign(n * m, 0);
    for (int v = 0; v < n * m; v++) {
        dfs(v);
    }
    reverse(tops.begin(), tops.end());
    used.assign(n * m, 0);
    int curColor = 0;
    function<void(int, int)> paint = [&](int v, int cl) {
        if (used[v])
            return;
        used[v] = 1;
        color[v] = cl;
        for (int to : gr[v])
            paint(to, cl);
    };
    for (int v : tops) {
        if (used[v])
            continue;
        paint(v, curColor);
        curColor++;
    }

    vector<int> din(curColor), cnt(curColor);
    for (int v = 0; v < n * m; v++) {
        int cv = color[v];
        for (int to : g[v]) {
            int cto = color[to];
            if (cv == cto)
                continue;
            din[cto]++;
        }
        if (mat[v / m][v % m] == '#')
            cnt[cv]++;
    }

    int res = 0;
    for (int c = 0; c < curColor; c++) {
        if (din[c] == 0 && cnt[c] > 0) {
            res++;
        }
    }

    cout << res << "\n";

    return 0;
}