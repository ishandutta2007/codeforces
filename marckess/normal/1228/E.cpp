#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 255, mod = 1000000007;
int n, k, c[MX][MX];
ll mem[MX][MX], pk[2][MX], p[MX][MX];

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
	if (n == k || k == 0) return 1;
	if (c[n][k] != -1) return c[n][k];
	return c[n][k] = (comb(n - 1, k) + comb(n - 1, k - 1)) % mod;
}

ll dp (int i, int a, int b) {
	if (i == n) return b == n;
	ll &res = mem[i][a];
	if (res != -1) return res;
	res = 0;

	for (int j = 1; j <= a; j++)
		res += comb(a, j) * p[a - j][b] % mod * dp(i + 1, a - j, b + j) % mod;

	for (int j = 0; j < b; j++)
		res += pot(k - 1, j) * p[a][b - j - 1] % mod * dp(i + 1, a, b) % mod;

	return res %= mod;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(mem, -1, sizeof(mem));
	memset(c, -1, sizeof(c));
	
	cin >> n >> k;

	for (int i = 0; i <= n; i++) {
		pk[0][i] = pot(k - 1, i);
		pk[1][i] = pot(k, i);
	}

	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			p[i][j] = pk[0][i] * pk[1][j] % mod;

	cout << dp(0, n, 0) << endl;

	return 0;
}