#ifndef LOCAL
#pragma GCC optimize "-O3"
#endif
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

const int MAXN = 1e6 + 100;

int p[MAXN];
int sz[MAXN];
int en[MAXN];

vector<int> eds[MAXN];

vector<pair<ll, int> > vv;

ll a[MAXN];

int n;

int get(int a) {
	if (a == p[a])
		return a;
	return p[a] = get(p[a]);
}

void un(int a, int b) {
	a = get(a);
	b = get(b);
	if (a == b)
		return;
	if (sz[a] > sz[b])
		swap(a, b);
	sz[b] += sz[a];
	p[a] = b;
}

ll ans;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%lld", a + i);
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a, --b;
		eds[a].push_back(b);
		eds[b].push_back(a);
	}
	for (int i = 0; i < n; ++i)
		vv.push_back(make_pair(a[i], i));
	sort(vv.begin(), vv.end());
	for (int i = 0; i < n; ++i)
		sz[i] = 1, p[i] = i, en[i] = 0;
	for (int i = 0; i < n; ++i) {
		int x = vv[i].second;
		ll cnt = 1;
		en[x] = 1;
		for (int u: eds[x]) {
			if (en[u]) {
				u = get(u);
				ans += vv[i].first * cnt * sz[u];
				cnt += sz[u];
				un(u, x);
			}
		}
	}
	reverse(vv.begin(), vv.end());
	for (int i = 0; i < n; ++i)
		sz[i] = 1, p[i] = i, en[i] = 0;
	for (int i = 0; i < n; ++i) {
		int x = vv[i].second;
		ll cnt = 1;
		en[x] = 1;
		for (int u: eds[x]) {
			if (en[u]) {
				u = get(u);
				ans -= vv[i].first * cnt * sz[u];
				cnt += sz[u];
				un(u, x);
			}
		}
	}
	cout << ans << "\n";
	return 0;
}