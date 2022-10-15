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

vector<int> with_k_more_elements(vector<int> v, int k, int e) {
    for (int i = 0; i < k; ++i) {
        v.push_back(e);
    }
    return v;
}

bool ok(vector<int> a, vector<int> b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int a_sum = 0, b_sum = 0;
    for (int i = a.size() / 4; i < a.size(); ++i) a_sum += a[i];
    for (int i = b.size() / 4; i < b.size(); ++i) b_sum += b[i];
    return a_sum >= b_sum;
}

void solve() {
    autoint n;
    vector<int> a(n);
    cin >> a;
    for (int &x : a) --x;
    vector<int> input = a;

    set<int> free;
    for (int i = 0; i < n; ++i) free.insert(i);

    for (int i = 0; i < n; ++i) {
        if (free.count(a[i]) == 0)
            a[i] = -1;
        else
            free.erase(a[i]);
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] == -1) {
            a[i] = *free.begin();
            if (a[i] == i) {
                a[i] = *free.rbegin();
            }
            free.erase(a[i]);
        }
    }


    for (int j = 0; j < n; ++j) {
        if (a[j] == j) {
            for (int i = 0; i < n; ++i) if (a[i] == input[j]) a[i] = a[j];
            a[j] = input[j];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) ans += input[i] == a[i]++;

    cout << ans << '\n' << a << '\n';
}