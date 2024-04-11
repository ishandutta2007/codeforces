// time-limit: 1000
// problem-url: https://codeforces.com/contest/1707/problem/C

// Hallelujah, praise the one who set me free
// Hallelujah, death has lost its grip on me
// You have broken every chain, There's salvation in your name
// Jesus Christ, my living hope
#include <bits/stdc++.h> 
using namespace std;

#define REP(i, s, e) for (int i = (s); i < (e); i++)
#define RREP(i, s, e) for (int i = (s); i >= (e); i--)
template <class T>
inline bool mnto(T& a, T b) {return a > b ? a = b, 1 : 0;}
template <class T>
inline bool mxto(T& a, T b) {return a < b ? a = b, 1: 0;}
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
const int MAXL = 20;

int n, m;
vii eg;
vi adj[MAXN];

int dsup[MAXN], rnk[MAXN];
void init() {
    REP (i, 1, n + 1) {
        dsup[i] = i;
        rnk[i] = 0;
    }
}
int findp(int i) {
    if (dsup[i] == i) return i;
    return dsup[i] = findp(dsup[i]);
}
inline bool join(int a, int b) {
    int pa = findp(a), pb = findp(b);
    if (pa == pb) {
        return 0;
    }
    if (rnk[pa] < rnk[pb]) swap(pa, pb);
    if (rnk[pa] == rnk[pb]) rnk[pa]++;
    dsup[pb] = pa;
    return 1;
}

int pre[MAXN], mp[MAXN], pst[MAXN], ptr = 1;
int p[MAXL][MAXN];
void dfs(int u, int cp) {
    p[0][u] = cp;
    REP (k, 1, MAXL) {
        if (p[k - 1][u] == -1) {
            p[k][u] = -1;
        } else {
            p[k][u] = p[k - 1][p[k - 1][u]];
        }
    }
    pre[u] = ptr++;
    mp[pre[u]] = u;
    for (int v : adj[u]) {
        if (v == cp) continue;
        dfs(v, u);
    }
    pst[u] = ptr;
}

int psm[MAXN];
void incre(int s, int e, int x) {
    psm[s] += x;
    psm[e + 1] -= x;
}

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    cin >> n >> m;
    init();
    REP (i, 0, m) {
        int u, v; cin >> u >> v;
        if (join(u, v)) {
            adj[u].pb(v);
            adj[v].pb(u);
        } else {
            eg.pb({u, v});
        }
    }
    dfs(1, -1);
    for (auto [u, v] : eg) {
        if (pre[u] > pre[v]) {
            swap(u, v);
        }
        if (pre[u] <= pre[v] && pre[v] < pst[u]) {
            int w = v;
            RREP (k, MAXL - 1, 0) {
                if (p[k][w] == -1) {
                    continue;
                }
                if (pre[p[k][w]] > pre[u]) {
                    w = p[k][w];
                }
            }
            incre(pre[w], pst[w] - 1, 1);
            incre(pre[v], pst[v] - 1, -1);
        } else {
            incre(pre[1], pst[1] - 1, 1);
            incre(pre[u], pst[u] - 1, -1);
            incre(pre[v], pst[v] - 1, -1);
        }
    }
    REP (i, 1, n + 1) {
        psm[i] += psm[i - 1];
    }
    string ans(n, '1');
    REP (i, 1, n + 1) {
        assert(psm[i] >= 0);
        if (psm[i]) {
            ans[mp[i] - 1] = '0';
        }
    }
    cout << ans << '\n';
    return 0;
}