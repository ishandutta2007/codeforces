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
typedef double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int n, m;
char c[105][105];

void solve () {
	cin >> n >> m;

	forn (i, n) forn (j, m) c[i][j] = "WB"[i % 2 == j % 2];

	int x = 0;
	if (n * m % 2 == 0) x = 1;

	forn (i, n) {
		forn (j, m) {
			if (c[i][j] == 'W' && x) {
				c[i][j] = 'B';
				x = 0;
			}
			cout << c[i][j];
		}
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