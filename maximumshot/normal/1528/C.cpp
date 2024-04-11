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

vector<pii> get_timers(int n, vector<int> p) {
    vector<vector<int>> g(n + 1);
    for (int i = 2; i <= n; i++)
        g[p[i]].push_back(i);
    vector<pii> t(n + 1);
    int timer = 1;
    function<void(int)> dfs = [&](int v) {
        t[v].first = timer++;
        for (int to : g[v])
            dfs(to);
        t[v].second = timer++;
    };
    dfs(1);
    return t;
}

int slow(int n, vector<int> a, vector<int> b) {
    vector<pii> ta = get_timers(n, a);
    vector<pii> tb = get_timers(n, b);
    vector<int> perm(n + 1);
    for (int i = 1; i <= n; i++)
        perm[i] = i;
    sort(perm.begin() + 1, perm.end(), [&](int i, int j) {
        return tb[i].second < tb[j].second;
    });
    vector<int> dp(n + 1);
    for (int i = 1; i <= n; i++) {
        int v = perm[i];
        auto [l1, r1] = ta[v];
        auto [l2, r2] = tb[v];
        cout << l2 << " " << r2 << ", v = " << v << "\n";
        int j = 0;
        {
            int bl = 0, br = i, bm;
            while (br - bl > 1) {
                bm = (bl + br) >> 1;
                int u = perm[bm];
                if (tb[u].second < l2) bl = bm;
                else br = bm;
            }
            j = bl;
        }
        dp[i] = 1;
        for (int q = 1; q <= j; q++) {
            int u = perm[q];
            if ((ta[u].first <= l1 && r1 <= ta[u].second) ||
                (l1 <= ta[u].first && ta[u].second <= r1)) {
                dp[i] = max(dp[i], dp[q] + 1);
            }
        }
    }

    cout << "dp\n";
    for (int i = 1; i <= n; i++)
        cout << dp[i] << " ";
    cout << "\n";
    return *max_element(dp.begin(), dp.end());
}

struct Tree {
    int n = 0; // [1, n]
    vector<vector<int>> p;
    int LOG = 0;
    vector<int> depth;
    vector<int> tin, tout;
    vector<vector<int>> g;
    int timer = 0;

    Tree(int n_, vector<int> p_) {
        n = n_;
        while ((1 << LOG) <= n) LOG++;
        LOG += 2;

        depth.resize(n + 1);
        p.resize(LOG, vector<int>(n + 1, -1));
        p_[1] = -1;
        p[0] = p_;

        for (int j = 1; j < LOG; j++) {
            for (int v = 1; v <= n; v++) {
                int pv = p[j - 1][v];
                if (pv == -1) p[j][v] = -1;
                else p[j][v] = p[j - 1][pv];
            }
        }

        for (int i = 2; i <= n; i++)
            depth[i] = depth[p[0][i]] + 1;

        g.resize(n + 1);
        for (int i = 2; i <= n; i++)
            g[p[0][i]].push_back(i);

        tin.resize(n + 1);
        tout.resize(n + 1);
        timer = 0;
        dfs(1);
    }

    void dfs(int v) {
        tin[v] = timer++;
        for (int to : g[v])
            dfs(to);
        tout[v] = timer;
    }

    int get_lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        for (int j = LOG - 1; j >= 0; j--) {
            int pu = p[j][u];
            if (pu == -1 || depth[pu] < depth[v])
                continue;
            u = pu;
        }
        for (int j = LOG - 1; j >= 0; j--) {
            int pu = p[j][u];
            int pv = p[j][v];
            if (pu == -1 || pv == -1 || pu == pv)
                continue;
            u = pu;
            v = pv;
        }
        if (u != v) u = p[0][u];
        return u;
    }

    int get_tin(int v) {
        return tin[v];
    }

    int get_tout(int v) {
        return tout[v];
    }

    bool is_parent(int S, int P) {
        return tin[P] <= tin[S] && tout[S] <= tout[P];
    }
};

int fast(int n, vector<int> a, vector<int> b) {
    Tree tb(n, b);
    vector<vector<int>> g(n + 1);
    for (int i = 2; i <= n; i++)
        g[a[i]].push_back(i);
    int res = 0;

    vector<int> leafs, vs;
    set<pii> q;

    auto add = [&](int v) {
        int cur = leafs.empty() ? 0 : leafs.back();
        int prv = -1;

        {
            auto it = q.upper_bound({tb.get_tin(v), v});
            if (it != q.begin()) {
                it--;
                prv = it->second;
            }
        }

        if (prv == -1 || !tb.is_parent(v, prv))
            cur++;
        else {
            auto it = q.upper_bound({tb.get_tin(prv), prv});
            if (it != q.end() && tb.is_parent(it->second, prv))
                cur++;
        }

        q.insert({tb.get_tin(v), v});

        vs.push_back(v);
        leafs.push_back(cur);
    };

    auto pop = [&]() {
        int v = vs.back();
        vs.pop_back();
        leafs.pop_back();
        q.erase({tb.get_tin(v), v});
    };

    auto query = [&]() -> int {
        return leafs.empty() ? 0 : leafs.back();
    };

    function<void(int)> dfs = [&](int v) {
        add(v);
        if (g[v].empty())
            res = max(res, query());
        for (int to : g[v])
            dfs(to);
        pop();
    };

    dfs(1);
    return res;
}

void test() {
    mt19937 rnd(42);
    const int MAXN = 5;
    while (1) {
        int n = rnd() % MAXN + 1;
        vector<int> a(n + 1), b(n + 1);
        for (int i = 2; i <= n; i++)
            a[i] = rnd() % (i - 1) + 1;
        for (int i = 2; i <= n; i++)
            b[i] = rnd() % (i - 1) + 1;
        int fs = fast(n, a, b);
        int sl = slow(n, a, b);
        if (fs == sl) {
            cout << "OK(" << fs << ")" << endl;
        } else {
            cout << "WA\n";
            cout << n << "\n";
            cout << "exp = " << sl << "\n";
            cout << "fnd = " << fs << "\n";
            cout << n << "\n";
            for (int i = 2; i <= n; i++)
                cout << a[i] << " ";
            cout << "\n";
            for (int i = 2; i <= n; i++)
                cout << b[i] << " ";
            cout << "\n";
            break;
        }
    }
}

void work() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1), b(n + 1);
        for (int i = 2; i <= n; i++)
            cin >> a[i];
        for (int i = 2; i <= n; i++)
            cin >> b[i];

        int res = fast(n, a, b);

        cout << res << "\n";
    }
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

//    test();
    work();

    return 0;
}