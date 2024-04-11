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

struct interactor {
    static int square(int i, int j, int k) {
        cout << "1 " << i + 1 << ' ' << j + 1 << ' ' << k + 1 << endl;
        return autoint();
    }

    static int sign(int i, int j, int k) {
        cout << "2 " << i + 1 << ' ' << j + 1 << ' ' << k + 1 << endl;
        return autoint();
    }
};

void solve() {
    autoint n;
    int second = 1;
    for (int j = 2; j < n; ++j) if (interactor::sign(0, second, j) == -1) second = j;
    vector<pair<int, int>> height;
    for (int j = 1; j < n; ++j) if (second != j) height.emplace_back(interactor::square(0, second, j), j);
    sort(height.begin(), height.end());
    int middle = height.back().second;
    vector<int> left, right;
    for (int i = (int)height.size() - 2; i >= 0; --i)
        (interactor::sign(0, middle, height[i].second) == 1 ? left : right).push_back(height[i].second + 1);
    reverse(right.begin(), right.end());
    cout << "0 1 " << second + 1 << ' ' << right << middle + 1 << ' ' << left;
}