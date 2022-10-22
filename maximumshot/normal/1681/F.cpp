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
    ll res;

    void print() {
        cout << res << "\n";
    }

    bool operator == (const output& o) const {
        throw;
    }
};

vector<pair<int*, int>> buffer;
vector<int> szs;

void ASSIGN(int* ptr, int val) {
    buffer.emplace_back(ptr, *ptr);
    *ptr = val;
}

void SAVE() {
    szs.push_back((int) buffer.size());
}

void ROLLBACK() {
    int need = szs.back();
    szs.pop_back();
    while ((int) buffer.size() > need) {
        auto [ptr, val] = buffer.back();
        buffer.pop_back();
        *ptr = val;
    }
}

struct DSU {
    int n = 0; // [0, n)
    vector<int> p, sz;

    DSU() = default;

    DSU(int nn) {
        n = nn;
        p.assign(n, 0);
        iota(p.begin(), p.end(), 0);
        sz.assign(n, 1);
    }

    int find(int x) {
        return x == p[x] ? x : find(p[x]);
    }

    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y)
            return;
        if (sz[x] < sz[y]) swap(x, y);
        ASSIGN(&p[y], x);
        ASSIGN(&sz[x], sz[x] + sz[y]);
    }

    int size(int v) {
        return sz[find(v)];
    }
};

struct input {
    int n;

    struct Edge {
        int u = 0;
        int v = 0;
        int x = 0;
    };

    vector<Edge> es;

    input() = default;

    void read() {
        cin >> n;
        es.resize(n - 1);
        for (auto& e : es) {
            cin >> e.u >> e.v >> e.x;
            e.u--, e.v--, e.x--;
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
        vector<vector<int>> x_to_es(n);
        for (int i = 0; i < n - 1; i++) {
            auto e = es[i];
            x_to_es[e.x].push_back(i);
        }
        struct Seg {
            int l = 0;
            int r = 0;
            int eid;
        };
        vector<Seg> segs;
//        vector<pair<char, int>> queries;
        vector<int> last(n - 1);
        int timer = 0;
        vector<pii> qs_times;
        for (int x = 0; x < n; x++) {
            for (int i : x_to_es[x]) {
                segs.push_back(Seg{0, timer, i});
            }
            timer++;
            for (int i : x_to_es[x]) {
                qs_times.emplace_back(timer, i);
                timer++;
            }
            for (int i : x_to_es[x])
                last[i] = timer;
        }
        for (int i = 0; i < n - 1; i++)
            segs.push_back(Seg{last[i], timer, i});
        timer++;
        vector<int> qs(timer, -1);
        for (auto [t, eid] : qs_times)
            qs[t] = eid;
        ll res = 0;
//        for (int t = 0; t < timer; t++) {
//            if (qs[t] == -1)
//                continue;
//            DSU dsu(n);
//            SAVE();
//            for (auto seg : segs) {
//                if (seg.l < t && t < seg.r) {
//                    auto e = es[seg.eid];
//                    dsu.merge(e.u, e.v);
//                }
//            }
//            auto e = es[qs[t]];
//            res += 1ll * dsu.size(e.u) * dsu.size(e.v);
//            ROLLBACK();
//        }
        DSU dsu(n);
        function<void(int, int, vector<Seg>)> rec = [&](int tl, int tr, vector<Seg> ar) {
            SAVE();
            int tm = (tl + tr) >> 1;
            vector<Seg> ar_l, ar_r;
            for (auto seg : ar) {
                if (seg.r < tl || seg.l > tr) continue;
                if (seg.l <= tl && tr <= seg.r) {
                    auto e = es[seg.eid];
                    dsu.merge(e.u, e.v);
                } else {
                    if (seg.l <= tm) ar_l.push_back(seg);
                    if (seg.r > tm) ar_r.push_back(seg);
                }
            }
            if (tl < tr) {
                rec(tl, tm, ar_l);
                rec(tm + 1, tr, ar_r);
            } else {
                int eid = qs[tl];
                if (eid != -1) {
                    auto e = es[eid];
                    res += 1ll * dsu.size(e.u) * dsu.size(e.v);
                }
            }
            ROLLBACK();
        };
        rec(0, timer - 1, segs);
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