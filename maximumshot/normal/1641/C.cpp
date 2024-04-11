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
            cout << (x == 1 ? "YES" : x == 0 ? "NO" : "N/A") << "\n";
    }

    bool operator == (const output& o) const {
        throw;
    }
};

struct RangeTree {
    int n = 0; // [0, n)
    vector<pii> t;
    vector<multiset<int>> val;

    RangeTree() = default;

    RangeTree(int nn) {
        n = nn;
        t.assign(2 * n, {inf, inf});
        val.resize(n);
    }

    void set(int i, int x, int ty) {
        if (ty == +1) val[i].insert(x);
        else val[i].erase(val[i].find(x));
        for (i += n, t[i] = {val[i - n].empty() ? inf : *val[i - n].begin(), i - n}, i >>= 1; i > 0; i >>= 1)
            t[i] = min(t[i << 1], t[i << 1 | 1]);
    }

    pii get(int l, int r) {
        pii res = {inf, inf};
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res = min(res, t[l++]);
            if (r & 1) res = min(res, t[--r]);
        }
        return res;
    }
};

struct input {
    int n, m;

    struct Query {
        int t, l, r, x, j;
    };

    vector<Query> qs;

    input() = default;

    void read() {
        cin >> n >> m;
        qs.resize(m);
        for (auto& q : qs) {
            cin >> q.t;
            if (q.t == 0) {
                cin >> q.l >> q.r >> q.x;
            } else {
                cin >> q.j;
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

    output fast() {
        set<int> Q;
        for (int i = 0; i <= n + 1; i++)
            Q.insert(i);
        RangeTree rt(n + 1);
        vector<int> res;
        for (auto q : qs) {
            if (q.t == 0) {
                if (q.x == 1) {
                    rt.set(q.l, q.r, +1);
                } else {
                    for (auto it = Q.lower_bound(q.l); it != Q.end() && *it <= q.r;)
                        it = Q.erase(it);
                }
            } else {
                if (!Q.count(q.j)) {
                    res.push_back(0);
                } else {
                    auto it = Q.find(q.j);
                    int L = *prev(it);
                    int R = *next(it);
                    if (L + 1 <= q.j) {
                        while (1) {
                            auto [qr, ql] = rt.get(L + 1, q.j);
                            if (qr < q.j) {
                                rt.set(ql, qr, -1);
                            } else {
                                if (qr < R) {
                                    res.push_back(1);
                                } else {
                                    res.push_back(-1);
                                }
                                break;
                            }
                        }
                    }
                }
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