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

vector<vector<int>> G;
vector<int> bad;
vector<char> used;
vector<pair<int, int>> ans;

pair<int, int> dfs_comp(int v) {
    used[v] = 1;
    pair<int, int> edge = {-1, -1};
    for (auto u : G[v]) {
        if (u == 0) {
            edge = {0, v};
            continue;
        }
        if (!used[u]) {
           pair<int, int> cur = dfs_comp(u);
           if (cur.first != -1)
            edge = cur;
        }       
    }
    return edge;
}

void dfs(int v) {
    used[v] = 1;
    for (auto u : G[v])
        if (!used[u]) {
            ans.emplace_back(v, u);
            dfs(u);
        }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, m, d;
    cin >> n >> m >> d;
    G.resize(n);
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u, v--, u--;
        G[v].push_back(u);
        G[u].push_back(v);
    }
    if (G[0].size() < d)
        return cout << "NO\n", 0;
    vector<char> already(n, 0);
    used = vector<char>(n, 0);
    for (int i = 1; i < n; i++) {
        if (used[i])
            continue;
        if (d == 0)
            return cout << "NO\n", 0;
        d--;
        pair<int, int> cur = dfs_comp(i);
        if (cur.first == -1)
            return cout << "NO\n", 0;
        ans.push_back(cur);
        already[cur.second] = 1;
    }
    for (auto u : G[0]) {
        if (d == 0)
            break;
        if (!already[u]) {
            d--;
            ans.emplace_back(0, u);
        }
    }
    used = vector<char>(n, 0);
    used[0] = 1;
    for (auto i : ans)
        used[i.second] = 1;
    vector<pair<int, int>> start = ans;
    for (auto i : start)
        dfs(i.second);
    cout << "YES\n";
    for (auto i : ans)
        cout << i.first + 1 << ' ' << i.second + 1 << '\n';
}