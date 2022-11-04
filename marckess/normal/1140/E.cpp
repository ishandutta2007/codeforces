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

const int MX = 200005, mod = 998244353;
int n, k;
ll x = 1, y = 1, dp[MX][2];
vi a, b;

ll pot (ll b, int p) {
	ll res = 1;
	while (p) {
		if (p & 1) (res *= b) %= mod;
		(b *= b) %= mod;
		p /= 2;
	}
	return res;
}

ll go (int i, int j) {
	if (i == n) return !j;
	ll &res = dp[i][j];
	if (res != -1) return res;
	if (j) return res = (k - 1) * go(i+1, 0) % mod;
	return res = ((k - 2) * go(i+1, 0) + go(i+1, 1)) % mod;
}

ll solve () {
	ll res = 1;
	int ant = -1;
	n = 0;

	for (int i = 0; i < a.size(); i++) {
		if (i && a[i] != -1 && a[i-1] == a[i])
			return 0;
		
		if (a[i] == -1) {
			n++;
		} else {
			if (n) {
				for (int i = 0; i <= n; i++)
					dp[i][0] = dp[i][1] = -1;

				if (ant == -1) {
					(res *= ((k - 1) * go(1, 0) + go(1, 1)) % mod) %= mod;
				} else if (ant != a[i]) {
					(res *= go(0, 0)) %= mod;
				} else {
					(res *= go(0, 1)) %= mod;
				}
			}

			ant = a[i];
			n = 0;
		}
	}

	if (n == a.size())
		return k * pot(k - 1, n - 1) % mod;

	if (n) {
		for (int i = 0; i <= n; i++)
			dp[i][0] = dp[i][1] = -1;

		(res *= ((k - 1) * go(1, 0) + go(1, 1)) % mod) %= mod;
	}

	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;

		if (i % 2 == 0) a.push_back(t);
		else b.push_back(t);
	}

	x = solve();
	swap(a, b);
	y = solve();

	cout << x * y % mod << endl;

	return 0;
}