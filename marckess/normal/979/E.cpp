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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 55, mod = 1000000007;
int n, p, c[MX];
ll mem[MX][MX][MX][MX], p2[MX], res;

ll dp (int idx, int i, int j, int k, int l) {
	if (!idx) return 1;

	ll &res = mem[idx][i][j][k];
	if (res != -1) return res;
	res = 0;

	if (c[idx] != 1) {
		if (i && l) res += dp(idx - 1, i - 1, j, k, l) * p2[i + j - 1] % mod * p2[k] % mod * p2[l - 1]         % mod;
		if (j) 		res += dp(idx - 1, i, j - 1, k, l) * p2[i + j - 1] % mod * p2[k] % mod * p2[max(0, l - 1)] % mod;
	}

	if (c[idx] != 0) {
		if (k && j) res += dp(idx - 1, i, j, k - 1, l) * p2[k + l - 1] % mod * p2[i] % mod * p2[j - 1]         % mod;
		if (l) 		res += dp(idx - 1, i, j, k, l - 1) * p2[k + l - 1] % mod * p2[i] % mod * p2[max(0, j - 1)] % mod;
	}

	return res %= mod;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(mem, -1, sizeof(mem));

	p2[0] = 1;
	for (int i = 1; i < MX; i++) 
		p2[i] = 2 * p2[i - 1] % mod;

	cin >> n >> p;
	forn (i, n) cin >> c[i + 1];

	forn (i, n + 1) forn (j, n + 1) forn (k, n + 1) forn (l, n + 1)
		if (i + j + k + l == n && (j + l) % 2 == p)
			(res += dp(n, i, j, k, l)) %= mod;

	cout << res << endl;

	return 0;
}