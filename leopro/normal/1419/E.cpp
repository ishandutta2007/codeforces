#include <bits/stdc++.h>

namespace {
    using namespace std;
#define int long long
    using ll = long long;

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
    cin >> t;
    do { try { solve(); } catch (exit_exception &) {}} while (--t);
    return 0;
}

void solve() {
    autoint n;
    vector<int> divs(1, n);
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            divs.push_back(i);
            if (i * i != n) divs.push_back(n / i);
        }
    }
    stable_sort(divs.begin(), divs.end());
    vector<int> primes;
    for (int x : divs) {
        bool p = true;
        for (int prev : primes) if (x % prev == 0) p = false;
        if (p) primes.push_back(x);
    }
    if (divs.size() > 3 && primes.size() > 1) {
        vector<int> keys(primes.size());
        if (primes.size() == 2) {
            keys[0] = primes[0] * primes[1];
            if (find(divs.begin(), divs.end(), primes[0] * primes[0]) != divs.end())
                keys[1] = (primes[0] * primes[0] * primes[1]);
            else keys[1] = (primes[1] * primes[1] * primes[0]);
            primes.push_back(primes.front());
        } else {
            primes.push_back(primes.front());
            for (int i = 0; i + 1 < primes.size(); ++i) keys[i] = primes[i] * primes[i + 1];
        }
        vector<vector<int>> groups(primes.size());
        for (int div : divs) {
            if (find(primes.begin(), primes.end(), div) != primes.end() ||
                find(keys.begin(), keys.end(), div) != keys.end())
                continue;
            for (int g = 0; g + 1 < primes.size(); ++g) {
                if (div % primes[g] == 0) {
                    groups[g].push_back(div);
                    break;
                }
            }
        }
        for (int g = 0; g + 1 < primes.size(); ++g) {
            cout << primes[g] << ' ';
            for (int x : groups[g]) cout << x << ' ';
            cout << keys[g] << ' ';
        }
        answer("", 0);
    } else {
        answer(divs, primes.size() > 1);
    }
}