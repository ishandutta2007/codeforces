#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define find(v,x) (lower_bound(ALL(v), x) - v.begin())

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 100005, mod = 1000000007;

ll fac[MX], inv[MX];

ll pot (ll b, ll p) {
	ll res = 1;

	while (p) {
		if (p & 1) res = res * b % mod;
		b = b * b % mod;
		p /= 2;
	}

	return res;
} 

void pre () {
	fac[0] = 1;
	inv[0] = 1;

	for (int i = 1; i < MX; i++) {
		fac[i] = (fac[i-1] * i) %  mod;
		inv[i] = pot(fac[i], mod-2);
	}
}

ll c (int n, int k) {
	if (n < 0 || k < 0 || n < k) return 0;

	return fac[n] * inv[k] % mod * inv[n-k] % mod;
}

int n, f, q;
int dp[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	pre();

	cin >> q;

	while (q--) {
		cin >> n >> f;

		vi d, e;

		for (int i = 1; i * i <= n; i++)
			if (n % i == 0) {
				d.push_back(i);
				if (i * i < n)
					e.push_back(n/i);
			}

		for (int i = (int)e.size() - 1; i >= 0; i--)
			d.push_back(e[i]);

		for (int i = 0; i < d.size(); i++) {
			int &_ = dp[d[i]];
			_ = c(d[i]-1, f-1);
			for (int j = 0; j < i; j++)
				if (d[i] % d[j] == 0) {
					_ -= dp[d[j]];
					if (_ < 0) _ += mod;
				}
		}

		cout << dp[n] << endl;

		for (int x : d) dp[x] = 0;
	}

	return 0;
}