#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <ll, ll> pii;
#define fir first
#define sec second
template <typename __Tp> void read(__Tp &x) {
	int f = x = 0; char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = 1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	if (f) x = -x;
}
void read(char &ch) { for (ch = getchar(); isspace(ch); ch = getchar()); }
template <typename __Tp1, typename ...__Tp2> void read(__Tp1 &x, __Tp2 &... y) { read(x), read(y...); }
template <typename __Tp> void write(__Tp x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) write(x / 10);
	putchar(x % 10 + 48);
}
void write(char ch) { putchar(ch); }
void write(const char *s) { for (; *s; ++s) putchar(*s); }
template <typename __Tp1, typename ...__Tp2> void write(__Tp1 x, __Tp2 ... y) { write(x), write(y...); }

const ll maxn = 1e6 + 10;
ll n, m, k, q, dis[maxn], fa[maxn];
ll get(ll x) { return x == fa[x] ? x : fa[x] = get(fa[x]); }
struct edge {
	ll x, y, z;
	friend bool operator < (edge a, edge b) { return a.z < b.z; }
} a[maxn];
struct Edge {
	ll v, w, nxt;
} e[maxn];
ll h[maxn], cnt_e;
void add(ll x, ll y, ll z) { e[++cnt_e] = {y, z, h[x]}, h[x] = cnt_e; }

ll f[maxn][21], g[maxn][21], dep[maxn];
void dfs(ll u, ll pre) {
	dep[u] = dep[pre] + 1;
	for (ll i = 1; i < 21; ++i)
		f[u][i] = f[f[u][i - 1]][i - 1],
		g[u][i] = max(g[u][i - 1], g[f[u][i - 1]][i - 1]);
	for (ll j = h[u]; j; j = e[j].nxt) {
		ll v = e[j].v, w = e[j].w;
		if (v == pre) continue;
		f[v][0] = u, g[v][0] = w, dfs(v, u);
	}
}

ll query(ll x, ll y) {
	if (dep[x] < dep[y]) swap(x, y);
	ll res = 0;
	for (ll i = 20; i >= 0; --i)
		if (dep[x] - dep[y] >= (1 << i)) res = max(res, g[x][i]), x = f[x][i];
	if (x == y) return res;
	for (ll i = 20; i >= 0; --i)
		if (f[x][i] != f[y][i])
			res = max(res, max(g[x][i], g[y][i])),
			x = f[x][i], y = f[y][i];
	return max(res, max(g[x][0], g[y][0]));
}

int main() {
	memset(dis, 0x3f, sizeof dis);
	read(n, m, k, q);
	for (ll i = 1; i <= m; ++i)
		read(a[i].x, a[i].y, a[i].z),
		add(a[i].x, a[i].y, a[i].z),
		add(a[i].y, a[i].x, a[i].z);
	priority_queue <pii, vector <pii>, greater <pii> > pq;
	for (ll i = 1; i <= k; ++i) dis[i] = 0, pq.push({0, i});
	while (!pq.empty()) {
		ll u = pq.top().sec, val = pq.top().fir; pq.pop();
		if (val != dis[u]) continue;
		for (ll j = h[u]; j; j = e[j].nxt) {
			ll v = e[j].v, w = e[j].w;
			if (dis[v] > dis[u] + w)
				dis[v] = dis[u] + w, pq.push({dis[v], v});
		}
	}
	for (ll i = 1; i <= m; ++i) a[i].z += dis[a[i].x] + dis[a[i].y];
	sort(a + 1, a + m + 1);
	cnt_e = 0;
	for (ll i = 1; i <= n; ++i) h[i] = 0, fa[i] = i;
	for (ll i = 1; i <= m; ++i) {
		ll x = a[i].x, y = a[i].y, z = a[i].z;
		if (get(x) == get(y)) continue;
		fa[get(x)] = get(y);
		add(x, y, z), add(y, x, z);
	}
	dfs(1, 0);
	while (q--) {
		ll x, y; read(x, y);
		write(query(x, y), '\n');
	}
	return 0;
}