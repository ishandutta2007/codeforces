#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 500005, LMX = 20;
int n, q, p, v, h;
vi adj[MX], pos[MX];
int ini[MX], fin[MX], acu[MX], bo[MX], lvl[MX], cn = 1;
char c;

void dfs (int u, int l) {
	pos[l].push_back(u);
	lvl[u] = l;
	ini[u] = cn++;

	for (int v : adj[u])
		dfs(v, l+1);

	fin[u] = cn - 1;
}

int binBusc (int x, vi &v) {
	if (v.empty())
		return 0;
	
	int i = 0, j = v.size(), rep = 20;

	while (rep--) {
		int m = (i+j)/2;

		if (ini[v[m]] >= x)
			j = m;
		else
			i = m;
	}

	return j;
}

bool obtRes (int a, int b, int h) {
	int l = binBusc (a, pos[h]);
	int r = binBusc (b + 1, pos[h]);

	if (l == r)
		return 1;

	l = pos[h][l];
	r = pos[h][r-1];

	int d = acu[bo[r]] ^ acu[bo[l]-1];

	if (!d)
		return 1;

	if (d == (d & -d))
		return 1;

	return 0;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> q;
	for (int i = 2; i <= n; i++) {
		cin >> p;
		adj[p].push_back(i);
	}

	dfs(1, 1);

	cn = 1;
	for (int i = 1; i <= n; i++)
		for (int x : pos[i])
			bo[x] = cn++;

	for (int i = 1; i <= n; i++) {
		cin >> c;
		acu[bo[i]] = (1 << int(c - 'a'));
	}

	for (int i = 1; i <= n; i++)
		acu[i] ^= acu[i-1];

	while (q--) {
		cin >> v >> h;
		if (obtRes(ini[v], fin[v], h))
			cout << "Yes" << endl;
		else
			cout << "No" << endl; 
	}

	return 0;
}