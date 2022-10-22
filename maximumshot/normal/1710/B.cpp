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
    vector<int> res;

    void print() {
        for (auto x : res)
            cout << x;
        cout << "\n";
    }

    bool operator == (const output& o) const {
        throw;
    }
};

using pli = pair<long long, int>;

struct RMQ {
    int n = 0;
    vector<pli> t;

    RMQ(const vector<ll>& aa) {
        n = (int) aa.size();
        t.assign(2 * n, make_pair(-inf64, -1));
        for (int i = 0; i < n; i++)
            t[i + n] = {aa[i], i};
        for (int i = n - 1; i >= 0; i--)
            t[i] = max(t[i << 1], t[i << 1 | 1]);
    }

    pli get_max(int l, int r) const {
        pli res = make_pair(-inf64, -1);
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res = max(res, t[l++]);
            if (r & 1) res = max(res, t[--r]);
        }
        return res;
//        int lg = _log[r - l + 1];
//        return max(rmq[lg][l], rmq[lg][r - (1 << lg) + 1]);
    }
};


struct input {
    int n, m;
    vector<pii> a;

    input() = default;

    void read() {
        cin >> n >> m;
        a.resize(n);
        for (auto& [x, p] : a)
            cin >> x >> p;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        vector<int> xs;
        for (auto [x, p] : a) {
            xs.push_back(x);
            xs.push_back(x - p);
            xs.push_back(x + p);
        }
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
        int sz = (int) xs.size();
        vector<ll> K(sz + 1), B(sz + 1);
        auto add_line = [&](int l, int r, ll kk, ll bb) {
//            cout << "add [" << l << " .. " << r << "] k = " << kk << ", b = " << bb << "\n";
            if (l > r) return;
            K[l] += kk;
            B[l] += bb;

            K[r + 1] -= kk;
            B[r + 1] -= bb;
        };
        for (auto [x, p] : a) {
            int l = lower_bound(xs.begin(), xs.end(), x - p) - xs.begin();
            int r = lower_bound(xs.begin(), xs.end(), x + p) - xs.begin();
            int i = lower_bound(xs.begin(), xs.end(), x) - xs.begin();
            add_line(l, i, 1, p - x);
            add_line(i + 1, r, -1, p + x);
        }
        for (int i = 1; i < sz; i++) {
            K[i] += K[i - 1];
            B[i] += B[i - 1];
        }
        vector<ll> now(sz), need(sz);
        for (int i = 0; i < sz; i++) {
            now[i] = K[i] * xs[i] + B[i];
//            cout << xs[i] << " " << now[i] << "\n";
            need[i] = max(0ll, now[i] - m);
        }
        vector<int> res;
        RMQ rmq1(need);
        vector<ll> le(sz), ri(sz);
        for (int i = 0; i < sz; i++) {
            le[i] = need[i] - xs[i];
            ri[i] = need[i] + xs[i];
        }
        RMQ rmq_le(le), rmq_ri(ri);
        for (auto [x, p] : a) {
            int l = lower_bound(xs.begin(), xs.end(), x - p) - xs.begin();
            int r = lower_bound(xs.begin(), xs.end(), x + p) - xs.begin();
            int i = lower_bound(xs.begin(), xs.end(), x) - xs.begin();
            int ok = 1;
            ok &= rmq_le.get_max(l, i).first <= p - x;
//            for (int j = l; j <= i; j++)
//                ok &= p - x >= need[j] - xs[j];
//            for (int j = i; j <= r; j++)
//                ok &= p + x >= need[j] + xs[j];
            ok &= rmq_ri.get_max(i, r).first <= p + x;
//            for (int j = 0; j < l; j++)
//                ok &= need[j] <= 0;
//            for (int j = r + 1; j < sz; j++)
//                ok &= need[j] <= 0;
            if (0 < l) ok &= rmq1.get_max(0, l - 1).first <= 0;
            if (r + 1 < sz) ok &= rmq1.get_max(r + 1, sz - 1).first <= 0;
            res.push_back(ok);
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