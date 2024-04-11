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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, a[MX], b[MX];
vi adj[MX];
ll res, mx[MX];
vi ord;

ll dfs1 (int u) {
	mx[u] = a[u];
	for (int v : adj[u]) mx[u] += max(0ll, dfs1(v));
	res += mx[u];
	return mx[u];
}

void dfs2 (int u) {
	for (int v : adj[u]) if (mx[v] > 0) dfs2(v);
	ord.pb(u);
	for (int v : adj[u]) if (mx[v] <= 0) dfs2(v);
}

void solve () {
	cin >> n;
	
	forn (i, n) cin >> a[i];

	forn (i, n) {
		cin >> b[i];
		if (b[i] != -1) {
			b[i]--;
			adj[b[i]].pb(i);
		}
	}

	forn (i, n) if (b[i] == -1) {
		dfs1(i);
		dfs2(i);
	}

	cout << res << endl;
	for (int v : ord) cout << v + 1 << " ";
	cout << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t = 1;
	//cin >> t;
	while (t--)
		solve();	

	return 0;
}