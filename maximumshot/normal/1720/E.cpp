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
    int res;

    void print() {
        cout << res << "\n";
    }

    bool operator == (const output& o) const {
        throw;
    }
};

struct input {
    int n, k;
    vector<vector<int>> a;

    input() = default;

    void read() {
        cin >> n >> k;
        a.resize(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cin >> a[i][j], a[i][j]--;
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
        vector<int> used(n * n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                used[a[i][j]] = 1;
        }
        int cc = 0;
        for (int x = 0; x < n * n; x++) {
            cc += used[x];
        }
        if (cc <= k) {
            return output{k - cc};
        }
        // 1 or 2
        struct Rec {
            int li = inf;
            int ri = -inf;
            int lj = inf;
            int rj = -inf;

            void update(int i, int j) {
                li = min(li, i);
                ri = max(ri, i);
                lj = min(lj, j);
                rj = max(rj, j);
            }

            int area() const {
                return (ri - li + 1) * (rj - lj + 1);
            }

            bool check_cover(const Rec& o) const {
                return li <= o.li && o.ri <= ri && lj <= o.lj && o.rj <= rj;
            }

            int get_max_dim() const {
                return max(ri - li + 1, rj - lj + 1);
            }
        };
        vector<Rec> recs(n * n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                recs[a[i][j]].update(i, j);
            }
        }
        vector<vector<int>> f(n + 1, vector<int>(n + 1));
        auto update = [&](int li, int ri, int lj, int rj) {
            f[li][lj]++;
            f[ri + 1][lj]--;
            f[li][rj + 1]--;
            f[ri + 1][rj + 1]++;
        };
        auto push = [&]() {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    f[i + 1][j] += f[i][j];
                    f[i][j + 1] += f[i][j];
                    f[i + 1][j + 1] -= f[i][j];
                }
            }
        };
        for (int W = 1; W <= n; W++) {
            f.assign(n + 1, vector<int>(n + 1, 0));
            for (int x = 0; x < n * n; x++) {
                if (!used[x]) continue;
                auto r = recs[x];
                int li = max({0, r.ri - W + 1});
                int ri = min(r.li, n - 1);
                int lj = max({0, r.rj - W + 1});
                int rj = min(r.lj, n - 1);
                if (li > ri || lj > rj) continue;
                update(li, ri, lj, rj);
            }
            push();
            int ok = 0;
            for (int i = 0; i + W - 1 < n; i++) {
                for (int j = 0; j + W - 1 < n; j++) {
                    if (f[i][j] == cc - k + 1 || f[i][j] == cc - k) {
                        ok = 1;
                        break;
                    }
                }
                if (ok) break;
            }
            if (ok) return output{1};
        }
        return output{2};
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