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

using namespace std;
using ll = long long;

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
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        set<array<int, 3>> was;
        int x = 0, y = 0;
        int ans = 0;
        for (auto el : s) {
            if (el == 'S') {
                ans += (was.count({x, y, 1}) ? 1 : 5);
                was.insert({x, y, 1});
                was.insert({x + 1, y, 2});
                x++;
            } else if (el == 'N') {
                ans += (was.count({x, y, 2}) ? 1 : 5);
                was.insert({x, y, 2});
                was.insert({x - 1, y, 1});
                x--;
            } else if (el == 'W') {
                ans += (was.count({x, y, 3}) ? 1 : 5);
                was.insert({x, y, 3});
                was.insert({x, y - 1, 4});
                y--;
            } else {
                ans += (was.count({x, y, 4}) ? 1 : 5);
                was.insert({x, y, 4});
                was.insert({x, y + 1, 3});
                y++;
            }
        }
        cout << ans << '\n';
    }
}