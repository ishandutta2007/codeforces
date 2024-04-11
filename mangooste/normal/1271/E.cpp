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

ll get(ll n, ll val) {
    if (val > n)
        return 0;
    ll ans = 1 + (val + 1 <= n && val % 2 == 0);
    debug(ans);
    for (ll k = 1; (val << k) <= n; k++) {
        ll cur_val = (val << k);
        ll cnt = (1LL << k);
        ans += min(cnt, n - cur_val + 1);
        debug(ans);
        if (val % 2 == 0)
            ans += min(cnt, max(0LL, n - cur_val - (1LL << k) + 1));
        debug(ans);
    }
    debug("get", n, val, ans);
    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    get(20, 2);
    ll n, k;
    cin >> n >> k;
    ll L = 0, R = (n + 1) / 2 + 1;
    while (R - L > 1) {
        ll mid = (L + R) / 2;
        if (get(n, mid * 2 + 1) >= k)
            L = mid;
        else
            R = mid;
    }
    ll ans = 2 * L + 1;
    L = 0, R = (n + 1) / 2 + 1;
    while (R - L > 1) {
        ll mid = (L + R) / 2;
        if (get(n, mid * 2) >= k)
            L = mid;
        else
            R = mid;
    }
    ans = max(ans, 2 * L);
    cout << ans << '\n';
}