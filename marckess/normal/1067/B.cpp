#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
int n, k, u, v, dis[MX];
vi adj[MX];
bitset<MX> bs;

int bfs () {
	queue<int> q;
	memset(dis, -1, sizeof(dis));

	for (int i = 1; i <= n; i++)
		if (adj[i].size() == 1) {
			q.push(i);
			dis[i] = 0;
		}

	while (q.size()) {
		int u = q.front();
		q.pop();

		for (int v : adj[u])
			if (dis[v] == -1) {
				q.push(v);
				dis[v] = dis[u] + 1;
			}
	}

	int ind = 1;
	for (int i = 2; i <= n; i++)
		if (dis[i] > dis[ind])
			ind = i;

	return ind;
}

bool dfs (int u, int k) {
	int sz = 0;
	bs[u] = 1;

	for (int v : adj[u])
		if (!bs[v])
			sz++;

	if (sz == 0 && k == 0) return 1;
	if (sz < 3 || k == 0) return 0;

	for (int v : adj[u])
		if (!bs[v] && !dfs(v, k-1))
			return 0;

	return 1;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> k;
	for (int i = 1; i < n; i++) {
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	int root = bfs();
	if (dfs(root, k)) cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}