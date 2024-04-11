#include <bits/stdc++.h>
 
//#define endl '\n'
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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 1005;
int n, root, p[MX], d, lvl[MX];
vi adj[MX];

ii query (vi v) {
	cout << "? " << v.size();
	for (int x : v)
		cout << " " << x;
	cout << endl;

	int r, d;
	cin >> r >> d;
	if (r == -1) exit(0);

	return {r, d};
}

void dfs (int u) {
	for (int v : adj[u])
		if (v != p[u]) {
			p[v] = u;
			lvl[v] = lvl[u] + 1;
			dfs(v);
		}
}

void solve () {
	cin >> n;

	for (int i = 1; i <= n; i++)
		adj[i].clear();

	forn (i, n - 1) {
		int a, b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	vi v;
	forn (i, n) v.pb(i + 1);
	tie(root, d) = query(v);

	p[root] = root;
	lvl[root] = 0;
	dfs(root);

	int i = d / 2, j = d, ult = root;
	while (i <= j) {
		int m = (i + j + 1) / 2;

		v.clear();
		for (int k = 1; k <= n; k++)
			if (lvl[k] == m)
				v.pb(k);

		if (v.size() == 0) {
			j = m - 1;
			continue;
		}

		int u, w;
		tie(u, w) = query(v);

		if (w == d) {
			ult = u;
			i = m + 1;
		} else {
			j = m - 1;
		}
	}

	p[ult] = ult;
	lvl[ult] = 0;
	dfs(ult);

	v.clear();
	for (int i = 1; i <= n; i++)
		if (lvl[i] == d)
			v.pb(i);

	int u, kk;
	tie(u, kk) = query(v);

	cout << "! " << ult << " " << u << endl;

	string s;
	cin >> s;
	if (s[0] == 'I')
		exit(0);
}

int main () {
	//ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		solve();

	return 0;
}