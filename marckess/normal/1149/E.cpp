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
int n, m, u, v, a[MX], b[MX], ex[MX], x[MX];
vi adj[MX], in[MX];

void dfs (int u) {
	if (b[u] != -1) return;
	for (int v : adj[u]) dfs(v);
	for (int v : adj[u]) ex[b[v]] = u;
	b[u] = 0;
	while (ex[b[u]] == u) b[u]++;
	in[b[u]].pb(u);
	x[b[u]] ^= a[u];
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	forn (i, n) cin >> a[i+1];
	while (m--) {
		cin >> u >> v;
		adj[u].pb(v);
	}

	memset(b, -1, sizeof(b));
	forn (i, n) dfs(i + 1);

	for (int i = n; i + 1; i--)
		if (x[i]) {
			int s = 0;
			forn (j, 30) if (x[i] & (1 << j)) s = j;

			for (int u : in[i])
				if (a[u] & (1 << s)) {
					a[u] ^= x[i];
					
					for (int v : adj[u]) ex[b[v]] = v;
					forn (j, i) a[ex[j]] ^= x[j];

					break;
				}

			cout << "WIN" << endl;
			forn (i, n) cout << a[i+1] << " ";
			cout << endl;

			return 0;
		}

	cout << "LOSE" << endl;

	return 0;
}