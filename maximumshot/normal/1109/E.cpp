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

struct Query {
    int t = 0;
    int l = 0;
    int r = 0;
    int x = 0;
    int p = 0;
};

vector<pii> factorize(int x) {
    vector<pii> res;
    for (int p = 2; p * p <= x; p++) {
        if (x % p)
            continue;
        int cnt = 0;
        while (x % p == 0) {
            x /= p;
            cnt++;
        }
        res.emplace_back(p, cnt);
    }
    if (x > 1)
        res.emplace_back(x, 1);
    return res;
}

inline int _sum(int a, int b, int mod) {
    return a + b < mod ? a + b : a + b - mod;
}

inline int _mul(int a, int b, int mod) {
    return (1ll * a * b) % mod;
}

inline int _binpow(int x, int pw, int mod) {
    int res = 1, tmp = x;
    while (pw > 0) {
        if (pw & 1)
            res = _mul(res, tmp, mod);
        pw >>= 1;
        tmp = _mul(tmp, tmp, mod);
    }
    return res;
}

void gcd(int a, int b, int& x, int& y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return;
    }
    int x1, y1;
    gcd(b % a, a, x1, y1);
    // (b - (b / a) * a) * x1 + a * y1 == g
    // a * (y1 - (b / a) * x1) + b * x1 == g
    x = y1 - (b / a) * x1;
    y = x1;
}

int _div(int a, int mod) {
    // ax + mod * y == 1
    int x, y;
    gcd(a, mod, x, y);
    x = (x % mod + mod) % mod;
    return x;
}

struct RangeTree {
    int n = 0; // [1, n]
    int mod = 1;
    vector<pii> ds;

    struct Node {
        vector<int> pu;
        int coprime = 1;
        int value = 1;
        int s = 0;

        Node(int sz): pu(sz, 0) { }
    };

    Node merge(const Node& l, const Node& r) {
        Node res((int) l.pu.size());
        res.s = _sum(l.s, r.s, mod);
        return res;
    }

    vector<Node> t;

    void upd(int v, int value, int coprime, const vector<int>& delta) {
        t[v].value = _mul(t[v].value, value, mod);
        t[v].coprime = _mul(t[v].coprime, coprime, mod);
        t[v].s = _mul(t[v].s, value, mod);
        for (int i = 0; i < (int) t[v].pu.size(); i++)
            t[v].pu[i] += delta[i];
    }

    void push(int v) {
        upd(v << 1, t[v].value, t[v].coprime, t[v].pu);
        upd(v << 1 | 1, t[v].value, t[v].coprime, t[v].pu);
        t[v].pu.assign(t[v].pu.size(), 0);
        t[v].coprime = t[v].value = 1;
    }

    RangeTree(int n_, int mod_): n(n_), mod(mod_) {
        ds = factorize(mod);
        t.resize(4 * n, Node((int) ds.size()));
        build(1, 1, n);
    }

    void build(int v, int tl, int tr) {
        if (tl == tr) {
            t[v].s = 1;
        } else {
            int tm = (tl + tr) >> 1;
            build(v << 1, tl, tm);
            build(v << 1 | 1, tm + 1, tr);
            t[v] = merge(t[v << 1], t[v << 1 | 1]);
        }
    }

    void mul(int v, int tl, int tr, int l, int r, int value, int coprime, const vector<int>& delta) {
        if (l <= tl && tr <= r) {
            upd(v, value, coprime, delta);
        } else {
            int tm = (tl + tr) >> 1;
            push(v);
            if (l <= tm)
                mul(v << 1, tl, tm, l, r, value, coprime, delta);
            if (r > tm)
                mul(v << 1 | 1, tm + 1, tr, l, r, value, coprime, delta);
            t[v] = merge(t[v << 1], t[v << 1 | 1]);
        }
    }

    pair<int, vector<int>> process(int value) {
        int coprime = value;
        vector<int> delta((int) ds.size());
        for (int i = 0; i < (int) ds.size(); i++) {
            while (coprime % ds[i].first == 0) {
                coprime /= ds[i].first;
                delta[i]++;
            }
        }
        coprime %= mod;
        return {coprime, delta};
    }

    void mul(int l, int r, int value) {
        auto [coprime, delta] = process(value);
        mul(1, 1, n, l, r, value, coprime, delta);
    }

    int query(int v, int tl, int tr, int l, int r) {
        if (l <= tl && tr <= r) {
            return t[v].s;
        } else {
            int tm = (tl + tr) >> 1;
            push(v);
            int res = 0;
            if (l <= tm)
                res += query(v << 1, tl, tm, l, r);
            if (r > tm)
                res += query(v << 1 | 1, tm + 1, tr, l, r);
            t[v] = merge(t[v << 1], t[v << 1 | 1]);
            return res % mod;
        }
    }

