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
    vector<tuple<int, int, int>> res;

    void print() {
        if (res.empty()) {
            cout << "-1\n";
        } else {
            cout << (int) res.size() << "\n";
            for (auto [l, r, i] : res) {
                cout << l + 1 << " " << r + 1 << " " << i + 1 << "\n";
            }
        }
    }

    bool operator == (const output& o) const {
        throw;
    }
};

struct input {
    int n, m;
    vector<string> a;

    input() = default;

    void read() {
        cin >> n >> m;
        a.resize(n + 1);
        for (int i = 0; i <= n; i++)
            cin >> a[i];
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        vector<int> dp(m + 1, 0);
        vector<tuple<int, int, int>> fr(m + 1, {-1, -1, -1});
        dp[0] = 1;
        unordered_map<string, tuple<int, int, int>> mem;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int len = 2; len <= 3 && j + len <= m; len++) {
                    mem[a[i].substr(j, len)] = {j, j + len - 1, i};
                }
            }
        }
        for (int i = 1; i <= m; i++) {
            for (int len = 2; len <= 3; len++) {
                if (i - len < 0 || !dp[i - len])
                    continue;
                // (i - len, i]
                auto fnd = mem.find(a[n].substr(i - len, len));
                if (fnd == mem.end())
                    continue;
                dp[i] = 1;
                fr[i] = fnd->second;
            }
        }
        if (!dp[m])
            return output{};
        vector<tuple<int, int, int>> res;
        for (int i = m; i > 0;) {
            auto [l, r, q] = fr[i];
            int len = r - l + 1;
            res.emplace_back(l, r, q);
            i -= len;
        }
        reverse(res.begin(), res.end());
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