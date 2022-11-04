
// Problem : D. Treelabeling
// Contest : Codeforces - Codeforces Round #754 (Div. 2)
// URL : https://codeforces.com/contest/1605/problem/D
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
int n, res[MX];
vi adj[MX], a, b;

void dfs (int u, int p, int c) {
	if (c) a.pb(u);
	else b.pb(u);
	
	for (int v : adj[u])
		if (v != p)
			dfs(v, u, 1 - c);
}

void main_() {
	cin >> n;
	
	set<int> st;
	for (int i = 1; i <= n; i++) {
		adj[i].clear();
		st.insert(i);
	}
	a.clear();
	b.clear();
	
	forn (i, n - 1) {
		int u, v;
		cin >> u >> v;
		
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	dfs(1, 1, 0);
	
	if (a.size() > b.size())
		swap(a, b);
	
	vi in;
	forn (i, 20)
		if (a.size() & (1 << i))
			for (int j = 1 << i; j < (1 << (i + 1)); j++) {
				in.pb(j);
				st.erase(j);
			}
	
	forn (i, a.size())
		res[a[i]] = in[i];
	
	forn (i, b.size()) {
		res[b[i]] = *st.begin();
		st.erase(st.begin());
	}
	
	for (int i = 1; i <= n; i++)
		cout << res[i] << " ";
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