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
vector<char> used;
vector<pair<int, int>> ans;

void dfs(int v) {
    used[v] = 1;
    for (auto u : G[v])
        if (!used[u]) {
            dfs(u);
            ans.emplace_back(v, u);
        }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    G.resize(n);
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u, v--, u--;
        G[v].push_back(u);
        G[u].push_back(v);
    }
    int start = 0;
    for (int i = 1; i < n; i++)
        if (G[i].size() > G[start].size())
            start = i;
    used.resize(n, 0);
    used[start] = 1;
    for (auto v : G[start]) {
        used[v] = 1;
        ans.emplace_back(start, v);
    }
    for (auto v : G[start])
        dfs(v);
    for (auto i : ans)
        cout << i.first + 1 << ' ' << i.second + 1 << '\n';
}