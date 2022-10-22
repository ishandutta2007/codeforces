#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

void dfs(int v, vector<int> &used, vector<int> &tops, const vector<vector<int>> &g) {
    if (used[v]) return;
    used[v] = 1;
    for (int to : g[v]) {
        dfs(to, used, tops, g);
    }
    tops.push_back(v);
}

void mark(int v, vector<int> &color, int cur_color, const vector<vector<int>> &gr) {
    if (color[v]) return;
    color[v] = cur_color;
    for (int to : gr[v]) {
        mark(to, color, cur_color, gr);
    }
}

int tt, ti;

void solve() {
    int n, m;
    cin >> n >> m;
    string type;
    cin >> type;
    vector<vector<int>> g(2 * n), gr(2 * n);
    auto get_id = [&](int x) -> int {
        return x > 0 ? x - 1 : -x + n - 1;
    };
    auto get_rev = [&](int x) -> int {
        return x < n ? x + n : x - n;
    };
    for (int u, v, i = 0; i < m; i++) {
        cin >> u >> v;
        u = get_id(u);
        v = get_id(v);
        u = get_rev(u);
        g[u].push_back(v);
        g[get_rev(v)].push_back(get_rev(u));
    }
    for (int u = 0; u < 2 * n; u++) {
        for (int to : g[u]) {
            gr[to].push_back(u);
        }
    }
    vector<int> used(2 * n), tops, color(2 * n);
    for (int v = 0; v < 2 * n; v++) {
        if (used[v]) continue;
        dfs(v, used, tops, g);
    }
    reverse(tops.begin(), tops.end());
    int cur_color = 0;
    for (int v : tops) {
        if (color[v]) continue;
        cur_color++;
        mark(v, color, cur_color, gr);
    }
    for (int v = 0; v < n; v++) {
        if (color[v] == color[v + n]) {
            cout << "FALSE\n";
#ifdef debug
            cerr << "1" << endl;
            cerr << color[v] << "\n";
#endif
            return;
        }
    }
    vector<int> min_e_in_scc(cur_color + 1, inf), max_a_in_scc(cur_color + 1, -inf);
    for (int v = 0; v < 2 * n; v++) {
        int vv = v % n;
        int cc = color[v];
        if (type[vv] == 'E') {
            min_e_in_scc[cc] = min(min_e_in_scc[cc], vv);
        } else {
            if (max_a_in_scc[cc] != -inf && max_a_in_scc[cc] != vv) {
                cout << "FALSE\n";
#ifdef debug
                cerr << "2" << endl;
#endif
                return; // two As in one scc
            }
            max_a_in_scc[cc] = max(max_a_in_scc[cc], vv);
        }
    }
    for (int c = 1; c <= cur_color; c++) {
        if (min_e_in_scc[c] < max_a_in_scc[c]) {
            cout << "FALSE\n";
#ifdef debug
            cerr << "3" << endl;
#endif
            return;
        }
    }
    vector<int> can_in_scc(cur_color + 1), can_reach(cur_color + 1);
    for (int iter = (int) tops.size() - 1; iter >= 0; iter--) {
        int v = tops[iter];
        int vv = v % n;
        int cc = color[v];
        if (type[vv] == 'A') {
            can_in_scc[cc] = 1;
        }
    }
    for (int iter = (int) tops.size() - 1; iter >= 0; iter--) {
        int v = tops[iter];
        int vv = v % n;
        int cc = color[v];
        for (int to : g[v]) {
            if (color[to] == cc) continue;
            can_reach[cc] |= can_reach[color[to]];
            can_reach[cc] |= can_in_scc[color[to]];
        }
        if (can_in_scc[cc] && can_reach[cc]) {
            cout << "FALSE\n";
            return;
        }
    }
    cout << "TRUE\n";
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> tt;

    for (ti = 0; ti < tt; ti++) {
        solve();
    }

    return 0;
}