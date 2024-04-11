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
        cout << (res ? "AC" : "WA") << "\n";
    }

    bool operator == (const output& o) const {
        throw;
    }
};

struct input {
    int n;
    vector<int> a, b;

    input() = default;

    void read() {
        cin >> n;
        a.resize(n);
        b.resize(n);
        for (auto& x : a) cin >> x, x--;
        for (auto& x : b) cin >> x, x--;
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
        vector<int> cnt(n);
        for (auto x : a) cnt[x]++;
        for (int i = 0; i < n; i++)
            g[a[i]].push_back(b[i]);
        vector<int> color(n);
        int x = max_element(cnt.begin(), cnt.end()) - cnt.begin();
        int ok = 1;
        function<void(int)> dfs = [&](int v) {
            color[v] = 1;
            for (int to : g[v]) {
                if (to == x)
                    continue;
                if (color[to] == 0) {
                    dfs(to);
                } else if (color[to] == 1) {
                    ok = 0;
                } else if (color[to] == 2) {

                }
            }
            color[v] = 2;
        };
        for (int v = 0; v < n; v++) {
            if (v == x) continue;
            dfs(v);
        }
        return output{ok};
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