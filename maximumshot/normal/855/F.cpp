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
    vector<ll> res;

    void print() {
        for (auto x : res)
            cout << x << "\n";
    }

    bool operator == (const output& o) const {
        return res == o.res;
    }
};

const int X = 1e9 + 10;

struct RangeTreeSlow {
    int n = 0; // [1, n]
    vector<int> mn, mx;

    RangeTreeSlow() = default;

    RangeTreeSlow(int nn) {
        n = nn;

        mn.resize(n + 1, -X);
        mx.resize(n + 1, +X);
    }

    void update(int l, int r, int k) {
        for (int i = l; i <= r; i++) {
            if (k > 0) mx[i] = min(mx[i], k);
            else mn[i] = max(mn[i], k);
        }
    }

    ll query(int l, int r) {
        ll res = 0;
        for (int i = l; i <= r; i++) {
            if (mn[i] != -X && mx[i] != +X)
                res += mx[i] - mn[i];
        }
        return res;
    }
};

struct RangeTree {
    int n = 0; // [1, n]

    struct Node {
        int push_activate = 0;
        int push_mn = 0;

        ll total_sm = 0;
        ll activated_sm = 0;

        int mx1 = X;
        int mx2 = -X;
        int cnt_mx1 = 0;
        int cnt_activated_mx1 = 0;

        void update(int x, int c, int ca) {
            if (x > mx1) {
                mx2 = mx1;
                mx1 = x;
                cnt_mx1 = c;
                cnt_activated_mx1 = ca;
            } else if (x == mx1) {
                cnt_mx1 += c;
                cnt_activated_mx1 += ca;
            } else if (x > mx2) {
                mx2 = x;
            }
        }
    };

    vector<Node> t;

    Node merge(const Node& l, const Node& r) {
        Node res;
        res.total_sm = l.total_sm + r.total_sm;
        res.activated_sm = l.activated_sm + r.activated_sm;
        res.mx1 = l.mx1;
        res.mx2 = l.mx2;
        res.cnt_mx1 = l.cnt_mx1;
        res.cnt_activated_mx1 = l.cnt_activated_mx1;
        res.update(r.mx1, r.cnt_mx1, r.cnt_activated_mx1);
        res.update(r.mx2, 1, 1);
        return res;
    }

    void merge(int v) {
        t[v] = merge(t[v << 1], t[v << 1 | 1]);
    }

    void upd(int v, int x) {
        if (!(t[v].mx2 < x && x < t[v].mx1))
            return;
        t[v].push_mn = x;
        t[v].total_sm += 1ll * (x - t[v].mx1 * int(t[v].mx1 != X)) * t[v].cnt_mx1;
        t[v].activated_sm += 1ll * (x - t[v].mx1 * int(t[v].mx1 != X)) * t[v].cnt_activated_mx1;
        t[v].mx1 = x;
    }

    void act(int v) {
        t[v].push_activate = 1;
        t[v].activated_sm = t[v].total_sm;
        t[v].cnt_activated_mx1 = t[v].cnt_mx1;
    }

    void push(int v) {
        if (t[v].push_activate) {
            act(v << 1);
            act(v << 1 | 1);
            t[v].push_activate = 0;
        }
        if (t[v].push_mn) {
            upd(v << 1, t[v].push_mn);
            upd(v << 1 | 1, t[v].push_mn);
            t[v].push_mn = 0;
        }
    }

    RangeTree() = default;

    RangeTree(int nn) {
        n = nn;
        t.resize(4 * n);
        build(1, 1, n);
    }

    void build(int v, int tl, int tr) {
        if (tl == tr) {
            t[v].mx1 = X;
            t[v].mx2 = -X;
            t[v].total_sm = 0;
            t[v].activated_sm = 0;
            t[v].push_activate = 0;
            t[v].cnt_mx1 = 1;
            t[v].cnt_activated_mx1 = 0;
        } else {
            int tm = (tl + tr) >> 1;
            build(v << 1, tl, tm);
            build(v << 1 | 1, tm + 1, tr);
            merge(v);
        }
    }

