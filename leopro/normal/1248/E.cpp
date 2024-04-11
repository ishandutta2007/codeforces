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
//    cin >> t;
    do { try { solve(); } catch (exit_exception &) {}} while (--t);
    return 0;
}

void solve() {
    autoint n, p;
    set<pair<int, int>> t;
    for (int i = 0; i < n; ++i) t.emplace(autoint(), i);
    vector<int> ans(n);
    set<int> ready;
    queue<int> out;
    set<int> outs;
    int spent = 0;
    while (!t.empty() || !ready.empty() || !out.empty()) {
        while (!t.empty() && t.begin()->first < spent) {
            auto idx = t.begin()->second;
            if (!out.empty() && *outs.begin() < idx) ready.insert(idx);
            else {
                out.push(idx);
                outs.insert(idx);
            }
            t.erase(t.begin());
        }
        if (!out.empty()) {
            outs.erase(out.front());
            out.pop();
        }
        if (t.empty() && out.empty() && ready.empty()) break;
        if (ready.empty() && out.empty()) spent = t.begin()->first;
        while (!t.empty() && t.begin()->first == spent) {
            auto idx = t.begin()->second;
            ready.insert(idx);
            t.erase(t.begin());
        }
        if (!ready.empty() && (outs.empty() || *ready.begin() < *outs.begin())) {
            outs.insert(*ready.begin());
            out.push(*ready.begin());
            ready.erase(ready.begin());
        }
        ans[out.front()] = spent += p;
    }
    answer(ans);
}