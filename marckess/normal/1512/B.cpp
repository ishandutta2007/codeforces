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

const int MX = 405;
int n;
char c[MX][MX];

void solve () {
	cin >> n;
	
	vii pos;
	forn (i, n)
		forn (j, n) {
			cin >> c[i][j];
			if (c[i][j] == '*')
				pos.pb({i, j});
		}
	
	if (pos[0].fi == pos[1].fi) {
		int ot = 0;
		if (pos[0].fi == 0)
			ot = 1;
		c[ot][pos[0].se] = '*';
		c[ot][pos[1].se] = '*';
	} else if (pos[0].se == pos[1].se) {
		int ot = 0;
		if (pos[0].se == 0)
			ot = 1;
		c[pos[0].fi][ot] = '*';
		c[pos[1].fi][ot] = '*';
	} else {
		c[pos[0].fi][pos[1].se] = '*';
		c[pos[1].fi][pos[0].se] = '*';
	}
	
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
		solve();	

	return 0;
}