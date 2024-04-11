#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define find(v,x) (lower_bound(ALL(v), x) - v.begin())

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 45;
int n, m, q, a, b, c, d;
int v[MX][MX], acu[MX][MX];
map<int, int> mp, ma;
char h;

int hsh (int a, int b, int c, int d) {
	return a * (1 << 18) + b * (1 << 12) + c * (1 << 6) + d;
}

int query (int a, int b, int c, int d) {
	return v[c][d] - v[a-1][d] - v[c][b-1] + v[a-1][b-1];
}

int procesa (int a, int b) {
	memset(acu, 0, sizeof(acu));

	for (int i = a; i <= n; i++)
		for (int j = b; j <= m; j++) {
			acu[i][j] = (query(a, b, i, j) == 0) + acu[i-1][j] + acu[i][j-1] - acu[i-1][j-1];
			mp[hsh(a, b, i, j)] = acu[i][j];
		}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			cin >> h;
			v[i][j] = h == '1';
		}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			v[i][j] += v[i-1][j] + v[i][j-1] - v[i-1][j-1];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			procesa(i, j);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			for (int k = 1; k <= i; k++)
				for (int l = 1; l <= j; l++)
					ma[hsh(k, l, i, j)] = mp[hsh(k, l, i, j)] + ma[hsh(k-1, l, i, j)] + ma[hsh(k, l-1, i, j)] - ma[hsh(k-1, l-1, i, j)];

	while (q--) {
		cin >> a >> b >> c >> d;
		cout << ma[hsh(c, d, c, d)] 
				- ma[hsh(a-1, d, c, d)] 
				- ma[hsh(c, b-1, c, d)] 
				+ ma[hsh(a-1, b-1, c, d)] << endl;
	}

	return 0;
}