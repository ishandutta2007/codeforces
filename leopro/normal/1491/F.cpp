#ifdef LEONID_PROGRAMMER_AKA_LEOPRO
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

namespace {
    using namespace std;
#define int long long
    using ll = long long;

    template<typename F, typename S>
    ostream &operator<<(ostream &os, const pair<F, S> &p) {
        os << p.first << (is_integral_v<F> || is_integral_v<S> ? " " : "") << p.second << "\n";
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
        for (const T &t : v) os << t << (is_integral_v<T> ? " " : "");
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
        for (const T &t : v) os << t << (is_integral_v<T> ? " " : "");
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

int query(vector<int> l, vector<int> r) {
    cout << "? " << l.size() << ' ' << r.size() << '\n' << l << r << flush;
    return autoint();
}

void solve() {
    autoint n;
    vector<int> cur{1};
    int m = -1;
    for (int i = 2; i <= n; ++i) {
        if (query(cur, {i})) {
            m = i;
            break;
        }
        cur.push_back(i);
    }
    if (m == -1) throw exception();
    vector<int> ans;
    for (int i = m + 1; i <= n; ++i) if (!query({m}, {i})) ans.push_back(i);
    int l = 0, r = cur.size();
    while (r - l > 1) {
        int mid = (l + r) / 2;
        vector<int> half;
        for (int j = l; j < mid; ++j) half.push_back(cur[j]);
        if (query({m}, half)) r = mid; else l = mid;
    }
    for (int i = 0; i < cur.size(); ++i) if (i != l) ans.push_back(cur[i]);
    cout << "! " << ans.size() << '\n' << ans << flush;
}