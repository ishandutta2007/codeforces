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

struct edge {
    int u, v;

    edge(int u, int v) : u(u), v(v) {}

    edge() = default;
};

void solve() {
    autoint n;
    vector<int> a(n);
    cin >> a;
    for (int &x : a) --x;

    vector<edge> segments;
    for (int i = 0; i < n; ++i) {
        if (i == 0 || a[i] == a[i - 1]) {
            if (!segments.empty()) segments.back().v = i - 1;
            segments.emplace_back(i, n - 1);
        }
    }

    vector<int> cnt(n);
    for (auto s : segments) cnt[a[s.u]]++;
    for (auto s : segments) cnt[a[s.v]]++;

    if (*max_element(cnt.begin(), cnt.end()) <= segments.size() + 1) answer(segments.size() - 1);

    int f = max_element(cnt.begin(), cnt.end()) - cnt.begin();


    int good = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i] == a[i - 1]) continue;
        if (a[i] != f && a[i - 1] != f) good++;
    }
    if (*max_element(cnt.begin(), cnt.end()) <= segments.size() + good + 1) answer(*max_element(cnt.begin(), cnt.end()) - 2);
    answer(-1);

}