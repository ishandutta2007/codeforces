#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 505;
int n, m, a[MX][MX], mcm;

ll f (ll n) {
	return n * n * n * n;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	forn (i, n) forn (j, m) cin >> a[i][j];
	
	mcm = 1;
	for (int i = 1; i <= 16; i++)
		mcm = mcm * i / __gcd(mcm, i);
	
	forn (i, n) forn (j, m)
		if ((i + j) % 2) a[i][j] = mcm;
		else a[i][j] = mcm - f(a[i][j]);
	
	forn (i, n) {
		forn (j, m)
			cout << a[i][j] << " ";
		cout << endl;
	}

	return 0;
}