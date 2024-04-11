#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <ll, ll> pii;

template <typename __Tp> void read(__Tp &x) {
	ll f = 0; x = 0; char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = 1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	if (f) x = -x;
}

const ll maxn = 2e5 + 10, maxa = 1e7 + 10, maxk = 30;
ll v[maxa],p[maxa],cntp;
void prework() {
	v[1] = 1;
	for (ll i = 2; i <= 10000000; ++i) {
		if (!v[i]) v[i] = i, p[++cntp] = i;
		for (ll j = 1; j <= cntp; ++j) {
			if (i * p[j] > 10000000 || p[j] > v[i]) break;
			v[i * p[j]] = p[j];
		}
	}
}

ll n,k,d,a[maxn],cnt[maxn],nxt[maxn][maxk],f[maxn][maxk];
vector <ll> A;

void work() {
	A.clear();
	read(n), read(k);
	for (ll i = 1; i <= n; ++i) {
		read(a[i]);
		ll t = 1;
		while (a[i] > 1) {
			ll x = v[a[i]];
			if (t % x == 0) t /= x;
			else t *= x;
			a[i] /= x;
		}
		a[i] = t;
		A.push_back(t);
	}
	sort(A.begin(), A.end());
	A.erase(unique(A.begin(), A.end()), A.end());
	d = A.size();
	for (ll i = 1; i <= n; ++i) a[i] = lower_bound(A.begin(), A.end(), a[i]) - A.begin() + 1;
	a[n + 1] = 0;
	for (ll j = 0; j <= k; ++j) {
		for (ll i = 1; i <= d; ++i) cnt[i] = 0;
		for (ll l = 1, r = 0, sum = 0; l <= n; ++l) {
			while (r <= n && sum <= j) {
				if (cnt[a[++r]]) sum++;
				++cnt[a[r]];
			}
			nxt[l][j] = r - 1;
			--cnt[a[l]];
			if (cnt[a[l]]) sum--;
		}
	}
	for (ll i = 1; i <= n; ++i)
		for (ll j = 0; j <= k; ++j)
			f[i][j] = n;
	f[0][0] = 0;
	for (ll i = 0; i < n; ++i)
		for (ll j = 0; j <= k; ++j)
			for (ll c = 0; j + c <= k; ++c)
				f[nxt[i + 1][c]][j + c] = min(f[nxt[i + 1][c]][j + c], f[i][j] + 1);
	ll ans = n;
	for (ll j = 0; j <= k; ++j) ans = min(ans, f[n][j]);
	printf("%lld\n", ans);
}

int main() {
//	freopen("seq.in", "r", stdin), freopen("seq.out", "w", stdout);
	prework();
	ll t; read(t);
	while (t--) work();
	return 0;
}