    void update(int v, int tl, int tr, int l, int r, int k) {
        if (t[v].mx1 <= k)
            return;
        if (l <= tl && tr <= r && t[v].mx2 < k) {
            upd(v, k);
        } else {
            int tm = (tl + tr) >> 1;
            push(v);
            if (l <= tm)
                update(v << 1, tl, tm, l, r, k);
            if (r > tm)
                update(v << 1 | 1, tm + 1, tr, l, r, k);
            merge(v);
        }
    }

    void update(int l, int r, int k) {
        update(1, 1, n, l, r, k);
    }

    Node query(int v, int tl, int tr, int l, int r) {
        if (l <= tl && tr <= r) {
            return t[v];
        } else {
            int tm = (tl + tr) >> 1;
            push(v);
            Node res;
            if (l <= tm) {
                if (r > tm) res = merge(query(v << 1, tl, tm, l, r), query(v << 1 | 1, tm + 1, tr, l, r));
                else res = query(v << 1, tl, tm, l, r);
            } else {
                res = query(v << 1 | 1, tm + 1, tr, l, r);
            }
            merge(v);
            return res;
        }
    }

    void activate(int v, int tl, int tr, int l, int r) {
        if (l <= tl && tr <= r) {
            act(v);
        } else {
            int tm = (tl + tr) >> 1;
            push(v);
            if (l <= tm)
                activate(v << 1, tl, tm, l, r);
            if (r > tm)
                activate(v << 1 | 1, tm + 1, tr, l, r);
            merge(v);
        }
    }

    void activate(int l, int r) {
        activate(1, 1, n, l, r);
    }

    ll query(int l, int r) {
        Node res = query(1, 1, n, l, r);
        return res.activated_sm;
    }
};

struct input {
    int m;

    struct Query {
        int t, l, r, k;
    };

    vector<Query> qs;

    input() = default;

    void read() {
        cin >> m;
        qs.resize(m);
        for (auto& q : qs) {
            cin >> q.t >> q.l >> q.r;
            q.r--;
            if (q.t == 1)
                cin >> q.k;
        }
    }

    void print() {
        cout << m << "\n";
        for (auto q : qs) {
            cout << q.t << " " << q.l << " " << q.r + 1 << " ";
            if (q.t == 1)
                cout << q.k;
            cout << "\n";
        }
    }

    void gen() {
        static mt19937 rnd(42);
        const int MAXN = 50;
        const int MAXX = 100;
        m = rnd() % MAXN + 1;
        qs.resize(m);
        for (auto& q : qs) {
            q.t = rnd() % 2 + 1;
            q.r = rnd() % MAXX + 1;
            q.l = rnd() % q.r + 1;
            if (q.t == 1)
                q.k = (rnd() % MAXX + 1) * (rnd() % 2 ? +1 : -1);
        }
    }

    output fast() {
        int n = 1;
        for (auto q : qs)
            n = max(n, q.r);

        // [1, n]

        RangeTree pos(n), neg(n);
        vector<ll> res;
        for (auto q : qs) {
            if (q.t == 1) {
                if (q.k > 0) {
                    pos.update(q.l, q.r, q.k);
                    neg.activate(q.l, q.r);
                } else {
                    neg.update(q.l, q.r, -q.k);
                    pos.activate(q.l, q.r);
                }
            } else {
                ll pos_res = pos.query(q.l, q.r);
                ll neg_res = neg.query(q.l, q.r);
                res.push_back(pos_res + neg_res);
            }
        }
        return output{res};
    }

    output slow() {
        int n = 1;
        for (auto q : qs)
            n = max(n, q.r);

        // [1, n]

        RangeTreeSlow rt(n);
        vector<ll> res;
        for (auto q : qs) {
            if (q.t == 1) {
                rt.update(q.l, q.r, q.k);
            } else {
                res.push_back(rt.query(q.l, q.r));
            }
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