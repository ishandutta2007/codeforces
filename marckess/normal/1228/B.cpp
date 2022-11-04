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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 1005, mod = 1000000007;
int n, m, a[MX][MX], r[MX], c[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	forn(i, n) {
		cin >> r[i];
		forn (j, r[i])
			a[i][j] = 1;
		a[i][r[i]] = -1;
	}
	forn(j, m) {
		cin >> c[j];
		forn(i, c[j])
			a[i][j] = 1;
		a[c[j]][j] = -1;
	}
	forn(i, n) {
		forn(j, r[i])
			if (a[i][j] != 1) {
				cout << 0 << endl;
				return 0;
			}
		if (a[i][r[i]] != -1) {
			cout << 0 << endl;
			return 0;
		}
	}

	int res = 1;
	forn (i, n) forn(j, m)
		if (a[i][j] == 0)
			(res *= 2) %= mod;
	cout << res << endl;

	return 0;
}