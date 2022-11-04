#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define FORR(i,a,b) for (int i = a; i <= b; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 2e6+5, mod = 1e9+7;
int n, k, res = 0;
ll dp[MX], acu = 0;
vi a[MX];

ll pot (ll b, int p) {
	ll res = 1;
	while (p) {
		if (p & 1) res = res * b % mod;
		b = b * b % mod;
		p /= 2;
	}
	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k;
	
	for (ll i = 2; i <= k; i++)
		for (ll j = i * i; j <= k; j += i)
			a[j].pb(i);

	for (int i = 1; i <= k; i++) {
		for (int x : a[i]) {
			int y = i / x;

			acu -= dp[x-1];
			if (x != y) acu -= dp[y-1];

			acu += dp[x];
			if (x != y) acu += dp[y];
		}

		if (i > 1) acu++;
		acu = MOD(acu, mod);

		dp[i] = pot(i, n) - acu;
		if (dp[i] < 0) dp[i] += mod;

		res += dp[i] ^ i;
		if (res >= mod) res %= mod;
	}

	cout << res << endl;

	return 0;
}