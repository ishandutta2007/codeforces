#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using ll = long long;
using namespace std;

namespace Debug {
    // #define DEBUG

    template<class A, class B>
    ostream& operator << (ostream &out, pair<A, B> &p) {
        out << "(" << p.first << ", " << p.second << ")";
        return out;
    }

    template<class T> 
    ostream& operator << (ostream &out, vector<T> &v) {
        out << "{";
        string sep;
        for (T el : v)
            out << sep << el, sep = ", ";
        out << "}";
        return out;
    }

    template<class T>
    ostream& operator << (ostream &out, set<T> &st) {
        out << '(';
        string sep = "";
        for (auto el : st)
            out << sep << el, sep = ", ";
        out << ')';
        return out;
    }

    void debug_out() { cerr << endl; }
    template<class Head, class... Tail>
    void debug_out(Head head, Tail... tail) {
        cerr << ' ' << head;
        debug_out(tail...);
    }

    #ifdef DEBUG
    #define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
    #else
    #define debug(...)
    #endif
}

using namespace Debug;

// #define int long long
#define all(a) a.begin(), a.end()

class str_hash {
private:
    long long MOD, b;
    vector<long long> norm, rev, power;
 
    long long mult(long long a, long long b) {
        return (a * b) % MOD;
    }
 
    long long add(long long a, long long b) {
        long long c = a + b;
        if (c >= MOD)
            c -= MOD;
        return c;
    }
 
    long long sub(long long a, long long b) {
        long long c = a - b;
        if (c < 0)
            c += MOD;
        return c;
    }
 
public:
    str_hash(): MOD(2286661337LL), b(239LL) {}
 
    void clear() {
        norm.clear();
        rev.clear();
        power.clear();
    }
 
    void build(string s, long long MOD_ = 2286661337LL, long long b_ = 239LL) {
        MOD = MOD_, b = b_;
        int n = (int)s.size();
        power.resize(n);
        power[0] = 1LL;
        for (int i = 1; i < n; i++)
            power[i] = mult(power[i - 1], b);
        norm.resize(n + 1);
        for (int i = 0; i < n; i++)
            norm[i + 1] = add(mult(norm[i], b), s[i]);
        rev.resize(n + 1);
        for (int i = n - 1; i >= 0; i--)
            rev[i] = add(mult(rev[i + 1], b), s[i]);
    }

    // hash of s.substr(L, R - L + 1) [L, R]
    long long get_norm(int L, int R) {
        R++;
        return sub(norm[R], mult(norm[L], power[R - L]));
    }

    // revhash of s.substr(L, R - L + 1) [L, R]
    long long get_rev(int L, int R) {
        R++;
        return sub(rev[L], mult(rev[R], power[R - L]));
    }

    // true if s.substr(L, R - L + 1) [L, R] is a palindrome
    bool is_pal(int L, int R) {
        return get_norm(L, R) == get_rev(L, R);
    }
};

int n, a, b;
string s;
str_hash hs1, hs2;
vector<vector<int>> nxt;
vector<int> mx, dp;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> a >> b >> s;
    nxt.resize(n, vector<int>(26, -1));
    nxt[n - 1][s[n - 1] - 'a'] = n - 1;
    for (int i = n - 2; i >= 0; i--) {
        nxt[i] = nxt[i + 1];
        nxt[i][s[i] - 'a'] = i;
    }
    hs1.build(s);
    hs2.build(s, 1e9 + 7, 239);
    mx.resize(n);
    for (int i = 0; i < n; i++)
        mx[i] = i;
    for (int len = 1; len < n; len++) {
        set<ll> already1, already2;
        for (int i = len; i + len - 1 < n; i++) {
            already1.insert(hs1.get_norm(i - len, i - 1));
            already2.insert(hs2.get_norm(i - len, i - 1));
            if (already1.find(hs1.get_norm(i, i + len - 1)) != already1.end() && already2.find(hs2.get_norm(i, i + len - 1)) != already2.end())
                mx[i] = i + len;
        }
    }
    debug(mx);
    dp.resize(n);
    for (int i = 0; i < n; i++)
        dp[i] = (i + 1) * a;
    debug(dp);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++)
            dp[i] = min(dp[i], dp[j] + (i - j) * a);
        for (int j = i; j < mx[i]; j++)
            dp[j] = min(dp[j], dp[i - 1] + b);
    }
    debug(dp);
    cout << dp[n - 1] << '\n';
}