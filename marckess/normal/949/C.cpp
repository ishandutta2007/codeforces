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
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
int n, m, h, u[MX], c1, c2;
set<int> adj[MX];

int num[MX], low[MX], vis[MX], cn = 0, scc = 0;
int c[MX], sz[MX], d[MX];
stack<int> st;
vi pos[MX];

void tarjan (int u) {
	low[u] = num[u] = ++cn;
	st.push(u);
	vis[u] = 1;

	for (int v : adj[u]) {
		if (num[v] == -1) tarjan(v);
		if (vis[v])
			low[u] = min(low[u], low[v]);
	}

	if (low[u] == num[u]) {
		while (1) {
			int v = st.top(); st.pop();
			vis[v] = 0;
			c[v] = scc;
			pos[scc].pb(v);
			if (u == v) {
				scc++;
				break;
			}	
		}
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m >> h; 

	for (int i = 1; i <= n; i++) cin >> u[i];

	while (m--) {
		cin >> c1 >> c2;
		if ((u[c1] + 1) % h == u[c2]) adj[c1].insert(c2);
		if ((u[c2] + 1) % h == u[c1]) adj[c2].insert(c1);
	}

	memset(num, -1, sizeof(num));
	for (int i = 1; i <= n; i++)
		if (num[i] == -1)
			tarjan(i);

	for (int u = 1; u <= n; u++)
		for (int v : adj[u])
			if (c[u] != c[v])
				d[c[u]]++;

	int ind = -1;
	for (int i = 0; i < scc; i++)
		if (!d[i] && (ind == -1 || pos[i].size() < pos[ind].size()))
			ind = i;
	
	cout << pos[ind].size() << endl;
	for (int x : pos[ind]) cout << x << " ";
	cout << endl;

	return 0;
}