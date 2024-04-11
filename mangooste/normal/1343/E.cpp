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

int n, m;
vector<int> p;
vector<vector<int>> G;

vector<int> bfs(int v) {
    vector<int> dst(n, 2 * n + 1);
    dst[v] = 0;
    queue<int> q;
    q.push(v);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto u : G[cur]) {
            if (dst[u] < dst[cur] + 1)
                continue;
            dst[u] = dst[cur] + 1;
            q.push(u);
        }
    }
    return dst;
}

void solve() {
    p.clear();
    G.clear();
    int a, b, c;
    cin >> n >> m >> a >> b >> c, a--, b--, c--;
    G.resize(n);
    p.resize(m);
    for (int &i : p)
        cin >> i;
    sort(all(p));
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u, v--, u--;
        G[v].push_back(u);
        G[u].push_back(v);
    }
    vector<int> dst_a = bfs(a), dst_c = bfs(c);
    debug(dst_a);
    debug(dst_c);
    vector<long long> pref(m + 1);
    pref[0] = 0;
    for (int i = 0; i < m; i++)
        pref[i + 1] = pref[i] + p[i];
    queue<int> q;
    q.push(b);
    long long cur = 0, ans = 1e18;
    vector<int> dst(n, 2 * n + 1);
    dst[b] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        debug(v, dst[v]);
        if (dst[v] + dst_a[v] + dst_c[v] <= m) {
            long long c1 = pref[dst[v]];
            long long c2 = pref[dst_a[v] + dst[v]] - pref[dst[v]];
            long long c3 = pref[dst_a[v] + dst[v] + dst_c[v]] - pref[dst_a[v] + dst[v]];
            debug(v, c1, c2, c3);
            ans = min(ans, 2 * c1 + c2 + c3);
        }
        for (auto u : G[v]) {
            if (dst[u] < dst[v] + 1)
                continue;
            dst[u] = dst[v] + 1;
            q.push(u);
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}