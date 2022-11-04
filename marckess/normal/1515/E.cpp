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

const int MX = 405;
int n, mod;
ll fac[MX], inv[MX], mem[MX][MX], p2[MX];

ll pot (ll b, int p) {
	ll res = 1;
	while (p) {
		if (p & 1) (res *= b) %= mod;
		(b *= b) %= mod;
		p /= 2;
	}
	return res;
}

ll dp (int i, int j) {
	if (i == n) return 0;
	if (i == n + 1) return j == 0;
	if (i > n + 1) return 0;
	
	ll &res = mem[i][j];
	if (res != -1) return res;
	res = 0;
	
	for (int k = 1; k <= j; k++) {
		ll f = inv[k] * p2[k - 1] % mod * dp(i + k + 1, j - k) % mod;
		
		res += f;
		if (res >= mod)
			res -= mod;
	}
	
	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> mod;
	
	fac[0] = inv[0] = p2[0] = 1;
	for (int i = 1; i < MX; i++) {
		fac[i] = fac[i - 1] * i % mod;
		inv[i] = pot(fac[i], mod - 2);
		p2[i] = p2[i - 1] * 2 % mod;
	}
	
	memset(mem, -1, sizeof(mem));
	
	ll res = 0;
	for (int i = 1; i <= n; i++)
		(res += fac[i] * dp(0, i)) %= mod;
	cout << res << endl;
		
	return 0;
}