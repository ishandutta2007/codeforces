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
int n, f = 1, vis[MX], col[MX];
map<int, int> mp, cn;
vi adj[MX];

void add (int a, int b) {
	adj[a].pb(b);
	adj[b].pb(a);
}

void dfs (int u) {
	vis[u] = 1;
	for (int v : adj[u]) {
		if (vis[v]) {
			if (col[u] == col[v])
				f = 0;
		} else {
			col[v] = 1 - col[u];
			dfs(v);
		}
	}
}

void main_() {
	cin >> n;
	f = 1;
	
	mp.clear();
	cn.clear();
	forr (i, 1, n) {
		adj[i].clear();
		vis[i] = 0;
	}
	
	forr (i, 1, n) {
		int a, b;
		cin >> a >> b;
		
		if (a == b) f = 0;
		if (++cn[a] > 2) f = 0;
		if (++cn[b] > 2) f = 0;
		
		if (mp.count(a))
			add(i, mp[a]);
		mp[a] = i;
		
		if (mp.count(b))
			add(i, mp[b]);
		mp[b] = i;
	}
	
	forr (i, 1, n)
		if (!vis[i]) {
			col[i] = 0;
			dfs(i);
		}
	
	if (f) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}