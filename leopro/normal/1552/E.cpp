#pragma GCC optimize ("O3")
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
        for (const T &t : v) os << t << (is_integral_v<T> && !is_same_v<T, char> ? " " : "\n");
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

void solve() {
    autoint n, k;
    vector<int> over(n * k);
    vector<int> c(n * k);
    cin >> c;
    vector<vector<int>> colorsArray(n);
    vector<int> prev(n * k, -1);
    for (int i = 0; i < n * k; ++i) {
        if (colorsArray[--c[i]].size()) prev[i] = colorsArray[c[i]].back();
        colorsArray[c[i]].push_back(i);
    }
    vector<pair<int, int>> ans(n);
    auto maxOn = [&](int l, int r) {
        int res = 0;
        for (int i = l; i < r; ++i) res = max(res, over[i]);
        return res;
    };
    auto incOn = [&](int l, int r) {
        for (int i = l; i < r; ++i) over[i]++;
    };
    for (int i = 0; i < n * k; ++i) {
        if (ans[c[i]] != pair{0, 0}) continue;
        if (prev[i] != -1 && maxOn(prev[i], i + 1) < (n + k - 2) / (k - 1)) {
            ans[c[i]] = {prev[i] + 1, i + 1};
            incOn(prev[i], i + 1);
        }
    }
    cout << ans;
}