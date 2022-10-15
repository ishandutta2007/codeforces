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

void solve() {
    autoint n;
    vector<int> a(n);
    cin >> a;
    for (int &x : a)--x;
    vector<int> left(n), right(n);
    deque<int> incr;
    for (int i = 0; i < n; ++i) {
        while (!incr.empty() && a[incr.back()] >= a[i]) incr.pop_back();
        left[i] = incr.empty() ? -1 : incr.back();
        incr.push_back(i);
    }
    deque<int> decr;
    for (int i = n - 1; i >= 0; --i) {
        while (!decr.empty() && a[decr.back()] > a[i]) decr.pop_back();
        right[i] = decr.empty() ? n + 0 : decr.back();
        decr.push_back(i);
    }

    vector<vector<int>> end(n);
    for (int i = 0; i < n; ++i) end[right[i] - left[i] - 2].push_back(i);


    map<int, int> count;
    set<int> absent;
    for (int x : a) count[x]++;
    for (int i = 0; i < n; ++i) if (count.find(i) == count.end()) absent.insert(i);


    for (int i = 0; i < n; ++i) {
        auto perm = [&]() {
            return
                    count.begin()->first == 0 &&
                    count.rbegin()->first == n - 1 - i &&
                    *absent.begin() > count.rbegin()->first;
        };
        cout << perm();
        for (int y : end[i]) {
            int x = a[y];
            if (!--count[x]) {
                count.erase(x);
                absent.insert(x);
            }
        }
    }
    cout << '\n';
}