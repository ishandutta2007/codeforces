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

int n;
vector<int> a, dp2;
vector<vector<int>> dp;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    a.resize(n);
    for (int &i : a)
        cin >> i;
    dp.resize(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        dp[i][i] = a[i];
    for (int i = n - 2; i >= 0; i--)
        for (int j = i + 1; j < n; j++)
            for (int k = i; k < j; k++)
                if (dp[i][k] && dp[i][k] == dp[k + 1][j])
                    dp[i][j] = dp[i][k] + 1;
    debug(dp);
    dp2.resize(n, 0);
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++)
            if (dp[j][i])
                dp2[i] = max(dp2[i], (j == 0 ? 0 : dp2[j - 1]) + i - j);
    debug(dp2);
    cout << n - dp2[n - 1] << '\n';
}