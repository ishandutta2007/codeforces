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
typedef vector<iii> viii;

#define INF 1000000005
#define LINF 1000000000000000005
#define MOD 1000000007
#define MAXN 200005

int t;
int n;
vi adj[MAXN];
vector<tuple<int, int, int, int>> ans;

int memo[MAXN][5];
vi rem[MAXN][5];
int dfs(int u, int p, int num) {
	if (memo[u][num] != -1) return memo[u][num];
	viii child;
	for (int v : adj[u]) {
		if (v == p) {
			continue;
		}
		child.pb(MT(dfs(v, u, 2), dfs(v, u, 1), v));
	}
	if (child.empty()) return memo[u][num] = 0;
	sort(ALL(child), [&](iii& l, iii& r) {
			int lf, ls, l_, rf, rs, r_;
		   	tie(lf, ls, l_) = l; tie(rf, rs, l_) = r;
			return lf - ls < rf - rs;
			});
	int res = 0;
	REP (i, 0, max(0, (int) child.size() - num)) {
		int f, s, v; tie(f, s, v) = child[i];
		res += f + 1;
		rem[u][num].pb(v);
	}
	REP (i, max(0, (int) child.size() - num), child.size()) {
		int f, s, v; tie(f, s, v) = child[i];
		res += s;
	}
	return memo[u][num] = res;
}

bool visited[MAXN];
ii rec(int u, int p, int num) {
	int l = -1, r = -1, prv = -1;
	int res = -1;
	for (auto v : rem[u][num]) {
		visited[v] = 1;
		ii tmp = rec(v, u, 2);
		if (l == -1) {
			tie(l, r) = tmp;
		} else {
			ans.pb(u, prv, r, tmp.FI);
			r = tmp.SE;
		}
		prv = v;
	}
	for (int v : adj[u]) {
		if (v == p) continue;
		if (visited[v]) continue;
		visited[v] = 1;
		ii tmp = rec(v, u, 1);
		if (prv != -1) {
			ans.pb(u, prv, r, tmp.FI);
			prv = -1;
			r = -1;
		} else if (l == -1) {
			l = tmp.FI;
		} else if (r == -1) {
			r = tmp.FI;
		}
	}
	if (l == -1) l = u;
	if (r == -1) r = u;
	return MP(l, r);
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		REP (i, 1, n + 1) {
			adj[i].clear();
		}
		REP (i, 1, n) {
			int u, v; scanf("%d%d", &u, &v);
			adj[u].pb(v);
			adj[v].pb(u);
		}
		REP (i, 1, n + 1) {
			REP (j, 0, 5) {
				memo[i][j] = -1;
				rem[i][j].clear();
			}
		}
		printf("%d\n", dfs(1, -1, 2));
		REP (i, 1, n + 1) {
			visited[i] = 0;
		}
		ans.clear();
		rec(1, -1, 2);
		for (auto [a, b, c, d] : ans) {
			printf("%d %d %d %d\n", a, b, c, d);
		}
	}
	return 0;
}