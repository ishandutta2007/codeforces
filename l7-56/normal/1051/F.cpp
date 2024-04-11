#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
typedef pair <ll, ll> pll;

const ll maxn = 1e5 + 10;
ll n,m,d,q;
struct Edge {
	ll v,w,nxt;
}e[maxn << 1];
ll h[maxn],cnt_e;
void add(ll x, ll y, ll z) {
	e[++cnt_e] = {y, z, h[x]};
	h[x] = cnt_e;
}

ll dep[maxn],len[maxn],fa[maxn][20];
vector <ll> V;
void dfs(ll u, ll pre) {
	dep[u] = dep[pre] + 1;
	fa[u][0] = pre;
	for (ll i = 1; i <= 18; ++i) fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for (ll j = h[u]; j; j = e[j].nxt) {
		ll v = e[j].v, w = e[j].w;
		if (v == pre) continue;
		if (dep[v]) { V.push_back(v); continue; }
		len[v] = len[u] + w;
		dfs(v, u);
	}
}

ll lca(ll x, ll y) {
	if (dep[x] < dep[y]) swap(x, y);
	for (ll i = 18; i >= 0; --i)
		if (dep[x] - dep[y] >= (1 << i)) x = fa[x][i];
	if (x == y) return x;
	for (ll i = 18; i >= 0; --i)
		if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
	return fa[x][0];
}

ll dis[50][maxn];
void dij(ll st, ll id) {
	memset(dis[id], 0x3f, sizeof dis[id]);
	priority_queue <pll, vector <pll>, greater <pll> > pq;
	pq.push({dis[id][st] = 0, st});
	while (!pq.empty()) {
		ll u = pq.top().second, val = pq.top().first; pq.pop();
		if (val > dis[id][u]) continue;
		for (ll j = h[u]; j; j = e[j].nxt) {
			ll v = e[j].v, w = e[j].w;
			if (dis[id][v] > val + w) {
				dis[id][v] = val + w;
				pq.push({dis[id][v], v});
			}
		}
	}
}

int main() {
	scanf("%lld%lld", &n, &m);
	for (ll i = 1; i <= m; ++i) {
		ll x, y, z;
		scanf("%lld%lld%lld", &x, &y, &z);
		add(x, y, z), add(y, x, z);
	}
	dfs(1, 0);
	sort(V.begin(), V.end());
	V.erase(unique(V.begin(), V.end()), V.end());
	d = V.size();
	for (ll i = 0; i < d; ++i) dij(V[i], i);
	scanf("%lld", &q);
	while (q--) {
		ll x, y;
		scanf("%lld%lld", &x, &y);
		ll res = len[x] + len[y] - 2 * len[lca(x, y)];
		for (ll i = 0; i < d; ++i) res = min(res, dis[i][x] + dis[i][y]);
		printf("%lld\n", res);
	}
	return 0;
}