#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO
#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i < (r); ++i)

#ifdef FASTIO
#define scanf abacaba
#define printf abacaba
#endif

typedef long long ll;
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
const int MAXN = 410000;
int n, m;
int a[MAXN];
int b[MAXN];
int c[MAXN];
int d[MAXN];
int z1[MAXN];
int z2[MAXN];

void zf(int *a, int n, int *z) {
	int l = 0, r = 0;
	z[0] = 0;
	for (int i = 1; i < n; ++i) {
		if (i < r)
			z[i] = min(r - i, z[i - l]);
		else
			z[i] = 0;
		while (i + z[i] < n && a[i + z[i]] == a[z[i]])
			++z[i];
		if (i + z[i] > r)
			r = i + z[i], l = i;
	}
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a, a + n);
	ll tmp = a[0];
	for (int i = 0; i < n; ++i)
		a[i] -= tmp;
	a[n] = m;
	for (int i = 0; i < n; ++i)
		b[i] = a[i + 1] - a[i];
	for (int i = 0; i < n; ++i)
		c[i] = b[i];
	for (int i = 0; i < n; ++i)
		c[n + i] = b[n - 1 - i];
	zf(c, 2 * n, z1);
	for (int i = 0; i < n; ++i)
		d[i] = c[n + i];
	for (int i = 0; i < n; ++i)
		d[i + n] = c[i];
	zf(d, 2 * n, z2);
	vector<ll> ans;
	for (int i = 0; i < n; ++i) {
		if (z1[n + n - i] >= i && z2[n + i] >= n - i)
			ans.push_back((a[i] + 2 * tmp) % m);
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	if (ans.size()) {
		for (ll i: ans)
			cout << i << " ";
		cout << "\n";
	}
	return 0;
}