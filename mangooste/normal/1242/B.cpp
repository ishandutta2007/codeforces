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
vector<int> parent, sz;

int get_parent(int v) {
    if (parent[v] == v)
        return v;
    parent[v] = get_parent(parent[v]);
    return parent[v];
}

void unite(int v, int u) {
    int pv = get_parent(v);
    int pu = get_parent(u);
    if (sz[pv] > sz[pu])
        parent[pu] = pv, sz[pv] += sz[pu];
    else
        parent[pv] = pu, sz[pu] += sz[pv];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    G.resize(n);
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u, v--, u--;
        G[v].push_back(u);
        G[u].push_back(v);
    }
    parent.resize(n);
    sz.resize(n);
    for (int i = 0; i < n; i++)
        sz[i] = 1, parent[i] = i;
    vector<int> comps;
    for (int v = 0; v < n; v++) {
        vector<int> cur;
        bool need = true;
        bool already_unite = false;
        for (auto root : comps) {
            int cnt = 0;
            for (auto u : G[v])
                cnt += (get_parent(u) == root);
            if (cnt != sz[root]) {
                unite(v, root);
                if (!already_unite)
                    cur.push_back(v);
                need = false;
                already_unite = true;
            } else
                cur.push_back(root);
        }
        comps = cur;
        if (need)
            comps.push_back(v);
        for (auto &root : comps)
            root = get_parent(root);
    }
    cout << comps.size() - 1 << '\n';
}