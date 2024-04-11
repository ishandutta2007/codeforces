#include <bits/stdc++.h>
using namespace std;

#define mnto(x, y) x = min(x, (__typeof__(x)) y)
#define mxto(x, y) x = max(x, (__typeof__(x)) y)
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
#define pb emplace_back
typedef vector<int> vi;
typedef vector<ii> vii;

#define INF 1000000005
#define LINF 1000000000000000005
#define MOD 1000000007
#define MAXN 200005

int n;
int a[MAXN], b[MAXN], c[MAXN];
vi adj[MAXN];
ll ans;

ii dfs(int u, int p, int curmn) {
	ii cur = MP(0, 0);
	if (b[u] != c[u]) {
		if (b[u]) cur.FI++;
		else cur.SE++;
	}
	for (int v : adj[u]) {
		if (v == p) continue;
		ii temp = dfs(v, u, min(curmn, a[u]));
		cur.FI += temp.FI;
		cur.SE += temp.SE;
	}
	if (a[u] <= curmn) {
		int swp = min(cur.FI, cur.SE);
		ans += (ll) a[u] * swp * 2;
		cur.FI -= swp;
		cur.SE -= swp;
	}
	return cur;
}

int main() {
	scanf("%d", &n);
	REP (i, 1, n + 1) {
		scanf("%d%d%d", &a[i], &b[i], &c[i]);
	}
	REP (i, 1, n) {
		int u, v; scanf("%d%d", &u, &v);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	ii res = dfs(1, -1, INF);
	if (res != MP(0, 0)) {
		printf("-1\n");
	} else {
		printf("%lld\n", ans);
	}
	return 0;
}