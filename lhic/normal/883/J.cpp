#include <bits/stdc++.h>

typedef long long ll;
typedef long long llong;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}
const int MAXN = 220000;
const ll INF = 1e18;

ll rmq[MAXN * 4];
ll dd[MAXN * 4];
ll sm[MAXN];
int n, m;
int ans;
map<ll, int> mm;

pair<ll, ll> b[MAXN];
ll a[MAXN];

void build(int v, int tl, int tr) {
	if (tl + 1 == tr) {
		rmq[v] = sm[tl];
		return;
	}
	int m = (tl + tr) >> 1;
	build(v * 2 + 1, tl, m);
	build(v * 2 + 2, m, tr);
	rmq[v] = min(rmq[v * 2 + 1], rmq[v * 2 + 2]);
}

void add(int v, int tl, int tr, int l, int r, ll d) {
	if (r <= tl || tr <= l)
		return;
	if (l <= tl && tr <= r) {
		rmq[v] += d;
		dd[v] += d;
		return;
	}
	int m = (tl + tr) >> 1;
	add(v * 2 + 1, tl, m, l, r, d);
	add(v * 2 + 2, m, tr, l, r, d);
	rmq[v] = min(rmq[v * 2 + 1], rmq[v * 2 + 2]) + dd[v];
}

ll get(int v, int tl, int tr, int l, int r) {
	if (r <= tl || tr <= l)
		return INF;
	if (l <= tl && tr <= r)
		return rmq[v];
	int m = (tl + tr) >> 1;
	return min(get(v * 2 + 1, tl, m, l, r), get(v * 2 + 2, m, tr, l, r)) + dd[v];
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%lld", a + i);
	for (int i = 0; i < m; ++i)
		scanf("%lld", &b[i].first);
	for (int i = 0; i < m; ++i)
		scanf("%lld", &b[i].second);
	sort(b, b + m);
	int cur = 0;
	for (int i = n - 1; i >= 0; --i) {
		while (cur < m && b[cur].first <= a[i]) {
			mm[b[cur].first] = i;
			++cur;
		}
	}
	sm[0] = a[0];
	for (int i = 1; i < n; ++i)
		sm[i] = sm[i - 1] + a[i];
	build(0, 0, n);
	sort(b, b + m, cmp);
	for (int i = 0; i < m; ++i) {
		if (!mm.count(b[i].first))
			continue;
		int x = mm[b[i].first];
		if (get(0, 0, n, x, n) >= b[i].second) {
			++ans;
			add(0, 0, n, x, n, -b[i].second);
		}
	}
	cout << ans << "\n";
	return 0;
}