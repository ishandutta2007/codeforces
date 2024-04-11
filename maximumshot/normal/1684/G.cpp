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
    vector<pii> p;

    void print() {
        if (can) {
            cout << (int) p.size() << "\n";
            for (auto [x, y] : p)
                cout << x << " " << y << "\n";
        } else {
            cout << "-1\n";
        }
    }

    bool operator == (const output& o) const {
        throw;
    }
};

struct input {
    int n, m;
    vector<int> t;

    input() = default;

    void read() {
        cin >> n >> m;
        t.resize(n);
        for (auto& x : t)
            cin >> x;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        vector<int> ls, rs;
        for (auto x : t) {
            if (x > m / 3) ls.push_back(x);
            else rs.push_back(x);
        }
        int L = (int) ls.size();
        int R = (int) rs.size();
        if (L > R) return output{0, {}};
        if (L == 0) {
            vector<pii> res;
            for (auto x : t)
                res.emplace_back(3 * x, 2 * x);
            return output{1, res};
        }
        vector<vector<int>> g(L);
        for (int i = 0; i < L; i++) {
            for (int j = 0; j < R; j++) {
                int x = ls[i];
                int y = rs[j];
                if (x % y == 0 && 2 * x + y <= m)
                    g[i].push_back(j);
            }
        }
        mt19937 gen(42);
        for (int i = 0; i < L; i++)
            shuffle(g[i].begin(), g[i].end(), gen);
        vector<int> used(L), mt(R, -1), pair(L, -1);
        int timer = 10;
        function<int(int)> dfs = [&](int v) -> int {
            if (used[v] == timer) return 0;
            used[v] = timer;
            for (int to : g[v]) {
                if (mt[to] == -1 || dfs(mt[to])) {
                    pair[v] = to;
                    mt[to] = v;
                    return 1;
                }
            }
            return 0;
        };
        for (int run = 1; run;) {
            run = 0;
            timer++;
            for (int v = 0; v < L; v++) {
                if (pair[v] == -1 && used[v] != timer && dfs(v))
                    run = 1;
            }
        }
        vector<pii> res;
        for (int i = 0; i < L; i++) {
            int j = pair[i];
            if (j == -1) return output{0, {}};
            int x = ls[i];
            int y = rs[j];
            res.emplace_back(2 * x + y, x + y);
        }
        for (int j = 0; j < R; j++) {
            if (mt[j] == -1) {
                int x = rs[j];
                res.emplace_back(3 * x, 2 * x);
            }
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