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
    ll res;

    output() = default;

    void print() {
        cout << res << "\n";
    }

    bool operator == (const output& o) const {
        return res == o.res;
    }
};

struct DP {
    vector<vector<ll>> dp;
    const int MAXK = 20;
    const int MAXN = 1e5 + 5;

    vector<vector<int>> vals;
//    unordered_map<int, int> pos;

    vector<int> phi, mu;
    vector<ll> P;
    vector<vector<ll>> suff;

    DP() {
        mu.assign(MAXN, 0);
        phi.assign(MAXN, 0);

        mu[1] = 1;
        for (int x = 1; x < MAXN; x++) {
            for (int y = 2 * x; y < MAXN; y += x)
                mu[y] -= mu[x];
        }
        for (int d = 1; d < MAXN; d++) {
            for (int n = d; n < MAXN; n += d) {
                phi[n] += d * mu[n / d];
            }
        }

        P.assign(MAXN, 0);
        for (int n = 1; n < MAXN; n++)
            P[n] = P[n - 1] + phi[n];

        vals.resize(MAXN);
        for (int r = 1; r < MAXN; r++) {
            for (int g = r; g >= 1;) {
                vals[r].push_back(r / g);
                g = r / ((r / g) + 1);
            }
            reverse(vals[r].begin(), vals[r].end());
            for (int i = 0; i < (int) vals[r].size(); i++) {
                int v = vals[r][i];
//                pos[1ll * r * MAXN + v] = i;
            }
        }

        suff.resize(MAXN);
        for (int r = 1; r < MAXN; r++) {
            suff[r].resize(vals[r].size());
            int g1 = r / vals[r].back();
            for (int it = (int) vals[r].size() - 1; it >= 0; it--) {
                if (it + 1 < (int) vals[r].size())
                    suff[r][it] = suff[r][it + 1];
                int g2 = it > 0 ? r / vals[r][it - 1] : 0;
                suff[r][it] += 1ll * P[vals[r][it]] * (g1 - g2);
                g1 = g2;
            }
        }

        dp.assign(MAXK, vector<ll>(MAXN, inf64));
        for (int i = 1; i < MAXN; i++) {
            dp[1][i] = get(1, i);
        }
        for (int k = 2; k < MAXK; k++) {
            rec(k, 1, MAXN - 1, 1, MAXN - 1);
        }
    }

    ll get(int l, int r) {
        ll res = 0;

//        int i = pos[1ll * r * MAXN + (r / l)];
        int i;

        {
            int bl = 0, br = (int) vals[r].size(), bm;
            int x = r / l;
            while (br - bl > 1) {
                bm = (bl + br) >> 1;
                if (vals[r][bm] >= x)
                    bl = bm;
                else br = bm;
            }
            i = bl;
        }

        if (i + 1 < (int) suff[r].size())
            res += suff[r][i + 1];

        int v = vals[r][i];
        res += 1ll * ((r / v) - l + 1) * P[v];

//        ll res2 = 0;
//        for (int it = 0; it < (int) vals[r].size(); it++) {
//            int v = vals[r][it];
//            int g1 = r / v;
//            int g2 = it > 0 ? r / vals[r][it - 1] : 0;
//            // (g2, g1]
//            int lg = g2 + 1;
//            int rg = g1;
//            lg = max(lg, l);
//            rg = min(rg, r);
//            if (lg <= rg) {
//                res2 += 1ll * (rg - lg + 1) * P[v];
//            }
//        }
//        assert(res == res2);

//        for (int i = l; i <= r; i++) {
//            for (int j = i; j <= r; j++) {
//                int g = __gcd(i, j);
//                if (g >= l)
//                    res++;
//            }
//        }
        return res;
    }

    void rec(int k, int l, int r, int L, int R) {
        if (l > r || L > R)
            return;
        int m = (l + r) >> 1;
        int opt = L;
        ll cost = get(L, m);
        dp[k][m] = dp[k - 1][L - 1] + cost;
        for (int i = L + 1; i <= R && i <= m; i++) {
            cost -= P[m / (i - 1)];
            if (ll tmp = dp[k - 1][i - 1] + cost; dp[k][m] > tmp) {
                dp[k][m] = tmp;
                opt = i;
            }
        }
        rec(k, l, m - 1, L, min(opt, R));
        rec(k, m + 1, r, max(L, opt), R);
    }
} dp_;

struct input {
    int n, k;

    input() = default;

    void read() {
        cin >> n >> k;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    output fast(const DP& dp) {
        if (k >= dp.MAXK)
            return output{n};
        return output{dp.dp[k][n]};
    }

    output slow() {
        return output();
    }
};

void test_case() {
    input in;
    in.read();
    output res = in.fast(dp_);
    res.print();
}

void work() {
    int t;
    cin >> t;
    while (t--)
        test_case();
}

void test() {
    while (1) {
        input in;
        in.gen();
        output fs = in.fast(dp_);
        output sl = in.slow();
        if (fs == sl) {
            cout << "OK" << endl;
            fs.print();
            cout << "\n=========" << endl;
        } else {
            cout << "WA\n";
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