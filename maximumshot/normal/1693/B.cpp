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
        return res == o.res;
    }
};

struct input {
    int n;
    vector<int> p;
    vector<pii> s;
    vector<vector<int>> g;
    vector<int> tin, tout;

    input() = default;

    void read() {
        cin >> n;
        p.resize(n);
        for (int i = 1; i < n; i++)
            cin >> p[i], p[i]--;
        s.resize(n);
        for (auto& [l, r] : s)
            cin >> l >> r;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        g.resize(n);
        for (int i = 1; i < n; i++)
            g[p[i]].push_back(i);

        tin.resize(n);
        tout.resize(n);
        int timer = 0;
        function<void(int, int)> dfs = [&](int v, int par) {
            tin[v] = timer++;
            for (int to : g[v])
                dfs(to, v);
            tout[v] = timer;
        };
        dfs(0, -1);

        vector<ll> f(n);

        auto get = [&](int pos) -> ll {
            ll res = 0;
            for (int cur = pos; cur >= 0; cur = (cur & (cur + 1)) - 1)
                res += f[cur];
            return res;
        };

        auto update = [&](int i, ll dx) {
            for (int cur = i; cur < n; cur |= (cur + 1))
                f[cur] += dx;
        };

        auto update_path = [&](int son, int par, ll dx) {
            update(tin[son], +dx);
            if (par) update(tin[p[par]], -dx);
        };

        auto get_subtree = [&](int v) -> ll {
            return get(tout[v] - 1) - get(tin[v] - 1);
        };

        int res = 0;
        for (int v = n - 1; v >= 0; v--) {
            ll x = get_subtree(v);
            auto [l, r] = s[v];
            if (x < l) {
                res++;
                update_path(v, 0, r - x);
            } else if (x > r) {
                update_path(v, 0, r - x);
            }
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