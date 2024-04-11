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

const int MX = 255, mod = 998244353;
int n, k;
ll fac[MX], inv[MX], mem[MX][MX];

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

ll dp (int i, int j) {
	if (i == n) return 1;
	if (j > k) return 0;
	
	ll &res = mem[i][j];
	if (res != -1) return res; 
	res = 0;
	
	for (int x = 0; x <= n - i; x++)
		(res += 
			comb(n - i, x) * 
			pot(k - j + 1, i * x + x * (x - 1) / 2) % mod *
			dp(i + x, j + 1)
		) %= mod;
	
	return res;
}

void main_() {
	cin >> n >> k;
	memset(mem, -1, sizeof(mem));
	n--;
	cout << dp(0, 1) << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	fac[0] = inv[0] = 1;
	for (int i = 1; i < MX; i++) {
		fac[i] = fac[i - 1] * i % mod;
		inv[i] = pot(fac[i], mod - 2);
		assert(fac[i] * inv[i] % mod == 1);
	}
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}