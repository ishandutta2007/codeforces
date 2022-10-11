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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    string s;
    cin >> n >> s;
    vector<int> bal(n);
    bal[0] = (s[0] == '(' ? 1 : -1);
    for (int i = 1; i < n; i++)
        bal[i] = bal[i - 1] + (s[i] == '(' ? 1 : -1);
    vector<int> suf(n);
    suf[n - 1] = bal[n - 1];
    for (int i = n - 2; i >= 0; i--)
        suf[i] = min(suf[i + 1], bal[i]);
    int ans = 0;
    bool can = true;
    debug(bal);
    for (int i = 0; i < n; i++) {
        bool ok = can;
        if (s[i] == '(') {
            ok &= suf[i] >= 2;
            ok &= bal[n - 1] == 2;
        } else {
            ok &= suf[i] >= -2;
            ok &= bal[n - 1] == -2;
        }
        ans += ok;
        can &= bal[i] >= 0;
        debug(ok);
    }
    cout << ans << '\n';
}