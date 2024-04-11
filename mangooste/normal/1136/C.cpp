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

int n, m;
vector<vector<int>> a, b;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    a.resize(n + m);
    b.resize(n + m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            int el;
            cin >> el;
            a[i + j].push_back(el);
        }
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) {
            int el;
            cin >> el;
            b[i + j].push_back(el);
        }
    bool ok = true;
    for (auto &i : a)
        sort(all(i));
    for (auto &i : b)
        sort(all(i));
    for (int i = 0; i < n + m; i++)
        ok &= (a[i] == b[i]);
    cout << (ok ? "YES\n" : "NO\n");
}