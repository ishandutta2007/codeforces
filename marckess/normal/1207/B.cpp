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

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n, m, a[55][55], b[55][55] = {0};
	vi rx, ry;
	cin >> n >> m;
	forn(i, n) forn(j, m) cin >> a[i][j];

	forn(i, n-1) forn(j, m-1)
		if (a[i][j] + a[i][j+1] + a[i+1][j] + a[i+1][j+1] == 4) {
			b[i][j] = b[i][j+1] = b[i+1][j] = b[i+1][j+1] = 1;
			rx.pb(i+1), ry.pb(j+1);
		}

	forn (i, n) forn(j, m) if (a[i][j] != b[i][j]) {
		cout << -1 << endl;
		return 0;
	}

	cout << rx.size() << endl;
	forn(i, rx.size())
		cout << rx[i] << " " << ry[i] << endl;

	return 0;
}