#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 5005, mod = 998244353;
int n;
ll fac[MX], inv[MX], mem[MX][MX];

ll pot (ll b, int p) {
	ll res = 1;
	while (p) {
		if (p & 1) (res *= b) %= mod;
		(b *= b) %= mod;
		p /= 2;
	}
	return res;
}

ll dp (int n, int k) {
	if (k == 1) return 1;
	if (n == 0) return 0;

	ll &res = mem[n][k];
	if (res != -1) return res;

	return res = (k * dp(n - 1, k) + (n - k + 1) * dp(n - 1, k - 1)) % mod;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(mem, -1, sizeof(mem));

	fac[0] = inv[0] = 1;
	for (int i = 1; i < MX; i++) {
		fac[i] = i * fac[i - 1] % mod;
		inv[i] = pot(fac[i], mod - 2);
	}

	cin >> n;

	for (int i = 1; i <= n; i++) {
		ll res = 0;

		for (int j = i; j <= n; j++)
			(res += dp(j, i) * fac[n] % mod * inv[j]) %= mod;

		cout << MOD(res, mod) << " ";
	}
	cout << endl;

	return 0;
}