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

#include <bits/extc++.h>
using namespace __gnu_pbds;
typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

const int MX = 1000005;
int n, q, a[MX], p[MX], cn[MX], res[MX], v[MX], l[MX], k[MX];
vi adj[MX], pos[MX];
ordered_set st;

void dfs (int u) {
	if (cn[a[u]])
		st.erase(ii(cn[a[u]], a[u]));
	st.insert(ii(++cn[a[u]], a[u]));
	
	for (int i : pos[u]) {
		int off = st.order_of_key(ii(l[i], -1));
		auto it = st.find_by_order(off + k[i] - 1);
		
		if (it == st.end()) res[i] = -1;
		else res[i] = it->se;
	}
	
	for (int v : adj[u])
		dfs(v);
	
	st.erase(ii(cn[a[u]]--, a[u]));
	if (cn[a[u]])
		st.insert(ii(cn[a[u]], a[u]));
}

void main_() {
	cin >> n >> q;
	
	for (int i = 1; i <= n; i++) {
		adj[i].clear();
		cn[i] = 0;
		pos[i].clear();
	}
	st.clear();
	
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	
	for (int i = 2; i <= n; i++) {
		cin >> p[i];
		adj[p[i]].pb(i);
	}
	
	forn (i, q) {
		cin >> v[i] >> l[i] >> k[i];
		pos[v[i]].pb(i);
	}
	
	dfs(1);
	
	forn (i, q)
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