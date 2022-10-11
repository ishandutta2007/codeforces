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
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].first, a[i].second = i;
    sort(all(a));
    vector<long long> dp(n);
    vector<int> best(n, -1);
    dp[0] = dp[1] = 1e18;
    long long Min = 1e18;
    int pos = -1;
    for (int i = 2; i < n; i++) {
        dp[i] = a[i].first - a[0].first;
        best[i] = 0;
        if (a[i].first + Min < dp[i]) {
            best[i] = pos;
            dp[i] = Min + a[i].first;
        }
        if (dp[i - 2] - a[i - 1].first < Min) {
            Min = dp[i - 2] - a[i - 1].first;
            pos = i - 1;
        }
    }
    debug(a);
    debug(dp);
    debug(best);
    vector<int> ans(n, -1);
    int cur_num = 1;
    pos = n - 1;
    while (pos >= 0) {
        for (int i = best[pos]; i <= pos; i++)
            ans[a[i].second] = cur_num;
        cur_num++;
        pos = best[pos] - 1;
    }
    cout << dp.back() << ' ' << *max_element(all(ans)) << '\n';
    for (auto i : ans)
        cout << i << ' ';
    cout << '\n';
}