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

const string ALICE = "Alice";
const string BOB = "Bob";

struct output {
    string res;

    void print() {
        cout << res << "\n";
    }

    bool operator == (const output& o) const {
        return res == o.res;
    }
};

int mex(vector<int> a) {
    if (a.empty()) return 0;
    sort(a.begin(), a.end());
    if (a.front() > 0) return 0;
    for (int i = 0; i + 1 < (int) a.size(); i++) {
        if (a[i] + 1 < a[i + 1])
            return a[i] + 1;
    }
    return a.back() + 1;
}

struct input {
    int n;
    string s;

    input() = default;

    void read() {
        cin >> n >> s;
    }

    void print() {
        cout << n << " " << s << "\n";
    }

    void gen() {
        static mt19937 rnd(42);
        const int MAXN = 10;
        n = rnd() % MAXN + 2;
        s.assign(n, '?');
        for (char& c : s)
            c = rnd() % 2 ? 'R' : 'B';
    }

    void gen_max_test() {

    }

    output fast() {
        int cr = 0, cb = 0;
        for (char c : s) {
            if (c == 'R') cr++;
            else cb++;
        }
        if (cb != cr) return output{cr > cb ? ALICE : BOB};
        string pred = "00112031103322405223301130211045274011203110332244552330113021104537481120311033224455";
        string per = "9330113021104537481120311033224455";
        auto F = [&](int l) -> int {
            // l - k * |per| <= |pred| + |per| - 1
            // k >= (l + 1 - |per| - |pred|) / |per|
            int k = (max(0, l + 1 - (int) per.size() - (int) pred.size()) + (int) per.size() - 1) / (int) per.size();
            l -= k * (int) per.size();
            if (l < (int) pred.size()) return pred[l] - '0';
            else return per[l - (int) pred.size()] - '0';
        };
//        for (int i = 0; i <= n; i++)
//            cout << F(i);
//        cout << "\n";
//        vector<int> f(n + 1);
//        for (int l = 1; l <= n; l++) {
//            vector<int> ar;
//            for (int i = 1; i < l; i++) {
//                ar.emplace_back(f[i - 1] ^ f[l - (i + 1)]);
//            }
//            f[l] = mex(ar);
//        }
//        for (int l = 0; l <= n; l++)
//            cout << f[l], assert(f[l] < 10);
//        cout << "\n";
        int xr = 0;
        for (int i = 0; i < n; i++) {
            int j = i;
            while (j + 1 < n && s[j] != s[j + 1]) j++;
            int len = j - i + 1;
            xr ^= F(len);
            i = j;
        }
        if (xr) return output{ALICE};
        else return output{BOB};
    }

#ifdef DEBUG
    output slow() {
        vector<vector<int>> dp(2, vector<int>(1 << n));
        for (int mask = 0; mask < (1 << n); mask++) {
            for (int t = 0; t < 2; t++) {
                vector<int> ok(n);
                for (int i = 0; i < n; i++) {
                    if ((1 << i) & mask) {
                        if (t == 0 && s[i] == 'R') ok[i] = 1;
                        if (t == 1 && s[i] == 'B') ok[i] = 1;
                    }
                }
                for (int i = 0; i + 1 < n; i++) {
                    if (ok[i] || ok[i + 1]) {
                        int nmask = mask & ~(1 << i) & ~(1 << (i + 1));
                        if (!dp[t ^ 1][nmask]) dp[t][mask] = 1;
                    }
                }
            }
        }
        if (dp[0][(1 << n) - 1]) return output{ALICE};
        else return output{BOB};
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