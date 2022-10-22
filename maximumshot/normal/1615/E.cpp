#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ui = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

const int inf = 1e9;
const ll inf64 = 1e18;

struct output {
    ll res = 0;

    void print() {
        cout << res << "\n";
    }

    bool operator == (const output& o) const {
        return res == o.res;
    }
};

struct RangeTree {
    int n = 0; // [0, n)
    vector<int> pu;
    vector<pii> mx;

    RangeTree() = default;

    RangeTree(const vector<int>& a) {
        n = (int) a.size();
        pu.resize(2 * n);
        mx.resize(2 * n);
        for (int i = 0; i < n; i++)
            mx[i + n] = {a[i], i};
        for (int i = n - 1; i >= 0; i--)
            mx[i] = max(mx[i << 1], mx[i << 1 | 1]);
    }

    void inc(int v, int x) {
        pu[v] += x;
        mx[v].first += x;
    }

    void push(int v) {
        inc(v << 1, pu[v]);
        inc(v << 1 | 1, pu[v]);
        pu[v] = 0;
    }

    void push_to_leaf(int i) {
        vector<int> path;
        for (i += n, i >>= 1; i > 0; i >>= 1)
            path.push_back(i);
        reverse(path.begin(), path.end());
        for (int v : path)
            push(v);
        reverse(path.begin(), path.end());
        for (int v : path)
            mx[v] = max(mx[v << 1], mx[v << 1 | 1]);
    }

    void update(int L, int R, int x) {
        push_to_leaf(L);
        push_to_leaf(R);
        for (int l = L + n, r = R + n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) inc(l++, x);
            if (r & 1) inc(--r, x);
        }
        for (int leaf : {L, R}) {
            push_to_leaf(leaf);
            for (int v = (leaf + n) >> 1; v > 0; v >>= 1)
                mx[v] = max(mx[v << 1], mx[v << 1 | 1]);
        }
    }

    void put(int i, int x) {
        push_to_leaf(i);
        mx[i + n] = {x, i};
        for (i += n, i >>= 1; i > 0; i >>= 1)
            mx[i] = max(mx[i << 1], mx[i << 1 | 1]);
    }

    pii query(int l, int r) {
        push_to_leaf(l);
        push_to_leaf(r);
        pii res = {-inf, -1};
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res = max(res, mx[l++]);
            if (r & 1) res = max(res, mx[--r]);
        }
        return res;
    }
};

struct input {
    int n, k;
    vector<vector<int>> g;
    vector<int> p, d, leafs, euler, tin, tout, vs;
    int timer;

    input() = default;

    void read() {
        cin >> n >> k;
        g.resize(n + 1);
        for (int u, v, i = 0; i < n - 1; i++) {
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
    }

    void print() {
        cout << n << " " << k << "\n";
        for (int v = 1; v <= n; v++) {
            for (int to : g[v]) {
                if (v < to)
                    cout << v << " " << to << "\n";
            }
        }
    }

    void gen() {
        static mt19937 rnd(42);
        const int MAXN = 15;

        n = rnd() % MAXN + 2;
        k = rnd() % n + 1;
        g.resize(n + 1);
        for (int i = 2; i <= n; i++) {
            int j = rnd() % (i - 1) + 1;
            g[i].push_back(j);
            g[j].push_back(i);
        }
    }

    void dfs(int v, int par = -1) {
        p[v] = par;
        d[v] = par == -1 ? 0 : d[par] + 1;
        euler.push_back(d[v]);
        vs.push_back(v);
        tin[v] = timer++;
        int c = 0;
        for (int to : g[v]) {
            if (to == par)
                continue;
            dfs(to, v);
            c++;
        }
        if (c == 0)
            leafs.push_back(v);
        tout[v] = timer;
    }

    output fast() {
        timer = 0;
        tin.resize(n + 1);
        tout.resize(n + 1);
        p.resize(n + 1);
        d.resize(n + 1);
        dfs(1, -1);
        ll res = -inf64;
        vector<int> used(n + 1);
        used[1] = 1;
        int R = 1;
        RangeTree rt(euler);
        for (int it = 0; it < k; it++) {
//            int best_pos = max_element(euler.begin(), euler.end()) - euler.begin();
            auto [best_value, best_pos] = rt.query(0, n - 1);
            int best = vs[best_pos];
            R += best_value;
            vector<int> path;
            while (best != -1 && !used[best]) {
                path.push_back(best);
                used[best] = 1;
                best = p[best];
            }
            reverse(path.begin(), path.end());

            for (int i = 0; i < (int) path.size(); i++) {
                int v = path[i];
                int delta = -1;
//                for (int j = tin[v]; j < tout[v]; j++)
//                    euler[j] += delta;
                rt.update(tin[v], tout[v] - 1, delta);
                rt.put(tin[v], -inf);
//                euler[tin[v]] = -inf;
            }

            int r = min({R, n / 2, k});
            r = max(r, it + 1);
            int b = min(n / 2, n - R);
            int w = n - r - b;
            res = max(res, 1ll * w * (r - b));
        }
        return output{res};
    }

    output slow() {
        timer = 0;
        tin.resize(n + 1);
        tout.resize(n + 1);
        p.resize(n + 1);
        d.resize(n + 1);
        dfs(1, -1);
        if ((int) leafs.size() <= k) {
            k = min(k, n / 2);
            return output{1ll * (n - k) * k};
        }
        int sz = (int) leafs.size();
        ll res = -inf64;
        for (int mask = 1; mask < (1 << sz); mask++) {
            if (__builtin_popcount(mask) > k)
                continue;
            vector<int> blocked(n + 1);
            int r = 0;
            for (int i = 0; i < sz; i++) {
                if ((1 << i) & mask) {
                    int v = leafs[i];
                    r++;
                    while (v != -1) {
                        blocked[v] = 1;
                        v = p[v];
                    }
                }
            }
            int mxb = 0;
            for (int v = 1; v <= n; v++) {
                if (!blocked[v])
                    mxb++;
            }
            ll mn_score = inf64;
            for (int b = 0; b <= mxb; b++) {
                int w = n - r - b;
                mn_score = min(mn_score, 1ll * w * (r - b));
            }
            res = max(res, mn_score);
        }
        return output{res};
    }
};

void test_case() {
    input in;
    in.read();
    output res = in.fast();
    res.print();
}

void work() {
    int t = 1;
    while (t--)
        test_case();
}

void test() {
    for (int t = 1;;t++) {
        input in;
        in.gen();
        input in_fs = in;
        input in_sl = in;
        output fs = in_fs.fast();
        output sl = in_sl.slow();
        if (fs == sl) {
            cout << "OK" << endl;
            fs.print();
            cout << "\n=========" << endl;
        } else {
            cout << "WA " << t << "\n";
            cout << "exp\n";
            sl.print();
            cout << "\n=========\n";
            cout << "fnd\n";
            fs.print();
            cout << "\n=========\n";
            in.print();
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