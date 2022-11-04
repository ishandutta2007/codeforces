#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005, mod = 1e9 + 7;
int n, m, k, a[MX];
ll fac[MX], inv[MX], res;

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

void solve () {
	cin >> n;
	k = 2;
	m = 3;
	
	forn (i, n)
		cin >> a[i];
	sort(a, a + n);
	
	if (m == 1) {
		cout << n << endl;
		return;
	}
	
	res = 0;
	int i = 0, j = 0;
	
	while (i < n) {
		while (j < n && a[j] - a[i] <= k)
			j++;
		ll x = j - i - 1;
		if (x >= 2)
			res += x * (x - 1) / 2;
		i++;
	}	
	
	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	fac[0] = inv[0] = 1;
	for (int i = 1; i < MX; i++) {
		fac[i] = fac[i - 1] * i % mod;
		inv[i] = pot(fac[i], mod - 2);
	}
	
	int t;
	cin >> t;
	while (t--)
		solve();	
	
	return 0;
}