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
    cin >> t;
    do { try { solve(); } catch (exit_exception &) {}} while (--t);
    return 0;
}

vector<int> operator+=(vector<int> &a, const vector<int> &b) {
    for (int x : b) a.push_back(x);
    return a;
}

template<typename Functor>
vector<int> filter(const vector<vector<int>> &v, const Functor &f) {
    vector<int> res;
    for (int i = 0; i < v.size(); ++i) if (f(i)) res += v[i];
    return res;
}

int query(int till, const vector<int> &out1, const vector<int> &out2, int global_max) {
    vector<bool> numbers(till, true);
    for (int x : out1) if (x < till) numbers[x] = false;
    for (int x : out2) if (x < till) numbers[x] = false;
    int size = count(numbers.begin(), numbers.end(), true);
    if (size == 0) return global_max;
    cout << "? " << size << ' ';
    for (int x = 0; x < till; ++x) {
        if (numbers[x]) cout << x + 1 << ' ';
    }
    cout << endl;
    return autoint();
}

int query(int till, const vector<int> &out, int global_max) {
    return query(till, out, vector<int>(), global_max);
}

void solve() {
    autoint n, k;
    vector<vector<int>> sets(k);
    for (auto &set : sets) {
        autoint sz;
        set.assign(sz, 0);
        cin >> set;
        for (int &x : set) --x;
    }
    int global_max = query(n, vector<int>(), 0);
    vector<bool> out(n, true);
    for (auto &set : sets) {
        for (int x : set) {
            out[x] = false;
        }
    }
    vector<int> out_n;
    for (int x = 0; x < n; ++x) if (out[x]) out_n.push_back(x);
    int wm = 0;
    for (int bit = 0; bit < 10; ++bit) {
        int max = query(n, filter(sets, [bit](int x) { return x & (1 << bit); }), out_n, global_max);
        if (max != global_max) wm |= 1 << bit;
    }

    int rare = (wm < k ? query(n, sets[wm], global_max) : global_max);
    vector<int> ans(k, global_max);
    if (wm < k) ans[wm] = rare;
    cout << "! " << ans << flush;
    string verdict;
    cin >> verdict;
}