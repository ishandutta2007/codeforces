#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb emplace_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 200005;
int n, k, p[MX], q[MX];
vi adj[MX], dag[MX];

char c = 'a', res[MX];
int num[MX], low[MX], vis[MX], cn, scc, com[MX];
stack<int> st;

void tarjan (int u) {
	low[u] = num[u] = ++cn;
	vis[u] = 1;
	st.push(u);

	for (int v : adj[u]) {
		if (!num[v])
			tarjan(v);
		if (vis[v])
			low[u] = min(low[u], low[v]);
	}

	if (low[u] == num[u]) {
		++scc;
		while (1) {
			int v = st.top();
			st.pop();
			vis[v] = 0;
			com[v] = scc;
			if (u == v) break;
		}
	} 
}

void dfs (int u) {
	vis[u] = 1;
	for (int v : dag[u])
		if (!vis[v])
			dfs(v);
	res[u] = c;
	if (c < 'z') c++;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> k;
	forn(i, n) cin >> p[i+1];
	forn(i, n) cin >> q[i+1];
	forr(i, 1, n-1) {
		adj[p[i+1]].pb(p[i]);
		adj[q[i+1]].pb(q[i]);
	}

	forr(i, 1, n)
		if (!num[i])
			tarjan(i);

	forr(i, 1, n-1) {
		dag[com[p[i+1]]].pb(com[p[i]]);
		dag[com[q[i+1]]].pb(com[q[i]]);
	}

	if (scc < k) {
		cout << "NO" << endl;
		return 0;
	}

	memset(vis, 0, sizeof(vis));
	forr(i, 1, scc)
		if (!vis[i])
			dfs(i);

	cout << "YES" << endl;
	forn(i, n) cout << res[com[i+1]];
	cout << endl;

	return 0;
}