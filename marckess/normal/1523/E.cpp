#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005, mod = 1000000007;
ll fac[MX], inv[MX];

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
	if (n < 0 || k < 0 || k > n) return 0;
	return fac[n] * inv[k] % mod * inv[n - k] % mod;
}

ll res;
int n, k;

ll sum (ll n, ll k) {
	if (n < 0 || k < 0)
		return 0;
	if (n == 0)
		return 1;
	if (k == 0)
		return 0;
	
	return comb(n + k - 1, n);
}

void solve () {
	cin >> n >> k;
	res = 1;
	
	ll x = 1;
	for (int i = 1; i <= n; i++) {
		int a = n - i;
		int b = i + 1;
		ll p = 0;
		
		p = sum(a - 1ll * (b - 2) * (k - 1), b);
		(x *= i * pot(n - i + 1, mod - 2) % mod) %= mod;
		(res += p * x) %= mod; 
	}
	
	cout << MOD(res, mod) << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	fac[0] = inv[0] = 1;
	for (int i = 1; i < MX; i++) {
		fac[i] = fac[i - 1] * i % mod;
		inv[i] = pot(fac[i], mod - 2);
	}
	
	int t = 1;
	cin >> t;
	while (t--)
		solve();
 
	return 0;
}