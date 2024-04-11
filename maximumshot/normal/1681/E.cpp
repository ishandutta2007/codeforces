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

struct input {
    int n;
    vector<vector<pii>> a;
    int m;
    vector<pair<pii, pii>> qs;

    input() = default;

    void read() {
        cin >> n;
        a.resize(n - 1);
        for (auto& ps : a) {
            ps.resize(2);
            for (auto& p : ps) {
                auto& [x, y] = p;
                cin >> x >> y;
                x--, y--;
                swap(x, y);
            }
        }
        cin >> m;
        qs.resize(m);
        for (auto& [p1, p2] : qs) {
            auto& [x1, y1] = p1;
            auto& [x2, y2] = p2;
            cin >> x1 >> y1 >> x2 >> y2;
            x1--, y1--, x2--, y2--;
            swap(x1, y1);
            swap(x2, y2);
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
        vector<vector<vector<int>>> dist(n - 2, vector<vector<int>>(2, vector<int>(2, inf)));
        vector<int> between(n - 1);
        for (int i = 0; i < n - 1; i++) {
            auto[x1, y1] = a[i][0];
            auto[x2, y2] = a[i][1];
            between[i] = abs(x1 - x2) + abs(y1 - y2);
        }
        for (int i = 0; i + 1 < n - 1; i++) {
            for (int j1 = 0; j1 < 2; j1++) {
                auto [x1, y1] = a[i][j1];
                if (j1) x1++;
                else y1++;
                for (int j2 = 0; j2 < 2; j2++) {
                    auto [x2, y2] = a[i + 1][j2];
                    dist[i][j1][j2] = 1 + abs(x1 - x2) + abs(y1 - y2);
                }
            }
            vector<vector<int>> hlp = dist[i];
            for (int j1 = 0; j1 < 2; j1++) {
                for (int j2 = 0; j2 < 2; j2++) {
                    hlp[j1][j2] = min(hlp[j1][j2], between[i] + dist[i][j1 ^ 1][j2]);
                    hlp[j1][j2] = min(hlp[j1][j2], between[i] + dist[i][j1 ^ 1][j2 ^ 1] + between[i + 1]);
                }
            }
            dist[i] = hlp;
        }
        struct Node {
            vector<vector<ll>> d;
            int tl = 0;
            int tr = 0;

            Node() {
                d.assign(2, vector<ll>(2, inf64));
            }

            Node(int tl_, int tr_) {
                d.assign(2, vector<ll>(2, inf64));
                tl = tl_;
                tr = tr_;
            }
        };
        vector<Node> t(4 * n);
        auto merge = [&](const Node& le, const Node& ri) -> Node {
            Node res;
            res.tl = le.tl;
            res.tr = ri.tr;
            for (int j1 = 0; j1 < 2; j1++) {
                for (int j2 = 0; j2 < 2; j2++) {
                    for (int j3 = 0; j3 < 2; j3++) {
                        for (int j4 = 0; j4 < 2; j4++) {
                            res.d[j1][j2] = min(
                                    res.d[j1][j2],
                                    le.d[j1][j3] + ri.d[j4][j2] + dist[le.tr][j3][j4]
                            );
                        }
                    }
                }
            }
            return res;
        };
        function<void(int, int, int)> build = [&](int v, int tl, int tr) {
            if (tl == tr) {
                t[v].tl = t[v].tr = tl;
                for (int j1 = 0; j1 < 2; j1++) {
                    for (int j2 = 0; j2 < 2; j2++) {
                        t[v].d[j1][j2] = j1 == j2 ? 0 : between[tl];
                    }
                }
            } else {
                int tm = (tl + tr) >> 1;
                build(v << 1, tl, tm);
                build(v << 1 | 1, tm + 1, tr);
                t[v] = merge(t[v << 1], t[v << 1 | 1]);
            }
        };
        build(1, 0, n - 2);
        function<Node(int, int, int, int, int)> get = [&](int v, int tl, int tr, int l, int r) -> Node {
            if (l <= tl && tr <= r) {
                return t[v];
            } else {
                int tm = (tl + tr) >> 1;
                if (l <= tm) {
                    if (r > tm) {
                        Node le = get(v << 1, tl, tm, l, r);
                        Node ri = get(v << 1 | 1, tm + 1, tr, l, r);
                        return merge(le, ri);
                    } else {
                        return get(v << 1, tl, tm, l, r);
                    }
                } else {
                    return get(v << 1 | 1, tm + 1, tr, l, r);
                }
            }
        };
        vector<ll> res;
        for (auto [p1, p2] : qs) {
            auto [x1, y1] = p1;
            auto [x2, y2] = p2;
            if (max(x1, y1) > max(x2, y2)) {
                swap(p1, p2);
                swap(x1, x2);
                swap(y1, y2);
            }
            if (max(x1, y1) == max(x2, y2)) {
                res.push_back(abs(x1 - x2) + abs(y1 - y2));
                continue;
            }
            int lvl1 = max(x1, y1);
            int lvl2 = max(x2, y2);
            Node hlp = get(1, 0, n - 2, lvl1, lvl2 - 1);
            ll mn = inf64;
            for (int j1 = 0; j1 < 2; j1++) {
                auto q1 = a[lvl1][j1];
                for (int j2 = 0; j2 < 2; j2++) {
                    auto q2 = a[lvl2 - 1][j2];
                    if (j2) q2.first++;
                    else q2.second++;
                    ll tmp = 0;
                    tmp += abs(x1 - q1.first) + abs(y1 - q1.second);
                    tmp += hlp.d[j1][j2];
                    tmp += 1 + abs(x2 - q2.first) + abs(y2 - q2.second);
                    mn = min(mn, tmp);
                }
            }
            res.push_back(mn);
        }
        return output{res};
    }

#ifdef DEBUG
    output slow() {

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