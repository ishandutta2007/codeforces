#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const ll maxn = 3010;
ll n,ans;
struct Edge {
	ll v, nxt;
}e[maxn << 2];
ll h[maxn], cnt_e;
void add(ll x, ll y) { e[++cnt_e] = {y, h[x]}, h[x] = cnt_e; }
bitset <maxn> vis;
ll a[maxn],tot;

void dfs(ll u) {
	a[++tot] = u, vis[u] = 1;
	for (ll j = h[u]; j; j = e[j].nxt) {
		ll v = e[j].v;
		if (vis[v]) continue;
		dfs(v);
	}
}

ll calc(ll l, ll r, ll f1, ll f2) {
	if (f1 > f2) swap(f1, f2);
	if (l <= f1 && f1 <= r) return 0;
	if (l <= f2 && f2 <= r) return 0;
	if (l > r) {
		ll res = 0;
		if (f1 > 1) res += f1 * (f1 - 1) / 2;
		if (f2 > f1 + 1) res += (f2 - f1) * (f2 - f1 - 1) / 2;
		if (n > f2) res += (n - f2 + 1) * (n - f2) / 2;
		return res;
	}
	else {
		ll val1 = l, val2 = n - r + 1;
		if (f2 < l) val1 = l - f2;
		else if (f1 < l) val1 = l - f1, val2 = f2 - r;
		else val2 = f1 - r;
		return val1 * val2;
	}
}

ll calc() {
	// for (ll i = 1; i <= n; ++i) printf("%lld%c", a[i], " \n"[i == tot]);
	ll res = 0;
	for (ll i = 1; i <= tot; ++i) {
		ll lp = i, rp = i, L = n + n + 1, R = n, l = n + 1, r = 0;
		for (ll tim = 1; tim <= tot / 2; ++tim) {
			if (a[lp] > n) L = min(L, min(a[lp], a[rp])), R = max(R, max(a[lp], a[rp]));
			else l = min(l, min(a[lp], a[rp])), r = max(r, max(a[lp], a[rp]));
			--lp, ++rp;
			if (lp < 1) lp += tot;
			if (rp > tot) rp -= tot;
			if (a[lp] > n) res += calc(L - n, R - n, a[lp] - n, a[rp] - n) * calc(l, r, 0, n + 1);
			else res += calc(l, r, a[lp], a[rp]) * calc(L - n, R - n, 0, n + 1);
		}
	}
	return res;
}

int main() {
	scanf("%lld", &n);
	for (ll i = 1; i <= n + n; ++i) {
		ll x, y; scanf("%lld%lld", &x, &y);
		add(x, y), add(y, x);
	}
	for (ll i = 1; i <= n; ++i) ans += i * (n - i + 1) * (n + 1) * n;
	for (ll i = 1; i <= n; ++i)
		if (!vis[i]) tot = 0, dfs(i), ans -= calc();
	printf("%lld\n", ans / 2);
	return 0;
}