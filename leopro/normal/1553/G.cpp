#ifdef LEONID_PROGRAMMER_AKA_LEOPRO
#define _GLIBCXX_DEBUG
#else
#endif

#include <bits/stdc++.h>

namespace {
    using namespace std;
//#define int long long
    using ll = long long;
    using ull = unsigned long long;

    template<typename F, typename S>
    ostream &operator<<(ostream &os, const pair<F, S> &p) {
        os << p.first << (is_integral_v<S> && !is_same_v<S, char> ? " " : "") << p.second;
        return os;
    }

    template<typename F, typename S>
    istream &operator>>(istream &is, pair<F, S> &p) {
        is >> p.first >> p.second;
        return is;
    }

    template<typename T>
    istream &operator>>(istream &is, vector<T> &v) {
        for (T &t : v) is >> t;
        return is;
    }

    template<typename T>
    ostream &operator<<(ostream &os, const vector<T> &v) {
        for (const T &t : v) os << t << (is_integral_v<T> && !is_same_v<T, char> ? " " : "");
        os << "\n";
        return os;
    }

    template<typename T>
    istream &operator>>(istream &is, deque<T> &v) {
        for (T &t : v) is >> t;
        return is;
    }

    template<typename T>
    ostream &operator<<(ostream &os, const deque<T> &v) {
        for (const T &t : v) os << t << (is_integral_v<T> && !is_same_v<T, char> ? " " : "");
        os << "\n";
        return os;
    }

    class exit_exception : exception {
    };

    void answer() {}

    template<typename First, typename... Args>
    void answer(First &&val, Args &&... ans) {
        cout << val << "\n";
        answer(ans...);
        throw exit_exception();
    }

    struct autoint {
        int x;

        explicit autoint(int i) : x(i) {}

        autoint() { cin >> x; }

        operator int() const { return x; }

        int operator--() { return --x; }

        int operator--(signed) { return x--; }

        int operator++() { return ++x; }

        int operator++(signed) { return x++; }
    };
}

void solve();

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t = 1;
//    cin >> t;
    do { try { solve(); } catch (exit_exception &) {}} while (--t);
    return 0;
}

//
//struct segment_tree {
//    int sz;
//    vector<ll> sm;
//
//    explicit segment_tree(int n) : sz(2 << __lg(n)), sm(2 * sz) {}
//
//    void add(int i, int x) {
//        sm[i += sz] += x;
//        for (i /= 2; i > 0; i /= 2) sm[i] = sm[2 * i] + sm[2 * i + 1];
//    }
//
//    ll sum(int l, int r) {
//        if (r > sz) r = sz;
//        ll res = 0;
//        for (l += sz, r += sz; l < r; l /= 2, r /= 2) {
//            if (l & 1) res += sm[l++];
//            if (r & 1) res += sm[--r];
//        }
//        return res;
//    }
//
//    ll operator[](int i) { return sm[i + sz]; }
//};
//
//vector<int> brute(int n, vector<int> a) {
//    vector<int> ans(n);
//    for (int k = 0; k < n; ++k) {
//        for (int i = 0; i <= k; ++i) {
//            for (int j = 0; j <= k; ++j) ans[k] += a[i] % a[j];
//        }
//    }
//    return ans;
//}
//
//vector<int> solve(int n, vector<int> a) {
//    segment_tree cnt(3e5 + 1), values(3e5 + 1);
//    const int small = 1;
//    vector<int> modded(small);
//    ll cur = 0;
//    vector<int> ans;
//    for (int i = 0; i < n; ++i) {
//        if (a[i] < small) {
//            cur += modded[a[i]];
//        } else {
//            int p = a[i];
//            ll sum = values.sum(0, 3e5 + 1);
//            for (int m = p; m <= 3e5; m += p) {
//                int count = cnt.sum(m, m + p);
//                sum -= m * count;
//            }
//            cur += sum;
//            int q = sqrt(p);
//            for (int x = 1; x <= p / (q + 1); ++x) {
//                cur += (p % x) * cnt[x];
//            }
//            cur += cnt.sum(p + 1, cnt.sz) * p;
//            for (int d = 1; d <= q; ++d) {
//                int lb = p / (d + 1) + 1, ub = p / d + 1;
//                cur += p * cnt.sum(lb, ub) - values.sum(lb, ub) * d;
//            }
//        }
//
//
//        ans.push_back(cur);
//        cnt.add(a[i], 1);
//        values.add(a[i], a[i]);
//        for (int x = 1; x < small; ++x) modded[x] += (a[i] % x) + (x % a[i]);
//    }
//    return ans;
//}
struct dsu {
    vector<int> parent, size;

    dsu(int n) : parent(n), size(n, 1) { iota(parent.begin(), parent.end(), 0); }

    int get(int x) {
        if (parent[x] == x) return x;
        return parent[x] = get(parent[x]);
    }

    void unite(int x, int y) {
        if (get(x) == get(y)) return;
        x = get(x);
        y = get(y);

        if (size[x] > size[y]) swap(x, y);
        {
            parent[x] = y;
            size[y] += size[x];
        }
    }
};

void solve() {
    autoint n, q;
    vector<int> a(n);
    cin >> a;
    dsu dsu(n);
    vector<int> b(1e6 + 1, -1);
    for (int i = 0; i < n; ++i) b[a[i]] = i;
    for (int g = 2; g <= 1e6; ++g) {
        int f = -1;
        for (int x = g; x <= 1e6; x += g) {
            if (b[x] != -1 && f != -1) dsu.unite(b[x], f); else if (b[x] != -1) f = b[x];
        }
    }
    vector<vector<int>> c(1e6 + 2);
    for (int i = 2; i <= 1e6; ++i) {
        if (c[i].size()) continue;
        c[i].push_back(i);
        for (int j = 2 * i; j <= 1e6 + 1; j += i) c[j].push_back(i);
    }
    vector<int> primeIn(1e6 + 2, -1);
    for (int i = 0; i < n; ++i) {
        for (auto prime : c[a[i]]) primeIn[prime] = dsu.get(i);
    }
    vector<set<int>> near(n);
    for (int i = 0; i < n; ++i) {
        for (auto prime : c[a[i] + 1]) {
            near[dsu.get(i)].insert(primeIn[prime]);
        }
        for (auto p1 : c[a[i] + 1]) {
            for (auto p2 : c[a[i] + 1]) {
                if (primeIn[p1] != -1) near[primeIn[p1]].insert(primeIn[p2]);
            }
        }
    }
    for (int j = 0; j < q; ++j) {
        int s, t;
        cin >> s >> t;
        --s, --t;
        s = dsu.get(s), t = dsu.get(t);
        if (dsu.get(s) == dsu.get(t)) {
            cout << "0\n";
        } else {
            if (near[s].count(t) || near[t].count(s)) cout << "1\n"; else cout << "2\n";
        }
    }
}