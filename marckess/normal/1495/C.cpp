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
int n, m;
char c[MX][MX];

void solve () {
	cin >> n >> m;
	forn (i, n)
		cin >> c[i];
	
	if (n == 1) {
		forn (i, m)
			cout << 'X';
		cout << endl;
		return;
	}
	
	forn (i, m)
		c[0][i] = 'X';
	
	for (int j = m % 3 != 1; j < m; j += 3) {
		for (int i = 1; i < n; i++)
			c[i][j] = 'X';
		
		if (c[1][j + 1] == 'X' || c[1][j + 2] == 'X') {
			c[0][j + 1] = c[0][j + 2] = '.';
			c[1][j + 1] = c[1][j + 2] = 'X';
		}
	}
	
	if (m % 3 != 1 && c[1][0] == 'X')
		c[0][0] = '.';
	
	forn (i, n) {
		forn (j, m)
			cout << c[i][j];
		cout << endl;
	}
	cout << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0); 
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}