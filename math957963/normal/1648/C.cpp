#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N 200100
#define MOD 998244353
#define ll long long
#define rep(i, n) for(ll i = 0; i < n; ++i)
#define rep2(i, a, b) for(int i = a; i <= b; ++i)
#define rep3(i, a, b) for(int i = a; i >= b; --i)
#define eb emplace_back
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>
struct Setup_io {
	Setup_io() {
		ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
		cout << fixed << setprecision(15);
	}
} setup_io;

int F[N];

bool b[30];
ll k[N];
ll r[N];
ll rk[N];

void init(void){
	rep(i, N)F[i] = 0;
	return;
}

void Fplus(int k) {
	while (k < N) {
		F[k]++;
		k += (k&-k);
	}
	return;
}

void Fminus(int k) {
	while (k < N) {
		F[k]--;
		k += (k&-k);
	}
	return;
}

int sum(int k) {
	int s = 0;
	while (k > 0) {
		s += F[k];
		k -= (k&-k);
	}
	return s;
}

int s[N];

int main() {
	int n, m, x, y;
	ll z, zz;

	x = MOD - 2;
	rep(i, 30) {
		if (x % 2 == 1)b[i] = true;
		x /= 2;
	}
	r[0] = 0;
	r[1] = 1;
	rep2(i, 2, N - 1) {
		r[i] = 1LL;
		z = i;
		rep(j, 30) {
			if (b[j])r[i] = (r[i] * z) % MOD;
			z = (z*z) % MOD;
		}
	}

	k[0] = 1;
	rep(i, N - 1)k[i + 1] = (k[i] * (i + 1)) % MOD;
	rk[0] = 1;
	rep(i, N - 1)rk[i + 1] = (rk[i] * r[i + 1]) % MOD;

	rep(i, N)s[i] = 0;
	init();

	cin >> n >> m;
	z = k[n];
	rep(i, n) {
		cin >> x;
		s[x]++;
		z = (z*r[s[x]]) % MOD;
		Fplus(x);
	}
	ll ans = 0;
	rep(i, m) {
		if (i == n) {
			ans = (ans + z) % MOD;
			break;
		}
		cin >> x;
		y = sum(x - 1);
		zz = (z*r[n - i])%MOD;
		zz = (zz*y) % MOD;
		ans = (ans + zz) % MOD;
		
		y = sum(x) - y;
		if (y == 0)break;
		z = (z*r[n - i]) % MOD;
		z = (z*y) % MOD;
		Fminus(x);	
	}

	cout << ans << endl;

	return 0;
}