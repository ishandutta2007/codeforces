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
//    cin >> t;
    do { try { solve(); } catch (exit_exception &) {}} while (--t);
    return 0;
}

void solve() {
    autoint n, q;
    vector<int> p(n);
    cin >> p;
    stable_sort(p.begin(), p.end());
    set<int> heaps;
    map<int, int> diffs;
    for (int x : p) heaps.insert(x);
    for (int i = 1; i < n; ++i) diffs[p[i] - p[i - 1]]++;

    cout << *heaps.rbegin() - *heaps.begin() - (diffs.rbegin() == diffs.rend() ? 0 : diffs.rbegin()->first) << '\n';
    for (int query = 0; query < q; ++query) {
        autoint t, x;
        if (t == 0) {
            heaps.erase(x);
            bool both = true;
            if (heaps.upper_bound(x) != heaps.end()) {
                if (!--diffs[*heaps.upper_bound(x) - x])
                    diffs.erase(*heaps.upper_bound(x) - x);
            } else both = false;
            if (heaps.lower_bound(x) != heaps.begin()) {
                if (!--diffs[x - *(--heaps.lower_bound(x))])
                    diffs.erase(x - *(--heaps.lower_bound(x)));
            } else both = false;
            if (both) diffs[*heaps.upper_bound(x) - *(--heaps.lower_bound(x))]++;
        } else {

            heaps.insert(x);
            bool both = true;
            if (heaps.upper_bound(x) != heaps.end()) ++diffs[*heaps.upper_bound(x) - x]; else both = false;
            if (heaps.lower_bound(x) != heaps.begin()) ++diffs[x - *(--heaps.lower_bound(x))]; else both = false;
            if (both)
                if (!--diffs[*heaps.upper_bound(x) - *(--heaps.lower_bound(x))])
                    diffs.erase(*heaps.upper_bound(x) - *(--heaps.lower_bound(x)));

        }
        if (!heaps.empty())
            cout << *heaps.rbegin() - *heaps.begin() - (diffs.rbegin() == diffs.rend() ? 0 : diffs.rbegin()->first)
                 << '\n';
        else cout << "0\n";
    }
}