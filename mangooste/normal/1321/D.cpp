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
vector<vector<int>> G, rev_G;
vector<int> p, dst;
int s, t;
int ans_min = 0, ans_max = 0;
vector<int> cnt;

void bfs() {
    dst.resize(n, n + 1);
    dst[t] = 0;
    queue<int> q;
    q.push(t);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto u : rev_G[v])
            if (dst[u] > dst[v] + 1) {
                dst[u] = dst[v] + 1;
                q.push(u);
            }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    G.resize(n);
    rev_G.resize(n);
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u, v--, u--;
        G[v].push_back(u);
        rev_G[u].push_back(v);
    }
    cin >> k;
    p.resize(k);
    for (auto &el : p)
        cin >> el, el--;
    s = p[0], t = p[k - 1];
    bfs();
    cnt.resize(n);
    for (int i = 0; i < n; i++)
        for (auto v : G[i])
            cnt[i] += (dst[v] + 1 == dst[i]);
    for (int i = 0; i < k - 1; i++) {
        int v = p[i], u = p[i + 1];
        if (dst[u] == dst[v] - 1)
            ans_max += (cnt[v] > 1);
        else {
            ans_max++;
            ans_min++;
        }
    }
    cout << ans_min << ' ' << ans_max << '\n';
}