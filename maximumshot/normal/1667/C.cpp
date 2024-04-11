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
    vector<pii> res;

    void print() {
        cout << (int) res.size() << "\n";
        for (auto [i, j] : res)
            cout << i + 1 << " " << j + 1 << "\n";
    }

    bool operator == (const output& o) const {
        return res.size() == o.res.size();
    }
};

struct input {
    int n;

    input() = default;

    void read() {
        cin >> n;
    }

    void print() {
        cout << n << "\n";
    }

    void gen() {
        static mt19937 rnd(42);
        const int MAXN = 5;
        n = rnd() % MAXN + 1;
    }

    void gen_max_test() {

    }

    output fast() {
        int k = (2 * n + 1) / 3;
        int x = n - k;
        assert(3 * x - 1 <= n);
        vector<pii> res;
        for (int i = 0; i <= n - 3 * x && i < n; i++)
            res.emplace_back(i, i);
        for (int i = 0; i < x - 1; i++)
            res.emplace_back(n - 3 * x + 1 + i, n - 2 * x - 1 - i);
        for (int i = 0; i < x; i++)
            res.emplace_back(n - 2 * x + i, n - x - 1 - i);
        return output{res};
    }

#ifdef DEBUG
    output slow() {
        for (int k = 1; k <= n * n; k++) {
            vector<pii> res;
            function<void(ll, int)> rec = [&](ll mask, int cur) {
                if (__builtin_popcount(mask) == k) {
                    vector<pii> tmp;
                    vector<vector<int>> used(n, vector<int>(n));
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < n; j++) {
                            if ((1ll << (i * n + j)) & mask) {
                                tmp.emplace_back(i, j);
                            }
                        }
                    }
                    for (auto [i, j] : tmp) {
                        for (int q = 0; q < n; q++) {
                            used[q][j] = used[i][q] = 1;
                        }
                        for (int q = -n; q <= n; q++) {
                            if (0 <= i + q && i + q < n && 0 <= j + q && j + q < n)
                                used[i + q][j + q] = 1;
                        }
                    }
                    int ok = 1;
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < n; j++) {
                            if (!used[i][j])
                                ok = 0;
                        }
                    }
                    if (ok) {
                        res = tmp;
                    }
                } else if (cur < n * n) {
                    rec(mask, cur + 1);
                    if (!res.empty()) return;
                    rec(mask | (1ll << cur), cur + 1);
                    if (!res.empty()) return;
                }
            };
            rec(0, 0);
            if (!res.empty())
                return output{res};
        }
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