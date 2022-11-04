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
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 201, mod = 1000000007;
int n, k, mem[401][401][MX][2], res[MX];

ll dp (int x, int j, int c, int f) {
	if (j < 0 || c < 0) return 0;
	if (x == 0) return j == 0 && c == 0 && f == 1;
	
	int &res = mem[x][j][c][f];
	if (res != -1) return res;
	res = 0;
	
	if (f == 1) {
		res = (j * dp(x, j - 1, c, 0) + dp(x - 1, j + 1, c, 1)) % mod;
		return res;
	}
	
	res = (dp(x - 1, j, c - 1, 1) + j * dp(x, j - 1, c, 0)) % mod;
	
	return res;
}

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
	k = min(k, n - k);
	
	ll p = 1, q = 1;
	for (int i = 1; i <= k; i++) {
		(p *= n - i + 1) %= mod;
		(q *= i) %= mod;
	}
	
	return p * pot(q, mod - 2) % mod;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(mem, -1, sizeof(mem));
	
	cin >> n >> k;
	
	for (int i = 0; i <= k; i++) {
		ll x = 0;
		
		int t = n - i;
		if (t <= 0)
			break;
			
		for (int j = i; j <= 2 * i; j++)
			(x += comb(n, j) * dp(j, 0, j - i, 1)) %= mod;
		
		res[i] = x;
	}
	
	for (int i = 1; i <= k; i++) {
		if (i - 2 >= 0)
			(res[i] += res[i - 2]) %= mod;
		cout << res[i] << " ";
	}
	cout << endl;
	
	return 0;
}