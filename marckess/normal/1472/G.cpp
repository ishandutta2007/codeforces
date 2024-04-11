#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, m, dp[MX], dis[MX];
vi adj[MX], a;

void reset () {
	for (int i = 1; i <= n; i++) {
		adj[i].clear();
		dis[i] = -1;
	}
	a.clear();
}

void solve () {
	cin >> n >> m;
	
	reset();
	
	forn (i, m) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
	}
	
	queue<int> q;
	q.push(1);
	dis[1] = 0;
	
	while (q.size()) {
		int u = q.front();
		q.pop();
		a.pb(u);
		
		for (int v : adj[u])
			if (dis[v] == -1) {
				dis[v] = dis[u] + 1;
				q.push(v);
			}
	}
	
	reverse(all(a));
	for (int u : a) {
		dp[u] = dis[u];
		for (int v : adj[u])
			if (dis[v] > dis[u]) dp[u] = min(dp[u], dp[v]);
			else dp[u] = min(dp[u], dis[v]);
	}
	
	for (int i = 1; i <= n; i++)
		cout << dp[i] << " ";
	cout << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}