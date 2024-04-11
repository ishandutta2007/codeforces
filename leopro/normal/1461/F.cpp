#include <bits/stdc++.h>

namespace {
    using namespace std;
//#define int long long
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

vector<char> zip(vector<int> digits, vector<char> signs) {
    vector<char> res(2 * digits.size() - 1);
    for (int i = 0; i < digits.size(); ++i) res[2 * i] = '0' + digits[i];
    for (int i = 0; i + 1 < digits.size(); ++i) res[2 * i + 1] = signs[i % signs.size()];
    return res;
}

void solve() {
    autoint n;
    vector<int> a(n);
    cin >> a;
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    if (s == "+-") s = "+";
    if (s.size() == 1) answer(zip(a, {s[0]}));
    if (s == "*-") {
        int zero = find(a.begin(), a.end(), 0) - a.begin();
        if (zero == 0 || zero == a.size()) {
            answer(zip(a, {'*'}));
        } else {
            vector<char> signs(a.size() - 1, '*');
            signs[zero - 1] = '-';
            answer(zip(a, signs));
        }
    }
    vector<char> signs(n - 1);

    auto fill = [&](int start, int finish) {
        if (start >= finish) return;
        vector<int> non_ones;
        for (int i = start; i <= finish; ++i) if (a[i] != 1) non_ones.push_back(i);

        int cnt = non_ones.size();
        if (cnt == 0) return;
        if (cnt > 20 || (1 << cnt) > 10 * (finish - start + 1)) {
            std::fill(signs.begin() + non_ones.front(), signs.begin() + non_ones.back(), '*');
            return;
        }
        auto calculate = [&](int mask) {
            int ans = (non_ones.front() - start) + (finish - non_ones.back());
            for (int i = 0; i < cnt; ++i) {
                if (i == cnt - 1 || !(mask & (1 << i)))
                    ans += a[non_ones[i]] + (i == cnt - 1 ? 0 : (non_ones[i + 1] - 1 - non_ones[i]));
                else {
                    int cur = a[non_ones[i]];
                    while (mask & (1 << i)) cur *= a[non_ones[++i]];
                    ans += cur + (i == cnt - 1 ? 0 : (non_ones[i + 1] - 1 - non_ones[i]));;
                }
            }
            return ans;
        };

        int value = 0, m = 0;
        for (int mask = 0; mask < (1 << (cnt - 1)); ++mask) {
            int c = calculate(mask);
            if (c > value) value = c, m = mask;
        }
        for (int bit = 0; bit < cnt - 1; ++bit) {
            std::fill(signs.begin() + non_ones[bit], signs.begin() + non_ones[bit + 1], "+*"[(m >> bit) & 1]);
        }
    };

    int start = 0;
    std::fill(signs.begin(), signs.end(), '+');
    for (int i = 0; i < n; ++i)
        if (a[i] == 0) {
            fill(start, i - 1);
            start = i + 1;
        }
    if (a.back()) fill(start, n - 1);
    answer(zip(a, signs));
}