#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 1000005;
int n, m, b[MX];
ii a[MX];
set<int> st;
vi adj[MX];
bitset<MX> vis;

void no () {
	cout << "NO" << endl;
	exit(0);
}

void add (int u, int v) {
	adj[u].pb(v);
	adj[v].pb(u);
	m++;
	if (m > n) no();
}

void dfs (int u, int p) {
	vis[u] = 1;

	for (int v : adj[u])
		if (v != p) {
			if (vis[v])
				no();
			dfs(v, u);
		}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	forn(i, n)
		cin >> a[i].fi >> a[i].se;
	sort(a, a+n);

	for (int i = 0; i < n; i++) {
		while (st.size() && *st.begin() < a[i].fi)
			st.erase(st.begin());

		auto it = st.begin();
		while (it != st.end() && *it < a[i].se) {
			add(i, b[*it]);
			it++;
		}

		st.insert(a[i].se);
		b[a[i].se] = i;
	}

	dfs(0, 0);
	if (vis.count() == n) {
		cout << "YES" << endl;
	} else {
		no();
	}

	return 0;
}