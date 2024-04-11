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
    int n, m;

    struct Edge {
        int u, v, w;
    };

    vector<int> used;
    vector<vector<pii>> g;

    input() = default;

    void read() {
        cin >> n >> m;
        g.resize(n);
        for (int u, v, w, i = 0; i < m; i++) {
            cin >> u >> v >> w;
            u--, v--;
            g[u].emplace_back(v, w);
            g[v].emplace_back(u, w);
        }
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    bool check(int mask) {
        used.assign(n, 0);
        used[0] = 1;
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (auto [to, w] : g[v]) {
                if (w & mask)
                    continue;
                if (!used[to]) {
                    used[to] = 1;
                    q.push(to);
                }
            }
        }
        for (int v = 0; v < n; v++) {
            if (!used[v])
                return false;
        }
        return true;
    }

    output fast() {
        int res = 0;
        int mask = 0;
        used.resize(n);
        for (int j = 30; j >= 0; j--) {
            if (check(mask | (1 << j))) {
                mask |= 1 << j;
            } else {
                res |= 1 << j;
            }
        }
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