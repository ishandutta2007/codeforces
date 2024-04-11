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

const ll mod = 1000000007ll;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int h, w;
    cin >> h >> w;
    vector<int> r(h), c(w);
    for (int &el : r)
        cin >> el;
    for (int &el : c)
        cin >> el;
    vector<vector<int>> table(h, vector<int>(w, 0));
    for (int i = 0; i < h; i++)
        for (int j = 0; j < r[i]; j++)
            table[i][j] = 1;
    for (int j = 0; j < w; j++)
        for (int i = 0; i < c[j]; i++)
            table[i][j] = 1;
    bool ok = true;
    for (int i = 0; i < h; i++)
        ok &= (r[i] == w || table[i][r[i]] == 0);
    for (int j = 0; j < w; j++)
        ok &= (c[j] == h || table[c[j]][j] == 0);
    if (!ok)
        return cout << "0\n", 0;
    int cnt = 0;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            cnt += (j > r[i] && i > c[j]);
    ll ans = 1;
    for (int i = 0; i < cnt; i++)
        ans *= 2ll, ans %= mod;
    cout << ans << '\n';
}