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

const int MX = 105;
int n, res[MX][MX];
vi ord;

void solve () {
	cin >> n;
	
	if (n == 2) {
		cout << -1 << endl;
		return;
	}
	
	int k = 1;
	forn (i, n)
		forn (j, n)
			if ((i + j) % 2 == 0)
				res[i][j] = k++;
	
	forn (i, n)
		forn (j, n)
			if ((i + j) % 2 == 1)
				res[i][j] = k++;
	
	forn (i, n) {
		forn (j, n)
			cout << res[i][j] << " ";
		cout << endl;
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
		
	return 0;
}