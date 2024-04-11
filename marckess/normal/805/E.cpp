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

const int MX = 300005;
int n, m, s, k, u, v, res[MX];
vi adj[MX];
set<int> st, pos[MX];

void dfs (int u, int p) {
	if (p != -1)
		for (int x : pos[u]) 
			if (pos[u].count(x))
				st.erase(res[x]);

	for (int x : pos[u])
		if (!res[x]){
			res[x] = *st.begin();
			st.erase(st.begin());
		}

	for (int x : pos[u])
		st.insert(res[x]);

	for (int v : adj[u])
		if (v != p)
			dfs(v, u);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		cin >> s;
		while (s--) {
			cin >> k;
			pos[i].insert(k);
		}
	}

	for (int i = 1; i < n; i++) {
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	for (int i = 1; i <= m; i++)
		st.insert(i);

	dfs(1, -1);
	for (int i = 1; i <= m; i++)
		res[i] = max(res[i], 1);

	cout << *max_element(res+1, res+m+1) << endl;
	for (int i = 1; i <= m; i++) cout << res[i] << " ";
	cout << endl;

	return 0;
}