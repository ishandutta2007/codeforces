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

int n;
vector<vector<int>> G;
vector<int> a;
vector<ll> sub_sum, dp;
ll ans = 0;

void calc(int v, int pr) {
    sub_sum[v] = a[v];
    dp[v] = 0;
    for (auto u : G[v]) {
        if (u == pr)
            continue;
        calc(u, v);
        sub_sum[v] += sub_sum[u];
        dp[v] += dp[u] + sub_sum[u];
    }
}

void dfs(int v, int pr, ll up_val, ll up_sum) {
    ans = max(ans, dp[v] + up_val);
    for (auto u : G[v])
        if (u != pr)
            dfs(u, v, up_val + (dp[v] - dp[u] - sub_sum[u]) + up_sum + sub_sum[v] - sub_sum[u], up_sum + sub_sum[v] - sub_sum[u]);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    a.resize(n);
    for (int &el : a)
        cin >> el;
    G.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u, v--, u--;
        G[v].push_back(u);
        G[u].push_back(v);
    }
    sub_sum.resize(n);
    dp.resize(n);
    calc(0, 0);
    dfs(0, 0, 0LL, 0LL);
    cout << ans << '\n';
}