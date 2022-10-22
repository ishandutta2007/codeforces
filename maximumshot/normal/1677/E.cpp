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

struct RT {
    int n = 0; // [0, n)
    vector<ll> sm, pu;

    RT() = default;

    RT(int nn) {
        n = nn;
        sm.assign(4 * n, 0);
        pu.assign(4 * n, 0);
    }

    void inc(int v, int tl, int tr, ll x) {
        pu[v] += x;
        sm[v] += x * (tr - tl + 1);
    }

    void push(int v, int tl, int tm, int tr) {
        if (pu[v]) {
            inc(v << 1, tl, tm, pu[v]);
            inc(v << 1 | 1, tm + 1, tr, pu[v]);
            pu[v] = 0;
        }
    }

    void merge(int v) {
        sm[v] = sm[v << 1] + sm[v << 1 | 1];
    }

    void update(int v, int tl, int tr, int l, int r, ll x) {
        if (l <= tl && tr <= r) {
            inc(v, tl, tr, x);
        } else {
            int tm = (tl + tr) >> 1;
            push(v, tl, tm, tr);
            if (l <= tm) update(v << 1, tl, tm, l, r, x);
            if (r > tm) update(v << 1 | 1, tm + 1, tr, l, r, x);
            merge(v);
        }
    }

    void update(int l, int r, ll x) {
        update(1, 0, n - 1, l, r, x);
    }

    ll get(int v, int tl, int tr, int l, int r) {
        if (l <= tl && tr <= r) {
            return sm[v];
        } else {
            int tm = (tl + tr) >> 1;
            push(v, tl, tm, tr);
            ll res = 0;
            if (l <= tm) res += get(v << 1, tl, tm, l, r);
            if (r > tm) res += get(v << 1 | 1, tm + 1, tr, l, r);
            merge(v);
            return res;
        }
    }

    ll get(int l, int r) {
        return get(1, 0, n - 1, l, r);
    }
};

struct SegmentsHolder {
    int n = 0; // [1, n]
//    multiset<pii> q;
//    vector<ll> f;
//    vector<ll> ks, bs;
    RT rt_ks, rt_bs;
    ll t = 0;

    SegmentsHolder() = default;

    SegmentsHolder(int nn) {
        n = nn;
//        f.assign(n + 1, 0);
//        ks.assign(n + 1, 0);
//        bs.assign(n + 1, 0);
        rt_ks = RT(n + 1);
        rt_bs = RT(n + 1);
    }

    void add_segment(int l, int r) {
        if (l > r) return;
//        q.insert({l, r});
        rt_ks.update(l, r, +1);
        rt_bs.update(l, r, -t);
//        for (int j = l; j <= r; j++) {
//            ks[j]++;
//            bs[j] -= t;
//        }
    }

    void remove_segment(int l, int r) {
        if (l > r) return;
//        q.erase(q.find({l, r}));
        rt_ks.update(l, r, -1);
        rt_bs.update(l, r, +t);
//        for (int j = l; j <= r; j++) {
//            ks[j]--;
//            bs[j] += t;
//        }
    }

    void inc() {
        t++;
//        for (auto [l, r] : q) {
//            for (int j = l; j <= r; j++)
//                f[j]++;
//        }
    }

    ll get(int l, int r) {
        ll res = 0;
//        for (int j = l; j <= r; j++)
//            res += ks[j] * t + bs[j];
        res += rt_ks.get(l, r) * t + rt_bs.get(l, r);
        return res;
    }
};

struct input {
    int n, q;
    vector<int> p;
    vector<pii> qs;

    input() = default;

    void read() {
        cin >> n >> q;
        p.resize(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> p[i];
        qs.resize(q);
        for (auto& [l, r] : qs)
            cin >> l >> r;
    }

    void print() {
        cout << n << " " << q << "\n";
        for (int i = 1; i <= n; i++)
            cout << p[i] << " ";
        cout << "\n";
        for (auto [l, r] : qs)
            cout << l << " " << r << "\n";
    }

    void gen() {
        static mt19937 rnd(42);
        const int MAXN = 8;
        n = rnd() % MAXN + 1;
        p.resize(n + 1);
        iota(p.begin(), p.end(), 0);
        shuffle(p.begin() + 1, p.end(), rnd);
        q = rnd() % (MAXN * MAXN) + 1;
//        q = 1;
        qs.resize(q);
        for (auto& [l, r] : qs) {
            r = rnd() % n + 1;
            l = rnd() % r + 1;
        }
    }

    void gen_max_test() {

    }

    output fast() {
        vector<int> tol(n + 1, -inf), pos(n + 1, -1);
        for (int i = 1; i <= n; i++)
            pos[p[i]] = i;
        p[0] = inf;
        vector<int> st = {0};
        vector<int> in_st(n + 1, -1);
        in_st[0] = 0;
        vector<vector<int>> upd(n + 1);
        for (int i = 0; i < q; i++) {
            auto [l, r] = qs[i];
            upd[r].push_back(i);
        }
        vector<ll> res(q);
//        vector<int> acc(n + 1);
        auto get_seg = [&](int id) -> pii {
            int ql = st[id - 1] + 1;
            int qr = min(st[id], tol[st[id]]);
            return {ql, qr};
        };
        SegmentsHolder sh(n);
        for (int i = 1; i <= n; i++) {
            while (p[st.back()] < p[i]) {
                auto [ql, qr] = get_seg((int) st.size() - 1);
                sh.remove_segment(ql, qr);
                in_st[st.back()] = -1;
                st.pop_back();
            }
            in_st[i] = (int) st.size();
            st.push_back(i);
            {
                auto [ql, qr] = get_seg((int) st.size() - 1);
                sh.add_segment(ql, qr);
            }
            for (int x = 1; x * p[i] <= n; x++) {
                if (x == p[i])
                    continue;
                int j = pos[x];
                int k = pos[x * p[i]];
                if (j < i) {
                    if (in_st[k] != -1) {
                        auto [ql, qr] = get_seg(in_st[k]);
                        sh.remove_segment(ql, qr);
                    }
                    tol[k] = max(tol[k], j);
                    if (in_st[k] != -1) {
                        auto [ql, qr] = get_seg(in_st[k]);
                        sh.add_segment(ql, qr);
                    }
                }
            }
            sh.inc();
//            for (int it = 1; it < (int) st.size(); it++) {
//                auto [ql, qr] = get_seg(it);
//                for (int jit = ql; jit <= qr; jit++)
//                    acc[jit]++;
//            }
            for (int qid : upd[i]) {
                auto [l, r] = qs[qid];
                ll sm = 0;
//                for (int it = l; it <= r; it++)
//                    sm += acc[it];
                sm += sh.get(l, r);
                res[qid] = sm;
            }
        }
        return output{res};
    }

#ifdef DEBUG
    output slow() {
        vector<ll> res;
        for (auto [l, r] : qs) {
            ll sm = 0;
            for (int x = l; x <= r; x++) {
                for (int y = x; y <= r; y++) {
                    int mx = *max_element(p.begin() + x, p.begin() + y + 1);
                    int ok = 0;
                    for (int i = x; i <= y; i++) {
                        for (int j = i + 1; j <= y; j++) {
                            if (1ll * p[i] * p[j] == mx)
                                ok = 1;
                        }
                    }
                    sm += ok;
//                    if (ok)
//                        cout << x << " " << y << "\n";
                }
            }
            res.push_back(sm);
        }
        return output{res};
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