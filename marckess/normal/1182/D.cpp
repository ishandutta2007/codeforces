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
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 100005;
int n, a[MX], vis[MX], r, d[MX], dis[MX];
vi adj[MX];

bool dfs (int u, int lvl, int p = -1) {
	if (a[lvl] == -1) {
		a[lvl] = adj[u].size();
	} else if (a[lvl] != adj[u].size())
		return 0;

	for (int v : adj[u])
		if (v != p)
			if (!dfs(v, lvl+1, u))
				return 0;

	return 1;
}

void esPos (int u) {
	memset(a, -1, sizeof(a));
	if (dfs(u, 0)) {
		cout << u << endl;
		exit(0);
	}
}

void go (int u, int p = -1) {
	if (adj[u].size() <= 1)
		esPos(u);

	for (int v : adj[u])
		if (v != p && adj[v].size() <= 2)
			go(v, u);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(a, -1, sizeof(a));

	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (adj[i].size() <= 1) {
			q.push(i);
			vis[i] = 1;
			dis[i] = 0;
		}
		d[i] = adj[i].size();
	}

	while (q.size()) {
		r = q.front();
		q.pop();

		for (int v : adj[r])
			if (!vis[v]) {
				d[v]--;
				if (d[v] < 2) {
					vis[v] = 1;
					dis[v] = dis[r] + 1;
					q.push(v);
				}
			}
	}

	esPos(r);

	int mx = 0;
	map<int, int> mp;
	for (int v : adj[r]) {
		mp[dis[v]]++;
		mx = max(mx, mp[dis[v]]);
	}

	int f = 20;
	for (int v : adj[r])
		if (mp[dis[v]] == mx) {
			go(v);
			if (!f)
				break;
			f--;
		}

	f = 20;
	for (int v : adj[r])
		if (mp[dis[v]] != mx) {
			go(v);
			if (!f)
				break;
			f--;
		} 

	cout << -1 << endl;

	return 0;
}