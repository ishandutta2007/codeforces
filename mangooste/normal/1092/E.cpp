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

int n, m;
vector<vector<int>> G;
vector<int> roots;
vector<int> mx_depth;
int len = 0;

void dfs_fnd(int v, int pr) {
    mx_depth[v] = 0;
    for (auto u : G[v]) {
        if (u == pr)
            continue;
        dfs_fnd(u, v);
        mx_depth[v] = max(mx_depth[v], mx_depth[u] + 1);
    }
}

void dfs_get(int v, int pr, vector<pair<int, int>> &cur, int up) {
    len = max(len, up + mx_depth[v]);
    cur.emplace_back(v, max(up, mx_depth[v]));
    pair<int, int> mx1 = {-1, -1}, mx2 = {-1, -1};
    for (auto u : G[v]) {
        if (u == pr)
            continue;
        if (mx_depth[u] + 1 >= mx1.second)
            mx2 = mx1, mx1 = {u, mx_depth[u] + 1};
        else if (mx_depth[u] + 1 > mx2.second)
            mx2 = {u, mx_depth[u] + 1};
    }
    for (auto u : G[v]) {
        if (u == pr)
            continue;
        if (u == mx1.first)
            dfs_get(u, v, cur, max(up, mx2.second) + 1);
        else
            dfs_get(u, v, cur, max(up, mx1.second) + 1);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    G.resize(n);
    for (int i = 0; i < m; i++)  {
        int v, u;
        cin >> v >> u, v--, u--;
        G[v].push_back(u);
        G[u].push_back(v);
    }
    mx_depth.resize(n, -1);
    for (int i = 0; i < n; i++)
        if (mx_depth[i] == -1) {
            roots.push_back(i);
            dfs_fnd(i, i);
        }
    vector<pair<int, int>> maybe;
    for (auto root : roots) {
        vector<pair<int, int>> cur;
        dfs_get(root, root, cur, 0);
        sort(all(cur), [](pair<int, int> &a, pair<int, int> &b) {
            return a.second < b.second;
        });
        maybe.emplace_back(cur[0].first, cur[0].second);
    }
    sort(all(maybe), [](pair<int, int> &a, pair<int, int> &b) {
        return a.second > b.second;
    });
    int k = maybe.size();
    if (k <= 1)
        return cout << len << '\n', 0;
    vector<int> ans(k);
    ans[0] = maybe[0].first;
    for (int i = 1; i < k; i++)
        ans[i] = maybe[i].first;
    len = max(len, maybe[0].second + 1 + maybe[1].second);
    if (k != 2)
        len = max(len, maybe[1].second + 2 + maybe[2].second);
    cout << len << '\n';
    for (int i = 1; i < k; i++)
        cout << ans[0] + 1 << ' ' << ans[i] + 1 << '\n';
}