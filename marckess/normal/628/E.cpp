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

const int MX = 3005;
int n, m, a[MX][MX], b[MX][MX];
vi acu[MX];
char c[MX][MX];
bitset<MX> bs[MX];
ll res = 0;

int ft[MX];

void update (int i, int k) {
	while (i < MX) {
		ft[i] += k;
		i += i & -i;
	}
}

int query (int i) {
	int sum = 0;
	while (i) {
		sum += ft[i];
		i -= i & -i;
	}
	return sum;
}

int query (int a, int b) {
	return query(b) - query(a-1);
}

int izq (int i, int j) {
	if (a[i][j]) return a[i][j];
	if (!j || c[i][j] == '.') return j+1;
	return a[i][j] = izq(i, j-1);
}

int der (int i, int j) {
	if (b[i][j]) return b[i][j];
	if (j > m || c[i][j] == '.') return j-1;
	return b[i][j] = der(i, j+1);
}

void impr (int a[MX][MX]) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			cout << a[i][j];
		cout << endl;
	}
}

void dfs (int i, int j) {
	if (c[i][j] != 'z') return;
	bs[i][j] = 1;

	update(j, 1);
	acu[a[i][j]].push_back(j);
	res += query(b[i][j]);
	
	for (int x : acu[j])
		update(x, -1);

	dfs(i+1, j-1);

	for (int x : acu[j])
		update(x, 1);
	
	if (acu[a[i][j]].size())
		acu[a[i][j]].clear();
	update(j, -1);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> c[i][j];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (c[i][j] == 'z' && !a[i][j])
				izq(i, j), der(i, j);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (c[i][j] == 'z' && !bs[i][j]) 
				dfs(i, j);

	cout << res << endl;

	return 0;
}