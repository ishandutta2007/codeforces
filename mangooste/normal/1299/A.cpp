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

const int LOG = 31;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &el : a)
        cin >> el;
    vector<vector<int>> bits(LOG);
    for (int bit = 0; bit < LOG; bit++)
        for (int i = 0; i < n; i++)
            if (a[i] & (1 << bit))
                bits[bit].pb(i);
    vector<int> ans;
    vector<char> used(n, 0);
    for (int bit = LOG - 1; bit >= 0; bit--) {
        if (bits[bit].size() > 1 || bits[bit].size() == 0)
            continue;
        if (!used[bits[bit][0]]) {
            used[bits[bit][0]] = 1;
            ans.pb(a[bits[bit][0]]);
        }
    }
    for (int i = 0; i < n; i++)
        if (!used[i])
            ans.pb(a[i]);
    for (auto el : ans)
        cout << el << ' ';
    cout << '\n';
}