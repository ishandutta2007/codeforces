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

const int INF = 2e9;
int n;
vector<vector<int>> G;
vector<int> depth;
vector<vector<int>> dp;
int ans = 0;

void dfs(int v, int pr) {
    dp[v][0] = 1, dp[v][1] = INF, dp[v][2] = 0;
    bool can_2 = true;
    vector<pair<int, int>> down;
    for (auto u : G[v]) {
        if (u == pr)
            continue;
        depth[u] = depth[v] + 1;
        dfs(u, v);
        dp[v][0] += min({dp[u][0], dp[u][1], dp[u][2]});
        can_2 &= (dp[u][1] != INF);
        dp[v][2] += dp[u][1];
        down.emplace_back(dp[u][0], dp[u][1]);
    }
    if (!can_2)
        dp[v][2] = INF;
    if (down.size() == 0)
        return;
    sort(all(down), [](pair<int, int> &a, pair<int, int> &b) {
        return a.first - min(a.first, a.second) < b.first - min(b.first, b.second);
    });
    dp[v][1] = down[0].first;
    for (int i = 1; i < down.size(); i++)
        dp[v][1] += min(down[i].first, down[i].second);
}

void calc_ans(int v, int pr) {
    if (depth[v] > 1)
        return;
    vector<int> cur;
    for (auto u : G[v]) {
        if (u == pr)
            continue;
        calc_ans(u, v);
        cur.push_back(min({dp[u][0], dp[u][1], dp[u][2]}));
    }
    if (depth[v] == 1 && cur.size() != 0)
        ans += min({dp[v][0], dp[v][1], dp[v][2], accumulate(all(cur), 0)});
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    G.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u, v--, u--;
        G[v].push_back(u);
        G[u].push_back(v);
    }
    dp.resize(n, vector<int>(3));
    depth.resize(n);
    dfs(0, 0);
    for (int i = 0; i < n; i++) 
        debug(i, dp[i]);
    calc_ans(0, 0);
    cout << ans << '\n';
}