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

const int MX = 505;
int n, m, a[MX][MX], b[MX][MX], c[MX], r[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> b[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			r[i] ^= a[i][j] ^ b[i][j];
			c[j] ^= a[i][j] ^ b[i][j];
		}

	for (int i = 0; i < n; i++)
		if (r[i]) {
			cout << "NO" << endl;
			return 0;
		}

	for (int i = 0; i < m; i++)
		if (c[i]) {
			cout << "NO" << endl;
			return 0;
		}

	cout << "Yes" << endl;

	return 0;
}