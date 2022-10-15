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
    autoint n, m;
    vector<int> p(n);
    cin >> p;
    for (int &x : p) --x;
    if (n == 3) {
        set<vector<int>> r{p};
        auto swapped = [&](vector<int> p, int i, int j) {
            swap(p[i], p[j]);
            return p;
        };
        if (m == 1) {
            r.insert(swapped(p, 0, 1));
            r.insert(swapped(p, 2, 1));
            r.insert(swapped(p, 0, 2));
        }
        vector<vector<int>> test{{0, 1, 2},
                                 {2, 0, 1},
                                 {1, 2, 0}};
        vector<int> ans;
        for (int i = 0; i < 3; ++i) {
            if (r.count(test[i])) ans.push_back(i);
        }
        cout << ans.size() << ' ' << ans;
        return;
    }

    map<int, int> cnt;
    for (int i = 0; i < n; ++i) cnt[(i - p[i] + n) % n]++;

    vector<int> test;
    for (auto p : cnt) if (p.second * 6 >= n) test.push_back(p.first);
    vector<int> ans;
    for (int x : test) {
        vector<int> c = p;
        for (int &y : c) y = (y + x) % n;
        vector<int> cmp(n, -1);
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            if (cmp[c[i]] == -1) {
                for (int j = i; cmp[c[j]] == -1; j = c[j]) cmp[c[j]] = cur;
                cur++;
            }
        }
        int ops = 0;
        for (int i = 0; i < n; ++i) if (c[i] != i) ops++; else cur--;
        if (ops - cur <= m) ans.push_back(x);
    }
    sort(ans.begin(), ans.end()); //size <= 1
    cout << ans.size() << ' ' << ans;
}