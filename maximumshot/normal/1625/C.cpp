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
    int n, l, k;
    vector<int> d, a;

    input() = default;

    void read() {
        cin >> n >> l >> k;
        d.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> d[i];
        }
        a.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
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
        const int X = 1e9 + 10;
        d.push_back(l);
        n++;
        k = n - k;
        vector<vector<int>> dp(n, vector<int>(n + 1, X));
        dp[0][1] = 0;
        for (int i = 1; i < n; i++) {
            for (int c = 1; c <= n; c++) {
                for (int j = i - 1; j >= 0; j--) {
                    dp[i][c] = min(dp[i][c], dp[j][c - 1] + (d[i] - d[j]) * a[j]);
                }
            }
        }
        int res = X;
        for (int c = k; c <= n; c++)
            res = min(res, dp[n - 1][c]);
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
    int t = 1;
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