    int query(int l, int r) {
        return query(1, 1, n, l, r);
    }

    void del(int v, int tl, int tr, int pos, int value) {
        if (tl == tr) {
            auto [coprime, delta] = process(value);
            t[v].s = t[v].coprime = _mul(t[v].coprime, _div(coprime, mod), mod);
            for (int i = 0; i < (int) delta.size(); i++) {
                t[v].pu[i] -= delta[i];
                t[v].s = _mul(t[v].s, _binpow(ds[i].first, t[v].pu[i], mod), mod);
            }
        } else {
            int tm = (tl + tr) >> 1;
            push(v);
            if (pos <= tm)
                del(v << 1, tl, tm, pos, value);
            else
                del(v << 1 | 1, tm + 1, tr, pos, value);
            t[v] = merge(t[v << 1], t[v << 1 | 1]);
        }
    }

    void del(int pos, int value) {
        del(1, 1, n, pos, value);
    }
};

vector<int> fast(int n, int mod, vector<int> a, int m, vector<Query> qs) {
    vector<int> res;
    RangeTree rt(n, mod);
    for (int i = 1; i <= n; i++)
        rt.mul(i, i, a[i]);
    for (auto q : qs) {
        if (q.t == 1) {
            rt.mul(q.l, q.r, q.x);
        } else if (q.t == 2) {
            rt.del(q.p, q.x);
        } else if (q.t == 3) {
            res.push_back(rt.query(q.l, q.r));
        }
    }
    return res;
}

vector<int> slow(int n, int mod, vector<int> a, int m, vector<Query> qs) {
    vector<int> b = a;
    vector<int> res;
    for (auto q : qs) {
        if (q.t == 1) {
            for (int i = q.l; i <= q.r; i++)
                b[i] *= q.x;
        } else if (q.t == 2) {
            b[q.p] /= q.x;
        } else {
            int s = 0;
            for (int i = q.l; i <= q.r; i++)
                s += b[i];
            s %= mod;
            res.push_back(s);
        }
    }
    return res;
}

void work() {
    int n, mod;
    cin >> n >> mod;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int m;
    cin >> m;
    vector<Query> qs(m);
    for (auto& q : qs) {
        cin >> q.t;
        if (q.t == 1) {
            cin >> q.l >> q.r >> q.x;
        } else if (q.t == 2) {
            cin >> q.p >> q.x;
        } else if (q.t == 3) {
            cin >> q.l >> q.r;
        }
    }
    vector<int> res = fast(n, mod, a, m, qs);
    for (auto x : res)
        cout << x << "\n";
}

void test() {
    const int MAXN = 8;
    const int MAXX = 10;
    const int MAXQ = 7;
    mt19937 rnd(42);
    while (1) {
        int n = rnd() % MAXN + 1;
        int mod = rnd() % (MAXX * MAXX) + 1;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
            a[i] = rnd() % MAXX + 1;
        int m = rnd() % MAXQ + 1;
        vector<Query> qs;
        vector<int> b = a;
        for (int it = 0; it < m; it++) {
            Query q;
            q.t = rnd() % 3 + 1;
            if (q.t == 1) {
                q.r = rnd() % n + 1;
                q.l = rnd() % q.r + 1;
                q.x = rnd() % MAXX + 1;
                for (int i = q.l; i <= q.r; i++)
                    b[i] *= q.x;
            } else if (q.t == 2) {
                q.p = rnd() % n + 1;
                vector<int> candidates;
                for (int p = 1; p <= b[q.p]; p++) {
                    if (b[q.p] % p == 0)
                        candidates.push_back(p);
                }
                q.x = candidates[rnd() % (int) candidates.size()];
                b[q.p] /= q.x;
            } else {
                q.r = rnd() % n + 1;
                q.l = rnd() % q.r + 1;
            }
            qs.push_back(q);
        }
        vector<int> fs = fast(n, mod, a, m, qs);
        vector<int> sl = slow(n, mod, a, m, qs);
        if (fs == sl) {
            cout << "OK( "; for (auto x : fs) cout << x << " "; cout << ")" << endl;
        } else {
            cout << "WA\n";
            cout << "exp = "; for (auto  x : sl) cout << x << " "; cout << "\n";
            cout << "fnd = "; for (auto  x : fs) cout << x << " "; cout << "\n";
            cout << n << " " << mod << "\n";
            for (int i = 1; i <= n; i++)
                cout << a[i] << " ";
            cout << "\n";
            cout << m << "\n";
            for (auto q : qs) {
                cout << q.t << " ";
                if (q.t == 1)
                    cout << q.l << " " << q.r << " " << q.x << "\n";
                else if (q.t == 2)
                    cout << q.p << " " << q.x << "\n";
                else
                    cout << q.l << " " << q.r << "\n";
            }
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