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

struct RangeTree {
    int n = 0; // [0, n)

    struct Node {
        int l = 0;
        int m = 0;
        int r = 0;
        int ops = 0;

        Node() {

        }

        Node(int x) {
            ops = 0;
            if (x == 0) {
                l = 1;
                m = 0;
                r = 0;
            } else {
                l = 0;
                m = 1;
                r = 0;
            }
        }

        int sum() const {
            int res = ops;
            if (m == 0) {
                int tmp = l + r;
                if (tmp >= 3) {
                    // tmp - 2 * k <= 2
                    int k = (tmp - 2 + 1) / 2;
                    res += k;
                    tmp -= 2 * k;
                }
//                while (tmp >= 3) {
//                    tmp -= 2;
//                    res++;
//                }
                res += tmp;
            } else {
                int tmp;

                res += (l + 1) / 2;
//                tmp = l;
//                while (tmp >= 1) {
//                    tmp -= 2;
//                    res++;
//                }

                res += (r + 1) / 2;
//                tmp = r;
//                while (tmp >= 1) {
//                    tmp -= 2;
//                    res++;
//                }

                res += m;
            }
            return res;
        }
    };

    Node merge(Node l, Node r) {
        Node res;
        if (l.m == 0) {
            res = r;
            res.ops += l.ops;
            res.l += l.l + l.r;
        } else if (r.m == 0) {
            res = l;
            res.ops += r.ops;
            res.r += r.l + r.r;
        } else {
            res.ops = l.ops + r.ops;
            if (l.r == 0 && r.l == 0) {
                res.l = l.l;
                res.r = r.r;
                res.m = l.m + r.m;
            } else {
                int tmp = l.r + r.l;
//                while (tmp >= 2) {
//                    tmp -= 2;
//                    res.ops++;
//                }
                {
                    int k = tmp / 2;
                    res.ops += k;
                    tmp -= 2 * k;
                }
                if (tmp == 1) {
                    if (l.m > r.m) {
                        res.ops += r.m;
                        res.l = l.l;
                        res.m = l.m - r.m;
                        res.r = 1 + r.r;
                    } else {
                        res.ops += l.m;
                        res.l = 1 + l.l;
                        res.m = r.m - l.m;
                        res.r = r.r;
                    }
                } else {
                    res.l = l.l;
                    res.r = r.r;
                    res.m = l.m + r.m;
                }
            }
        }
        return res;
    }

    vector<Node> t;

    RangeTree() = default;

    RangeTree(const vector<int>& a) {
        n = (int) a.size();
        t.resize(4 * n);
        build(1, 0, n - 1, a);
    }

    void build(int v, int tl, int tr, const vector<int>& a) {
        if (tl == tr) {
            t[v] = Node(a[tl]);
        } else {
            int tm = (tl + tr) >> 1;
            build(v << 1, tl, tm, a);
            build(v << 1 | 1, tm + 1, tr, a);
            t[v] = merge(t[v << 1], t[v << 1 | 1]);
        }
    }

    Node get(int v, int tl, int tr, int l, int r) {
        if (l <= tl && tr <= r) {
            return t[v];
        } else {
            int tm = (tl + tr) >> 1;
            Node res;
            if (l <= tm) res = merge(res, get(v << 1, tl, tm, l, r));
            if (r > tm) res = merge(res, get(v << 1 | 1, tm + 1, tr, l, r));
            return res;
        }
    }

    int get(int l, int r) {
        Node tmp = get(1, 0, n - 1, l, r);
        return tmp.sum();
    }
};

struct input {
    int n, m;
    vector<int> a;
    vector<pii> qs;

    input() = default;

    void read() {
        cin >> n >> m;
        a.resize(n);
        string buf;
        cin >> buf;
        for (int i = 0; i < n; i++)
            a[i] = buf[i] - '0';
        qs.resize(m);
        for (auto& [l, r] : qs) {
            cin >> l >> r;
            l--, r--;
        }
    }

    void print() {
        cout << n << " " << m << "\n";
        for (auto x : a)
            cout << x;
        cout << "\n";
        for (auto [l, r] : qs)
            cout << l + 1 << " " << r + 1 << "\n";
    }

    void gen() {
        static mt19937 rnd(42);
        const int N = 10;
        n = rnd() % N + 1;
        a.resize(n);
        for (auto& x : a)
            x = rnd() % 2;

//        m = 1;
//        qs = {{0, n - 1}};

        m = rnd() % N + 1;
        qs.resize(m);
        for (auto& [l, r] : qs) {
            r = rnd() % n;
            l = rnd() % (r + 1);
        }
    }

    void gen_max_test() {

    }

    output fast() {
        vector<int> blocks, P;
        for (int i = 0; i < n; i++) {
            int j = i;
            while (j + 1 < n && a[j] != a[j + 1]) j++;
            // [i, j]
            blocks.push_back((j - i + 1) % 2);
            P.push_back(j - i + 1);
            i = j;
        }
        for (int i = 1; i < (int) P.size(); i++)
            P[i] += P[i - 1];
        RangeTree rt(blocks);
        vector<int> res;
        for (auto [l, r] : qs) {
            l = lower_bound(P.begin(), P.end(), l + 1) - P.begin();
            r = lower_bound(P.begin(), P.end(), r + 1) - P.begin();
            int tmp = rt.get(l, r);
            res.push_back(tmp);
        }
        return output{res};
    }

#ifdef DEBUG

    int solve(vector<int> ar) {
        if (ar.empty()) return 0;
        int res = inf;
        for (int l = 0; l < (int) ar.size(); l++) {
            for (int r = l; r < (int) ar.size(); r++) {
                if (r > l && ar[r] == ar[r - 1]) break;
                vector<int> to_ar;
                for (int j = 0; j < l; j++) to_ar.push_back(ar[j]);
                for (int j = r + 1; j < (int) ar.size(); j++) to_ar.push_back(ar[j]);
                res = min(res, 1 + solve(to_ar));
            }
        }
        return res;
    }

    output slow() {
        vector<int> res;
        for (auto [l, r] : qs) {
            vector<int> ar;
            for (int j = l; j <= r; j++)
                ar.push_back(a[j]);
            int tmp = solve(ar);
            res.push_back(tmp);
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