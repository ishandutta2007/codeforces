#include <bits/stdc++.h>

#include <utility>

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

        operator int() { return x; }                                               //NOLINT
        int operator--() { return --x; }

        int operator--(signed) { return x--; }

        int operator++() { return ++x; }

        int operator++(signed) { return x++; }
    };   //NOLINT
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
    vector<int> primes(1, 2);
    for (int p = 3; p * p < 1e7; p += 2) {
        bool prime = true;
        for (int pr : primes) {
            if (p % pr == 0) prime = false;
            if (!prime) break;
            if (pr * pr > p) break;
        }
        if (prime) primes.push_back(p);
    }
    autoint n;
    vector<int> a(n);
    cin >> a;
    vector<pair<int, int>> ans(n);

    for (int i = 0; i < n; ++i) {
        int prime = 0;
        for (int p : primes) {
            if (a[i] % p == 0) prime = p;
            if (prime) break;
            if (p * p > a[i]) break;
        }
        if (prime == 0) {
            ans[i] = {-1, -1};
            continue;
        }
        while (a[i] % prime == 0) a[i] /= prime;
        ans[i] = (a[i] == 1 ? pair<int, int>{-1, -1} : pair<int, int>{prime, a[i]});
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i].first << ' ';
    }
    cout << '\n';

    for (int i = 0; i < n; ++i) {
        cout << ans[i].second << ' ';
    }
}