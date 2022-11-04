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
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 505, LG = 10;
int n, m, q, acu[4][MX][MX], mx[MX][MX], st[MX][MX][LG][LG];
char a[MX][MX];

void build () {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			st[i][j][0][0] = mx[i][j];
	
	for (int k = 0; k < LG; k++)
		for (int i = 1; i + (1 << k) - 1 <= n; i++)
			for (int l = !k; l < LG; l++)
				for (int j = 1; j + (1 << l) - 1 <= m; j++)
					st[i][j][k][l] = k ? max(st[i][j][k - 1][l], st[i + (1 << (k - 1))][j][k - 1][l])
									   : max(st[i][j][k][l - 1], st[i][j + (1 << (l - 1))][k][l - 1]);
}

int query (int x1, int y1, int x2, int y2) {
	if (x1 > x2 || y1 > y2) return 0;
	int lx = log2(x2 - x1 + 1), ly = log2(y2 - y1 + 1);
	
	return max({
		st[x1][y1][lx][ly],
		st[x2 - (1 << lx) + 1][y1][lx][ly],
		st[x1][y2 - (1 << ly) + 1][lx][ly],
		st[x2 - (1 << lx) + 1][y2 - (1 << ly) + 1][lx][ly]
	});
}

void pre (char c, int acu[MX][MX]) {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			acu[i][j] = (a[i][j] == c) + acu[i-1][j] + acu[i][j-1] - acu[i-1][j-1];
}

int query (int ind, int a, int b, int c, int d) {
	return acu[ind][c][d] - acu[ind][c][b - 1] - acu[ind][a - 1][d] + acu[ind][a - 1][b - 1];
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];

	pre('R', acu[0]);
	pre('G', acu[1]);
	pre('Y', acu[2]);
	pre('B', acu[3]);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			for (int k = 1; min(i, j) - k + 1 > 0 && i + k <= n && j + k <= m; k++) {
				if (query(0, i - k + 1, j - k + 1, i, j) != k * k) break;
				if (query(1, i - k + 1, j + 1, i, j + k) != k * k) break;
				if (query(2, i + 1, j - k + 1, i + k, j) != k * k) break;
				if (query(3, i + 1, j + 1, i + k, j + k) != k * k) break;

				mx[i][j] = k;
			}

	build();

	while (q--) {
		int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;
		
		int i = 0, j = n, rep = 10;
		while (rep--) {
			int m = (i + j + 1) / 2;
			if (query(r1 + m - 1, c1 + m - 1, r2 - m, c2 - m) >= m) i = m;
			else j = m;
		}

		cout << 4 * i * i << endl;	
	}

	return 0;
}