// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % abs(k)) + abs(k) ) % abs(k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, m, dis[MX], vis[MX], deg[MX];
vi adj[MX];
priority_queue<ii, vii, greater<ii>> pq;

void main_() {
	cin >> n >> m;
	
	forn (i, m) {
		int u, v;
		cin >> u >> v;
		adj[v].pb(u);
		deg[u]++;
	}
	
	memset(dis, -1, sizeof(dis));
	dis[n] = 0;
	pq.push({0, n});
	
	while (pq.size()) {
		auto [d, u] = pq.top();
		pq.pop();
		
		if (vis[u]) continue;
		if (d != dis[u]) continue;
		vis[u] = 1;
		
		for (int v : adj[u])
			if (!vis[v]) {
				deg[v]--;
				int w = d + 1 + deg[v];
				
				if (dis[v] == -1)
					dis[v] = w;
				else
					dis[v] = min(dis[v], w);
				
				pq.push({dis[v], v});
			}
	}
	
	cout << dis[1] << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}