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

#define int long long
#define all(a) a.begin(), a.end()

int n, mx, mn;
vector<int> v;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    v.resize(n);
    for (int &el : v)
        cin >> el;
    mx = *max_element(all(v));
    mn = *min_element(all(v));
    if (mx - mn < 2) {
        cout << n << '\n';
        for (auto el : v)
            cout << el << ' ';
        cout << '\n';
        return 0;
    }
    int a = 0, b = 0, c = 0;
    for (int el : v) {
        a += (el == mn);
        b += (el == mn + 1);
        c += (el == mx);
    }
    int sm = accumulate(all(v), 0LL);
    int a_ans = -1, b_ans = -1, c_ans = -1;
    int ans = n + 1;
    for (int i = 0; i <= n; i++) {
        int cur_a = i;
        int already = mn * cur_a;
        int need = sm - already;
        if (need < (mn + 1) * (n - cur_a) || need > mx * (n - cur_a))
            continue;
        int cur_c = need - (mn + 1) * (n - cur_a);
        int cur_b = n - cur_a - cur_c;
        debug(cur_a, cur_b, cur_c);
        debug(need, already);
        if (cur_b < 0 || cur_b > n || cur_c < 0 || cur_c > n)
            continue;
        int cur_ans = min(cur_a, a) + min(cur_b, b) + min(cur_c, c);
        if (cur_ans < ans) {
            ans = cur_ans;
            a_ans = cur_a;
            b_ans = cur_b;
            c_ans = cur_c;
        }
    }
    cout << ans << '\n';
    for (int i = 0; i < a_ans; i++)
        cout << mn << ' ';
    for (int i = 0; i < b_ans; i++)
        cout << mn + 1 << ' ';
    for (int i = 0; i < c_ans; i++)
        cout << mx << ' ';
    cout << '\n';
}