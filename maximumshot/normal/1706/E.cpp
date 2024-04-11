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

struct RangeTree {
    int n = 0; // [0, n)
    vector<set<tuple<int, int, int>>> f;
    vector<tuple<int, int, int>> mn;

    RangeTree() = default;

    RangeTree(int nn) {
        n = nn;
        f.resize(n);
        mn.assign(2 * n, make_tuple(inf, inf, inf));
    }

    void put(int i, tuple<int, int, int> val) {
        i += n;
        mn[i] = val;
        i >>= 1;
        while (i > 0) {
            mn[i] = min(mn[i << 1], mn[i << 1 | 1]);
            i >>= 1;
        }
    }

    void add(int ql, int qr, int qid) {
        f[ql].insert({qr, ql, qid});
        auto val = *f[ql].begin();
        put(ql, val);
    }

    int pop(int l, int r) {
        int mem_r = r;
        tuple<int, int, int> tmp = {inf, inf, inf};
        l += n, r += n + 1;
        while (l < r) {
            if (l & 1) tmp = min(tmp, mn[l++]);
            if (r & 1) tmp = min(tmp, mn[--r]);
            l >>= 1;
            r >>= 1;
        }
        auto [qr, ql, qid] = tmp;
        if (qid == inf || qr > mem_r) return -1;
        f[ql].erase(f[ql].begin());
        tuple<int, int, int> val = f[ql].empty() ? make_tuple(inf, inf, inf) : *f[ql].begin();
        put(ql, val);
        return qid;
    }
};

struct input {
    int n, m, q;
    vector<pii> es, qs;

    input() = default;

    void read() {
        cin >> n >> m >> q;
        es.resize(m);
        for (auto& [u, v] : es) {
            cin >> u >> v ;
            u--, v--;
        }
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
        vector<int> p(n);
        iota(p.begin(), p.end(), 0);
        vector<vector<int>> f(n);
        for (int v = 0; v < n; v++) {
            f[v] = {v};
        }
        vector<int> res(q, inf);
        RangeTree rt(n);
        for (int i = 0; i < q; i++) {
            auto [l, r] = qs[i];
            if (l == r) {
                res[i] = 0;
                continue;
            }
            rt.add(l, r, i);
        }
        vector<int> nxt(n), prv(n);
        for (int i = 0; i < n; i++) {
            nxt[i] = prv[i] = i;
        }
        function<int(int)> get_next = [&](int i) -> int {
            if (nxt[i] == n - 1 || p[nxt[i] + 1] != p[i]) return nxt[i];
            return nxt[i] = get_next(nxt[i] + 1);
        };
        function<int(int)> get_prev = [&](int i) -> int {
            if (prv[i] == 0 || p[prv[i] - 1] != p[i]) return prv[i];
            return prv[i] = get_prev(prv[i] - 1);
        };
        for (int i = 0; i < m; i++) {
            auto [u, v] = es[i];
            int pu = p[u];
            int pv = p[v];
            if (pu != pv) {
                if (f[pu].size() < f[pv].size()) {
                    swap(u, v);
                    swap(pu, pv);
                }
                for (int t : f[pv]) {
                    p[t] = pu;
                    f[pu].push_back(t);
                }
                for (int t : f[pv]) {
                    int ql = get_prev(t);
                    int qr = get_next(t);
                    while (1) {
                        int qid = rt.pop(ql, qr);
                        if (qid == -1) break;
                        res[qid] = i + 1;
                    }
                }
            }
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
    int t;
    cin >> t;
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