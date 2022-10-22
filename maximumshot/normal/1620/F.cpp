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
    int can = 0;
    vector<int> res;

    void print() {
        if (can) {
            cout << "YES\n";
            for (auto x : res)
                cout << x << " ";
            cout << "\n";
        } else {
            cout << "NO\n";
        }
    }

    bool operator == (const output& o) const {
        return can == o.can;
    }
};

struct input {
    int n;
    vector<int> p;

    input() = default;

    void read() {
        cin >> n;
        p.resize(n);
        for (auto& x : p)
            cin >> x;
    }

    void print() {
        cout << n << "\n";
        for (auto x : p)
            cout << x << " ";
        cout << "\n";
    }

    void gen() {
        static mt19937 rnd(42);
        const int MAXN = 15;
        n = rnd() % MAXN + 1;
        p.resize(n);
        iota(p.begin(), p.end(), 1);
        shuffle(p.begin(), p.end(), rnd);
    }

    bool check(vector<int> ar) {
        int n = (int) ar.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (ar[i] > ar[j] && ar[j] > ar[k])
                        return false;
                }
            }
        }
        return true;
    }

    output fast() {
        vector<vector<pii>> dp(n, vector<pii>(2, make_pair(inf, inf)));
        vector<vector<int>> from(n, vector<int>(2, -1));
        dp[0][0] = {p[0], -inf};
        dp[0][1] = {-p[0], -inf};
        for (int i = 1; i < n; i++) {
            for (int x = 0; x < 2; x++) {
                for (int y = 0; y < 2; y++) {
                    int was = p[i - 1] * (x == 0 ? +1 : -1);
                    int now = p[i] * (y == 0 ? +1 : -1);

                    if (now < dp[i - 1][x].second)
                        continue;

                    int now_mx = max(dp[i - 1][x].first, now);
                    int now_lb = dp[i - 1][x].second;
                    if (now < dp[i - 1][x].first)
                        now_lb = max(now_lb, now);

                    pii tmp = make_pair(now_mx, now_lb);

                    if (tmp < dp[i][y]) {
                        dp[i][y] = tmp;
                        from[i][y] = x;
                    }
                }
            }
        }
        int x = dp[n - 1][0] < dp[n - 1][1] ? 0 : 1;
        if (dp[n - 1][x].first == inf) return output{0, {}};
        vector<int> res(n);
        for (int i = n - 1; i >= 0; i--) {
            res[i] = x == 0 ? p[i] : -p[i];
            x = from[i][x];
        }
        return output{1, res};
    }

    output slow() {
        for (int mask = 0; mask < (1 << n); mask++) {
            vector<int> res = p;
            for (int i = 0; i < n; i++) {
                if ((1 << i) & mask)
                    res[i] = -res[i];
            }
            if (check(res))
                return output{1, res};
        }
        return output{0, {}};
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

        in.print();
        cout.flush();

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

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();
//    test();

    return 0;
}