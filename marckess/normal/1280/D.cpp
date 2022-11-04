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

const int MX = 3005;
int n, m, b[MX], w[MX], fi[MX][MX], sz[MX];
ll se[MX][MX]; 
vi adj[MX];

void dp (int u, int p) {
	fi[u][0] = 0;
	se[u][0] = w[u] - b[u];
	sz[u] = 1;

	for (int v : adj[u])
		if (v != p) {
			dp(v, u);

			for (int i = sz[u] - 1 + sz[v]; i >= 0; i--) {
				int x = -1;
				ll y;

				for (int j = i - sz[u] + 1 > 0 ? i - sz[u] + 1 : 0; j <= i && j < sz[v]; j++) {
					int a = fi[u][i - j] + fi[v][j];
					ll b = se[u][i - j] + se[v][j];

					if (a > x || (a == x && b > y))
						x = a, y = b;
				}

				for (int j = i - sz[u] > 0 ? i - sz[u] : 0; j <= i - 1 && j < sz[v]; j++) {
					int a = fi[u][i - j - 1] + fi[v][j] + (se[v][j] > 0);
					ll b = se[u][i - j - 1];

					if (a > x || (a == x && b > y))
						x = a, y = b;
				}

				fi[u][i] = x;
				se[u][i] = y;
			}

			sz[u] += sz[v];
		}
}

int solve () {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> b[i];
		adj[i].clear();

		for (int j = 0; j <= n; j++) {
			fi[i][j] = 0;
			se[i][j] = -1e18;
		}
	}

	for (int i = 1; i <= n; i++)
		cin >> w[i];

	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	dp(1, 1);
	cout << fi[1][m-1] + (se[1][m-1] > 0) << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}