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
    cin >> t;
    do { try { solve(); } catch (exit_exception &) {}} while (--t);
    return 0;
}

void solve() {
    autoint n;
    vector<pair<int, int>> s(n);
    cin >> s;
    vector<int> x;
    for (auto[l, r] : s) {
        x.push_back(l);
        x.push_back(r);
    }
    x.push_back(-2e9);
    sort(x.begin(), x.end());
    x.resize(unique(x.begin(), x.end()) - x.begin());
    for (auto &[l, r] : s) {
        l = lower_bound(x.begin(), x.end(), l) - x.begin();
        r = lower_bound(x.begin(), x.end(), r) - x.begin();
        l *= 2;
        r *= 2;
    }

    vector<int> over(2 * x.size() + 1);
    for (auto [l, r] : s) {
        over[l]++;
        over[r + 1]--;
    }
    for (int i = 1; i < over.size(); ++i) over[i] += over[i - 1];
    vector<int> occurrences01(over.size()), occurrences12(over.size());
    for (int i = 0; i + 1 < over.size(); ++i) {
        if (over[i] == 0 && over[i + 1] > 0) occurrences01[i]++;
        if (over[i] == 1 && over[i + 1] > 1) occurrences12[i]++;
    }
    for (int i = 1; i < over.size(); ++i) occurrences01[i] += occurrences01[i - 1];
    for (int i = 1; i < over.size(); ++i) occurrences12[i] += occurrences12[i - 1];

    int ans = 0;
    for (auto [l, r] : s) {
        int cur = occurrences01[l] + occurrences01.back() - occurrences01[r] + occurrences12[r] - occurrences12[l];
        if (over[l] == 1) cur--;
        if (ans < cur) ans = cur;
    }
    cout << ans << '\n';
}