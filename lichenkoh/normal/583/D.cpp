#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
	ios::sync_with_stdio(false);
	ll n, t;
	ll m = 0;
	cin >> n; cin >> t;
	ll *a = new ll[n+1];
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
		m = max(m, a[i]);
	}
	m++;
	ll **g = new ll*[m];
	for (ll i = 0; i < m; i++) {
		g[i] = new ll[m];
	}
	for (ll x = 0; x < m; x++) {
		for (ll y = 0; y < m; y++) {
			g[x][y] = 0;
		}
		for (ll i = 0; i < n; i++) {
			if (a[i] >= x) {
				g[x][a[i]]++;
				for (ll k = a[i]+1; k < m; k++) {
					g[x][k] = max(g[x][k], g[x][k-1]);
				}
			}
		}
	}
	// Find best x->x
	ll best = 0;
	for (ll x = 0; x < m; x++) {
		best = max(best, g[x][x]);
	}
	// Find good 1 -> 300 transition
	// All transitions used here MUST beat x->x
	ll q = min(m, t);
	ll **f = new ll*[2];
	for (ll i = 0; i < 2; i++) {
		f[i] = new ll[m];
	}
	for (ll x = 0; x < m; x++) {
		f[0][x] = 0;
	}
	for (ll k = 1; k <= q; k++) {
		ll cur = k%2;
		ll pre = (k-1)%2;
		for (ll x = 0; x < m; x++) {
			f[cur][x] = 0;
		}
		for (ll x = 0; x < m; x++) {
			for (ll y = x; y < m; y++) {
				f[cur][y] = max(f[cur][y], f[pre][x] + max(g[x][y], best));
			}
		}
		for (ll x = 1; x < m; x++) {
			f[cur][x] = max(f[cur][x], f[cur][x-1]);
		}
	}
	ll ans = f[q%2][m-1] + (t-q) * best;
	cout << ans << endl;
}