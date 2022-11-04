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

const int MX = 1005;
int n, m, vis[MX], dis[MX][MX], res;
vi adj[MX], v;

void dfs (int u) {
	vis[u] = 1;
	v.pb(u);
	for (int v : adj[u])
		if (!vis[v])
			dfs(v);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(dis, -1, sizeof(dis));
	
	cin >> n >> m;

	forn (i, m) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	for (int i = 1; i <= n; i++)
		if (!vis[i]) {
			v.clear();
			dfs(i);

			int p = -1;

			for (int s : v) {
				int f = 1, mx = 0;

				queue<int> q;
				q.push(s);
				dis[s][s] = 0;

				while (q.size()) {
					int u = q.front();
					q.pop();
					
					mx = max(mx, dis[s][u]);

					for (int v : adj[u]) {
						if (dis[s][v] == dis[s][u]) f = 0;
						
						if (dis[s][v] == -1) {
							dis[s][v] = dis[s][u] + 1;
							q.push(v);
						}
					}
				}

				if (f) p = max(p, mx);
			}

			if (p == -1) {
				cout << -1 << endl;
				return 0;
			}

			res += p;
		}

	cout << res << endl;
	
	return 0;
}