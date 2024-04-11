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

vector<pair<int, int>> solve(int a, int b) {
    if (a > b)
        swap(a, b);
    vector<pair<int, int>> ans;
    int x, y;
    x = y = 2;
    for (int i = 0; i < a; i++)
        ans.eb(x, y + i * 2);
    for (int i = 0; i < a - 1; i++)
        ans.eb(x, y + 2 * i + 1);
    b -= a - 1;
    vector<pair<int, int>> can;
    can.eb(x, y - 1);
    can.eb(x, y + 2 * (a - 1) + 1);
    for (int i = 0; i < a && can.size() < b; i++) {
        can.eb(ans[i].first - 1, ans[i].second);
        can.eb(ans[i].first + 1, ans[i].second);
    }
    if (b > can.size())
        return {};
    for (int i = 0; i < b; i++)
        ans.eb(can[i]);
    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        vector<pair<int, int>> ans = solve(b, a);
        if (ans.size() == 0) {
            cout << "NO\n";
            continue;
        }
        if (a < b)
            for (auto &el : ans)
                el.first++;
        cout << "YES\n";
        for (auto el : ans)
            cout << el.first << ' ' << el.second << '\n';
    }
}