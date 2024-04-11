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

    #define DEBUG

    #ifdef DEBUG
    #define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
    #else
    #define debug(...)
    #endif
}

using namespace Debug;

// #define int long long
#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define mp make_pair

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    bool m = false, w = false;
    for (auto el : s) {
        m |= (el == 'm');
        w |= (el == 'w');
    }
    if (m || w)
        return cout << "0\n", 0;
    vector<int> lens;
    for (int i = 0; i < n;) {
        if (s[i] != 'n' && s[i] != 'u') {
            i++;
            continue;
        }
        int j = i;
        while (j < n && s[i] == s[j])
            j++;
        if (j - i > 1)
            lens.pb(j - i);
        i = j;
    }
    const ll MOD = 1e9 + 7;
    vector<ll> dp(n + 1);
    dp[0] = dp[1] = 1;
    for (int len = 2; len <= n; len++) {
        dp[len] = dp[len - 2] + dp[len - 1];
        if (dp[len] >= MOD)
            dp[len] -= MOD;
    }
    ll ans = 1;
    for (auto len : lens) {
        ans *= dp[len];
        ans %= MOD;
    }
    cout << ans << '\n';
}