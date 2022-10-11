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

#define int long long
#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define mp make_pair

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &el : a)
            cin >> el;
        if (*max_element(all(a)) == -1) {
            cout << "0 0\n";
            continue;
        }
        int mn = 1000000001, mx = -2;
        for (int i = 1; i < n; i++)
            if (a[i - 1] == -1 && a[i] != -1) {
                mn = min(mn, a[i]);
                mx = max(mx, a[i]);
            }
        for (int i = 0; i < n - 1; i++)
            if (a[i + 1] == -1 && a[i] != -1) {
                mn = min(mn, a[i]);
                mx = max(mx, a[i]);
            }
        for (int &el : a)
            if (el == -1)
                el = (mn + mx) / 2;
        int ans = 0;
        for (int i = 0; i < n - 1; i++)
            ans = max(ans, abs(a[i + 1] - a[i]));
        cout << ans << ' ' << (mn + mx) / 2 << '\n';
    }
}