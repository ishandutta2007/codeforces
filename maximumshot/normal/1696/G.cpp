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
    vector<ld> res;

    void print() {
        cout.precision(20);
        cout << fixed;
        for (auto x : res)
            cout << x << "\n";
    }

    bool operator == (const output& o) const {
        throw;
    }
};

struct RangeTree {
    int n = 0; // [0, n)
    ld A, B;

    struct Node {
        ld dp[3][3];

        Node() {
            fill((ld*) dp, (ld*) dp + 9, -1e18);
        }
    };

    Node init(int x) {
        Node res;
        res.dp[0][0] = 0;
        res.dp[1][1] = ld(x) / B;
        res.dp[2][2] = ld(x) / (A + B);
        return res;
    }

    Node merge(const Node& l, const Node& r) {
        Node res;
        for (int x = 0; x < 3; x++) {
            for (int y = 0; y < 3; y++) {
                for (int z = 0; z < 3; z++) {
                    for (int w = 0; w < 3; w++) {
                        if (y == 1 && z != 0) continue;
                        if (z == 1 && y != 0) continue;
                        res.dp[x][w] = max(res.dp[x][w], l.dp[x][y] + r.dp[z][w]);
                    }
                }
            }
        }
        return res;
    }

    vector<Node> t;

    RangeTree() = default;

    RangeTree(const vector<int>& a, ld A_, ld B_) {
        n = (int) a.size();
        A = A_;
        B = B_;
        if (A > B) swap(A, B);
        t.resize(4 * n);
        build(1, 0, n - 1, a);
    }

    void build(int v, int tl, int tr, const vector<int>& a) {
        if (tl == tr) {
            t[v] = init(a[tl]);
        } else {
            int tm = (tl + tr) >> 1;
            build(v << 1, tl, tm, a);
            build(v << 1 | 1, tm + 1, tr, a);
            t[v] = merge(t[v << 1], t[v << 1 | 1]);
        }
    }

    void update(int v, int tl, int tr, int i, int x) {
        if (tl == tr) {
            t[v] = init(x);
        } else {
            int tm = (tl + tr) >> 1;
            if (i <= tm) update(v << 1, tl, tm, i, x);
            else update(v << 1 | 1, tm + 1, tr, i, x);
            t[v] = merge(t[v << 1], t[v << 1 | 1]);
        }
    }

    void update(int i, int x) {
        update(1, 0, n - 1, i, x);
    }

    Node get(int v, int tl, int tr, int l, int r) {
        if (l <= tl && tr <= r) {
            return t[v];
        } else {
            int tm = (tl + tr) >> 1;
            if (l <= tm) {
                if (r > tm) {
                    return merge(
                        get(v << 1, tl, tm, l, r),
                        get(v << 1 | 1, tm + 1, tr, l, r)
                    );
                } else {
                    return get(v << 1, tl, tm, l, r);
                }
            } else {
                return get(v << 1 | 1, tm + 1, tr, l, r);
            }
        }
    }

    ld query(int l, int r) {
        Node tmp = get(1, 0, n - 1, l, r);
        ld res = 0;
        for (int x = 0; x < 3; x++) {
            for (int y = 0; y < 3; y++)
                res = max(res, tmp.dp[x][y]);
        }
        return res;
    }
};

struct input {
    int n, m, A, B;
    vector<int> a;

    struct Query {
        int t;
        int k, v;
        int l, r;

        void read() {
            cin >> t;
            if (t == 1) {
                cin >> k >> v;
                k--;
            } else {
                cin >> l >> r;
                l--, r--;
            };
        }
    };

    vector<Query> qs;

    input() = default;

    void read() {
        cin >> n >> m >> A >> B;
        a.resize(n);
        for (auto& x : a) cin >> x;
        qs.resize(m);
        for (auto& q : qs)
            q.read();
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        vector<ld> res;
        RangeTree rt(a, A, B);
        for (auto q : qs) {
            if (q.t == 1) {
                rt.update(q.k, q.v);
            } else {
                ld tmp = rt.query(q.l, q.r);
                res.push_back(tmp);
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