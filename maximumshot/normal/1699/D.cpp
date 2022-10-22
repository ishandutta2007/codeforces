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
    vector<int> a;

    input() = default;

    void read() {
        cin >> n;
        a.resize(n);
        for (auto& x : a)
            cin >> x, x--;
    }

    void print() {
        cout << n << "\n";
        for (auto x : a)
            cout << x + 1 << " ";
        cout << "\n";
    }

    void gen() {
        static mt19937 rnd(42);
        const int MAXN = 10;
        n = rnd() % MAXN + 1;
        a.resize(n);
        for (auto& x : a)
            x = rnd() % n;
    }

    void gen_max_test() {

    }

    output fast() {
        vector<vector<int>> f(n, vector<int>(n));
        for (int l = 0; l < n; l++) {
            vector<int> cn(n);
            int mx = 0;
            for (int r = l; r < n; r++) {
                int x = a[r];
                cn[x]++;
                mx = max(mx, cn[x]);
                int total = r - l + 1;
                int rem = mx <= total - mx ? total % 2 : mx - (total - mx);
                f[l][r] = rem == 0;
            }
        }
        vector<int> dp(n, -inf);
        for (int i = 0; i < n; i++) {
            if (i == 0 || f[0][i - 1]) dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (a[i] == a[j] && (j + 1 > i - 1 || f[j + 1][i - 1]))
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (i + 1 == n || f[i + 1][n - 1])
                res = max(res, dp[i]);
        }
        return output{res};
    }

#ifdef DEBUG
    output slow() {
        vector<int> dp(1 << n);
        for (int mask = 1; mask < (1 << n); mask++) {
            int last_i = -1, any = 0;
            for (int i = 0; i < n; i++) {
                if ((1 << i) & mask) {
                    if (last_i != -1 && a[last_i] != a[i]) {
                        any = 1;
                        dp[mask] = max(dp[mask], dp[mask ^ (1 << last_i) ^ (1 << i)]);
                    }
                    last_i = i;
                }
            }
            if (!any) dp[mask] = __builtin_popcount(mask);
        }
        int res = dp[(1 << n) - 1];
        return output{res};
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