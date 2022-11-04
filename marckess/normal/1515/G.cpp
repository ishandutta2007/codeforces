#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
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
int n, m, in[MX];
vii adj[MX];

vector<vi> scc() {
	vi low(n), label(n);
	int time = 0;
	vector<vi> ans;
	stack<int> S;
	
	function<void(int)> dfs = [&](int u){
		label[u] = low[u] = ++time;
		S.push(u);
		for(ii &v : adj[u]){
			if(!label[v.fi]) dfs(v.fi);
			low[u] = min(low[u], low[v.fi]);
		}
		if(label[u] == low[u]){
			vi comp;
			while(S.top() != u){
				comp.push_back(S.top());
				low[S.top()] = n + 1;
				S.pop();
			}
			comp.push_back(S.top());
			S.pop();
			ans.push_back(comp);
			low[u] = n + 1;
		}
	};
	
	for (int u = 0; u < n; ++u)
		if (!label[u])
			dfs(u);
	
	return ans;
}

int vis[MX];
ll g[MX], dis[MX];
void dfs (int u) {
	vis[u] = 1;
	
	for (ii &v : adj[u]) {
		if (in[u] != in[v.fi])
			continue;
		
		if (!vis[v.fi]) {
			dis[v.fi] = dis[u] + v.se;
			dfs(v.fi);
 		} else {
 			g[in[u]] = __gcd(g[in[u]], dis[u] + v.se - dis[v.fi]);
 		}
 	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	forn (i, m) {
		int u, v, w;
		cin >> u >> v >> w;
		u--, v--;
		adj[u].pb({v, w});
	}
	
	for (vi v : scc())
		for (int u : v)
			in[u] = v[0];
		
	forn (i, n)
		if (!vis[i])
			dfs(i);
	
	int q;
	cin >> q;
	while (q--) {
		int v, s, t;
		cin >> v >> s >> t;
		v--;
		
		if (s % __gcd(1ll * t, g[in[v]]) == 0) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
		
	return 0;
}