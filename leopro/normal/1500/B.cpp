#ifdef LEONID_PROGRAMMER_AKA_LEOPRO
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

namespace {
    using namespace std;
#define int long long
    using ll = long long;

    template<typename F, typename S>
    ostream &operator<<(ostream &os, const pair<F, S> &p) {
        os << p.first << (is_integral_v<S> && !is_same_v<S, char> ? " " : "") << p.second << "\n";
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

        autoint(int i) : x(i) {}

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

pair<int, int> gcd_ex(int s, int x, int y) {
    //returns [a, b] where s == a * x + b * y
    if (x == 0) return {0, s / y};
    auto[b, a] = gcd_ex(s, y % x, x);
    a -= b * (y / x);
    return {a, b};
}

int solve2(int n, int m, int k, vector<int> a, vector<int> b) {
    vector<int> precalc(2 * n + 2 * m);
    int g = __gcd(m, n);
    for (int i = 0; i < precalc.size(); ++i) {
        auto[l, k] = gcd_ex(i - n - m, m, n);
        k %= m / g;
        if (k < 0) k += m / g;
        precalc[i] = k;
    }
    vector<vector<pair<int, int>>> groups(g);
    for (int i = 0; i < g; ++i) {
        int s = 0;
        for (int j = i; j < m; j += g) groups[i].emplace_back(b[j], j);
    }
    for (auto &g : groups) sort(g.begin(), g.end());
    int period = 0;
    for (int i = 0; i < n; ++i) {
        period += m / g;
        if (lower_bound(groups[i % g].begin(), groups[i % g].end(), pair<int, int>{a[i], 0})->first != a[i]) continue;
        period--;
    }
    vector<int> jindices(n);
    for (int i = 0; i < n; ++i) {
        if (lower_bound(groups[i % g].begin(), groups[i % g].end(), pair<int, int>{a[i], 0})->first != a[i]) {
            jindices[i] = -1;
            continue;
        }
        int j = lower_bound(groups[i % g].begin(), groups[i % g].end(), pair<int, int>{a[i], 0})->second;
        jindices[i] = j;
    }
    auto count = [&](int days) {
        int f = days / (n / __gcd(m, n) * m) * period;
        int rem = days % (n / __gcd(m, n) * m);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += (rem - i + n - 1) / n;
            int j = jindices[i];
            if (j == -1) continue;
            auto k = precalc[j - i + m + n];
            if (i + k * n < rem) ans--;
            ans++;
            ans--;
        }
        return ans + f;
    };
    int l = 0, r = 1e18;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        (count(mid) >= k ? r : l) = mid;
    }
    return r;
}

int solve(int n, int m, int k, vector<int> a, vector<int> b) {
    int x = 0, i = 0;
    for (; x < k; ++i) {
        if (a[i % n] != b[i % m]) x++;
    }
    return i;
}

void solve() {
    autoint n, m, k;
    vector<int> a(n), b(m);
    cin >> a >> b;
    cout << solve2(n, m, k, a, b);
    return;

}