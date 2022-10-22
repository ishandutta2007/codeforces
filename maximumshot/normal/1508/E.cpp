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

tuple<bool, ll, vector<int>> slow(int n, vector<int> a, vector<pii> edges) {
    vector<vector<int>> g(n + 1);
    for (auto [u, v] : edges)
        g[u].push_back(v);
    for (int v = 1; v <= n; v++)
        sort(g[v].begin(), g[v].end());

    vector<int> p(n + 1);
    int timer;
    function<void(int)> go = [&](int v) {
        p[v] = ++timer;
        for (int to : g[v])
            go(to);
    };

    auto check = [&]() -> ll {
        timer = 0;
        go(1);
        for (ll days = 0;; days++) {
            if (p == a)
                return days;
            int bu = -1, bv = -1;
            for (int v = 1; v <= n; v++) {
                for (int to : g[v]) {
                    if (p[v] < p[to]) {
                        if (bu == -1) {
                            bu = v, bv = to;
                        } else {
                            if (make_pair(p[v], p[to]) < make_pair(p[bu], p[bv]))
                                bu = v, bv = to;
                        }
                    }
                }
            }
            if (bu == -1)
                return -1;
            swap(p[bu], p[bv]);
        }
    };

    tuple<bool, ll, vector<int>> res = {false, 0, {}};

    function<void(int)> rec = [&](int v) {
        if (v > n) {
            if (ll days = check(); days != -1) {
                timer = 0;
                go(1);
                res = {true, days, vector<int>(p.begin() + 1, p.end())};
            }
            return;
        }
        do {
            rec(v + 1);
        } while (next_permutation(g[v].begin(), g[v].end()));
    };
    rec(1);

    return res;
}

tuple<bool, ll, vector<int>> fast(int n, vector<int> a, vector<pii> edges) {
    vector<vector<int>> g(n + 1);
    vector<set<int>> h(n + 1);
    for (auto e : edges) {
        g[e.first].push_back(e.second);
        h[e.first].insert(e.second);
    }

    vector<int> any_leaf(n + 1, -1);
    function<void(int)> dfs = [&](int v) {
        if (g[v].empty()) {
            any_leaf[v] = v;
            return;
        }
        for (int to : g[v]) {
            dfs(to);
            any_leaf[v] = any_leaf[to];
        }
        sort(g[v].begin(), g[v].end(), [&](int to1, int to2) {
            return a[any_leaf[to1]] < a[any_leaf[to2]];
        });
    };
    dfs(1);

    vector<int> p(n + 1), parent(n + 1, -1), depth(n + 1);
    int timer = 0;
    function<void(int)> go = [&](int v) {
        p[v] = ++timer;
        for (int to : g[v]) {
            parent[to] = v;
            depth[to] = depth[v] + 1;
            go(to);
        }
    };
    go(1);

    set<pii> leafs;
    for (int v = 1; v <= n; v++) {
        if (h[v].empty())
            leafs.insert({a[v], v});
    }

    ll days = 0;
    ll pre_days = 0;
    int last_leaf = -1;
    vector<int> b(n + 1, -1);
    for (int k = 1; k <= n; k++) {
        if (leafs.empty())
            return {false, 0, {}};
        int leaf = leafs.begin()->second;
        if (a[leaf] == k) {
            leafs.erase({a[leaf], leaf});
            int x = parent[leaf];
            if (x != -1) {
                h[x].erase(leaf);
                if (h[x].empty())
                    leafs.insert({a[x], x});
            }
            b[leaf] = k;
            days += depth[leaf];
        } else {
            while (leaf != -1 && a[leaf] != k)
                leaf = parent[leaf];
            if (leaf == -1)
                return {false, 0, {}};
            pre_days = days;
            days += depth[leaf];
            last_leaf = leaf;
            break;
        }
    }


    {
        leafs.clear();
        for (int v = 1; v <= n; v++) {
            h[v] = set<int>(g[v].begin(), g[v].end());
            if (h[v].empty())
                leafs.insert({p[v], v});
        }

        vector<int> b(n + 1, -1);
        int k = 1;
        for (ll d = 0; ;) {
            if (leafs.empty())
                break;
            int leaf = leafs.begin()->second;
            if (d + depth[leaf] <= days) {
                d += depth[leaf];
                leafs.erase({p[leaf], leaf});
                b[leaf] = k++;
                int x = parent[leaf];
                if (x != -1) {
                    h[x].erase(leaf);
                    if (h[x].empty())
                        leafs.insert({p[x], x});
                }
                continue;
            }
            vector<int> path;
            for (int x = leaf; x != -1; x = parent[x])
                path.push_back(x);
            if ((int) path.size() < days - d + 1)
                return {false, 0, {}};
            reverse(path.begin(), path.end());
            path.resize(days - d + 1);
            for (int i = 0; i + 1 < (int) path.size(); i++)
                b[path[i]] = k + i + 1;
            b[path.back()] = k;
            break;
        }
        vector<int> used(n + 1);
        for (int v = 1; v <= n; v++) {
            if (b[v] != -1)
                used[b[v]] = 1;
        }
        timer = 1;
        function<void(int)> walk = [&](int v) {
            if (b[v] == -1) {
                while (used[timer])
                    timer++;
                b[v] = timer++;
            }
            for (int to : g[v])
                walk(to);
        };
        walk(1);
        b[0] = a[0];
        if (b != a)
            return {false, 0, {}};
    }
    p.erase(p.begin());
    return {true, days, p};
}

