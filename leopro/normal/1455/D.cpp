#include <bits/stdc++.h>

namespace {
    using namespace std;
#define int long long

    template<typename T>
    inline bool whitespace(const vector<T> &) { return false; }

    template<typename T>
    inline bool whitespace(const T &) { return true; }

    inline bool whitespace(const char) { return false; }

    template<typename F, typename S>
    inline bool whitespace(const pair<F, S> &) { return false; }

    template<typename F, typename S>
    ostream &operator<<(ostream &os, const pair<F, S> &p) {
        os << p.first << (whitespace(p.second) ? " " : "") << p.second << "\n";
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
        for (const T &t : v) os << t << (whitespace(t) ? " " : "");
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
        for (const T &t : v) os << t << (whitespace(t) ? " " : "");
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

        operator int() { return x; }

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

int x_sort(vector<int> a, vector<int> b, int x) {
    vector<int> indices;
    for (int i = 0; i < a.size(); ++i) if (a[i] != b[i]) indices.push_back(i);
    sort(indices.begin(), indices.end(), [&](int i, int j) { return a[i] < a[j]; });
    if (b[indices[0]] != x || a[indices[0]] <= x) return 1e9;
    for (int i = 1; i < indices.size(); ++i) {
        if (b[indices[i]] != a[indices[i - 1]] || a[indices[i]] == a[indices[i - 1]]) return 1e9;
    }
    return indices.size();
}

bool is_sorted(const vector<int> &a) {
    for (int i = 1; i < a.size(); ++i) if (a[i] < a[i - 1]) return false;
    return true;
}

void solve() {
    autoint n, x;
    vector<int> a(n);
    cin >> a;
    if (is_sorted(a)) answer(0);
    int ans = 1e9;
    for (int i = 0; i < n; ++i) {
        auto b = a;
        b.erase(b.begin() + i);
        b.push_back(x);
        sort(b.begin(), b.end());
        ans = min(ans, x_sort(a, b, x));
    }
    answer(ans == 1e9 ? -1 : ans);
}