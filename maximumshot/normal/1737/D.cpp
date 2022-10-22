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

struct input {
    int n, m;
    vector<tuple<int, int, int>> es;

    input() = default;

    void read() {
        cin >> n >> m;
        es.resize(m);
        for (auto& [u, v, w] : es) {
            cin >> u >> v >> w;
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
        vector<vector<int>> f(n, vector<int>(n, inf)), g(n, vector<int>(n, inf));
        for (int v = 0; v < n; v++) g[v][v] = 0;
        for (auto [u, v, w] : es) {
            g[u][v] = g[v][u] = 1;
        }
        for (int w = 0; w < n; w++) {
            for (int u = 0; u < n; u++) {
                for (int v = 0; v < n; v++) {
                    g[u][v] = min(g[u][v], g[u][w] + g[w][v]);
                }
            }
        }
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                f[u][v] = min(f[u][v], g[0][u] + g[n - 1][v]);
                f[u][v] = min(f[u][v], g[0][v] + g[n - 1][u]);
                for (int z = 0; z < n; z++) {
                    f[u][v] = min(f[u][v], 1 + min(g[u][z], g[v][z]) + g[0][z] + g[z][n - 1]);
                    f[u][v] = min(f[u][v], g[0][u] + g[n - 1][v]);
                }
            }
        }
        ll res = inf64;
        for (auto [u, v, w] : es) {
//            cout << u << " " << v << " " << w << " : " << f[u][v] << "\n";
            res = min(res, 1ll * w * f[u][v] + w);
            swap(u, v);
            res = min(res, 1ll * w * f[u][v] + w);
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
//#ifdef DEBUG
    cin >> t;
//#endif
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