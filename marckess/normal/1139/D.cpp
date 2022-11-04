#include <bits/stdc++.h>

//#define endl '\n'
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

const int MX = 100005, mod = 1000000007;
int m;
ll dp[MX], cn[MX];
vi d[MX];

ll pot (ll b, int p) {
	ll res = 1;
	while (p) {
		if (p & 1) (res *= b) %= mod;
		(b *= b) %= mod;
		p /= 2;
	}
	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> m;

	for (int i = 1; i <= m; i++)
		for (int j = i; j <= m; j += i)
			d[j].pb(i);

	for (int i = 2; i <= m; i++) {
		dp[i] = m;

		for (int j = (int)d[i].size() - 1; j >= 0; j--) {
			int x = d[i][j];

			cn[x] = m / x;

			for (int y : d[i / x])
				if (y > 1)
					cn[x] -= cn[x * y];

			if (x ^ i) (dp[i] += dp[x] * cn[x]) %= mod;
		}

		(dp[i] *= pot(m - cn[i], mod - 2)) %= mod;
	}

	ll res = m;
	for (int i = 1; i <= m; i++)
		(res += dp[i]) %= mod;
	(res *= pot(m, mod - 2)) %= mod;

	cout << res << endl;

	return 0;
}