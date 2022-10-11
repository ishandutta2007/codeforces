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

int n, m, k;
vector<pair<int, int>> edges;
vector<vector<pair<int, int>>> G;
vector<string> ans;
vector<int> dst;
vector<vector<int>> comps;

void bfs() {
    dst.resize(n, n + 1);
    dst[0] = 0;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto i : G[v])
            if (dst[i.first] > dst[v] + 1) {
                dst[i.first] = dst[v] + 1;
                q.push(i.first);
            }
    }
}

void calc_ans(int cur) {
    if (ans.size() == k)
        return;
    if (cur == n) {
        ans.push_back("");
        for (int i = 0; i < m; i++)
            ans.back().push_back('0');
        return;
    }
    for (auto edg : comps[cur]) {
        int was = ans.size();
        calc_ans(cur + 1);
        for (int i = was; i < ans.size(); i++)
            ans[i][edg] = '1';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    edges.resize(m);
    G.resize(n);
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u, v--, u--;
        G[v].emplace_back(u, i);
        G[u].emplace_back(v, i);
        edges[i] = {v, u};
    }
    bfs();
    for (auto &i : edges)
        if (dst[i.first] > dst[i.second])
            swap(i.first, i.second);
    comps.resize(n);
    for (int i = 0; i < m; i++)
        if (dst[edges[i].first] != dst[edges[i].second])
            comps[edges[i].second].push_back(i);
    calc_ans(1);
    cout << ans.size() << '\n';
    for (auto i : ans)
        cout << i << '\n';
}