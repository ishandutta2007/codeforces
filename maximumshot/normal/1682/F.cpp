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
        return res == o.res;
    }
};

const int mod = 1'000'000'007;

inline int sum_(int a, int b) {
    return a + b < mod ? a + b : a + b - mod;
}

inline int mul_(int a, int b) {
    return (1ll * a * b) % mod;
}

inline int sub_(int a, int b) {
    return a >= b ? a - b : a - b + mod;
}

inline void inc_(int &x, int y) {
    if ((x += y) >= mod) {
        x -= mod;
    }
}

inline void dec_(int &x, int y) {
    if ((x -= y) < 0) {
        x += mod;
    }
}

inline int binpow_(int x, int pw) {
    if (x == 0)
        return 0;
    int res = 1;
    int tmp = x;
    while (pw > 0) {
        if (pw & 1) {
            res = mul_(res, tmp);
        }
        tmp = mul_(tmp, tmp);
        pw >>= 1;
    }
    return res;
}

inline int div_(int a, int b) {
    return mul_(a, binpow_(b, mod - 2));
}


const int X = 1e9 + 10;

struct RangeTree {
//    vector<pair<ll, int>> a;
    vector<ll> crd;
    int n = 0, sz = 0; // [0, n)

    struct Node {
        Node* l = nullptr;
        Node* r = nullptr;
        int sm = 0;

        Node() = default;

        Node(int x) {
            sm = x;
        }

        Node(Node* l_, Node* r_) {
            l = l_;
            r = r_;
            sm = sum_(l ? l->sm : 0, r ? r->sm : 0);
        }
    };

    Node* add(Node* v, int tl, int tr, int pos, int val) {
        if (tl == tr) {
            return new Node(sum_(v ? v->sm : 0, val));
        } else {
            int tm = (tl + tr) >> 1;
            if (pos <= tm) {
                return new Node(
                    add(v ? v->l : nullptr, tl, tm, pos, val),
                    v ? v->r : nullptr
                );
            } else {
                return new Node(
                    v ? v->l : nullptr,
                    add(v ? v->r : nullptr, tm + 1, tr, pos, val)
                );
            }
        }
    }

    vector<Node*> roots;

    RangeTree() = default;

    RangeTree(vector<pair<ll, int>> ar) {
        for (auto [k, v] : ar)
            crd.push_back(k);
        sort(crd.begin(), crd.end());
        crd.erase(unique(crd.begin(), crd.end()), crd.end());
        n = (int) ar.size();
        sz = (int) crd.size();
        roots.emplace_back(nullptr);
        for (auto [k, v] : ar) {
            int pos = lower_bound(crd.begin(), crd.end(), k) - crd.begin();
            roots.emplace_back(add(roots.back(), 0, sz - 1, pos, v));
        }
    }

    int get(Node* v, int tl, int tr, int l, int r) {
        if (!v) return 0;
        if (l <= tl && tr <= r) {
            return v->sm;
        } else {
            int tm = (tl + tr) >> 1, res = 0;
            if (l <= tm) inc_(res, get(v->l, tl, tm, l, r));
            if (r > tm) inc_(res, get(v->r, tm + 1, tr, l, r));
            return res;
        }
    }

    int get(int l, int r, ll lx, ll rx) {
        if (l > r || lx > rx) return 0;
        int lpos = lower_bound(crd.begin(), crd.end(), lx) - crd.begin();
        int rpos = upper_bound(crd.begin(), crd.end(), rx) - crd.begin() - 1;
        if (lpos > rpos) return 0;
        int res = 0;
//        for (int i = l; i <= r; i++) {
//            if (lx <= a[i].first && a[i].first <= rx)
//                inc_(res, a[i].second);
//        }
        inc_(res, get(roots[r + 1], 0, sz - 1, lpos, rpos));
        dec_(res, get(roots[l], 0, sz - 1, lpos, rpos));
        return res;
    }
};

struct input {
    int n, q;
    vector<int> a, b;
    vector<pii> qs;

    input() = default;

    void read() {
        cin >> n >> q;
        a.resize(n);
        b.resize(n);
        for (auto& x : a) cin >> x;
        for (auto& x : b) cin >> x;
        qs.resize(q);
        for (auto& [l, r] : qs) {
            cin >> l >> r;
            l--, r--;
        }
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        vector<int> res;
        vector<ll> B(n);
        for (int i = 0; i < n; i++)
            B[i] = (i > 0 ? B[i - 1] : 0) + b[i];
        for (int i = n - 1; i > 0; i--)
            a[i] -= a[i - 1];
        vector<int> f(n);
        for (int i = 0; i + 1 < n; i++)
            f[i] = mul_(a[i + 1] % mod, (B[i] % mod + mod) % mod);
        a.erase(a.begin());
        vector<pair<ll, int>> ar_f(n - 1), ar_a(n - 1);
        for (int i = 0; i < n - 1; i++) {
            ar_f[i] = {B[i], f[i]};
            ar_a[i] = {B[i], a[i]};
        }
        RangeTree rt_f(ar_f), rt_a(ar_a);
        for (auto [l, r] : qs) {
            int s1 = 0;
            int s2 = 0;
            ll sm = 0;
            ll C = l > 0 ? B[l - 1] : 0;
            r--;
//            for (int i = l; i <= r; i++) {
//                if (B[i] >= C) {
//                    sm += f[i];
//                    sm -= C * a[i];
//                } else {
//                    sm += C * a[i];
//                    sm -= f[i];
//                }
//            }

            inc_(s1, rt_f.get(l, r, C, inf64));
            dec_(s1, rt_f.get(l, r, -inf64, C - 1));

            dec_(s2, rt_a.get(l, r, C, inf64));
            inc_(s2, rt_a.get(l, r, -inf64, C - 1));

            int coef = (C % mod + mod) % mod;
            sm = sum_(s1, mul_(s2, coef));

            res.push_back(sm % mod);
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