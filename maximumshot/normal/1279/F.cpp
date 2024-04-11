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
    int n, k, l;
    string s;
    vector<ll> pref;
    vector<pair<ll, int>> dp, pr;

    input() = default;

    void read() {
        cin >> n >> k >> l >> s;
    }

    void print() {
        cout << n << " " << k << " " << l << "\n" << s << "\n";
    }

    void gen() {
        static mt19937 rnd(42);
        const int MAXN = 100;
        n = rnd() % MAXN + 1;
        k = rnd() % 5 + 1;
        l = rnd() % 10 + 1;
        s.resize(n, '?');
        for (char& c : s)
            c = rnd() % 2 ? 'a' : 'A';
    }

    void gen_max_test() {

    }

    pair<ll, int> calc(vector<int> a, int lambda) {
        dp.assign(n + 1, make_pair(-inf64, -inf));
        pr.assign(n + 1, make_pair(-inf64, -inf));
        pr[0] = {0, 0};
        pair<ll, int> res = {-inf64, -inf};
        for (int i = 1; i <= n; i++) {
            dp[i] = {-inf64, -inf};
            {
                int j = max(1, i - l + 1);
                pair<ll, int> tmp = {
                    pr[j - 1].first + (pref[i] - pref[j - 1]) - lambda,
                    pr[j - 1].second + 1
                };
                dp[i] = max(dp[i], tmp);
            }
            pr[i] = max(pr[i - 1], dp[i]);
            res = max(res, dp[i]);
        }
        return res;
    }

    int calc_fast(vector<int> a) {
        pref.assign(n + 1, 0);
        for (int i = 1; i <= n; i++)
            pref[i] = pref[i - 1] + a[i - 1];
        int bl = 0, br = 1e6 + 10, bm;
        while (br - bl > 1) {
            bm = (bl + br) >> 1;
            pair<ll, int> tmp = calc(a, bm);
            if (tmp.second >= k) bl = bm;
            else br = bm;
        }
        pair<ll, int> tmp = calc(a, bl);
        int res = int(tmp.first + 1ll * bl * k);
        return res;
    }

    output fast() {
        vector<int> a(n);
        int S = 0;
        for (int i = 0; i < n; i++) {
            if ('a' <= s[i] && s[i] <= 'z') a[i] = 0;
            else a[i] = 1;
            S += a[i];
        }
        int res = S - calc_fast(a);
        for (auto& x : a)
            x ^= 1;
        S = n - S;
        res = min(res, S - calc_fast(a));
        return output{res};
    }

    int calc_slow(vector<int> a) {
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -inf));
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            dp[i][0] = dp[i - 1][0];
            for (int c = 1; c <= k; c++) {
                dp[i][c] = max(dp[i - 1][c], dp[i][c - 1]);
                int sm = 0;
                for (int j = i; j > 0 && i - j + 1 <= l; j--) {
                    sm += a[j - 1];
                    dp[i][c] = max(dp[i][c], dp[j - 1][c - 1] + sm);
                }
            }
        }
        int res = dp[n][k];
        return res;
    }

    output slow() {
#ifndef DEBUG
        throw;
#endif
        vector<int> a(n);
        int S = 0;
        for (int i = 0; i < n; i++) {
            if ('a' <= s[i] && s[i] <= 'z') a[i] = 0;
            else a[i] = 1;
            S += a[i];
        }
        int res = S - calc_slow(a);
        for (auto& x : a)
            x ^= 1;
        S = n - S;
        res = min(res, S - calc_slow(a));
        return output{res};
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