#include<bits/stdc++.h>

using namespace std;

#define rep(x, L, R) for(int x = (L), _x = (R); x <= _x; x++)
#define per(x, R, L) for(int x = (R), _x = (L); x >= _x; x--)
#define broken fprintf(stderr, "running on %s %d\n", __FUNCTION__, __LINE__)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define SZ(v) (int)(v).size()
#define ALL(x) (x).begin(), (x).end()
#define x first
#define y second
#define mp make_pair
#define pb push_back

template<typename T> inline bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef pair<int, int> par;
typedef long long LL;
typedef unsigned long long uLL;
typedef double db;
const int N = 3e5 + 10;
int n, m, X, vis[N];
vector<par> g[N], e[N];
LL a[N];
LL c[N], sz[N];
int ans[N], tot = 0;

void adde(int u, int v, int w) { g[u].push_back(mp(v, w)); }
void addt(int u, int v, int w) { e[u].push_back(mp(v, w)); }
int cmp(par a, par b) { return c[a.x] - (sz[a.x] - 1) * X > c[b.x] - (sz[b.x] - 1) * X; }
void dfs(int u, int fa) {
	c[u] = a[u];
	vis[u] = sz[u] = 1;
	for(par &e : g[u]) {
		int v = e.x;
		if(v == fa || vis[v]) continue;
		addt(u, v, e.y);
		dfs(v, u);
		c[u] += c[v];
		sz[u] += sz[v];
	}
	return;
}

void Solve(int u) {
	sort(e[u].begin(), e[u].end(), cmp);
	for(par &t : e[u]) {
		int v = t.x;
		if(a[v] + a[u] - X >= 0) {
			ans[++tot] = t.y;
			a[v] = a[v] + a[u] - X;
			Solve(v);
			a[u] = a[v];
		} else {
			Solve(v);
			a[u] += a[v] - X;
			ans[++tot] = t.y;
		}
	}
	return;
}

int main() {
	scanf("%d%d%d", &n, &m, &X);
	LL s = 0;
	for(int i = 1; i <= n; i++) scanf("%lld", &a[i]), s += a[i];
	for(int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		adde(u, v, i), adde(v, u, i);
	}
	if(1ll * X * (n - 1) > s) printf("NO\n"), exit(0);
	dfs(1, 0);
	Solve(1);
	printf("YES\n");
	for(int i = 1; i < n; i++) printf("%d\n", ans[i]);
	return 0;
}