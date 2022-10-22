#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

void work() {
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    vector<int> id(n + 1);
    vector<vector<pii>> g(4 * n + n + 5);
    function<void(int, int, int)> build = [&](int v, int tl, int tr) {
        if (tl == tr) {
            id[tl] = v;
        } else {
            g[v].emplace_back(v << 1, 0);
            g[v].emplace_back(v << 1 | 1, 0);
            int tm = (tl + tr) >> 1;
            build(v << 1, tl, tm);
            build(v << 1 | 1, tm + 1, tr);
        }
    };
    build(1, 1, n);
    for (int v = 1; v <= n; v++) {
        g[id[v]].emplace_back(4 * n + v + b[v], 0);
    }
    function<void(int, int, int, int, int, int)> add_edges = [&](int v, int tl, int tr, int l, int r, int fr) {
        if (l <= tl && tr <= r) {
            g[fr].emplace_back(v, 1);
        } else {
            int tm = (tl + tr) >> 1;
            if (l <= tm) add_edges(v << 1, tl, tm, l, r, fr);
            if (r > tm) add_edges(v << 1 | 1, tm + 1, tr, l, r, fr);
        }
    };
    for (int v = 1; v <= n; v++) {
        add_edges(1, 1, n, max(1, v - a[v]), v, 4 * n + v);
    }
    int st = 4 * n + n;
    vector<int> dist(g.size(), inf), from(g.size(), -1);
    dist[st] = 0;
    deque<int> q;
    q.push_back(st);
    while (!q.empty()) {
        int v = q.front();
        q.pop_front();
        for (auto [to, w] : g[v]) {
            if (dist[to] > dist[v] + w) {
                dist[to] = dist[v] + w;
                from[to] = v;
                if (w) q.push_back(to);
                else q.push_front(to);
            }
        }
    }
    int fn = -1;
    for (int v = 1; v <= n; v++) {
        if (dist[4 * n + v] == inf)
            continue;
        if (v - a[v] == 0 && (fn == -1 || dist[fn] > dist[4 * n + v])) {
            fn = 4 * n + v;
        }
    }
    if (fn == -1) {
        cout << "-1\n";
        return;
    }
    cout << dist[fn] + 1 << "\n";
    vector<int> path;
    vector<int> rev_id(g.size(), -1);
    for (int v = 1; v <= n; v++)
        rev_id[id[v]] = v;
    for (int v = fn; v != st; v = from[v]) {
        if (rev_id[v] != -1)
            path.push_back(rev_id[v]);
    }
    reverse(path.begin(), path.end());
    path.push_back(0);
    for (int v : path)
        cout << v << " ";
    cout << "\n";
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    work();

    return 0;
}