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
        return res == o.res;
    }
};

struct RangeTree {
    int n = 0; // [0, n)
    vector<int> t;

    RangeTree() = default;

    RangeTree(vector<int> ar) {
        n = (int) ar.size();
        t.resize(2 * n, 1);
        for (int i = 0; i < n; i++)
            t[i + n] = ar[i];
        for (int i = n - 1; i > 0; i--)
            t[i] = t[i << 1] & t[i << 1 | 1];
    }

    int get(int l, int r) {
        int res = 1;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res &= t[l++];
            if (r & 1) res &= t[--r];
        }
        return res;
    }
};

struct input {
    int n, m;
    vector<int> a, b;
    vector<vector<int>> g;

    input() = default;

    void read() {
        cin >> n >> m;
        a.resize(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        g.resize(m);
        for (int i = 0; i < m; i++) {
            int sz;
            cin >> sz;
            g[i].resize(sz);
            for (int j = 0; j < sz; j++) {
                int x;
                cin >> x;
                g[i][j] = (int) b.size();
                b.push_back(x);
            }
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
        vector<int> ts(n);
        iota(ts.begin(), ts.end(), 0);
        sort(ts.begin(), ts.end(), [&](int i, int j) {
            return a[i] > a[j];
        });
        ts.resize(m);
        reverse(ts.begin(), ts.end());
        vector<int> lb(m);
        for (int i = 0; i < m; i++) {
            ll S = 0;
            int sz = (int) g[i].size();
            for (int j : g[i])
                S += b[j];
            S = (S + sz - 1) / sz;
            lb[i] = S;
        }
        vector<int> gs(m);
        iota(gs.begin(), gs.end(), 0);
        sort(gs.begin(), gs.end(), [&](int i, int j) {
            return lb[i] < lb[j];
        });
        vector<int> LB(m);
        for (int i = 0; i < m; i++)
            LB[i] = lb[gs[i]];
        vector<int> pr(m, 1), sf(m, 1);
        for (int it = 0; it < m; it++) {
            if (it > 0) pr[it] = pr[it - 1];
            pr[it] &= a[ts[it]] >= lb[gs[it]];
        }
        for (int it = m - 1; it >= 0; it--) {
            if (it + 1 < m) sf[it] = sf[it + 1];
            sf[it] &= a[ts[it]] >= lb[gs[it]];
        }
        vector<int> ld(m, 1), rd(m, 1);
        for (int it = 1; it < m; it++)
            ld[it] = (a[ts[it]] >= lb[gs[it - 1]]);
        for (int it = m - 2; it >= 0; it--)
            rd[it] = (a[ts[it]] >= lb[gs[it + 1]]);
        for (int i = 0; i < m; i++) {
            sort(g[i].begin(), g[i].end(), [&](int x, int y) {
                return b[x] < b[y];
            });
        }
        vector<int> res(b.size(), -1);
        RangeTree le(ld), ri(rd);
        for (int it = 0; it < m; it++) {
            int bl = -1, br = (int) g[gs[it]].size() - 1, bm;
            int sz = (int) g[gs[it]].size();
            ll S = 0;
            for (int j : g[gs[it]])
                S += b[j];
            auto check = [&](int id) -> int {
                ll nS = S - b[g[gs[it]][id]];
                int nsz = sz - 1;
                int nlb = (nS + nsz - 1) / nsz;
                int pos = lower_bound(LB.begin(), LB.end(), nlb) - LB.begin();
                int ok = 1;
                if (pos <= it) {
                    if (pos > 0) ok &= pr[pos - 1];
                    if (it + 1 < m) ok &= sf[it + 1];
                    if (pos + 1 <= it)
                        ok &= le.get(pos + 1, it);
//                    for (int q = pos + 1; q <= it; q++)
//                        ok &= ld[q];
                    ok &= a[ts[pos]] >= nlb;
                } else {
                    if (pos + 1 < m) ok &= sf[pos + 1];
                    if (it > 0) ok &= pr[it - 1];
//                    for (int q = it; q < pos - 1; q++)
//                        ok &= rd[q];
                    if (it <= pos - 2)
                        ok &= ri.get(it, pos - 2);
                    ok &= a[ts[pos - 1]] >= nlb;
                }
                return ok;
            };
            while (br - bl > 1) {
                bm = bl + (br - bl) / 2;
                if (check(bm)) br = bm;
                else bl = bm;
            }
            if (!check(br)) br++;
            for (int j = 0; j < (int) g[gs[it]].size(); j++) {
                if (j < br) res[g[gs[it]][j]] = 0;
                else res[g[gs[it]][j]] = 1;
            }
        }
        return output{res};
    }

    output slow() {
        return output();
    }
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