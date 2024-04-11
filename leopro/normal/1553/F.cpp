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

struct sqrt_decomposition {
    const int sq = 566;
    vector<ll> prefix;
    vector<vector<ll>> values;

    sqrt_decomposition() : values(sq, vector<ll>(sq + 1)), prefix(sq + 1) {}

    void add(int i, ll x) {
        int b = i / sq;
        for (int j = i - b * sq; j < sq; ++j) values[b][j + 1] += x;
        for (int j = b + 1; j <= sq; ++j) prefix[j] += x;
    }

    ll sum(int l, int r) {
        return get(r) - get(l);
    }

    ll get(int bound) {
        if (bound >= sq * sq) bound = sz;
        int b = bound / sq;
        return prefix[b] + values[b][bound - b * sq];
    }
    int sz = 3e5 + 2;

    int operator[](int i) {
        int b = i / sq;
        int r = i - b * sq;
        return values[b][r + 1] - values[b][r];
    }
};

vector<ll> solve(int n, vector<int> a) {
    sqrt_decomposition cnt, values;
    const int small = 601;
    vector<ll> modded(small);
    ll cur = 0;
    vector<ll> ans;
    for (int i = 0; i < n; ++i) {
        int &p = a[i];
        if (p < small) {
            cur += modded[p];
        } else {
            ll sum = values.sum(0, 3e5 + 1);
            for (int m = p; m <= 3e5; m += p) {
                int count = cnt.sum(m, m + p);
                sum -= m * 1LL * count;
            }
            cur += sum;
            int q = sqrt(p);
            for (int x = 1; x <= p / (q + 1); ++x) {
                cur += (p % x) * 1LL * cnt[x];
            }
            cur += cnt.sum(p + 1, cnt.sz) * p;
            for (int d = 1; d <= q; ++d) {
                int lb = p / (d + 1) + 1, ub = p / d + 1;
                cur += p * cnt.sum(lb, ub) - values.sum(lb, ub) * d;
            }
        }

        ans.push_back(cur);
        cnt.add(p, 1);
        values.add(p, p);
        for (int x = 1; x < small; ++x) modded[x] += (p % x) + (x % p);
    }
    return ans;
}

void solve() {
    autoint n;
    vector<int> a(n);
    cin >> a;
    cout << solve(n, a);
}