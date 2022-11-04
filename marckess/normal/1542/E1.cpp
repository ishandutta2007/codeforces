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

const int MX = 55;
int n, mod, c[MX][MX];
ll fac[MX];
int mem[MX][MX][2 * MX * MX][2];

int comb (int n, int k) {
	if (n < 0 || k < 0 || k > n) return 0;
	if (n == 0) return 1;
	
	int &res = c[n][k];
	if (res != -1) return res;
	
	res = comb(n - 1, k) + comb(n - 1, k - 1);
	if (res >= mod)
		res -= mod;
	
	return res;
}

void sum (int &a, int b) {
	a += b;
	if (a >= mod)
		a -= mod;
}

ll dp (int i, int j, int k, int f) {
	if (!i) return f && k > MX * MX;
	
	int &res = mem[i][j][k][f];
	if (res != -1) return res;
	res = 0;
	
	// delta 0
	sum(res, dp(i - 1, j + 1, k, 0));
	sum(res, (j - 1) * dp(i - 1, j + 1, k, f) % mod);
	
	for (int d = 1; d < j; d++) {
		// delta pos
		sum(res, dp(i - 1, j + 1, k + d, 0));
		sum(res, (j - d - 1) * dp(i - 1, j + 1, k + d, f) % mod);
		
		// delta neg
		sum(res, dp(i - 1, j + 1, k - d, 1));
		sum(res, (j - d - 1) * dp(i - 1, j + 1, k - d, f) % mod);
	}
	
	return res;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	memset(c, -1, sizeof(c));
	memset(mem, -1, sizeof(mem));
	
	cin >> n >> mod;
	
	fac[0] = 1;
	for (int i = 1; i < MX; i++)
		fac[i] = i * fac[i - 1] % mod;
	
	ll res = 0;
	forn (i, n)
		(res += comb(n, i) * fac[i] % mod * dp(n - i, 1, MX * MX, 0)) %= mod;
	cout << res << endl;
	
	return 0;
}