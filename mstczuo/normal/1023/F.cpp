# include <bits/stdc++.h>
using namespace std;

const int maxn = 500010;

vector<int> g[maxn];
bool vis[maxn];
int par[maxn];
int dep[maxn];

void dfs(int u, int last) {
	for(auto v: g[u]) if(v != last) {
		par[v] = u;
		dep[v] = dep[u] + 1;
		dfs(v, u);
	}
}

int f[maxn];
int get(int x) { return f[x] == x ? x : f[x] = get(f[x]); }

struct Edge {
	int w, x, y;
	bool operator<(const Edge&ot) const {
		return w < ot.w;
	}
} e[maxn];

int main() {
	int n, k, m; scanf("%d%d%d", &n, &k, &m);
	for(int i = 1; i <= n; ++i) f[i] = i;
	for(int i = 0; i < k; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
		f[get(x)] = get(y);
	}
	for(int i = 0; i < m; ++i) 
		scanf("%d%d%d", &e[i].x, &e[i].y, &e[i].w);
	sort(e, e + m);
	for(int i = 0; i < m; ++i) {
		int x = e[i].x, y = e[i].y;
		if(get(x) != get(y)) {
			f[get(x)] = get(y);
			g[x].push_back(y);
			g[y].push_back(x);
			vis[i] = true;
		}
	}
	for(int i = 1; i <= n; ++i) f[i] = i;
	for(int i = 1; i <= n; ++i) if(par[i] == 0) dfs(i, i);
	for(int i = 0; i < m; ++i) if(vis[i]) {
		int x = e[i].x, y = e[i].y;
		if(par[y] == x) swap(x, y); // par[x] = y;
		f[get(x)] = get(y);
	}
	long long ans = 0;
	int cnt = 0;
	for(int i = 0; i < m; ++i) {
		int x = e[i].x, y = e[i].y;
		if(get(x) == get(y)) continue;
		x = get(x), y = get(y);
		while(x != y) {
			if(dep[x] < dep[y]) swap(x, y);
			f[x] = get(par[x]);
			x = f[x];
			ans += e[i].w;
			cnt += 1;
		}
	}
	if(cnt < k) {
		cout << -1 << endl;
	} else {
		cout << ans << endl;
	}
	return 0;
}