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
    vector<int> a; // [0, n)
    int n, LOG;
    vector<int> _log;
    vector<vector<int>> rmq;

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
        rmq.resize(LOG, vector<int>(n));
        for (int i = 0; i < n; i++) {
            rmq[0][i] = a[i];
        }
        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                rmq[j][i] = max(rmq[j - 1][i], rmq[j - 1][i + (1 << (j - 1))]);
            }
        }
    }

    int get_max(int l, int r) const {
        int lg = _log[r - l + 1];
        return max(rmq[lg][l], rmq[lg][r - (1 << lg) + 1]);
    }
};


struct output {
    ll res;

    void print() {
        cout << res << "\n";
    }

    bool operator == (const output& o) const {
        return res == o.res;
    }
};

struct input {
    int n;
    vector<ll> a;

    input() = default;

    void read() {
        cin >> n;
        a.resize(n);
        for (auto& x : a)
            cin >> x;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        const ll MAXK = 2e6 + 123;
        vector<int> d(n - 1);
        for (int i = 0; i + 1 < n; i++)
            d[i] = a[i + 1] - a[i];
        ll res = inf64;
        RMQ rmq(d);
        for (ll k = 1; k <= MAXK; k++) {
            ll cur = k;
            ll ql = 0, qr = inf64;
            for (int i = 0; i < n; i++) {
                // [cur^2 - a[i], cur^2 + cur]
                ql = max(ql, cur * cur - a[i]);
                qr = min(qr, cur * cur + cur - a[i]);
                ll R = cur * cur + cur;
                if (i + 1 == n) break;
                if (d[i] <= cur) {
//                    while (i + 1 < n - 1 && d[i + 1] <= cur) i++;
                    int bl = i, br = n - 1, bm;
                    while (br - bl > 1) {
                        bm = (bl + br) >> 1;
                        if (rmq.get_max(i, bm) <= cur) bl = bm;
                        else br = bm;
                    }
                    i = bl;
                    continue;
                }
                if (ql > qr) break;
                {
                    ll bl = cur, br = cur + ll(3e6), bm;
                    while (br - bl > 1) {
                        bm = (bl + br) >> 1;
                        if (R + d[i] > bm * bm) bl = bm;
                        else br = bm;
                    }
                    cur = bl;
                }
                while (R + d[i] >= (cur + 1) * (cur + 1)) cur++;
            }
            if (ql <= qr)
                res = min(res, ql);
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
    int t = 1;
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