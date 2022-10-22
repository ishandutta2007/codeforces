#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ui = unsigned int;
using ull = unsigned long long;
using ld =  double;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

const int inf = 1e9;
const ll inf64 = 1e18;

const ld eps = 1e-9;

struct output {
    ld res;

    void print() {
        cout.precision(20);
        cout << fixed;
        cout << res << "\n";
    }

    bool operator == (const output& o) const {
        return abs(res - o.res) < eps;
    }
};

struct input {
    int n, a, b;
    vector<ld> p, u, pu;
    vector<vector<pair<ld, int>>> dp;

    input() = default;

    void read() {
        cin >> n >> a >> b;
        p.resize(n);
        u.resize(n);
        for (int i = 0; i < n; i++)
            cin >> p[i];
        for (int i = 0; i < n; i++)
            cin >> u[i];
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    pair<ld, int> calc(ld lambda) {
        pair<ld, int> tmp;
        for (int j = 0; j <= a; j++)
            dp[0][j] = {-inf64, -inf};
        dp[0][0] = {0, 0};
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= a; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j > 0) {
                    dp[i][j] = max(dp[i][j], dp[i][j - 1]);

                    tmp = {
                        dp[i - 1][j - 1].first + p[i - 1],
                        dp[i - 1][j - 1].second
                    };
                    dp[i][j] = max(dp[i][j], tmp);

                    tmp = {
                        dp[i - 1][j - 1].first + p[i - 1] + u[i - 1] - pu[i - 1] - lambda,
                        dp[i - 1][j - 1].second + 1
                    };
                    dp[i][j] = max(dp[i][j], tmp);
                }
                tmp = {
                    dp[i - 1][j].first + u[i - 1] - lambda,
                    dp[i - 1][j].second + 1
                };
                dp[i][j] = max(dp[i][j], tmp);
            }
        }
        return dp[n][a];
    }

    output fast() {
        if (b == 0) {
            sort(p.rbegin(), p.rend());
            ld res = 0;
            for (int i = 0; i < a; i++)
                res += p[i];
            return output{res};
        }
        pu.resize(n);
        for (int i = 0; i < n; i++)
            pu[i] = p[i] * u[i];
        dp.resize(n + 1, vector<pair<ld, int>>(a + 1, make_pair(-1e18, -inf)));
        const int MAX_ITER = 30;
        ld bl = 0, br = 2, bm;
        for (int iter = 0; iter < MAX_ITER; iter++) {
            bm = (bl + br) * 0.5;
            pair<ld, int> tmp = calc(bm);
            if (tmp.second >= b) bl = bm;
            else br = bm;
        }
        ld lambda = (bl + br) * 0.5;
        pair<ld, int> tmp = calc(lambda);
        ld res = tmp.first + b * lambda;
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