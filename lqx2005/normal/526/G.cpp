#include <bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 1e5 + 10, K = 20;
struct Edge {
	int v, w;
};
int n, q;
vector<Edge> g[N];
struct Solver {
	int rt;
	int f[K][N];
	int son[N], weg[N], dis[N], dep[N], tot = 0, id[N], ans[N];
	int fir[N];
	void Main(int rt) {
		this -> rt = rt;
		dfs(rt, 0, 0);
		id[++tot] = rt;
		sort(id + 1, id + tot + 1, [&](int x, int y) {
			return dep[x] > dep[y];
		});
		for(int i = 1; i <= n; i++) fir[i] = n + 1;
		int cnt = 0;
		for(int i = 1; i <= tot; i++) {
			int u = id[i];
			for(; son[u]; u = son[u]);
			fir[u] = ++cnt;
			ans[cnt] = ans[cnt - 1] + dep[id[i]];
		}
		Dfs(rt, 0);
		return;
	}
	
	void dfs(int u, int fa, int cost) {
		dis[u] = dis[fa] + cost;
		son[u] = 0;
		f[0][u] = fa;
		for(int i = 1; i < K; i++) {
			f[i][u] = f[i - 1][f[i - 1][u]];
		}
		for(Edge &e : g[u]) {
			int v = e.v, w = e.w;
			if(v != fa) {
				dfs(v, u, w);
				if(dep[son[u]] < dep[v]) {
					son[u] = v;
					weg[u] = w;
				}
			}
		}
		dep[u] = dep[son[u]] + cost;
		for(Edge &e : g[u]) {
			int v = e.v;
			if(v != fa && v != son[u]) {
				id[++tot] = v;
			}
		}
		return;
	}
	
	void Dfs(int u, int fa) {
		for(Edge &e : g[u]) {
			int v = e.v;
			if(v != fa) {
				Dfs(v, u);
				fir[u] = min(fir[u], fir[v]);
			}
		}
		return;
	}
	
	int getanc(int u, int y) {
		for(int i = K - 1; i >= 0; i--) {
			if(fir[f[i][u]] > y) {
				u = f[i][u];
			}
		}
		return f[0][u];
	}	
	
	int query(int x, int y) {
		y = 2 * y - 1;
		if(tot <= y) return ans[tot];
		if(fir[x] <= y) return ans[y];
		int anc = getanc(x, y);
		int res = ans[y - 1];
		res = max(res, ans[y] - dep[son[anc]]);
		return res + dep[son[x]] + dis[x] - dis[anc];
	}
	
}T1, T2;
int mxd, id;
void findd(int u, int fa, int dep) {
	if(dep > mxd) {
		mxd = dep, id = u;
	}
	for(Edge &e : g[u]) {
		int v = e.v, w = e.w;
		if(v != fa) {
			findd(v, u, dep + w);
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> q;
	for(int i = 1, u, v, w; i < n; i++) {
		cin >> u >> v >> w;
		g[u].pb(Edge{v, w}), g[v].pb(Edge{u, w});
	}
	mxd = id = -1;
	findd(1, 0, 0);
	int rt1 = id;
	mxd = id = -1;
	findd(rt1, 0, 0);
	int rt2 = id;
	T1.Main(rt1), T2.Main(rt2);
	int ans = 0;
	for(int i = 1, x, y; i <= q; i++) {
		cin >> x >> y;
		x = (x + ans - 1) % n + 1, y = (y + ans - 1) % n + 1;
		ans = max(T1.query(x, y), T2.query(x, y));
		cout << ans << endl;
	}
	return 0;
}