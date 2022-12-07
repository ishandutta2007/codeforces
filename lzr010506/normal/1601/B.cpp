#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1), d(3 * n, 3 * n), p(3 * n), f(3 * n);
    for (int i = 1; i <= n; i += 1) cin >> a[i];
    for (int i = 1; i <= n; i += 1) cin >> b[i];
    vector<vector<pair<int, int>>> G(3 * n);
    vector<int> ls(2 * n), rs(2 * n);
    int r, t = 0;
    function<void(int&, int, int, int)> build = [&](int& v, int tl, int tr, int p) {
        v = t += 1;
        if (p) G[v + n].push_back({p + n, 0});
        int tm = midpoint(tl, tr);
        if (tl == tr) {
            G[tm + b[tm]].push_back({v + n, 0});
            f[v + n] = tm;
        }
        else {
            build(ls[v], tl, tm, v);
            build(rs[v], tm + 1, tr, v);
        }
    };
    build(r, 1, n, 0);
    function<void(int, int, int, int, int, int)> add = [&](int v, int tl, int tr, int u, int L, int R) {
        if (tl >= L and tr <= R) return G[v + n].push_back({u, 1});
        else {
            int tm = midpoint(tl, tr);
            if (L <= tm) add(ls[v], tl, tm, u, L, R);
            if (R > tm) add(rs[v], tm + 1, tr, u, L, R);
        }
    };
    for (int i = 1; i <= n; i += 1) {
        if (a[i] == i) G[0].push_back({i, 1});
        int L = max(i - a[i], 1), R = i;
        add(1, 1, n, i, L, R);
    }
    deque q{0};
    d[0] = 0;
    while (not q.empty()) {
        int u = q.front();
        q.pop_front();
        for (auto [v, w] : G[u]) {
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                p[v] = u;
                if (w) q.push_back(v);
                else q.push_front(v);
            }
        }
    }
    if (0) for (int i = 1; i < 3 * n; i += 1)
        for (auto [j, w] : G[i]) cout << i << " " << j << " " << w << "\n";
    if (d[n] == 3 * n) {
        cout << "-1";
        return 0;
    }
    vector<int> path;
    for (int x = n; x; x = p[x]) if (f[x]) path.push_back(f[x]);
    cout << path.size() + 1 << "\n";
    for (int x : path) cout << x << " "; cout << "0";
    return 0;
}