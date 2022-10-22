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

int t;
int n, m;
vii adj[MAXN];
bool ban[MAXN];
int vis[MAXN];
bool ans[MAXN];

viii bck;
void dfs(int u, int p) {
    vis[u] = 1;
    for (auto [v, id] : adj[u]) {
	if (v == p) continue;
	if (vis[v] == 1) {
	    bck.pb({u, v, id});
	} else if (!vis[v]) {
	    dfs(v, u);
	}
    }
    vis[u] = 2;
}
void dfs2(int u, int p, int x) {
    for (auto [v, id] : adj[u]) {
	if (v == p || ban[id]) continue;
	ans[id] = x;
	dfs2(v, u, x ^ 1);
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> t;
    while (t--) {
	cin >> n >> m;
	REP (i, 1, n + 1) {
	    adj[i].clear();
	}
	REP (i, 0, m) {
	    int u, v; cin >> u >> v;
	    adj[u].pb({v, i});
	    adj[v].pb({u, i});
	}
	REP (i, 1, n + 1) {
	    vis[i] = 0;
	}
	bck.clear();
	dfs(1, -1);
	REP (i, 0, m) {
	    ans[i] = 0;
	}
	for (auto [u, v, i] : bck) {
	    ans[i] = 1;
	}
	set<int> st;
	for (auto [u, v, i] : bck) {
	    st.insert(u); st.insert(v);
	}
	if (SZ(bck) <= 2 || SZ(st) > 3) {
	    REP (i, 0, m) {
		cout << ans[i];
	    }
	    cout << '\n';
	    continue;
	}
	REP (i, 0, m + 1) {
	    ban[i] = 0;
	}
	for (auto [u, v, i] : bck) {
	    ban[i] = 1;
	}
	dfs2(1, -1, 0);
	REP (i, 0, 3) {
	    auto [u, v, id] = bck[i];
	    ans[id] = i & 1;
	}
	REP (i, 0, m) {
	    cout << ans[i];
	}
	cout << '\n';
    }
    return 0;
}