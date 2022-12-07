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

const int MX = 2000005, mod = 1000000007;
int n, k;
ll p3[MX];
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

ll bars_and_stars (int n, int k) {
	return comb(n + k - 1, k);
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
	cin >> n >> k;
	
	if (k == 0) {
		cout << pot(3, n) << endl;
		return;
	}
	
	ll res = 0;
	forr (i, 1, n) {
		int x = k - i;
		int y = n - k - i;
		if (x >= 0 && y >= 0) {
			(res +=
				bars_and_stars(i, x)
				* comb(i + y, i) % mod
				* p3[y] % mod
				* p3[x]
			) %= mod;
		}
		
		x = k - i;
		y = n - k - i + 1;
		if (x >= 0 && y >= 0) {
			(res +=
				bars_and_stars(i, x)
				* comb(i + y - 1, i - 1) % mod
				* p3[y] % mod
				* p3[x]
			) %= mod;
		}
	}
	
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	precalc_comb();
	
	p3[0] = 1;
	forr (i, 1, MX - 1) {
		p3[i] = (3 * p3[i - 1]) % mod;
	}
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}