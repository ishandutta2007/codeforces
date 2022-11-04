#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = (a); i <= (b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 55;
int n, m, vis[MX][MX], cn;
int mx[] = {1, -1, 0, 0};
int my[] = {0, 0, 1, -1};
char a[MX][MX];

bool valid (int i, int j) {
	return 0 <= i && i < n && 0 <= j && j < m && a[i][j] == '#' && !vis[i][j];
}

void dfs (int i, int j) {
	vis[i][j] = 1;
	for (int l = 0; l < 4; l++)
		if (valid(i + mx[l], j + my[l]))
			dfs(i + mx[l], j + my[l]);
}

int comp () {
	memset(vis, 0, sizeof(vis));
	int res = 0;

	forn (i, n) forn (j, m) if (valid(i, j)) {
		res++;
		dfs(i, j);
	}

	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	forn (i, n) cin >> a[i];

	forn (i, n) forn (j, m) if (a[i][j] == '#') {
		a[i][j] = '.';
		if (comp() > 1) {
			cout << 1 << endl;
			return 0;
		}
		a[i][j] = '#';
		cn++;
	}

	if (cn < 4) cout << -1 << endl; 
	else cout << 2 << endl;

	return 0;
}