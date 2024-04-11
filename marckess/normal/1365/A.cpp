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
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 55;
int n, m, x[MX], y[MX], a[MX][MX];

void solve () {
	int n, m;
	cin >> n >> m;
	memset(x, 0, sizeof(x));
	memset(y, 0, sizeof(y));

	forn (i, n) forn (j, m) {
		cin >> a[i][j];
		x[i] |= a[i][j];
		y[j] |= a[i][j];
	}

	int fil = 0, col = 0;
	forn (i, n) fil += 1 - x[i];
	forn (i, m) col += 1 - y[i];

	if (min(fil, col) & 1) cout << "Ashish" << endl;
	else cout << "Vivek" << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}