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

struct RMQ {
    vector<ll> a; // [0, n)
    int n, LOG;
    vector<int> _log;
    vector<vector<pair<ll, int>>> rmq;

    RMQ(const vector<ll>& aa) {
        a = aa;
        n = (int) a.size();
        LOG = 0;
        while ((1 << LOG) <= n) LOG++;
        _log.resize(n + 1);
        for (int i = 2; i <= n; i++) {
            _log[i] = _log[i - 1] + 1;
            if ((1 << _log[i]) > i) _log[i]--;
        }
        rmq.resize(LOG, vector<pair<ll, int>>(n));
        for (int i = 0; i < n; i++) {
            rmq[0][i] = {a[i], i};
        }
        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                rmq[j][i] = min(rmq[j - 1][i], rmq[j - 1][i + (1 << (j - 1))]);
            }
        }
    }

    int get_min(int l, int r) const {
        int lg = _log[r - l + 1];
        return min(rmq[lg][l], rmq[lg][r - (1 << lg) + 1]).second;
    }
};

struct output {
    int res;

    void print() {
        cout << (res ? "YES" : "NO") << "\n";
    }

    bool operator == (const output& o) const {
        return res == o.res;
    }
};

struct input {
    int n, k;
    vector<int> a;

    input() = default;

    void read() {
        cin >> n >> k;
        k--;
        a.resize(n);
        for (auto& x : a) cin >> x;
    }

    void print() {
        cout << n << " " << k + 1 << "\n";
        for (auto x : a)
            cout << x << " ";
        cout << "\n";
    }

    void gen() {
        static mt19937 rnd(42);
        const int MAXN = 10;
        const int MAXX = 10;
        n = rnd() % MAXN + 1;
        k = rnd() % n;
        a.resize(n);
        for (int i = 0; i < n; i++) {
            if (i == k) {
                a[i] = rnd() % MAXX;
            } else {
                a[i] = int(rnd() % (2 * MAXX + 1)) - MAXX;
            }
        }
    }

    void gen_max_test() {

    }

    output fast() {
        int l = k, r = k;

        vector<ll> pref(n), pref_max(n), suff_min(n);
        for (int i = 0; i < n; i++)
            pref[i] = (i ? pref[i - 1] : 0) + a[i];
        pref_max = pref;
        for (int i = 1; i < n; i++)
            pref_max[i] = max(pref_max[i - 1], pref_max[i]);
        suff_min = pref;
        for (int i = n - 2; i >= 0; i--)
            suff_min[i] = min(suff_min[i + 1], suff_min[i]);

        vector<ll> pref_ar = pref;
        for (auto& x : pref_ar) x = -x;
        RMQ pref_max_rmq(pref_ar);
        RMQ pref_min_rmq(pref);

        while (0 <= l && r < n) {
            ll cur = pref[r] - (l > 0 ? pref[l - 1] : 0);
            assert(cur >= 0);
            if (l == 0 || r == n - 1) return output{1};

            int ql = l, qr = r;
            int bl, br, bm;

            bl = 0, br = l;
            while (br - bl > 1) {
                bm = bl + (br - bl) / 2;
                // bm <= j <= l
                // cur + pref[l - 1] - pref[j - 1] >= 0
                // cur + pref[l - 1] >= pref[j - 1]
                assert(bm < l);
                assert(0 < bm);
                int tmp = pref_max_rmq.get_min(bm - 1, l - 1);
                if (pref[tmp] <= cur + pref[l - 1]) br = bm;
                else bl = bm;
            }
            ql = br;

            bl = r, br = n - 1;
            while (br - bl > 1) {
                bm = bl + (br - bl) / 2;
                // r <= j <= bm
                // cur + pref[j] - pref[r] >= 0
                // pref[j] >= pref[r] - cur
                if (pref[pref_min_rmq.get_min(r, bm)] >= pref[r] - cur) bl = bm;
                else br = bm;
            }
            qr = bl;
            if (ql == 1 && cur + pref[l - 1] >= 0) return output{1};
            if (qr == n - 2 && cur + pref[n - 1] - pref[r] >= 0) return {1};
            if (ql == l && qr == r) return output{0};
            int tol = -1, tor = -1;
            ll xl = -inf64, xr = -inf64;
            if (ql < l) {
                // ql <= j < l
                // pref[l - 1] - pref[j - 1] -> max
                // pref[j - 1] -> min
                tol = pref_min_rmq.get_min(ql - 1, l - 2) + 1;
                xl = pref[l - 1] - pref[tol - 1];
            }
            if (r < qr) {
                // r < j <= qr
                // pref[j] - pref[r] -> max
                // pref[j] -> max
                tor = pref_max_rmq.get_min(r + 1, qr);
                xr = pref[tor] - pref[r];
            }
            if (xl < xr) {
                assert(tor > r);
                r = tor;
            } else {
                assert(tol < l);
                l = tol;
            }
        }
        return output{0};
    }

#ifdef DEBUG
    output slow() {
        vector<vector<ll>> s(n, vector<ll>(n));
        for (int l = 0; l < n; l++) {
            ll cur = 0;
            for (int r = l; r < n; r++) {
                cur += a[r];
                s[l][r] = cur;
            }
        }
        vector<vector<int>> can(n, vector<int>(n));
        can[k][k] = 1;
        queue<pii> q;
        q.push({k, k});
        while (!q.empty()) {
            auto [l, r] = q.front();
            q.pop();
            if (l > 0 && s[l - 1][r] >= 0 && !can[l - 1][r]) {
                can[l - 1][r] = 1;
                q.push({l - 1, r});
            }
            if (r + 1 < n && s[l][r + 1] >= 0 && ! can[l][r + 1]) {
                can[l][r + 1] = 1;
                q.push({l, r + 1});
            }
        }
        for (int i = 0; i < n; i++) {
            if (can[0][i] || can[i][n - 1])
                return output{1};
        }
        return output{0};
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
//#ifdef DEBUG
    cin >> t;
//#endif
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