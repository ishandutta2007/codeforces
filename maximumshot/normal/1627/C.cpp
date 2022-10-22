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
        if (res.empty()) {
            cout << "-1\n";
        } else {
            for (auto x : res)
                cout << x << " ";
            cout << "\n";
        }
    }

    bool operator == (const output& o) const {
        throw;
    }
};

struct input {
    int n;
    vector<vector<int>> g;
    vector<pii> edges;

    input() = default;

    void read() {
        cin >> n;
        edges.resize(n);
        g.resize(n + 1);
        for (int u, v, i = 1; i < n; i++) {
            cin >> u >> v;
            edges[i] = {u, v};
            g[u].push_back(i);
            g[v].push_back(i);
        }
    }

    int get_to(int eid, int v) {
        return edges[eid].first ^ edges[eid].second ^ v;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        int s = 1;
        for (int v = 1; v <= n; v++) {
            if ((int) g[v].size() > 2)
                return output{{}};
            if ((int) g[v].size() == 1)
                s = v;
        }
        vector<int> res(n);
        function<void(int, int, int)> dfs = [&](int v, int par, int last) {
            for (int eid : g[v]) {
                int to = get_to(eid, v);
                if (to == par)
                    continue;
                res[eid] = 5 - last;
                dfs(to, v, res[eid]);
            }
        };
        dfs(s, -1, 3);
        res.erase(res.begin());
        return output{res};
    }

    output slow() {
#ifndef DEBUG
        throw;
#endif
        return output();
    }
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