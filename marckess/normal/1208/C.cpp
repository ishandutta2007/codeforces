#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb emplace_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

int n, a[1005][1005];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n, a[1005][1005];
	cin >> n;

	for (int i = 0, k = 0; i < n; i += 4)
		for (int j = 0; j < n; j += 4)
			for (int x = 0; x < 4; x++)
				for (int y = 0; y < 4; y++, k++)
					a[i+x][j+y] = k;

	forn(i, n) {
		int x = 0;
		forn(j, n) x ^= a[i][j];
		assert(x == 0);
	}
	forn(j, n) {
		int x = 0;
		forn(i, n) x ^= a[i][j];
		assert(x == 0);
	}
	forn(i, n) {
		forn(j, n) cout << a[i][j] << " ";
		cout << endl;
	}


	return 0;
}