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

int fast(int n, vector<pii> edges) {
    vector<int> is_fib(n + 1);
    is_fib[1] = 1;
    for (int f1 = 1, f2 = 1;;) {
        int f3 = f1 + f2;
        if (f3 > n)
            break;
        is_fib[f3] = 1;
        f1 = f2;
        f2 = f3;
    }
    if (!is_fib[n])
        return 0;
    auto get_to = [&](int eid, int from) -> int {
        auto [u, v] = edges[eid];
        return u == from ? v : u;
    };
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n - 1; i++) {
        auto [u, v] = edges[i];
        g[u].push_back(i);
        g[v].push_back(i);
    }
    vector<int> used(n - 1), sz(n + 1);
    function<void(int, int)> go = [&](int v, int par) {
        sz[v] = 1;
        for (int eid : g[v]) {
            if (used[eid])
                continue;
            int to = get_to(eid, v);
            if (to == par)
                continue;
            go(to, v);
            sz[v] += sz[to];
        }
    };
    mt19937 rnd(42);
    function<void(int, int, int, int&)> find = [&](int v, int par, int Size, int& fnd) {
        for (int eid : g[v]) {
            if (used[eid])
                continue;
            int to = get_to(eid, v);
            if (to == par)
                continue;
            if (is_fib[sz[to]] && is_fib[Size - sz[to]]) {
                if (fnd == -1 || rnd() % 2)
                    fnd = eid;
            }
            find(to, v, Size, fnd);
        }
    };
    function<int(int)> rec = [&](int v) -> int {
        go(v, -1);
        int fnd = -1;
        find(v, -1, sz[v], fnd);
        if (sz[v] == 1)
            return 1;
        if (fnd == -1) {
            return 0;
        }
        used[fnd] = 1;
        auto [x, y] = edges[fnd];
        return rec(x) && rec(y);
    };
    return rec(1);
}

void work() {
    int n;
    cin >> n;
    vector<pii> edges(n - 1);
    for (auto& [u, v] : edges)
        cin >> u >> v;
    int fs = fast(n, edges);
    cout << (fs ? "YES" : "NO") << "\n";
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();

    return 0;
}