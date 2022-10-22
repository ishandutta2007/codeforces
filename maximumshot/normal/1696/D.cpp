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
    int res;

    void print() {
        cout << res << "\n";
    }

    bool operator == (const output& o) const {
        throw;
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
            cin >> x, x--;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        vector<int> d(n, inf);
        d[0] = 0;
        queue<int> q;
        q.push(0);
        RMQ mn(p);
        for (auto& x : p) x = -x;
        RMQ mx(p);
        for (auto& x : p) x = -x;
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            vector<int> tos;
            { // p[i] == mn
                int bl = i, br = n, bm;
                while (br - bl > 1) {
                    bm = bl + (br - bl) / 2;
                    if (mn.get_min(i, bm).second == i) bl = bm;
                    else br = bm;
                }
                int j = mx.get_min(i, bl).second;
                tos.emplace_back(j);
            }
            { // p[i] == mx
                int bl = i, br = n, bm;
                while (br - bl > 1) {
                    bm = bl + (br - bl) / 2;
                    if (mx.get_min(i, bm).second == i) bl = bm;
                    else br = bm;
                }
                int j = mn.get_min(i, bl).second;
                tos.emplace_back(j);
            }
            for (int j : tos) {
                if (d[j] > d[i] + 1) {
                    d[j] = d[i] + 1;
                    q.push(j);
                }
            }
        }
        int res = d[n - 1];
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