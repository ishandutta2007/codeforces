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
    vector<int> res;

    void print() {
        for (auto x : res)
            cout << x << " ";
        cout << "\n";
    }

    bool operator == (const output& o) const {
        throw;
    }
};

struct Array {
    int l = 0;
    int r = -1;
    deque<int> f;

    int& operator [] (int i) {
        if (l > r) {
            l = r = i;
            f = {-1};
        }
        while (r < i) {
            f.push_back(-1);
            r++;
        }
        while (l > i) {
            f.push_front(-1);
            l--;
        }
        return f[i - l];
    }

    int size() const {
        return r - l + 1;
    }
};

template <class T>
struct RMQ {
    vector<T> a; // [0, n)
    int n = 0, LOG = 0;
    vector<int> _log;
    vector<vector<pair<T, int>>> rmq;

    RMQ() = default;

    RMQ(const vector<T>& aa) {
        a = aa;
        n = (int) a.size();
        LOG = 0;
        while ((1 << LOG) <= n) LOG++;
        _log.resize(n + 1);
        for (int i = 2; i <= n; i++) {
            _log[i] = _log[i - 1] + 1;
            if ((1 << _log[i]) > i) _log[i]--;
        }
        rmq.resize(LOG, vector<pii>(n));
        for (int i = 0; i < n; i++) {
            rmq[0][i] = {a[i], i};
        }
        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                rmq[j][i] = min(rmq[j - 1][i], rmq[j - 1][i + (1 << (j - 1))]);
            }
        }
    }

    pair<T, int> get_min(int l, int r) const {
        int lg = _log[r - l + 1];
        return min(rmq[lg][l], rmq[lg][r - (1 << lg) + 1]);
    }
};

struct Tree {
    int n = 0; // [0, n)
    vector<int> pos, euler, h;
    vector<vector<int>> g;
    RMQ<int> rmq;

    Tree() = default;

    Tree(const vector<int>& P) {
        n = (int) P.size();
        g.resize(n);
        for (int i = 1; i < n; i++) {
            g[P[i]].push_back(i);
        }
        pos.assign(n, -1);
        h.resize(n);
        dfs(0, -1);
        vector<int> ar(euler.size());
        for (int i = 0; i < (int) euler.size(); i++)
            ar[i] = h[euler[i]];
        rmq = RMQ(ar);
    }

    void dfs(int v, int par) {
        h[v] = par == -1 ? 0 : h[par] + 1;
        for (int to : g[v]) {
            if (pos[to] == -1) pos[to] = (int) euler.size();
            euler.push_back(to);
            dfs(to, v);
            if (pos[v] == -1) pos[v] = (int) euler.size();
            euler.push_back(v);
        }
    }

    int get_lca(int u, int v) {
        int l = pos[u];
        int r = pos[v];
        if (l > r) swap(l, r);
        return euler[rmq.get_min(l, r).second];
    }

    int get_dist(int u, int v) {
        int w = get_lca(u, v);
        return h[u] + h[v] - 2 * h[w];
    }
};

struct input {
    int n, q;
    vector<int> p, xs;

    input() = default;

    void read() {
        cin >> n;
        p.assign(n, -1);
        for (int i = 1; i < n; i++) {
            cin >> p[i];
            p[i]--;
        }
        cin >> q;
        xs.resize(q);
        for (auto& x : xs) cin >> x;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        vector<vector<int>> g(n);
        for (int i = 1; i < n; i++) {
            g[p[i]].push_back(i);
        }
        for (int i = 1; i < n; i++) {
            g[i].push_back(p[i]);
        }
        vector<int> A(n, inf);
        {
            queue<int> que;
            for (int v = 0; v < n; v++) {
                if ((int) g[v].size() == 1) {
                    A[v] = 0;
                    que.push(v);
                }
            }
            while (!que.empty()) {
                int v = que.front();
                que.pop();
                for (int to : g[v]) {
                    if (A[to] > A[v] + 1) {
                        A[to] = A[v] + 1;
                        que.push(to);
                    }
                }
            }
        }
        for (int v = 1; v < n; v++)
            g[v].pop_back();
        vector<int> d(n);
        for (int v = 1; v < n; v++)
            d[v] = d[p[v]] + 1;
        int sz = *max_element(A.begin(), A.end()) + 1;
        vector<vector<int>> seq(sz);
        for (int v = 0; v < n; v++)
            seq[A[v]].push_back(v);
        Tree tr(p);
        vector<pii> diam(sz);
        for (int it = 0; it < sz; it++) {
            assert(!seq[it].empty());
            int v1 = seq[it].front();
            int v2 = v1;
            int max_dist = 0;
            for (int v : seq[it]) {
                int tmp_dist = tr.get_dist(v, v1);
                if (tmp_dist > max_dist) {
                    max_dist = tmp_dist;
                    v2 = v;
                }
            }
            v1 = v2;
            v2 = v1;
            max_dist = 0;
            for (int v : seq[it]) {
                int tmp_dist = tr.get_dist(v, v1);
                if (tmp_dist > max_dist) {
                    max_dist = tmp_dist;
                    v2 = v;
                }
            }
            diam[it] = {v1, v2};
        }
        vector<int> res;
        for (int x_i : xs) {
            int D = 0;
            for (int cur_A = sz - 1; cur_A >= 0; cur_A--) {
                while (1) {
                    int min_A_v = max(0, D + 1 - cur_A - x_i);
                    if (min_A_v < sz) {
                        auto[v1, v2] = diam[cur_A];
                        auto[u1, u2] = diam[min_A_v];
                        if (tr.get_dist(v1, u1) > D || tr.get_dist(v1, u2) > D || tr.get_dist(v2, u1) > D ||
                            tr.get_dist(v2, u2) > D)
                            D++;
                        else
                            break;
                    } else break;
                }
            }
            res.push_back(D);
        }
        return output{res};
    }

#ifdef DEBUG
    output slow() {
        return output();
    }
#endif
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

#ifdef DEBUG
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
#endif

#ifdef DEBUG
void max_test() {
    input in;
    in.gen_max_test();
    input in_fs = in;
    output fs = in_fs.fast();
    fs.print();
}
#endif

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();
//    test();
//    max_test();

    return 0;
}