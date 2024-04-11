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

struct input {
    int n, q;
    vector<tuple<int, int, int>> cond;

    input() = default;

    void read() {
        cin >> n >> q;
        cond.resize(q);
        for (auto& [i, j, x] : cond) {
            cin >> i >> j >> x;
            i--, j--;
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
        vector<vector<pii>> g(n);
        for (auto [i, j, x] : cond) {
            g[i].emplace_back(j, x);
            g[j].emplace_back(i, x);
        }
        vector<int> a(n);
        const int LOG = 30;
        for (int j = LOG - 1; j >= 0; j--) {
            vector<int> f(n);
            for (auto [u, v, x] : cond) {
                if ((x >> j) & 1) {}
                else f[u] = f[v] = 1;
            }
            for (int i = 0; i < n; i++) {
                if (f[i]) continue;
                for (auto [k, x] : g[i]) {
                    if ((x >> j) & 1) {
                        if (f[k]) a[i] |= 1 << j;
                        else {
                            if (k <= i && !((a[k] >> j) & 1))
                                a[i] |= 1 << j;
                        }
                    }
                }
            }
        }
        return output{a};
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