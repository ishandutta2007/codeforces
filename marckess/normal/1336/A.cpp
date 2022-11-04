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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, k, p[MX], lvl[MX], deg[MX], sz[MX];
ll a[MX], res;
vi adj[MX];
priority_queue<ii> pq;

void dfs (int u) {
	a[u] = lvl[u];
	sz[u] = 1;

	for (int v : adj[u])
		if (v != p[u]) {
			lvl[v] = lvl[u] + 1;
			p[v] = u;
			deg[u]++;

			dfs(v);

			a[u] -= sz[v];
			sz[u] += sz[v];
		}

	if (!deg[u])
		pq.emplace(a[u], u);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	p[1] = 1;
	dfs(1);

	while (k--) {
		ll w;
		int u;

		tie(w, u) = pq.top();
		pq.pop();

		res += w;
		deg[p[u]]--;

		if (!deg[p[u]])
			pq.emplace(a[p[u]], p[u]);
	}

	cout << res << endl;

	return 0;
}