#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = (a); i <= (b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 500005, mod = 998244353;
int n, k, m, to[MX], l[MX], r[MX], x[MX];
ll acu[MX], dp[MX], p[MX], fc[MX], res = 1;

ll solve (int k) {
	memset(to, 0, sizeof(to));
	memset(acu, 0, sizeof(acu));

	for (int i = 0; i < m; i++)
		if (x[i] & (1 << k)) {
			acu[l[i]]++;
			acu[r[i] + 1]--;
		} else {
			to[r[i]] = max(to[r[i]], l[i]);
		}

	for (int i = 1; i <= n; i++) {
		acu[i] += acu[i - 1];
		acu[i - 1] = bool(acu[i - 1]);
	}

	acu[n] = bool(acu[n]);
	for (int i = 1; i <= n; i++)
		acu[i] += acu[i - 1];

	dp[0] = 1;
	int mx = 0;
	
	for (int i = 1; i <= n; i++) {
		fc[i] = (fc[i - 1] + (acu[i] - acu[i - 1] ? 0 : dp[i - 1])) % mod;

		if (!to[i] || mx >= to[i]) {
			dp[i] = (2 - (acu[i] - acu[i - 1])) * dp[i - 1] % mod;
		} else {
			dp[i] = (fc[i] - fc[to[i] - 1]) % mod;
			mx = max(mx, to[i]);
		}
	}

	return dp[n];
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	p[0] = 1;
	for (int i = 1; i < MX; i++)
		p[i] = 2 * p[i - 1] % mod;

	cin >> n >> k >> m;
	forn (i, m) cin >> l[i] >> r[i] >> x[i];

	while (k--)
		(res *= solve(k)) %= mod;
	cout << MOD(res, mod) << endl;

	return 0;
}