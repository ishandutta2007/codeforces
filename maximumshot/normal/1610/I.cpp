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
    string res;

    void print() {
        cout << res << "\n";
    }

    bool operator == (const output& o) const {
        throw;
    }
};

struct input {
    int n;
    vector<pii> es;
    vector<vector<int>> g;
    vector<int> sz, p, h;

    input() = default;

    void read() {
        cin >> n;
        es.resize(n - 1);
        for (auto& [u, v] : es) {
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

    void dfs(int v, int par = -1) {
        sz[v] = 1;
        p[v] = par;
        for (int to : g[v]) {
            if (to == par)
                continue;
            dfs(to, v);
            sz[v] += sz[to];
            h[v] ^= h[to] + 1;
        }
    }

    output fast() {
        g.resize(n);
        h.resize(n);
        for (auto [u, v] : es) {
            g[u].push_back(v);
            g[v].push_back(u);
        }
        sz.resize(n);
        p.resize(n);
        dfs(0);
        string res;
        vector<int> in(n);
        int xr = 0;
        {
            in[0] = 1;
            for (int to : g[0]) {
                xr ^= h[to] + 1;
            }
            if (xr) res.push_back('1');
            else res.push_back('2');
        }
        int cv = 1;
        for (int v = 1; v < n; v++) {
            vector<int> path;
            for (int x = v; x != -1 && !in[x]; x = p[x]) {
                in[x] = 1;
                cv++;
                path.push_back(x);
            }
            if (!path.empty()) {
                xr ^= h[path.back()] + 1;
                for (int x: path) {
                    for (int to: g[x]) {
                        if (!in[to]) {
                            xr ^= h[to] + 1;
                        }
                    }
                }
            }
            if ((xr ^ ((cv - 1) % 2))) res.push_back('1');
            else res.push_back('2');
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