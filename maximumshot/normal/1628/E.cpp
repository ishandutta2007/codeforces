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
            cout << x << "\n";
    }

    bool operator == (const output& o) const {
        throw;
    }
};

struct RMQ {
    vector<int> a; // [0, n)
    int n, LOG;
    vector<int> _log;
    vector<vector<pii>> rmq;

    RMQ(const vector<int>& aa) {
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
                rmq[j][i] = max(rmq[j - 1][i], rmq[j - 1][i + (1 << (j - 1))]);
            }
        }
    }

    int get_max(int l, int r) const {
        int lg = _log[r - l + 1];
        return max(rmq[lg][l], rmq[lg][r - (1 << lg) + 1]).first;
    }
};

struct RangeTree {
    int n = 0; // [1, n]
    vector<int> pos;

    struct Node {
        int mn = inf;
        int mx = -inf;
        int mn_active = inf;
        int mx_active = -inf;
        int pu = -1;
    };

    vector<Node> t;

    Node merge(const Node& l, const Node& r) {
        Node res;
        res.mn = min(l.mn, r.mn);
        res.mx = max(l.mx, r.mx);
        res.mn_active = min(l.mn_active, r.mn_active);
        res.mx_active = max(l.mx_active, r.mx_active);
        return res;
    }

    void merge(int v) {
        t[v] = merge(t[v << 1], t[v << 1 | 1]);
    }

    void upd(int v, int x) {
        t[v].pu = x;
        if (x == 0) {
            t[v].mn_active = inf;
            t[v].mx_active = -inf;
        } else {
            t[v].mn_active = t[v].mn;
            t[v].mx_active = t[v].mx;
        }
    }

    void push(int v) {
        if (t[v].pu != -1) {
            upd(v << 1, t[v].pu);
            upd(v << 1 | 1, t[v].pu);
            t[v].pu = -1;
        }
    }

    RangeTree() = default;

    RangeTree(const vector<int>& ar) {
        n = (int) ar.size() - 1;
        pos = ar;
        t.resize(4 * n);
        build(1, 1, n);
    }

    void build(int v, int tl, int tr) {
        if (tl == tr) {
            t[v].mn = t[v].mx = pos[tl];
        } else {
            int tm = (tl + tr) >> 1;
            build(v << 1, tl, tm);
            build(v << 1 | 1, tm + 1, tr);
            merge(v);
        }
    }

    void update(int v, int tl, int tr, int l, int r, int x) {
        if (l <= tl && tr <= r) {
            upd(v, x);
        } else {
            int tm = (tl + tr) >> 1;
            push(v);
            if (l <= tm)
                update(v << 1, tl, tm, l, r, x);
            if (r > tm)
                update(v << 1 | 1, tm + 1, tr, l, r, x);
            merge(v);
        }
    }

    void update(int l, int r, int x) {
        update(1, 1, n, l, r, x);
    }

    Node get(int v, int tl, int tr, int l, int r) {
        if (l <= tl && tr <= r) {
            return t[v];
        } else {
            int tm = (tl + tr) >> 1;
            push(v);
            Node res;
            if (l <= tm)
                res = merge(res, get(v << 1, tl, tm, l, r));
            if (r > tm)
                res = merge(res, get(v << 1 | 1, tm + 1, tr, l, r));
            merge(v);
            return res;
        }
    }

    pii get(int i) {
        Node res;
        if (i > 1) res = merge(res, get(1, 1, n, 1, i - 1));
        if (i < n) res = merge(res, get(1, 1, n, i + 1, n));
        return {res.mn_active, res.mx_active};
    }
};

struct input {
    int n, m;

    struct Edge {
        int u, v, w;

        bool operator < (const Edge& o) const {
            return w < o.w;
        }
    };

    vector<Edge> es;

    struct Query {
        int t, l, r, x;
    };

    vector<Query> qs;
    vector<int> p, nxt, fi, la, w;

    input() = default;

    void read() {
        cin >> n >> m;
        es.resize(n - 1);
        for (auto& e : es)
            cin >> e.u >> e.v >> e.w;
        qs.resize(m);
        for (auto& q : qs) {
            cin >> q.t;
            if (q.t == 3) {
                cin >> q.x;
            } else {
                cin >> q.l >> q.r;
            }
        }
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    int find(int x) {
        return x == p[x] ? x : p[x] = find(p[x]);
    }

    void merge(int x, int y, int W) {
        x = find(x);
        y = find(y);
        if (x == y)
            return;
        p[y] = x;
        nxt[la[x]] = fi[y];
        w[la[x]] = W;
        la[x] = la[y];
    }

    output fast() {
        p.resize(n + 1);
        nxt.resize(n + 1, -1);
        fi.resize(n + 1);
        la.resize(n + 1);
        w.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            p[i] = i;
            fi[i] = i;
            la[i] = i;
        }
        sort(es.begin(), es.end());
        for (auto e : es) {
            merge(e.u, e.v, e.w);
        }
        vector<int> pos(n + 1), ar;
        for (int i = 0, x = fi[find(1)]; x != -1; i++, x = nxt[x]) {
            pos[x] = i;
            ar.push_back(w[x]);
        }
        vector<int> res;
//        vector<int> active(n + 1);
        RMQ rmq(ar);
        RangeTree rt(pos);
        for (auto q : qs) {
            if (q.t == 1) {
                rt.update(q.l, q.r, 1);
//                for (int i = q.l; i <= q.r; i++)
//                    active[i] = 1;
            } else if (q.t == 2) {
                rt.update(q.l, q.r, 0);
//                for (int i = q.l; i <= q.r; i++)
//                    active[i] = 0;
            } else {
                auto [L, R] = rt.get(q.x);
//                int L = inf, R = -inf;
//                for (int i = 1; i <= n; i++) {
//                    if (i == q.x)
//                        continue;
//                    if (active[i]) {
//                        L = min(L, pos[i]);
//                        R = max(R, pos[i]);
//                    }
//                }
                if (L == inf) {
                    res.push_back(-1);
                    continue;
                }
                int mx = 0;
                if (pos[q.x] < R)
                    mx = max(mx, rmq.get_max(pos[q.x], R - 1));
                if (L < pos[q.x])
                    mx = max(mx, rmq.get_max(L, pos[q.x] - 1));
//                for (int i = pos[q.x]; i < R; i++)
//                    mx = max(mx, ar[i]);
//                for (int i = L; i < pos[q.x]; i++)
//                    mx = max(mx, ar[i]);
                res.push_back(mx);
            }
        }
        return output{res};
    }

    output slow() {
#ifndef DEBUG
        throw;
#endif
        return output();
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

void max_test() {
    input in;
    in.gen_max_test();
    input in_fs = in;
    output fs = in_fs.fast();
    fs.print();
}

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