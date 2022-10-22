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
        for (auto x : res)
            cout << (x ? "YES" : "NO") << "\n";
    }

    bool operator == (const output& o) const {
        return res == o.res;
    }
};

vector<int> build_tree(vector<int> a) {
    int n = (int) a.size();
    vector<int> par(n, -1);
    for (auto& x : a) x = -x;
    RMQ rmq(a);
    function<int(int, int)> dfs = [&](int l, int r) -> int {
        if (l >= r) return l;
        int m = rmq.get_min(l, r).second;
        if (l < m) par[dfs(l, m - 1)] = m;
        if (m < r) par[dfs(m + 1, r)] = m;
        return m;
    };
    dfs(0, n - 1);
    return par;
}

struct input {
    int n, q, k;
    vector<int> p, a, s, d;

    input() = default;

    void read() {
        cin >> n >> q;
        p.resize(n);
        for (auto& x : p) cin >> x;
        a.resize(n);
        for (auto& x : a) cin >> x;
        k = 0;
        for (auto x : a) k += x == 0;
        s.resize(k - 1);
        for (auto& x : s) cin >> x;
        d.resize(q);
        for (auto& x : d) cin >> x;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        vector<int> par = build_tree(p);
        vector<vector<int>> g(n);
        int root = -1;
        for (int v = 0; v < n; v++) {
            if (par[v] == -1) root = v;
            else g[par[v]].push_back(v);
        }
        vector<int> L(n), depth(n), R(n, inf);
        function<void(int)> dfs = [&](int v) {
            L[v] = a[v];
            for (int to : g[v]) {
                depth[to] = depth[v] + 1;
                if (a[v]) R[to] = a[v];
                else R[to] = R[v];
                dfs(to);
                L[v] = max(L[v], L[to]);
            }
        };
        dfs(root);
        vector<pii> segs;
        int flg = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == 0) {
                segs.emplace_back(L[i], R[i]);
            }
            if (L[i] > R[i]) flg = 1;
        }
        sort(segs.begin(), segs.end());
//        vector<int> crd;
//        for (auto [l, r] : segs) {
//            crd.push_back(l);
//            crd.push_back(r);
//        }
//        for (auto x : d)
//            crd.push_back(x);
        sort(s.begin(), s.end());
        vector<int> all = s;
        for (auto x : d) all.push_back(x);
        sort(all.begin(), all.end());
        all.erase(unique(all.begin(), all.end()), all.end());
        int sz = (int) all.size();
        vector<int> in_s(sz);
        for (auto x : s) {
            in_s[lower_bound(all.begin(), all.end(), x) - all.begin()] = 1;
        }
        vector<int> can(sz), tl(sz, inf), tr(sz, -inf);
        multiset<int> Q;
        for (int ptr = 0, it = 0; it < sz; it++) {
            int x = all[it];
            while (ptr < (int) segs.size() && segs[ptr].first <= x) {
                Q.insert(segs[ptr].second);
                ptr++;
            }
            if (in_s[it]) {
                if (Q.empty() || *Q.begin() < x) break;
                Q.erase(Q.begin());
            } else {
                if (!Q.empty() && *Q.begin() >= x) {
                    tr[it] = *Q.begin();
                }
            }
        }
        Q.clear();
        for (auto& [l, r] : segs) swap(l, r);
        sort(segs.rbegin(), segs.rend());
        for (auto& [l, r] : segs) swap(l, r);
        for (int ptr = 0, it = sz - 1; it >= 0; it--) {
            int x = all[it];
            while (ptr < (int) segs.size() && segs[ptr].second >= x) {
                Q.insert(segs[ptr].first);
                ptr++;
            }
            if (in_s[it]) {
                if (Q.empty()) break;
                if (*(--Q.end()) > x) break;
                Q.erase(--Q.end());
            } else {
                if (!Q.empty() && *(--Q.end()) <= x) {
                    tl[it] = *(--Q.end());
                }
            }
        }
        for (int i = 0; i < sz; i++)
            can[i] = !in_s[i] && (tl[i] <= all[i] && all[i] <= tr[i]);
        vector<int> res;
        for (auto x : d) {
            if (flg) res.push_back(0);
            else res.push_back(can[lower_bound(all.begin(), all.end(), x) - all.begin()]);
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