void work() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
   vector<pii> edges(n - 1);
   for (auto& e : edges)
       cin >> e.first >> e.second;
   auto [flag, days, p] = fast(n, a, edges);
   if (flag) {
       cout << "YES\n";
       cout << days << "\n";
       for (auto x : p)
           cout << x << " ";
       cout << "\n";
   } else {
       cout << "NO\n";
   }
}

vector<vector<int>> emulate(int n, vector<pii> edges) {
    vector<vector<int>> g(n + 1);
    for (auto [u, v] : edges)
        g[u].push_back(v);

    vector<int> p(n + 1);
    int timer;
    function<void(int)> go = [&](int v) {
        p[v] = ++timer;
        for (int to : g[v])
            go(to);
    };

    timer = 0;
    go(1);
    vector<vector<int>> history;
    for (ll days = 0;; days++) {
        history.push_back(vector<int>(p.begin() + 1, p.end()));
        int bu = -1, bv = -1;
        for (int v = 1; v <= n; v++) {
            for (int to : g[v]) {
                if (p[v] < p[to]) {
                    if (bu == -1) {
                        bu = v, bv = to;
                    } else {
                        if (make_pair(p[v], p[to]) < make_pair(p[bu], p[bv]))
                            bu = v, bv = to;
                    }
                }
            }
        }
        if (bu == -1)
            break;
        swap(p[bu], p[bv]);
    }

    return history;
}

void test() {
    mt19937 rnd(42);
    const int MAXN = 15;
    for (int T = 1;; T++) {
        int n = rnd() % MAXN + 2;
        vector<pii> edges;
        for (int i = 0; i < n - 1; i++) {
            int v = i + 2;
            int u = rnd() % (i + 1) + 1;
            edges.emplace_back(u, v);
        }
        shuffle(edges.begin(), edges.end(), rnd);
        auto history = emulate(n, edges);
        vector<int> perm(n);
        for (int i = 0; i < n; i++)
            perm[i] = i + 1;
        shuffle(perm.begin(), perm.end(), rnd);
        history.push_back(perm);
        shuffle(history.begin(), history.end(), rnd);
        vector<int> a = history[rnd() % (int) history.size()];
        a.insert(a.begin(), 0);
        auto fs = fast(n, a, edges);
        auto sl = slow(n, a, edges);
        if (get<0>(fs) == get<0>(sl)) {
            cout << "OK" << endl;
        } else {
            cout << "WA " << T << "\n";
            cout << "exp = " << get<0>(sl) << " " << get<1>(sl) << " : "; for (auto x : get<2>(sl)) cout << x << " "; cout << "\n";
            cout << "fnd = " << get<0>(fs) << " " << get<1>(fs) << " : "; for (auto x : get<2>(fs)) cout << x << " "; cout << "\n";
            cout << n << "\n";
            a.erase(a.begin());
            for (auto x : a)
                cout << x << " ";
            cout << "\n";
            for (auto [u, v] : edges)
                cout << u << " " << v << "\n";
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