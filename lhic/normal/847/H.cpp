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

const ll INF = 1e18;

int n;
ll a[120000];
pair<ll, ll> gl[120000];
pair<ll, ll> gr[120000];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%lld", a + i);
	gl[0] = make_pair(a[0], 0);
	for (int i = 1; i < n; ++i) {
		int go = max(a[i], gl[i - 1].first + 1);
		gl[i] = make_pair(go, gl[i - 1].second + go - a[i]);
	}
	gr[n - 1] = make_pair(a[n - 1], 0);
	for (int i = n - 2; i >= 0; --i) {
		int go = max(a[i], gr[i + 1].first + 1);
		gr[i] = make_pair(go, gr[i + 1].second + go - a[i]);
	}
	ll ans = INF;
	for (int i = 0; i < n; ++i) {
		ans = min(ans, gl[i].second + gr[i].second - (gl[i].first - a[i]) - (gr[i].first - a[i]) + max(gl[i].first, gr[i].first) - a[i]);
	}
	cout << ans << "\n";
	return 0;	
}