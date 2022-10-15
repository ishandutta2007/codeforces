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
        for (const T &t : v) {
            os << t << (whitespace(t) ? " " : "");
        }
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
        for (const T &t : v) {
            os << t << (whitespace(t) ? " " : "");
        }
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

        autoint() : x(0) { cin >> x; }

        operator int() { return x; }

        int operator--() { return --x; }

        int operator--(signed) { return x--; }

        int operator++() { return ++x; }

        int operator++(signed) { return x++; }
    };

    template<typename T>
    T gcd(T a, T b) {
        while (b) {
            T mod = a % b;
            a = b;
            b = mod;
        }
        return a;
    }

    template<typename T>
    vector<T> prefix_sum(const vector<T> &v, int from = 0) {
        vector<T> res(v.size() + 1 - from);
        res[0] = 0;
        for (int i = from; i < v.size(); ++i) res[i + 1 - from] = res[i - from] + v[i];
        return res;
    }
}

void solve();

signed main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int t = 1;
//    cin >> t;
    do { try { solve(); } catch (exit_exception &) {}} while (--t);
    return 0;
}

void solve() {
    int n, p;
    cin >> n >> p;

    vector<int> a(n);
    cin >> a;
    stable_sort(a.begin(), a.end());
    int mn = 0;
    for (int i = 0; i < n; ++i) mn = max(mn, a[i] - i);

    vector<int> cnta(4e3);
    for (int x : a) cnta[x]++;
    vector<int> cntl(4e3);
    for (int x = 1; x < cntl.size(); ++x) cntl[x] = cntl[x - 1] + cnta[x];

    vector<int> ans;
    for (int x = mn; x <= 2e3; ++x) {
        for (int i = 0; x + i <= 4e3 && i < n; ++i) {
            if ((cntl[x + i] - i) % p == 0) goto OUT;
            if (i % p < cntl[x + i] % p && cntl[x + i] % p < n % p && x + i > 2e3) goto OUT;
            if (i % p < cntl[x + i] % p && i / p != n / p && x + i > 2e3) goto OUT;
            if (cntl[x + i] % p < n % p && i / p != n / p && x + i > 2e3) goto OUT;
        }
        ans.push_back(x);
        OUT:;
    }
    cout << ans.size() << '\n' << ans;
}