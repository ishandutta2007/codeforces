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
            cout << x + 1 << " ";
        cout << "\n";
    }

    bool operator == (const output& o) const {
        throw;
    }
};

struct input {
    int n, m;
    vector<int> p;
    vector<pii> b;

    input() = default;

    void read() {
        cin >> n >> m;
        p.resize(n);
        for (auto& x : p) cin >> x, x--;
        b.resize(m);
        for (auto& [x, y] : b) {
            cin >> x >> y;
            x--, y--;
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
        vector<vector<int>> g(n);
        auto get_to = [&](int swap_id, int fr) -> int {
            auto [x, y] = b[swap_id];
            return x ^ y ^ fr;
        };
        for (int i = 0; i < m; i++) {
            auto [x, y] = b[i];
            g[x].push_back(i);
            g[y].push_back(i);
        }
        vector<int> f(n, -1);
        int timer = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; f[j] == -1; j = p[j])
                f[j] = timer++;
        }
        vector<int> res;
        vector<int> used(m), used_swp(m);
        vector<vector<int>> h(m);
        for (int v = 0; v < n; v++) {
            sort(g[v].begin(), g[v].end(), [&](int swp_id1, int swp_id2) {
                int to1 = get_to(swp_id1, v);
                int to2 = get_to(swp_id2, v);
                return f[to1] < f[to2];
            });
            int pos = 0;
            while (pos < (int) g[v].size()) {
                int swp_id = g[v][pos];
                int to = get_to(swp_id, v);
                if (f[to] > f[v]) break;
                pos++;
            }
            if (pos < (int) g[v].size())
                rotate(g[v].begin(), g[v].begin() + pos, g[v].end());
            for (int it = 1; it < (int) g[v].size(); it++) {
                h[g[v][it - 1]].push_back(g[v][it]);
            }
        }
        function<void(int)> dfs = [&](int v) {
            used[v] = 1;
            for (int to : h[v]) {
                if (!used[to]) {
                    dfs(to);
                }
            }
            res.push_back(v);
        };
        for (int i = 0; i < m; i++) {
            if (!used[i])
                dfs(i);
        }
        reverse(res.begin(), res.end());
#ifdef DEBUG
        vector<int> perm = p;
        for (int swap_id : res) {
            auto [x, y] = b[swap_id];
            swap(perm[x], perm[y]);
        }
        cout << "perm = \n";
        for (int i = 0; i < n; i++) {
            cout << perm[i] << " ";
        }
        cout << "\n";
#endif
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