#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 2005;
int n, a[MX][MX], mx[10], mn[10], res[10];

void go () {
	memset(mx, -1, sizeof(mx));
	memset(mn, -1, sizeof(mn));
	
	forn (i, n) forn (j, n) {
		if (mn[a[i][j]] == -1) mn[a[i][j]] = i;
		mx[a[i][j]] = i;
	}
	
	forn (d, 10) {
		forn (i, n) {
			int x = -1, y = -1;
			forn (j, n)
				if (a[i][j] == d) {
					res[d] = max(
						res[d],
						max(n - 1 - j, j) * max(abs(mx[d] - i), abs(mn[d] - i))
					);
					if (x == -1) x = j;
					y = j;
				}
			res[d] = max(
				res[d],
				(y - x) * max(n - 1 - i, i)
			);
		}
	}
}

void solve () {
	cin >> n;
	memset(res, 0, sizeof(res));
	
	forn (i, n) forn (j, n) {
		char c;
		cin >> c;
		a[i][j] = c - '0';
	}
	
	go();
	forn (i, n) forn (j, i) swap(a[i][j], a[j][i]);
	go();
	
	forn (i, 10) cout << res[i] << " ";
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