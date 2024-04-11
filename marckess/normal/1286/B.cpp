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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 2005;
int n, p[MX], c[MX], a[MX], root, sz[MX], mx;
vi adj[MX], x;

void no () {
	cout << "NO" << endl;
	exit(0);
}

void d2 (int u) {
	x.pb(a[u]);
	for (int v : adj[u])
		d2(v);
}

void d3 (int u, int in, int f) {
	if (a[u] >= f && u != in) a[u]++;
	for (int v : adj[u])
		d3(v, in, f);
}

void dfs (int u) {
	sz[u] = 1;
	for (int v : adj[u]) {
		dfs(v);
		sz[u] += sz[v];
	}

	if (c[u] >= sz[u]) no();

	x.clear();
	for (int v : adj[u])
		d2(v);
	sort(all(x));

	mx++;
	if (x.size() == c[u]) {
		a[u] = mx;
	} else {
		a[u] = x[c[u]];
		d3(root, u, a[u]);
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i] >> c[i];
		if (p[i]) adj[p[i]].pb(i);
		else root = i;
	}
	dfs(root);
 
	cout << "YES" << endl;
	for (int i = 1; i <= n; i++)
		cout << a[i] << " ";
	cout << endl;

	return 0;
}