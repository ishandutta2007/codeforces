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

bool check(int n, int m, vector<vector<int>> g, vector<int> x, vector<int> res) {
    if ((int) res.size() > 4 * n) {
        cout << "Too long " << (int) res.size() << " > " << 4 * n << "\n";
        return false;
    }
    vector<set<int>> G(n + 1);
    for (int v = 1; v <= n; v++)
        for (int to : g[v])
            G[v].insert(to);
    vector<int> cnt(n + 1);
    for (int i = 0; i + 1 < (int) res.size(); i++) {
        if (!G[res[i]].count(res[i + 1])) {
            cout << "No edge " << res[i] << " -> " << res[i + 1] << "\n";
            return false;
        }
    }
    for (int v : res)
        cnt[v] ^= 1;
    for (int v = 1; v <= n; v++) {
        if (cnt[v] != x[v]) {
            cout << "Incorrect parity for v = " << v << "\n";
            return false;
        }
    }
    cout << "OK" << endl;
    return true;
}

pair<vector<int>, bool> fast(int n, int m, vector<vector<int>> g, vector<int> x) {
    vector<int> xx = x;

    int root = n + 1, any = n + 1;
    for (int v = 1; v <= n; v++) {
        if (!x[v])
            continue;
        any = v;
        int ok = 0;
        for (int to : g[v]) {
            if (!x[to])
                ok = 1;
        }
        if (ok) {
            root = v;
            break;
        }
    }
    if (root > n)
        root = any;

    if (root > n) {
        return {{}, true};
    }

    vector<int> res, used(n + 1), y(n + 1);

    function<void(int)> dfs = [&](int v) {
        used[v] = 1;
        y[v] ^= 1;
        res.push_back(v);
        for (int to : g[v]) {
            if (used[to])
                continue;
            dfs(to);
            if (y[to] != x[to]) {
                res.push_back(v);
                res.push_back(to);
                res.push_back(v);
                y[to] ^= 1;
            } else {
                y[v] ^= 1;
                res.push_back(v);
            }
        }
    };

    {
        int ok = 0;
        for (int to : g[root]) {
            if (!x[to])
                ok = 1;
        }
        if (!ok && !g[root].empty()) {
            for (int to : g[root]) {
                res.push_back(root);
                res.push_back(to);
                x[root] = 0;
                x[to] = 0;
                break;
            }
        }
    }

    dfs(root);
    if (x[root] != y[root]) {
        for (int to : g[root]) {
            if (!x[to]) {
                res.push_back(to);
                res.push_back(root);
                res.push_back(to);
                break;
            }
        }
    }

    for (int v = 1; v <= n; v++) {
        if (x[v] && !used[v]) {
            return {{}, false};
        }
    }

    if (n == 2) {
        if (xx[1] && xx[2]) {
            res = {1, 2};
        } else if (xx[1]) {
            res = {1};
        } else if (xx[2]) {
            res = {2};
        }
    }

    return {res, true};
}

void work() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n + 1);
    for (int u, v, i = 0; i < m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> x(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> x[i];

    auto [res, fl] = fast(n, m, g, x);

    if (fl) {
        cout << (int) res.size() << "\n";
        for (int v : res)
            cout << v << " ", x[v] ^= 1;
        cout << "\n";
    } else {
        cout << "-1\n";
    }
}

void test() {
    mt19937 rnd(42);
    const int N = 200;
    const int M = 400;
    while (1) {
        int n = rnd() % (N - 2) + 2;
        int m = rnd() % M;
        vector<vector<int>> g(n + 1);
        for (int u, v, i = 0; i < m; i++) {
            while (1) {
                u = rnd() % n + 1;
                v = rnd() % n + 1;
                if (u != v)
                    break;
            }
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector<int> x(n + 1);
        for (int i = 1; i <= n; i++)
            x[i] = rnd() % 2;

        auto [res, fl] = fast(n, m, g, x);

        if (fl && !check(n, m, g, x, res)) {
            cout << "\n";
            cout << n << " " << m << "\n";
            for (int v = 1; v <= n; v++) {
                for (int to : g[v]) {
                    if (v < to)
                        cout << v << " " << to << "\n";
                }
            }
            for (int v = 1; v <= n; v++)
                cout << x[v] << " ";
            cout << "\n";
            cout << "res = "; for (int v : res) cout << v << " ";
            cout << "\n";
            break;
        }
    }
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();
//    test();

    return 0;
}