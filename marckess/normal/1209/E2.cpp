#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

int n, m, mx[2005], q[2005];
int mem[(1 << 12) + 5][13], mem2[(1 << 12) + 5][13];
vi a[2005];

void init () {
	for (int i = 0; i < n; i++) {
		a[i].resize(2 * m);
		mx[i] = 0;
	}

	for (int i = 0; i < (1 << m); i++)
		for (int j = 0; j < min(n, m); j++) {
			mem[i][j] = -1;
			mem2[i][j] = -1;
		}
}

int dp2 (int mk, int _i) {
	int &res = mem2[mk][_i];
	if (res != -1)
		return res;
	res = 0;
	int i = q[_i];

	for (int off = 0; off < m; off++) {
		int x = 0;
		for (int k = 0; k < m; k++)
			if (mk & (1 << k))
				x += a[i][k + off];
		res = max(res, x);
	}

	return res;
}

int dp (int mk, int _i) {
	if (_i == n) {
		if (__builtin_popcount(mk) == m) return 0;
		return -1e9;
	}

	int &res = mem[mk][_i];
	if (res != -1)
		return res;
	res = 0;
	int i = q[_i];

	int j = ~mk & ((1 << m) - 1);
	while (1) {
		int x = dp2(j, _i);
		res = max(res, dp(mk | j, _i + 1) + x);
		if (!j) break;
		j = (j - 1) & ~mk;
	}

	return res;
}

void solve () {
	cin >> m >> n;
	init();
	
	for (int j = 0; j < m; j++)
		for (int i = 0; i < n; i++) {
			cin >> a[i][j];
			mx[i] = max(mx[i], a[i][j]);
		}
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			a[i][j + m] = a[i][j];

	iota(q, q+n, 0);
	sort(q, q+n, [&] (int i, int j) {
		return mx[i] > mx[j];
	});
	n = min(n, m);

	cout << dp(0, 0) << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();	

	return 0;
}