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
    #define DEBUG

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
#define pb push_back
#define eb emplace_back

ll gcd(ll a, ll b) {
    while (b != 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

ll get_num(ll a, ll k) {
    if (a % k == 0)
        return a / k;
    return (a + k - 1) / k;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    ll n, m;
    int q;
    cin >> n >> m >> q;
    ll g = gcd(n, m);
    ll k_in = n / g, k_out = m / g;
    while (q--) {
        ll sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        ll num1, num2;
        if (sx == 2)
            num1 = get_num(sy, k_out);
        else
            num1 = get_num(sy, k_in);
        if (ex == 2)
            num2 = get_num(ey, k_out);
        else
            num2 = get_num(ey, k_in);
        cout << (num1 == num2 ? "YES\n" : "NO\n");
    }
}