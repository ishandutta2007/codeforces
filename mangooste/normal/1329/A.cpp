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
    int n, m;
    cin >> n >> m;
    vector<int> len(m);
    for (int &i : len)
        cin >> i;
    vector<long long> suf(m + 1, 0);
    for (int i = m - 1; i >= 0; i--)
        suf[i] = suf[i + 1] + len[i];
    vector<int> ans(m);
    debug(suf);
    for (int i = 0, cur_pos = 1; i < m; i++) {
        if (cur_pos > n)
            return cout << "-1\n", 0;
        if (n - cur_pos + 1 > suf[i])
            return cout << "-1\n", 0;
        if (cur_pos + len[i] - 1 > n)
            return cout << "-1\n", 0;
        ans[i] = cur_pos;
        cur_pos = max(cur_pos + 1LL, n - suf[i + 1] + 1);
        debug(cur_pos);
    }
    for (auto i : ans) 
        cout << i << ' ';
    cout << '\n';
}