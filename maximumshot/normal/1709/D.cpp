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
    vector<vector<pii>> rmq;

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


struct output {
    vector<int> res;

    void print() {
        for (auto x : res) {
            cout << (x ? "YES" : "NO") << "\n";
        }
    }

    bool operator == (const output& o) const {
        throw;
    }
};

struct input {
    int n, m;
    vector<int> a;
    int q;
    vector<tuple<int, int, int, int, int>> qs;

    input() = default;

    void read() {
        cin >> n >> m;
        a.resize(m);
        for (auto& x : a)
            cin >> x;
        cin >> q;
        qs.resize(q);
        for (auto& [xs, ys, xf, yf, k] : qs) {
            cin >> xs >> ys >> xf >> yf >> k;
            ys--, yf--;
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
        vector<int> res;
        vector<int> b = a;
        for (auto& x : b) x = -x;
        RMQ rmq(b);
        for (auto [xs, ys, xf, yf, k] : qs) {
            if (xs % k != xf % k || ys % k != yf % k) {
                res.push_back(0);
                continue;
            }
            // xs + k * t <= n
            int t = (n - xs) / k;
            xs += k * t;
            int mx = -rmq.get_min(min(ys, yf), max(ys, yf)).first;
            if (xs > mx) res.push_back(1);
            else res.push_back(0);
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