#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif

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

struct mod_int {
    static const int MOD = 1e9 + 7;
    ll value;

    mod_int(int i = 0) : value(i % MOD) {}

    mod_int operator+(mod_int m) const {
        mod_int i = *this;
        i += m;
        return i;
    }

    mod_int operator-(mod_int m) const {
        int x = value - m.value;
        if (x < 0) x += MOD;
        return x;
    }

    mod_int operator+=(mod_int m) {
        value += m.value;
        if (value >= MOD) value -= MOD;
        return *this;
    }

    mod_int operator*(mod_int m) const { return (value * m.value) % MOD; }

    mod_int operator*=(mod_int m) {
        value *= m.value;
        return value %= MOD;
    }

    mod_int power(int exp) {
        if (exp == 0) return 1;
        mod_int res = (exp & 1 ? value : 1);
        mod_int half = power(exp >> 1);
        return res * half * half;
    }

    friend std::istream &operator>>(std::istream &is, mod_int &m) {
        is >> m.value;
        return is;
    }

    friend std::ostream &operator<<(std::ostream &os, const mod_int &m) {
        os << m.value;
        return os;
    }

    operator int() { return value; }  //NOLINT
};

vector<int> prefix_fun(const string &pattern, const string &s) {
    string kmp = pattern + '#' + s;
    vector<int> prefix(kmp.size());
    for (int i = 1; i < kmp.size(); ++i) {
        int p = prefix[i - 1];
        for (; p > 0; p = prefix[p - 1]) if (kmp[i] == kmp[p]) break;
        prefix[i] = p + (kmp[i] == kmp[p]);
    }
    return prefix;
}

string reversed(string s) {
    reverse(s.begin(), s.end());
    return s;
}

vector<mod_int> powers, inv;

mod_int count(vector<char> pattern, const string &t, int k, const vector<vector<mod_int>> &cnt, int s = 0) {
    if (s >= k) return 0;
    if (pattern.size() == 1) {
        return mod_int(cnt[k][pattern[0] - 'a'] - cnt[s][pattern[0] - 'a']) * inv[t.size() - k];
    }
    mod_int res = 0;
    for (int rem = 0; rem < 2; ++rem) {
        bool ok = true;
        vector<char> half;
        for (int i = 0; i < pattern.size(); ++i) {
            if (i % 2 == rem && pattern[i] != t[s]) ok = false;
            if (i % 2 != rem) half.push_back(pattern[i]);
        }
        if (ok) res += count(half, t, k, cnt, s + 1);
    }
    return res;
}

void solve() {
    autoint n, q;
    string s, t;
    cin >> s >> t;
    powers.assign(n + 1, 1);
    inv.assign(n + 1, 1);
    for (int i = 1; i <= n; ++i) powers[i] = powers[i - 1] * mod_int(2);
    for (int i = 1; i <= n; ++i) inv[i] = powers[i].power(mod_int::MOD - 2);
    vector<vector<mod_int>> cnt(t.size() + 1, vector<mod_int>(26));
    for (int i = 0; i < t.size(); ++i) {
        cnt[i + 1] = cnt[i];
        cnt[i + 1][t[i] - 'a'] += powers[n - i - 1];
    }
    for (int j = 0; j < q; ++j) {
        autoint k;
        string name;
        cin >> name;
        auto prefix = prefix_fun(name, s);
        auto inside1 = prefix_fun(s, name);
        auto inside2 = prefix_fun(name, s);
        auto suffix = prefix_fun(reversed(name), reversed(s));

        vector<int> pbegin, pend;
        for (int p = prefix.back(); p > 0; p = prefix[p - 1]) pbegin.push_back(p);
        for (int p = suffix.back(); p > 0; p = suffix[p - 1]) pend.push_back(p);
        pbegin.push_back(0);
        pend.push_back(0);
        reverse(pend.begin(), pend.end());

        mod_int ans = mod_int(count(inside2.begin(), inside2.end(), name.size())) * powers[k];
        for (int sh : pbegin) {
            if (sh == name.size()) continue;
            int shr = (name.size() - (sh + 1)) % (s.size() + 1);
            if (shr == name.size() || !binary_search(pend.begin(), pend.end(), shr)) continue;
            vector<char> pattern{name[sh]};
            for (int i = sh + 1 + s.size(); i < name.size(); i += 1 + s.size()) {
                pattern.push_back(name[i]);
                if (inside1[i + s.size()] != s.size()) goto WELL_BUT_NOT;
            }
            ans += count(pattern, t, k, cnt);
            WELL_BUT_NOT:;
        }
        cout << ans << '\n';
    }
}