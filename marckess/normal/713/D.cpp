#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forab(i,a,b) for (int i = a; i <= b; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 1002, LMX = 10;
int n, m, a[MX][MX], st[MX][MX][LMX][LMX];

void obtST () {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			st[i][j][0][0] = a[i][j];

	for (int i = 0; i < n; i++)
		for (int l = 1; l < LMX; l++)
			for (int j = 0; j + (1 << l) <= m; j++)
				st[i][j][0][l] = max(st[i][j][0][l-1], st[i][j+(1<<(l-1))][0][l-1]);

	for (int k = 1; k < 10; k++)
		for (int i = 0; i + (1 << k) <= n; i++)
			for (int l = 0; l < 10; l++)
				for (int j = 0; j + (1 << l) <= m; j++)
					st[i][j][k][l] = max(st[i][j][k-1][l], st[i+(1<<(k-1))][j][k-1][l]);
}

int query (int x1, int y1, int x2, int y2) {
	int lx = log2(x2-x1+1);
	int ly = log2(y2-y1+1);
	return max({
		st[x1][y1][lx][ly],
		st[x2-(1<<lx)+1][y1][lx][ly],
		st[x1][y2-(1<<ly)+1][lx][ly],
		st[x2-(1<<lx)+1][y2-(1<<ly)+1][lx][ly]
	});
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];

	for (int i = n-1; i >= 0; i--)
		for (int j = m-1; j >= 0; j--)
			if (a[i][j])
				a[i][j] = min({a[i+1][j+1], a[i+1][j], a[i][j+1]}) + 1;

	obtST();

	int q, x, y, x2, y2;

	cin >> q;
	while (q--) {
		cin >> x >> y >> x2 >> y2;
		x--, y--, x2--, y2--;

		int i = 1, j = min(x2-x, y2-y) + 2, rep = 11;
		while (rep--) {
			int m = (i+j)/2;
			if (query(x,y,x2-m+1,y2-m+1) >= m) i = m;
			else j = m;
		}

		if (j < min(x2-x, y2-y) + 2 && query(x,y,x2-j+1,y2-j+1) >= j) cout << j << endl;
		else if (query(x,y,x2-i+1,y2-i+1) >= i) cout << i << endl;
		else cout << 0 << endl;
	}

	return 0;
}