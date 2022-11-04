#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 2005, mod = 998244353;

int n, k, l;
ll mem[2*MX][MX][2];

ll pot (ll b, int p) {
	ll res = 1;
	while (p) {
		if (p & 1) (res *= b) %= mod;
		(b *= b) %= mod;
		p /= 2;
	}
	return res;
}

ll dp (int i, int j, int f) {
	if (j > n) return 0;
	if (i == 2 * n + 1) return f && !j;

	ll &res = mem[i][j][f];
	if (res != -1) return res;
	
	res = dp(i+1, j+1, f);
	if (j) res += j * dp(i+1, j-1, f);
	if (j >= k && !f) res += dp(i+1, j, 1);

	return res %= mod;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k >> l;

	memset(mem, -1, sizeof(mem));
	ll p = dp(0, 0, 0);
	k = 0;
	memset(mem, -1, sizeof(mem));
	ll q = dp(0, 0, 0);

	cout << l * p % mod * pot(q, mod - 2) % mod << endl;

	return 0;
}