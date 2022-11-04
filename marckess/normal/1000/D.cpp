#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 1005, mod = 998244353;
int n, a[MX], comb[MX][MX];
int dp[MX];

int c (int n, int k) {
	if (n < 0 || k < 0 || n < k)
		return 0;

	if (n == k || k == 0)
		return 1;

	int &_ = comb[n][k];
	if (_ != -1)
		return _;
	return _ = (c(n-1, k) + c(n-1, k-1)) % mod;
}

int obtRes (int i) {
	if (i == n)
		return 0;

	if (a[i] < 1)
		return 0;

	int &_ = dp[i];
	if (_ != -1)
		return _;

	_ = c(n - i - 1, a[i]);

	for (int j = i+1; j < n; j++) {
		_ += (ll)c(j - i - 1, a[i]) * obtRes(j) % mod;
		_ %= mod;
	}

	return _;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (int i = 0; i < MX; i++) {
		dp[i] = -1;
		for (int j = 0; j < MX; j++)
			comb[i][j] = -1;
	}

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int res = 0;
	for (int i = 0; i < n; i++) {
		res += obtRes(i);
		res %= mod;
	}

	cout << res << endl;

	return 0;
}