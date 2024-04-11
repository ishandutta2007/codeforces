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

int n, m, a[105][10], mem[(1<<4)+5][105];

int dp (int mk, int i) {
	if (i == n) {
		if (__builtin_popcount(mk) == m) return 0;
		return -1e9;
	}

	int &res = mem[mk][i];
	if (res != -1) return res;
	res = 0;

	for (int j = 0; j < (1 << m); j++)
		if (!(mk & j)) {
			for (int off = 0; off < m; off++) {
				int x = 0;
				for (int k = 0; k < m; k++)
					if (j & (1 << k))
						x += a[i][k+off];
				res = max(res, dp(mk | j, i + 1) + x);
			}
		}

	return res;
}

void solve () {
	cin >> m >> n;
	
	for (int j = 0; j < m; j++)
		for (int i = 0; i < n; i++)
			cin >> a[i][j];
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			a[i][j + m] = a[i][j];

	memset(mem, -1, sizeof(mem));
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