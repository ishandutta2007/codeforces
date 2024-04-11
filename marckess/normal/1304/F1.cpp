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
typedef vector<ii> vii;

const int MX = 100005;
int n, m, k;
ll a[55][MX], st[MX], dp[55][MX], lz[MX];

void push (int i, int j, int pos) {
	st[pos] += lz[pos];
	if (i < j) {
		lz[pos * 2] += lz[pos];
		lz[pos * 2 + 1] += lz[pos];
	}
	lz[pos] = 0;
}

void update (int i, int j, int pos, int a, int b, int k) {
	if (lz[pos]) push(i, j, pos);
	if (j < a || b < i) return;
	if (a <= i && j <= b) {
		lz[pos] += k;
		push(i, j, pos);
		return;
	}
	int m = (i + j) / 2;
	update(i, m, pos * 2, a, b, k);
	update(m + 1, j, pos * 2 + 1, a, b, k);
	st[pos] = max(st[pos * 2], st[pos * 2 + 1]);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];

	for (int i = n; i > 0; i--) {
		memset(st, 0, sizeof(st));
		memset(lz, 0, sizeof(lz));

		for (int j = 1; j <= m; j++)
			update(1, m, 1, j, j, dp[i + 1][j]);

		ll acu = 0;
		for (int j = 1; j <= k; j++) {
			acu += a[i][j];

			int l = j - k + 1, r = j;
			if (l > 1) update(1, m, 1, 1, l - 1, a[i + 1][j]);
			if (r < m) update(1, m, 1, r + 1, m, a[i + 1][j]);
		}

		for (int j = 1; j <= m; j++) {
			dp[i][j] = st[1] + acu;

			int l = j - k + 1, r = j;
			if (l > 1) update(1, m, 1, 1, l - 1, -a[i + 1][j]);
			if (r < m) update(1, m, 1, r + 1, m, -a[i + 1][j]);
			acu -= a[i][j];

			l = j + 1, r = j + k;
			if (l > 1) update(1, m, 1, 1, l - 1, a[i + 1][j + k]);
			if (r < m) update(1, m, 1, r + 1, m, a[i + 1][j + k]);
			acu += a[i][j + k];
		}
	}

	ll res = 0;
	for (int j = 1; j <= m; j++)
		res = max(res, dp[1][j]);
	cout << res << endl;

	return 0;
}