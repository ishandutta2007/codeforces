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

int gcd(int a, int b) {
    while (b != 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

void solve() {
    int a, b, q;
    cin >> a >> b >> q;
    int k = a * b / gcd(a, b);
    if (a > b)
        swap(a, b);
    debug(k);
    for (int i = 0; i < q; i++) {
        ll L, R;
        cin >> L >> R;
        ll up = ((L + k - 1) / k) * k;
        ll down = (R / k) * k;
        debug(up, down);
        ll ans = R - L + 1;
        if (up > R) {
            ans -= max(0LL, min(R, down + b - 1) - L + 1);
            cout << ans << ' ';
            continue;
        }
        if (L % k != 0)
            ans -= max(0LL, (L / k) * k + b - 1 - L + 1);
        ans -= min(R, down + b - 1) - down + 1;
        ans -= ((down - up) / k) * b;
        cout << ans << ' ';
    }
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}