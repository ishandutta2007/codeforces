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
typedef double ld;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, m, vad[MX], vre[MX], vis[MX], res[MX];
vi adj[MX], rev[MX];

void no () {
	cout << -1 << endl;
	exit(0);
}

void dfs (int u) {
	vis[u] = 1;

	for (int v : adj[u]) {
		if (!vis[v]) {
			dfs(v);
		} else if (vis[v] == 1) {
			no();
		}
	}

	vis[u] = 2;
}

void dfs (int u, vi adj[], int vis[]) {
	if (vis[u]) return;
	vis[u] = 1;

	for (int v : adj[u])
		dfs(v, adj, vis);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	forn (i, m) {
		int a, b;
		cin >> a >> b;
		adj[a].pb(b);
		rev[b].pb(a);
	}

	for (int i = 1; i <= n; i++)
		if (!vis[i])
			dfs(i);

	int cn = 0;
	for (int i = 1; i <= n; i++) {
		res[i] = !vad[i] && !vre[i];
		cn += res[i];

		dfs(i, adj, vad);
		dfs(i, rev, vre);
	}

	cout << cn << endl;
	for (int i = 1; i <= n; i++)
		cout << "EA"[res[i]];
	cout << endl;

	return 0;
}