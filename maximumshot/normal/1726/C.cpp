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

struct DSU {
    int n = 0; // [0, n)
    vector<int> p;

    DSU() = default;

    DSU(int nn) {
        n = nn;
        p.resize(n);
        iota(p.begin(), p.end(), 0);
    }

    int find(int x) {
        return x == p[x] ? x : p[x] = find(p[x]);
    }

    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        p[y] = x;
    }

    int get_n_comps() {
        int res = 0;
        for (int i = 0; i < n; i++)
            res += i == find(i);
        return res;
    }
};

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


struct input {
    int n;
    string s;

    input() = default;

    void read() {
        cin >> n >> s;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        DSU dsu(2 * n);
        vector<int> b(2 * n);
        for (int i = 0; i < 2 * n; i++) {
            if (i) b[i] = b[i - 1];
            if (s[i] == '(') b[i]++;
            else b[i]--;
        }
        RMQ rmq(b);
        queue<pii> q;
        q.push({0, 2 * n - 1});
        while (!q.empty()) {
            auto [l, r] = q.front();
            q.pop();
            if (l > r) continue;
            for (int i = l; i <= r;) {
                int j = rmq.get_min(i, r).second;
                dsu.merge(l, j);
                dsu.merge(i, j);
                q.push({i + 1, j - 1});
                i = j + 1;
            }
        }
        int res = dsu.get_n_comps();
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