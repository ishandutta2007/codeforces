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
    vector<vector<int>> res;

    void print() {
        for (auto row : res) {
            for (auto x : row)
                cout << x << " ";
            cout << "\n";
        }
    }

    bool operator == (const output& o) const {
        throw;
    }
};

struct DSU {
    int n = 0; // [0, n)
    vector<int> par, sz, f;

    DSU() = default;

    DSU(int nn) {
        n = nn;
        par.assign(n, 0);
        iota(par.begin(), par.end(), 0);
        sz.assign(n, 1);
        f.assign(n, 0);
    }

    int find(int x) {
        if (x == par[x]) {
            return x;
        } else {
            int tmp = par[x];
            par[x] = find(par[x]);
            f[x] ^= f[tmp];
        }
        return par[x];
    }

    void merge(int x, int y, int w) {
        int px = find(x);
        int py = find(y);
        if (px == py) return;
        if (sz[px] < sz[py]) {
            swap(x, y);
            swap(px, py);
        }
        par[py] = px;
        f[py] ^= f[y] ^ f[py] ^ w ^ f[x] ^ f[px];
        sz[px] += sz[py];
    }
};

struct input {
    int n;
    vector<vector<int>> a;

    input() = default;

    void read() {
        cin >> n;
        a.resize(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
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
        int xr = 0, flg = 0;
        vector<int> blocked(n);
        DSU dsu(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (a[i][j] == a[j][i]) continue;
                int w = a[i][j] > a[j][i] ? 1 : 0;
                int pi = dsu.find(i);
                int pj = dsu.find(j);
                if (pi != pj) {
//                    cout << "add " << i << " " << j << " " << w << "\n";
                    dsu.merge(i, j, w);
                    if (a[i][j] > a[j][i]) swap(a[i][j], a[j][i]);
                } else {
//                    cout << "get " << i << " " << j << " = " << (dsu.f[i] ^ dsu.f[j]) << "\n";
                    if (dsu.f[i] ^ dsu.f[j]) swap(a[i][j], a[j][i]);
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
    int t;
    cin >> t;
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