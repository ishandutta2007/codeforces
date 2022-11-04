// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
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

const int MX = 1000005, mod = 1000000007;
ll n, m, k, fac[MX], inv[MX];

ll pot (ll b, int p) {
	p = MOD(p, mod);
	
	ll res = 1;
	while (p) {
		if (p & 1) (res *= b) %= mod;
		(b *= b) %= mod;
		p /= 2;
	}
	return res;
}

ll comb (ll n, ll k) {
	if (n < 0 || k < 0 || n < k) return 0;
	return fac[n] * inv[k] % mod * inv[n - k] % mod;
}

void main_() {
	cin >> n >> m >> k;
	
	if (n == m) {
		cout << k * n % mod << endl;
		return;
	}
	
	ll res = 0;
	for (int i = 1; i <= m; i++)
		(res += pot(2, i - 1) * i % mod * comb(n - i - 1, m - i)) %= mod;
	cout << MOD(k * res % mod * pot(2, -n) % mod, mod) << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	fac[0] = inv[0] = 1;
	for (int i = 1; i < MX; i++) {
		fac[i] = i * fac[i - 1] % mod;
		inv[i] = pot(fac[i], mod - 2);
	}
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}