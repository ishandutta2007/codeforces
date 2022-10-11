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

int n, q;
vector<vector<int>> G;
vector<int> sz, way, pos;

void dfs(int v) {
    way.push_back(v);
    pos[v] = way.size() - 1;
    sz[v] = 1;
    for (auto u : G[v]) {
        dfs(u);
        sz[v] += sz[u];
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> q;
    G.resize(n);
    for (int i = 1; i < n; i++) {
        int par;
        cin >> par, par--;
        G[par].push_back(i);
    }
    for (auto &i : G)
        sort(all(i));
    sz.resize(n);
    pos.resize(n);
    dfs(0);
    debug(way);
    debug(pos);
    while (q--) {
        int v, k;
        cin >> v >> k, v--, k--;
        if (k >= sz[v]) {
            cout << "-1\n";
            continue;
        }
        cout << way[pos[v] + k] + 1 << '\n';
    }
}