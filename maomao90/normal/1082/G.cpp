// time-limit: 2000
// problem-url: https://codeforces.com/contest/1082/problem/G

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
#define MP make_pair
#define FI first
#define SE second
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
#define MT make_tuple
typedef tuple<int, int, int> iii;
#define ALL(_a) _a.begin(), _a.end()
#define pb push_back
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

#ifndef DEBUG
#define cerr if (0) cerr
#endif

#define INF 1000000005
#define LINF 1000000000000000005ll
#define MAXN 1005

template <class T = int, int PW = 0>
class FlowGraph {
    public:
        FlowGraph(): n(0), inf(0) {}
        FlowGraph(int n): n(n), inf(0) {
            dist.resize(n, -1);
            ptr.resize(n, 0);
            adj.resize(n);
        }
        void addEdge(int u, int v, T cap, T rcap = 0) {
            int id = adj[u].size(), rid = adj[v].size();
            adj[u].pb((edge) {v, cap, 0, rid});
            adj[v].pb((edge) {u, rcap, 0, id});
            mxto(inf, max(cap, rcap) + 5);
        }
        T flow(int src, int sink) {
            T res = 0;
            for (lim = ((T) 1 << PW); lim > 0; lim >>= 1) {
                while (bfs(src, sink)) {
                    REP (i, 0, n) {
                        ptr[i] = 0;
                    }
                    while (T cflow = dfs(src, sink, inf)) {
                        res += cflow;
                    }
                }
            }
            return res;
        }
        bool leftCut(int x) {
            return dist[x] != -1;
        }
    private:
        struct edge {
            int v;
            T cap, flow;
            int rid;
        };
        int n;
        T lim;
        T inf;
        vector<vector<edge>> adj;
        vi dist, ptr;
        bool bfs(int src, int sink) {
            REP (i, 0, n) {
                dist[i] = -1;
            }
            queue<int> q;
            dist[src] = 0;
            q.push(src);
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (edge e : adj[u]) {
                    if (e.cap - e.flow < lim) continue;
                    if (dist[e.v] != -1) continue;
                    dist[e.v] = dist[u] + 1;
                    q.push(e.v);
                }
            }
            return dist[sink] != -1;
        }
        T dfs(int u, int sink, T flow) {
            if (u == sink) return flow;
            for (; ptr[u] < adj[u].size(); ptr[u]++) {
                edge &e = adj[u][ptr[u]];
                if (dist[u] + 1 != dist[e.v]) continue;
                if (e.cap - e.flow < lim) continue;
                T cflow = min(flow, e.cap - e.flow);
                cflow = dfs(e.v, sink, cflow);
                if (cflow) {
                    e.flow += cflow;
                    adj[e.v][e.rid].flow -= cflow;
                    return cflow;
                }
            }
            return 0;
        }
};

int n, m;
int a[MAXN];
vii adj[MAXN];

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    cin >> n >> m;
    FlowGraph<ll, 30> fg(n + 2);
    REP (i, 1, n + 1) {
        cin >> a[i];
        fg.addEdge(0, i, 2 * a[i]);
    }
    ll tot = 0;
    REP (i, 0, m) {
        int u, v, w; cin >> u >> v >> w;
        tot += w;
        adj[u].pb(MP(v, w));
        adj[v].pb(MP(u, w));
        fg.addEdge(u, v, w, w);
    }
    REP (i, 1, n + 1) {
        ll sm = 0;
        for (auto [v, w] : adj[i]) {
            sm += w;
        }
        fg.addEdge(i, n + 1, sm);
    }
    ll ans = 2 * tot - fg.flow(0, n + 1);
    assert(ans % 2 == 0);
    ans /= 2;
    cout << ans << '\n';
    return 0;
}