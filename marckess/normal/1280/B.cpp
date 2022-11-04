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

const int MX = 65;
int n, m, res, p;
char c[MX][MX];

void solve () {
	p = 0, res = 4;

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> c[i][j];
			if (c[i][j] == 'P')
				p++;
		}

	if (!p) {
		cout << 0 << endl;
		return;
	}

	if (p == n * m) {
		cout << "MORTAL" << endl;
		return;
	}

	for (int i = 0; i < n; i++) {
		int a = 0;
		
		for (int j = 0; j < m; j++)
			if (c[i][j] == 'A')
				a++;

		if (a == m) {
			if (i == 0 || i == n - 1)
				res = min(res, 1);
			else
				res = min(res, 2);
		} else if (c[i][0] == 'A' || c[i][m-1] == 'A') {
			if (i == 0 || i == n - 1)
				res = min(res, 2);
			else
				res = min(res, 3);
		} else if (a) {
			if (i == 0 || i == n - 1)
				res = min(res, 3);
			else
				res = min(res, 4);
		}
	}

	for (int j = 0; j < m; j++) {
		int a = 0;
		
		for (int i = 0; i < n; i++)
			if (c[i][j] == 'A')
				a++;

		if (a == n) {
			if (j == 0 || j == m - 1)
				res = min(res, 1);
			else
				res = min(res, 2);
		} else if (c[0][j] == 'A' || c[n-1][j] == 'A') {
			if (j == 0 || j == m - 1)
				res = min(res, 2);
			else
				res = min(res, 3);
		} else if (a) {
			if (j == 0 || j == m - 1)
				res = min(res, 3);
			else
				res = min(res, 4);
		}
	}

	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();	

	return 0;
}