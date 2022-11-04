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

const int MX = 2005, mod = 998244353;
int n, m, k;
ll fac[MX], inv[MX], s2[MX][MX];

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
	return fac[n] * inv[k] % mod * inv[n - k] % mod;
}

void main_() {
	cin >> n >> m >> k;
	
	ll res = 0;
	ll a = (m + 1) / 2, b = m / 2;
	ll num = 1, den = 1;
	ll pa = 1;
	ll pab = pot(a + b, n), iab = pot(a + b, mod - 2);
	
	forr (i, 0, k) {
		ll p = s2[k][i];
		
		(p *= fac[i]) %= mod;
		(p *= num) %= mod;
		(p *= den) %= mod;
		(p *= pa) %= mod;
		(p *= pab) %= mod;
		(res += p) %= mod;
		
		(num *= n - i) %= mod;
		(den *= inv[i + 1]) %= mod;
		(pa *= a) %= mod;
		(pab *= iab) %= mod;
	}
	
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	fac[0] = inv[0] = 1;
	forr (i, 1, MX - 1) {
		fac[i] = i * fac[i - 1] % mod;
		inv[i] = pot(i, mod - 2);
	}
	
	forn (i, MX) {
		s2[i][1] = 1;
		s2[i][i] = 1;
		
		for (int j = 2; j < i; j++)
			s2[i][j] = (j * s2[i - 1][j] + s2[i - 1][j - 1]) % mod;
	}
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}