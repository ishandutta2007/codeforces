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
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 55;
int n, m, vis[MX][MX];
char c[MX][MX];
int mx[] = {1, -1, 0, 0};
int my[] = {0, 0, 1, -1};

bool valid (int i, int j) {
	return 0 <= i && i < n && 0 <= j && j < m && c[i][j] != '#' && !vis[i][j];
}

void dfs (int i, int j) {
	if (!valid(i, j)) return;
	vis[i][j] = 1;

	forn (l, 4) {
		int x = i + mx[l];
		int y = j + my[l];
		dfs(x, y);
	}
}

void solve () {
	memset(vis, 0, sizeof(vis));
	
	cin >> n >> m;
	forn (i, n) cin >> c[i];

	forn (i, n) forn (j, m) if (c[i][j] == 'B') {
		forn (l, 4) {
			int x = i + mx[l];
			int y = j + my[l];

			if (valid(x, y)) {
				if (c[x][y] == '.')
					c[x][y] = '#';
				
				if (c[x][y] == 'G') {
					cout << "No" << endl;
					return;
				}
			}
		}
	}

	dfs(n - 1, m - 1);

	forn (i, n) forn (j, m) if (c[i][j] == 'G') {
		if (!vis[i][j]) {
			cout << "No" << endl;
			return;
		}
	}

	cout << "Yes" << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		solve();

	return 0;
}