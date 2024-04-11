#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
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

const int MX = 305;
int n;
char c[MX][MX];

void solve () {
	cin >> n;
	
	forn (i, n)
		forn (j, n)
			cin >> c[i][j];
	
	vi cn(3);
	forn (i, n)
		forn (j, n)
			if (c[i][j] == 'X')
				cn[(i + j) % 3]++;
	
	int x;
	if (cn[0] < cn[1] && cn[0] < cn[2]) {
		x = 0;
	} else if (cn[1] < cn[2]) {
		x = 1;
	} else {
		x = 2;
	}
	
	forn (i, n)
		forn (j, n)
			if (c[i][j] == 'X' && (i + j) % 3 == x)
				c[i][j] = 'O';
	
	forn (i, n) {
		forn (j, n)
			cout << c[i][j];
		cout << endl;
	}
		
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve ();
	
	return 0;
}