// time-limit: 3000
// problem-url: https://codeforces.com/problemset/problem/1399/E2

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
#define ALL(_a) _a.begin(), _a.end()
#define SZ(_a) (int) _a.size()
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
const int MAXN = 200005;

struct edge {
    int v, w, c;
};
struct node {
    int sz, w;
    ll getv() const {
        return (ll) (w + 1) / 2 * sz;
    }
    node hlf() const {
        return node{sz, w / 2};
    }
    bool operator< (const node &o) const {
        return getv() < o.getv();
    }
};

int t;
int n;
ll s;
vector<edge> adj[MAXN];
ll tot;
priority_queue<node> pq[2];

ll dist[MAXN];
int lc[MAXN];
void dfs(int u, int p) {
    lc[u] = 0;
    bool isl = 1;
    for (auto [v, w, c] : adj[u]) {
        if (v == p) {
            continue;
        }
        isl = 0;
        dist[v] = dist[u] + w;
        dfs(v, u);
        lc[u] += lc[v];
        pq[c - 1].push({lc[v], w});
    }
    if (isl) {
        lc[u] = 1;
        tot += dist[u];
    }
}

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    cin >> t;
    while (t--) {
        cin >> n >> s;
        REP (i, 1, n + 1) {
            adj[i].clear();
        }
        REP (z, 0, 2) {
            while (!pq[z].empty()) {
                pq[z].pop();
            }
        }
        REP (i, 1, n) {
            int u, v, w, c; cin >> u >> v >> w >> c;
            adj[u].pb({v, w, c});
            adj[v].pb({u, w, c});
        }
        pq[0].push({0, 0});
        pq[1].push({0, 0});
        pq[0].push({0, 0});
        pq[1].push({0, 0});
        tot = 0;
        dfs(1, -1);
        ll rem = tot - s;
        if (rem <= 0) {
            cout << 0 << '\n';
            continue;
        }
        int ans = 0;
        while (rem) {
            if (pq[0].top().getv() >= rem) {
                rem = 0;
                ans++;
                break;
            }
            if (pq[1].top().getv() >= rem) {
                rem = 0;
                ans += 2;
                break;
            }
            node tmp = pq[0].top(); pq[0].pop();
            ll fi = tmp.getv() + max(tmp.hlf().getv(), pq[0].top().getv());
            if (fi >= pq[1].top().getv()) {
                rem -= tmp.getv();
                pq[0].push(tmp.hlf());
                ans++;
            } else {
                pq[0].push(tmp);
                tmp = pq[1].top(); pq[1].pop();
                rem -= tmp.getv();
                pq[1].push(tmp.hlf());
                ans += 2;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}