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

const int MX = 2005, mod = 1000000007;
int n, m, a[MX][MX], b[MX][MX], sa[MX][MX], sb[MX][MX], der[MX][MX], aba[MX][MX];
char c[MX][MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> c[i][j];

	for (int i = 0; i < n; i++)
		for (int j = m - 1; j >= 0; j--)
			der[i][j] = der[i][j+1] + (c[i][j] == 'R');

	for (int j = 0; j < m; j++)
		for (int i = n - 1; i >= 0; i--)
			aba[i][j] = aba[i+1][j] + (c[i][j] == 'R');

	if (n == 1 && m == 1) {
		cout << 1 << endl;
		return 0;
	}

	if (n == 1) {
		cout << 1 - bool(der[0][0]) << endl;
		return 0;
	}

	if (m == 1) {
		cout << 1 - bool(aba[0][0]) << endl;
		return 0;
	}

	for (int i = n - 1; i >= 0; i--)
		for (int j = m - 1; j >= 0; j--) {
			if (i == n - 1) {
				if (!der[i][j])
					a[i][j] = sa[i][j] = 1;
			} else {
				a[i][j] = sb[i][j + 1] - sb[i][m - der[i][j + 1]];
				a[i][j] %= mod;

				sa[i][j] = a[i][j] + sa[i + 1][j];
				sa[i][j] %= mod;
			}

			if (j == m - 1) {
				if (!aba[i][j])
					b[i][j] = sb[i][j] = 1;
			} else {
				b[i][j] = sa[i + 1][j] - sa[n - aba[i + 1][j]][j];
				b[i][j] %= mod;

				sb[i][j] = b[i][j] + sb[i][j + 1];
				sb[i][j] %= mod;
			}
		}

	cout << MOD(a[0][0] + b[0][0], mod) << endl;

	return 0;
}