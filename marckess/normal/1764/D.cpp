#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % abs(k)) + abs(k) ) % abs(k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 5005;
int n, mod;
ll fac[MX], inv[MX], inv_fac[MX];

ll pot (ll b, int p) {
	ll res = 1;
	while (p) {
		if (p & 1) (res *= b) %= mod;
		(b *= b) %= mod;
		p /= 2;
	}
	return res;
}

ll comb (int n, int k) {
	if (n < 0 || k < 0 || n < k) return 0;
	return fac[n] * inv_fac[k] % mod * inv_fac[n - k] % mod;
}

void precalc_comb () {
	fac[0] = inv[0] = 1;
	forr (i, 1, MX - 1) {
		fac[i] = fac[i - 1] * i % mod;
	}
	
	inv[0] = inv[1] = 1;
	forr (i, 2, MX - 1) {
		inv[i] = inv[mod % i] * (mod - mod / i) % mod;
	}
	
	inv_fac[0] = 1;
	forr (i, 1, MX - 1) {
		inv_fac[i] = inv_fac[i - 1] * inv[i] % mod;
	}
}

void main_() {
	cin >> n >> mod;
	precalc_comb();
	
	ll res = 0;
	for (int i = n / 2 + 1; i <= n; i++) {
		int x = i - 1;
		int y = max(0, n - x - 2);
		int z = 0;
		
		for (int j = 1; j <= x; j++)
			if ((j - 0) < n / 2 + 1 && (i - j) < n / 2 + 1)
				z++;
		
		for (int j = 0; j <= y; j++) {
			ll p = z * n;
			(p *= comb(y, j)) %= mod;
			(p *= fac[x - 1 + j]) %= mod;
			(res += p) %= mod;
		}
	}
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}