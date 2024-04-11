#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const ll maxn = 1e5 + 10, maxk = 20, N = 100000, inf = 4e18;
ll v[maxn],pr[maxn],cntp,phi[maxn],sphi[maxn];
ll c(ll L, ll R) {
	ll res = 0;
	for (ll r; L <= R; L = r + 1) {
		r = min(R, R / (R / L));
		res += sphi[R / L] * (r - L + 1);
	}
	// printf("[%lld, %lld] %lld\n", L, R, res);
	return res;
}
ll f[maxn][maxk];
void solve(ll l, ll r, ll L, ll R, ll j) {
	if (l > r) return;
	ll mid = (l + r) >> 1, pos = 0, &val = f[mid][j] = inf, cst = c(R + 1, mid);
	for (ll i = min(R, mid); i >= L; --i) {
		cst += sphi[mid / i];
		if (val > f[i - 1][j - 1] + cst)
			val = f[i - 1][j - 1] + cst, pos = i;
	}
	solve(l, mid - 1, L, pos, j), solve(mid + 1, r, pos, R, j);
}
void prework() {
	v[1] = phi[1] = sphi[1] = 1;
	for (ll i = 2; i <= N; ++i) {
		if (!v[i]) v[i] = i, pr[++cntp] = i, phi[i] = i - 1;
		sphi[i] = sphi[i - 1] + phi[i];
		for (ll j = 1; j <= cntp; ++j) {
			if (i * pr[j] > N || v[i] < pr[j]) break;
			v[i * pr[j]] = pr[j];
			if (i % pr[j] == 0) phi[i * pr[j]] = phi[i] * pr[j];
			else phi[i * pr[j]] = phi[i] * (pr[j] - 1);
		}
	}
	for (ll i = 1; i <= N; ++i) f[i][1] = (i + 1) * i / 2;
	for (ll j = 2; j <= 17; ++j) solve(1, N, 1, N, j);
}

void work() {
	ll n, k;
	scanf("%lld%lld", &n, &k);
	if (k > 17 || (1 << k) > n) return printf("%lld\n", n), void();
	printf("%lld\n", f[n][k]);
}

int main() {
	prework();
	ll t; scanf("%lld", &t);
	while (t--) work();
	return 0;
}