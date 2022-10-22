// time-limit: 1000
// problem-url: https://codeforces.com/contest/1684/problem/G

// Hallelujah, praise the one who set me free
// Hallelujah, death has lost its grip on me
// You have broken every chain, There's salvation in your name
// Jesus Christ, my living hope
#include <bits/stdc++.h> 
using namespace std;

template <class T>
inline bool mnto(T& a, T b) {return a > b ? a = b, 1 : 0;}
template <class T>
inline bool mxto(T& a, T b) {return a < b ? a = b, 1: 0;}
#define REP(i, s, e) for (int i = s; i < e; i++)
#define RREP(i, s, e) for (int i = s; i >= e; i--)
typedef long long ll;
typedef long double ld;
#define FI first
#define SE second
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> iii;
#define SZ(_a) (int) _a.size()
#define ALL(_a) _a.begin(), _a.end()
#define pb push_back
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<iii> viii;

#ifndef DEBUG
#define cerr if (0) cerr
#endif

const int INF = 1000000005;
const ll LINF = 1000000000000000005ll;
const int MAXN = 1005;

int n, m;
int t[MAXN];
vii ans;

struct edge {
    int v, f, c, rid;
};
vector<edge> adj[MAXN];
void addEdge(int u, int v) {
    int id = SZ(adj[u]), rid = SZ(adj[v]);
    adj[u].pb({v, 0, 1, rid});
    adj[v].pb({u, 0, 0, id});
}
int dist[MAXN];
bool bfs(int s, int t) {
    fill(dist, dist + t + 1, INF);
    dist[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto [v, f, c, rid] : adj[u]) {
            if (f == c) continue;
            if (mnto(dist[v], dist[u] + 1)) {
                q.push(v);
            }
        }
    }
    return dist[t] < INF;
}
int ptr[MAXN];
int dfs(int u, int t, int cf) {
    if (u == t) {
        return cf;
    }
    //cerr << u << ' ' << t << ' ' << cf << '\n';
    for (; ptr[u] < SZ(adj[u]); ptr[u]++) {
        auto &[v, f, c, rid] = adj[u][ptr[u]];
        if (f == c || dist[v] != dist[u] + 1) continue;
        int nf = dfs(v, t, min(cf, c - f));
        if (nf) {
            f += nf;
            adj[v][rid].f -= nf;
            return nf;
        }
    }
    return 0;
}
int flow(int s, int t) {
    int res = 0;
    while (bfs(s, t)) {
        memset(ptr, 0, sizeof ptr);
        while (int f = dfs(s, t, INF)) {
            res += f;
        }
    }
    return res;
}

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    cin >> n >> m;
    vi l, r;
    REP (i, 0, n) {
        cin >> t[i];
        if (t[i] > m / 3) {
            l.pb(i);
        } else {
            r.pb(i);
        }
    }
    int src = n, sink = n + 1;
    for (int i : l) {
        addEdge(src, i);
    }
    for (int i : r) {
        addEdge(i, sink);
    }
    for (int i : l) {
        for (int j : r) {
            if (t[i] % t[j] == 0 && 2ll * t[i] + t[j] <= m) {
                cerr << i << ' ' << j << '\n';
                addEdge(i, j);
            }
        }
    }
    int res = flow(src, sink);
    if (res != SZ(l)) {
        cout << -1 << '\n';
        return 0;
    }
    for (int i : l) {
        for (auto [v, f, c, rid] : adj[i]) {
            if (f == 1) {
                ans.pb({t[i] * 2 + t[v], t[i] + t[v]});
            }
        }
    }
    for (int i : r) {
        for (auto [v, f, c, rid] : adj[i]) {
            if (f == 0 && c == 1) {
                ans.pb({3 * t[i], 2 * t[i]});
            }
        }
    }
    cout << SZ(ans) << '\n';
    for (auto [a, b] : ans) {
        cout << a << ' ' << b << '\n';
    }
    return 0;
}