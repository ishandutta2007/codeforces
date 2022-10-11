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

void solve() {
    int n, k;
    cin >> n >> k;
    vector<char> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    sort(all(s));
    if (k == n) {
        cout << s[n - 1] << '\n';
        return;
    }
    vector<string> dict(k, "");
    for (int i = 0; i < k; i++)
        dict[i].push_back(s[i]);
    if (s[0] == s[k - 1]) {
        if (s[k] == s.back()) {
            for (int i = k; i < n; i++)
                dict[(i - k) % k].push_back(s[i]);
        } else {
            for (int i = k; i < n; i++)
                dict[0].push_back(s[i]);
        }
    } else {
        for (int i = k; i < n; i++)
            dict[0].push_back(s[i]);
    }
    cout << *max_element(all(dict)) << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}