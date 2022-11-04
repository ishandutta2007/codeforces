// Powered by CP Editor (https://cpeditor.org)

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
int n, p[MX], root;
vi adj[MX];
vvi res;

void dfs (int u, int p, vi &c) {
	c.pb(u);
	
	int f = 0;
	for (int v : adj[u])
		if (v != p)
			if (f) {
				vi nc;
				dfs(v, u, nc);
				res.pb(nc);
			} else {
				dfs(v, u, c);
				f = 1;
			}
}

void main_() {
	cin >> n;
	
	res.clear();
	forr (i, 1, n) {
		adj[i].clear();
	}
	
	forr (i, 1, n) {
		cin >> p[i];
		
		if (i != p[i])
			adj[p[i]].pb(i);
		else
			root = i;
	}
	
	vi v;
	dfs(root, -1, v);
	res.pb(v);
	
	cout << res.size() << endl;
	for (vi &v : res) {
		cout << v.size() << endl;
		for (int u : v)
			cout << u << " ";
		cout << endl;
	}
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}