#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

template <typename __Tp> void read(__Tp &x) {
	ll f = 0; x = 0; char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = 1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	if (f) x = -x;
}

const ll maxn = 2e5 + 10;
ll n;
struct Edge {
	ll v, nxt;
}e[maxn << 1];
ll h[maxn], cnt_e;
void add(ll x, ll y) { e[++cnt_e] = {y, h[x]}, h[x] = cnt_e; }

ll fa[maxn][20],dep[maxn],siz[maxn];
void dfs(ll u, ll pre) {
	fa[u][0] = pre, dep[u] = dep[pre] + 1, siz[u] = 1;
	for (ll i = 1; i <= 19; ++i) fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for (ll j = h[u]; j; j = e[j].nxt) {
		ll v = e[j].v;
		if (v == pre) continue;
		dfs(v, u), siz[u] += siz[v];
	}
}

ll lca(ll x, ll y) {
	if (dep[x] < dep[y]) swap(x, y);
	for (ll i = 19; i >= 0; --i)
		if (dep[x] - dep[y] >= (1 << i)) x = fa[x][i];
	if (x == y) return x;
	for (ll i = 19; i >= 0; --i)
		if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
	return fa[x][0];
}

ll ans[maxn];

void work() {
	read(n); cnt_e = 0;
	for (ll i = 1; i <= n; ++i) h[i] = 0;
	for (ll i = 1; i < n; ++i) {
		ll x, y; read(x), read(y);
		++x, ++y, add(x, y), add(y, x);
	}
	dfs(1, 0);
	ll p = 0, q = 0, mid = 0, resp = 0, resq = 0;
	ans[0] = n * (n - 1) / 2;
	ans[1] = n - 1;
	for (ll j = h[1], sum = 0; j; j = e[j].nxt) {
		ll v = e[j].v;
		ans[1] += sum * siz[v], sum += siz[v];
	}
	for (ll i = 2; i <= n; ++i) {
		if (mid == -1) {
			ans[i] = 0;
			continue;
		}
		if (i == 2) {
			p = 1, q = 2, mid = lca(p, q);
			if (dep[p] < dep[q]) swap(p, q);
			resp = siz[p];
			if (q == mid) {
				ll f = p;
				for (ll j = 19; j >= 0; --j)
					if (dep[fa[f][j]] > dep[q]) f = fa[f][j];
				resq = n - siz[f];
			}
			else resq = siz[q];
		}
		else {
			if (dep[p] < dep[q]) swap(p, q), swap(resp, resq);
			ll x = lca(mid, i), y = lca(p, i), z = lca(q, i);
			if (x == mid) {
				if (q == mid) {
					if (y != mid && y != p && y != i) mid = -1;
					else if (y == p) p = i, resp = siz[i];
					else if (y == q) mid = q, q = i, resq = siz[i];
				}
				else {
					if (y != mid && y != p && y != i) mid = -1;
					else if (z != mid && z != q && z != i) mid = -1;
					else if (y == mid && z == mid && i != mid) mid = -1;
					else if (y == p) p = i, resp = siz[i];
					else if (z == q) q = i, resq = siz[i];
				}
			}
			else {
				if (q == mid) {
					ll f = p;
					for (ll j = 19; j >= 0; --j)
						if (dep[fa[f][j]] > dep[i]) f = fa[f][j];
					q = mid = i, resq = n - siz[f];
				}
				else mid = -1;
			}
		}
		if (mid == -1) ans[i] = 0;
		else ans[i] = resp * resq;
	}
	for (ll i = 0; i < n; ++i) printf("%lld ", ans[i] - ans[i + 1]);
	printf("%lld\n", ans[n]);
}

int main() {
//	freopen("route.in", "r", stdin), freopen("route.out", "w", stdout);
	ll t; read(t);
	while (t--) work();
	return 0;
}