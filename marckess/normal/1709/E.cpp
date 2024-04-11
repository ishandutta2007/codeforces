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
int n, a[MX], acu[MX];
vi adj[MX];
set<int> st[MX];

void pre (int u, int p) {
	acu[u] ^= a[u];
	
	for (int v : adj[u])
		if (v != p) {
			acu[v] = acu[u];
			pre(v, u);
		}
}

int res;
void dfs (int u, int p) {
	int f = 0;
	st[u].insert(acu[u]);
	
	for (int v : adj[u])
		if (v != p) {
			dfs(v, u);
			
			if (st[u].size() < st[v].size())
				swap(st[u], st[v]);
			
			for (int x : st[v])
				if (st[u].count(x ^ a[u]))
					f = 1;
			
			for (int x : st[v])
				st[u].insert(x);
			
			st[v].clear();
		}
	
	if (f) {
		st[u].clear();
		res++;
	}
}

void main_() {
	cin >> n;

	forr (i, 1, n)
		cin >> a[i];
		
	forn (i, n - 1) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	pre(1, 1);
	dfs(1, 1);
	
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}