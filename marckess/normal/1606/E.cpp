
// Problem : E. Arena
// Contest : Codeforces - Educational Codeforces Round 116 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1606/problem/E
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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

const int MX = 505, mod = 998244353;
int n, x;
ll mem[MX][MX], fac[MX], inv[MX], p[MX][MX];

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

ll dp (int i, int j) {
	if (j > x) return 0;
	
	ll &res = mem[i][j];
	if (res != -1) return res;
	res = i == n;
	 
	for (int a = 0; a <= n - i; a++)
		(res += p[i + a - 1][a] * comb(n - i, a) % mod * dp(i + a, j + (i + a - 1))) %= mod;
	
	return res;
} 

void main_() {
	cin >> n >> x;
	
	memset(mem, -1, sizeof(mem));
	
	ll res = 0;
	for (int i = 2; i <= n; i++)
		for (int j = 1; j <= i - 1; j++)
			(res += (p[j][i] - p[j - 1][i]) * comb(n, i) % mod * dp(i, j)) %= mod;
	
	cout << MOD(res, mod) << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	fac[0] = inv[0] = 1;
	for (int i = 1; i < MX; i++) {
		fac[i] = fac[i - 1] * i % mod;
		inv[i] = pot(fac[i], mod - 2);
		assert(fac[i] * inv[i] % mod == 1);
	}
	
	forn (i, MX) {
		p[i][0] = 1;
		for (int j = 1; j < MX; j++)
			p[i][j] = p[i][j - 1] * i % mod;
	}
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}