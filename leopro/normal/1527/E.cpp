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

struct segment_tree {
    int n;
    vector<int> mod, max;

    explicit segment_tree(int n) : n(n), mod(n), max(2 * n) {}

    void apply(int i, int x) {
        if (i < n) mod[i] += x;
        max[i] += x;
    }

    void update(int i) {
        if (mod[i]) return;
        max[i] = ::max(max[2 * i], max[2 * i + 1]);
    }

    void add(int l, int r, int x) {
        int l0 = l += n, r0 = r += n;
        for (int shift = 20; shift >= 0; --shift) {
            push(l0 >> shift);
            push((r0 - 1) >> shift);
        }
        for (; l < r; l /= 2, r /= 2) {
            if (l & 1) apply(l++, x);
            if (r & 1) apply(--r, x);
        }
        while (l0 > 0) update(l0 /= 2);
        --r0;
        while (r0 > 0) update(r0 /= 2);
    }

    void push(int i) {
        if (i >= n || mod[i] == 0) return;
        apply(2 * i, mod[i]);
        apply(2 * i + 1, mod[i]);
        mod[i] = 0;
    }

    int get(int l, int r) {
        l += n, r += n;
        for (int shift = 20; shift >= 0; --shift) {
            push(l >> shift);
            push((r - 1) >> shift);
        }
        int ans = 0;
        for (; l < r; l /= 2, r /= 2) {
            if (l & 1) ans = ::max(ans, max[l++]);
            if (r & 1) ans = ::max(ans, max[--r]);
        }
        return ans;
    }

};

int solveDp(int n, int k, vector<int> a) {
    for (int &x : a) --x;
    ll maxCost = 0;
    vector<int> lastOccurrence(n, -1);
    for (int i = 0; i < n; ++i) {
        if (lastOccurrence[a[i]] != -1) maxCost += i - lastOccurrence[a[i]];
        lastOccurrence[a[i]] = i;
    }

    fill(lastOccurrence.begin(), lastOccurrence.end(), -1);
    lastOccurrence[a[0]] = 0;
    vector<segment_tree> dp(k, segment_tree(n));
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < k; ++j) {
            if (lastOccurrence[a[i]] != -1) {
                dp[j - 1].add(lastOccurrence[a[i]], i, i - lastOccurrence[a[i]]);
            }
            const auto x = max(dp[j].get(i - 1, i), dp[j - 1].get(0, i));
            dp[j].add(i, i + 1, x);
        }
        lastOccurrence[a[i]] = i;
    }
    return maxCost - dp[k - 1].get(n - 1, n);
}

int bruteSolve(int n, int k, vector<int> a) {
    for (int &x : a) --x;
    int mn = 1e9;
    for (int mask = 0; mask < (1 << n - 1); ++mask) {
        if (__builtin_popcount(mask) != k - 1) continue;
        int cost = 0;

        vector<int> lastOccurrence(n, -1);
        for (int i = 0; i < n; ++i) {
            if (lastOccurrence[a[i]] != -1) cost += i - lastOccurrence[a[i]];
            lastOccurrence[a[i]] = i;
            if (mask & (1 << i)) fill(lastOccurrence.begin(), lastOccurrence.end(), -1);
        }
        mn = min(mn, cost);
    }
    return mn;
}

void solve() {
//    while (true) {
//        int n = rand() % 10 + 1;
//        int k = rand() % n + 1;
//        vector<int> a(n);
//        for (int i = 0; i < n; ++i) a[i] = rand() % n + 1;
//        if (solveDp(n, k, a) == bruteSolve(n, k, a))
//            continue;
//        else
//            answer(n, k, a);
//    }
    autoint n, k;
    vector<int> a(n);
    cin >> a;
    cout << solveDp(n, k, a) << '\n';
}