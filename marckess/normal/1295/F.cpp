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

const int MX = 55, mod = 998244353;
int n, l[MX], r[MX];
ll q, inv[MX], mem[MX][2 * MX];
vi c;

ll pot (ll b, int p) {
	ll res = 1;
	while (p) {
		if (p & 1) (res *= b) %= mod;
		(b *= b) %= mod;
		p /= 2;
	}
	return res;
}

ll f (int m, int n) {
	ll res = 1;
	for (int i = 1; i <= n; i++)
		(res *= (m + n - i) * inv[i] % mod) %= mod;
	return res;
}

ll dp (int i, int j) {
	if (i == n) return 1;
	if (j < 0) return 0;

	ll &res = mem[i][j];
	if (res != -1) return res;
	res = dp(i, j - 1);

	for (int k = i; k < n; k++) {
		if (j < l[k] || r[k] < j) break;
		(res += f(c[j + 1] - c[j], k - i + 1) * dp(k + 1, j - 1)) %= mod;
	}

	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	for (int i = 1; i < MX; i++)
		inv[i] = pot(i, mod - 2);
	q = 1;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> l[i] >> r[i];

		c.pb(l[i]);
		c.pb(r[i] + 1);

		(q *= r[i] - l[i] + 1) %= mod;
	}

	sort(all(c));
	c.erase(unique(all(c)), c.end());

	for (int i = 0; i < n; i++) {
		l[i] = lower_bound(all(c), l[i]) - c.begin();
		r[i] = lower_bound(all(c), r[i] + 1) - c.begin() - 1;
	}

	memset(mem, -1, sizeof(mem));
	cout << dp(0, c.size()) * pot(q, mod - 2) % mod << endl;

	return 0;
}