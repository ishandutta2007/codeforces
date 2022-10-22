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

struct DSU {
    int n = 0; // [0, n)
    vector<int> p, f, is_good;

    DSU() = default;

    DSU(int nn) {
        n = nn;
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        f.assign(n, (1 << 30) - 1);
        is_good.assign(n, 0);
    }

    void update(int v, int x) {
        v = find(v);
        f[v] &= x;
    }

    int find(int x) {
        return x == p[x] ? x : p[x] = find(p[x]);
    }

    void make_good(int v) {
        v = find(v);
        is_good[v] = 1;
    }

    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y)
            return;
        p[y] = x;
    }
};

struct input {
    int n, m, q;

    struct Edge {
        int u = 0;
        int v = 0;
        int w = 0;
    };

    vector<Edge> es;
    vector<pii> qs;

    input() = default;

    void read() {
        cin >> n >> m;
        es.resize(m);
        for (auto& e : es) {
            cin >> e.u >> e.v >> e.w;
            e.u--, e.v--;
        }
        cin >> q;
        qs.resize(q);
        for (auto& [u, v] : qs) {
            cin >> u >> v;
            u--, v--;
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
        vector<DSU> dsu(30);
        for (int j = 0; j < 30; j++) {
            dsu[j] = DSU(n);
            for (auto e : es) {
                if ((1 << j) & e.w)
                    dsu[j].merge(e.u, e.v);
            }
            for (auto e : es) {
                if ((1 << j) & e.w)
                    dsu[j].update(e.u, e.w);
            }
            for (auto e : es) {
                if (dsu[j].find(e.u) == dsu[j].find(e.v))
                    continue;
                for (int it = 0; it < 2; it++, swap(e.u, e.v)) {
                    int x = dsu[j].f[dsu[j].find(e.u)];
                    if ((x & e.w) == 0)
                        dsu[j].make_good(e.u);
                }
            }
        }
        vector<int> res;
        for (auto [u, v] : qs) {
            int any = 0;
            for (int j = 0; j < 30; j++) {
                if (dsu[j].find(u) == dsu[j].find(v)) {
                    any = 1;
                    break;
                }
            }
            if (any) {
                res.push_back(0);
                continue;
            }
            for (int j = 1; j < 30; j++) {
                if (dsu[j].is_good[dsu[j].find(u)]) {
                    any = 1;
                    break;
                }
            }
            if (any) {
                res.push_back(1);
            } else {
                res.push_back(2);
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