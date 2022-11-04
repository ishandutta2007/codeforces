
// Problem : E1. Escape The Maze (easy version)
// Contest : Codeforces - Codeforces Round #756 (Div. 3)
// URL : https://codeforces.com/contest/1611/problem/E1
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
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
int n, k, x[MX], dis[MX];
vi adj[MX];

int dfs (int u, int p, int d) {
	if (u != 1 && adj[u].size() == 1)
		return 1;
	
	int res = 0;
	for (int v : adj[u])
		if (v != p)
			if (dis[v] > d + 1)
				res |= dfs(v, u, d + 1);
	
	return res;
}

void main_() {
	cin >> n >> k;
	forn (i, k)
		cin >> x[i];
	
	forr (i, 1, n) {
		adj[i].clear();
		dis[i] = -1;
	}
	
	forn (i, n - 1) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	queue<int> q;
	forn (i, k) {
		dis[x[i]] = 0;
		q.push(x[i]);
	}
	
	while (q.size()) {
		int u = q.front();
		q.pop();
		
		for (int v : adj[u])
			if (dis[v] == -1) {
				dis[v] = dis[u] + 1;
				q.push(v);
			}
	}
	
	if (dfs(1, 1, 0)) cout << "YES" << endl;
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