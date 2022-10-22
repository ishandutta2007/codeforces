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

struct RMQ {
    vector<int> a; // [0, n)
    int n, LOG;
    vector<int> _log;
    vector<vector<pii>> rmq;

    RMQ() = default;

    RMQ(const vector<int>& aa) {
        a = aa;
        n = (int) a.size();
        LOG = 0;
        while ((1 << LOG) <= n) LOG++;
        _log.resize(n + 1);
        for (int i = 2; i <= n; i++) {
            _log[i] = _log[i - 1] + 1;
            if ((1 << _log[i]) > i) _log[i]--;
        }
        rmq.resize(LOG, vector<pii>(n));
        for (int i = 0; i < n; i++) {
            rmq[0][i] = {a[i], i};
        }
        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                rmq[j][i] = min(rmq[j - 1][i], rmq[j - 1][i + (1 << (j - 1))]);
            }
        }
    }

    pii get_min(int l, int r) const {
        int lg = _log[r - l + 1];
        return min(rmq[lg][l], rmq[lg][r - (1 << lg) + 1]);
    }
};


struct input {
    int n, k;
    vector<int> a;

    input() = default;

    void read() {
        cin >> n >> k;
        a.resize(n);
        for (auto& x : a) cin >> x;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        int lx = 1, rx = a[0];
        int res = inf;
        int X = a[n - 1] + 1;
        vector<int> used(X);
        for (int x : a) used[x] = 1;
        RMQ rmq_mn, rmq_mx;
        {
            vector<int> f(X, inf);
            for (int x : a)
                f[x] = x;
            rmq_mn = RMQ(f);
        }
        {
            vector<int> f(X, inf);
            for (int x : a)
                f[x] = -x;
            rmq_mx = RMQ(f);
        }
        vector<int> pref(X);
        for (int x = 0; x < X; x++) {
            pref[x] = (x ? pref[x - 1] : 0) + used[x];
        }
        for (int x = lx; x <= rx; x++) {
            int mn = inf, mx = -inf;
            int max_val = (X - 1) / x;
            for (int val_x = 0, val = 0; val <= max_val; val++, val_x += x) {
                int l = val_x;
                int r = min(X - 1, l + x - 1);
                // [l, r]
                int pi = min(k, val);
                if (pref[r] - (l ? pref[l - 1] : 0) > 0) {
                    int min_ai = rmq_mn.get_min(l, r).first;
                    int max_ai = -rmq_mx.get_min(l, r).first;
                    mn = min(mn, min_ai / pi);
                    mx = max(mx, max_ai / pi);
                }
            }
            res = min(res, mx - mn);
        }
        return output{res};
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