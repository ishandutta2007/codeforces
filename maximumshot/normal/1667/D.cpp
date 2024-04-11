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
    int can;
    vector<pii> res;

    void print() {
        if (can) {
            cout << "YES\n";
            for (auto [u, v] : res) {
                cout << u + 1 << " " << v + 1 << "\n";
            }
        } else {
            cout << "NO\n";
        }
    }

    bool operator == (const output& o) const {
        throw;
    }
};

struct input {
    int n;
    vector<pii> es;

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

    output fast() {
        vector<vector<int>> g(n);
        for (auto [u, v] : es) {
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int root = 0;
        while ((int) g[root].size() != 1) root++;
        vector<int> color(n, -1), p(n, -1);
        int ok = 1;
        function<void(int, int)> dfs = [&](int v, int par) {
            int cnt[2] = {0, 0};
            p[v] = par;
            for (int to : g[v]) {
                if (to == par)
                    continue;
                dfs(to, v);
                cnt[color[to]]++;
            }
            if (cnt[1] > cnt[0]) color[v] = 0;
            else color[v] = 1;
            cnt[color[v]]++;
            if (cnt[1] > cnt[0] + 1 || cnt[1] < cnt[0]) ok = 0;
        };
        dfs(g[root][0], root);
        ok &= color[g[root][0]] == 1;
        if (!ok) return output{0, {}};
        vector<vector<int>> h(n);
        for (int v = 0; v < n; v++) {
            if (v == root) continue;
            vector<int> tmp[2];
            for (int to : g[v]) {
                if (to == p[v]) continue;
                tmp[color[to]].push_back(to);
            }
            tmp[color[v]].push_back(v);
            int last = -1;
            if (tmp[1].size() > tmp[0].size()) {
                last = tmp[1].back();
                tmp[1].pop_back();
            }
            while (!tmp[0].empty()) {
                int x = tmp[0].back(); tmp[0].pop_back();
                int y = tmp[1].back(); tmp[1].pop_back();
                if (last != -1) h[last].push_back(x);
                h[x].push_back(y);
                last = y;
            }
        }
        vector<int> used(n), order;
        used[root] = 1;
        function<void(int)> go = [&](int v) {
            if (used[v]) return;
            used[v] = 1;
            for (int to : h[v]) {
                go(to);
            }
            order.push_back(v);
        };
        for (int v = 0; v < n; v++) {
            go(v);
        }
        reverse(order.begin(), order.end());
        vector<pii> res;
        for (int v : order) {
            res.emplace_back(v, p[v]);
        }
        return output{1, res};
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