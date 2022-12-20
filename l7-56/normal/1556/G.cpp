#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <ll> vl;
#define fir first
#define sec second

const int maxn = 3e6 + 10, maxm = 2e7 + 10;
ll n, m, N, d, fa[maxn], siz[maxn], ans[maxn];
bitset <maxn> vis;
ll get(ll x) { return x == fa[x] ? x : fa[x] = get(fa[x]); }
void merge(ll x, ll y) {
	x = get(x), y = get(y);
	if (x == y) return;
	if (siz[x] > siz[y]) swap(x, y);
	siz[y] += siz[x], fa[x] = y;
}
struct node {
	ll op, l, r;
} a[maxn];
vl X;
vi e[maxn];

struct SegTree {
	int ls[maxm], rs[maxm], tot;
	#define mid ((l + r) >> 1)
	void update(int &o, ll l, ll r, ll L, ll R) {
		if (L > r || R < l) return;
		if (!o) o = ++tot;
		if (L <= l && r <= R) return;
		update(ls[o], l, mid, L, R), update(rs[o], mid + 1, r, L, R);
	}
	void solve(int o, ll l, ll r) {
		if (!o) return;
		if (!ls[o]) X.push_back(l);
		if (!rs[o]) X.push_back(r + 1);
		solve(ls[o], l, mid), solve(rs[o], mid + 1, r);
	}
} tr;

int main() {
	scanf("%lld%lld", &n, &m), N = (1ll << n) - 1;
	int rt = 0;
	for (int i = 1; i <= m; ++i) {
		char opt[10]; ll l, r; scanf("%s%lld%lld", opt, &l, &r);
		a[i].op = (opt[0] == 'b'), a[i].l = l, a[i].r = r;
	}
	while (a[m].op) --m;
	for (int i = 1; i <= m; ++i) if (a[i].op) tr.update(rt, 0, N, a[i].l, a[i].r);
	tr.solve(rt, 0, N);
	sort(begin(X), end(X)), X.erase(unique(begin(X), end(X)), end(X)), d = X.size();
	auto ask = [&] (ll x) { return upper_bound(begin(X), end(X), x) - begin(X) - 1; };
	vis.reset();
	for (int i = 0; i < d - 1; ++i) {
		ll len = X[i + 1] - X[i];
		for (int j = 0; j < n; ++j) {
			if ((1ll << j) < len) continue;
			int v = ask(X[i] ^ (1ll << j));
			if (!vis[v]) e[i].push_back(v), e[v].push_back(i), vis[v] = 1;
			v = ask((X[i + 1] - 1) ^ (1ll << j));
			if (!vis[v]) e[i].push_back(v), e[v].push_back(i), vis[v] = 1;
		}
		for (int v : e[i]) vis[v] = 0;
	}
	// for (int i = 0; i < d - 1; ++i) {
	// 	printf("#%d [%lld, %lld]\n", i, X[i], X[i + 1] - 1);
	// 	for (int v : calc(i)) printf("%d ", v);
	// 	printf("\n");
	// }
	vis.set();
	for (int i = 1; i <= m; ++i) {
		a[i].l = ask(a[i].l), a[i].r = ask(a[i].r);
		if (a[i].op)
			for (int j = a[i].l; j <= a[i].r; ++j) vis[j] = 0;
	}
	iota(fa, fa + d, 0), fill(siz, siz + d, 1);
	for (int i = 0; i < d - 1; ++i) if (vis[i])
		for (int v : e[i]) if (vis[v]) merge(i, v);
	for (int i = m; i >= 1; --i)
		if (a[i].op) {
			for (int j = a[i].l; j <= a[i].r; ++j) vis[j] = 1;
			for (int j = a[i].l; j <= a[i].r; ++j)
				for (int v : e[j]) if (vis[v]) merge(j, v);
		}
		else ans[i] = (get(a[i].l) == get(a[i].r));
	for (int i = 1; i <= m; ++i) if (!a[i].op) printf("%lld\n", ans[i]);
	return 0;
}