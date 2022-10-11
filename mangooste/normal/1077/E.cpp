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

#define int long long
#define all(a) a.begin(), a.end()

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &el : a)
        cin >> el;
    vector<int>  b;
    sort(all(a));
    for (int i = 0; i < n;) {
        int j = i;
        while (j < n && a[i] == a[j])
            j++;
        b.push_back(j - i);
        i = j;
    }
    sort(all(b));
    debug(b);
    int m = b.size();
    int ans = b.back();
    int mx = b.back();
    for (int i = m - 2; i >= 0; i--) {
        mx /= 2;
        mx = min(mx, b[i]);
        debug(mx);
        ans = max(ans, mx * ((1LL << m - i) - 1));
        debug(ans);
    }
    cout << ans << '\n';
}