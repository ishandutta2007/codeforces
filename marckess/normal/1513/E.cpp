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
int n, a[MX];
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
	return fac[n] * inv[k] % mod * inv[n - k] % mod;
}

void solve () {
	cin >> n;
	
	ll sum = 0;
	forn (i, n) {
		cin >> a[i];
		sum += a[i];
	}
	
	if (sum % n) {
		cout << 0 << endl;
		return;
	}
	
	int x = 0, y = 0, z = 0;
	forn (i, n) {
		if (a[i] < sum / n) x++;
		else if (a[i] > sum / n) y++;
		else z++;
	}
	
	ll res = 0;
	if (x < 2 || y < 2) {
		res = fac[n];
	} else {
		res = 2 * comb(n, z) % mod * fac[x] % mod * fac[y] % mod * fac[z] % mod;
	}
	
	map<int, int> mp;
	forn (i, n)
		mp[a[i]]++;
	
	for (auto it : mp)
		(res *= inv[it.se]) %= mod;
	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	fac[0] = inv[0] = 1;
	for (int i = 1; i < MX; i++) {
		fac[i] = fac[i - 1] * i % mod;
		inv[i] = pot(fac[i], mod - 2);
		assert(fac[i] * inv[i] % mod == 1);
	}
	
	int t = 1;
	//cin >> t;
	while (t--)
		solve();

	return 0;
}