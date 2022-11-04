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
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int mod = 998244353, MX = 500005;
int n, q;
ll dp[MX];

ll res[4 * MX];
int pre[4 * MX], suf[4 * MX], ex[4 * MX], p[MX];

void build (int i, int j, int pos) {
	if (i == j) {
		p[i] = pos;
		return;
	}

	int m = (i + j) / 2;
	build(i, m, pos * 2);
	build(m + 1, j, pos * 2 + 1);
}

void update (int i, int d) {
	int pos = p[i];

	res[pos] = 1;

	if (d == 1) {
		pre[pos] = suf[pos] = 1;
		ex[pos] = -1;
	} else {
		pre[pos] = suf[pos] = 0;
		ex[pos] = d;
	}

	pos /= 2;

	while (pos) {
		res[pos] = res[pos * 2] * res[pos * 2 + 1] % mod;

		if (ex[pos * 2] != -1 && ex[pos * 2 + 1] != -1) {
			int len = suf[pos * 2] + pre[pos * 2 + 1], x = ex[pos * 2 + 1] + 1;
			if (len) (res[pos] *= (x * dp[len] + (10 - x) * dp[len - 1]) % mod) %= mod;
			else (res[pos] *= x) %= mod;
		}

		pre[pos] = pre[pos * 2];
		suf[pos] = suf[pos * 2 + 1];
		ex[pos] = ex[pos * 2];

		if (ex[pos * 2] == -1) pre[pos] += pre[pos * 2 + 1], ex[pos] = ex[pos * 2 + 1];
		if (ex[pos * 2 + 1] == -1) suf[pos] += suf[pos * 2];

		pos /= 2;
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	dp[0] = 1, dp[1] = 2;

	for (int i = 2; i < MX; i++)
		dp[i] = 2 * (dp[i - 1] + 4 * dp[i - 2]) % mod;

	cin >> n >> q;

	build(1, n, 1);

	for (int i = 1; i <= n; i++) {
		char c;
		cin >> c;
		update(i, c - '0');
	}

	while (q--) {
		int x, d;
		cin >> x >> d;
		update(x, d);

		ll r = res[1];
		
		int len = pre[1];
		x = ex[1] + 1;

		if (x) {
			if (len) (r *= (x * dp[len] + (10 - x) * dp[len - 1]) % mod) %= mod;
			else (r *= x) %= mod;

			(r *= dp[suf[1]]) %= mod;
		} else {
			r = dp[n];
		}

		cout << r << endl;
	}

	return 0;
}