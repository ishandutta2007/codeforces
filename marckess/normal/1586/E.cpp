
// Problem : E. Moment of Bloom
// Contest : Codeforces - Codeforces Round #749 (Div. 1 + Div. 2, based on Technocup 2022 Elimination Round 1)
// URL : https://codeforces.com/contest/1586/problem/E
// Memory Limit : 512 MB
// Time Limit : 3000 ms
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

const int MX = 300005;
int n, m, lvl[MX], p[MX], f[MX], cn;
vi adj[MX];
vvi res;

void dfs (int u) {
	for (int v : adj[u])
		if (!p[v]) {
			p[v] = u;
			lvl[v] = lvl[u] + 1;
			dfs(v);
		}
}

int dfs2 (int u) {
	int x = 0;
	
	for (int v : adj[u])
		if (p[v] == u)
			x += dfs2(v);
	
	cn -= x / 2;
	x %= 2;
	
	if (f[u]) {
		if (!x) cn++;
		return 1;
	}
	
	return 0;
}

void main_() {
	cin >> n >> m;
	
	while (m--) {
		int u, v;
		cin >> u >> v;
		
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	p[1] = -1;
	dfs(1);
	
	int q;
	cin >> q;
	
	while (q--) {
		int u, v;
		cin >> u >> v;
		
		vi pre = {u}, suf = {v};
		
		while (u != v) {
			if (lvl[u] > lvl[v]) {
				f[u] ^= 1;
				u = p[u];
				
				pre.pb(u);
			} else {
				f[v] ^= 1;
				v = p[v];
				
				suf.pb(v);
			}
		}
		
		suf.pop_back();
		reverse(all(suf));
		
		pre.insert(pre.end(), all(suf));
		res.pb(pre);
	}
	
	for (int i = 1; i <= n; i++)
		if (f[i]) {
			cout << "NO" << endl;
			dfs2(1);
			cout << cn << endl;
			return;
		}
	
	cout << "YES" << endl;
	for (vi &r : res) {
		cout << r.size() << endl;
		for (int x : r)
			cout << x << " ";
		cout << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}