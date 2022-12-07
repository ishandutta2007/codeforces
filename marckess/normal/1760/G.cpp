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

const int MX = 100005;
int n, a, b, acu[MX];
vii adj[MX];
set<int> st;

void dfs (int u, int p) {
	for (auto [v, w] : adj[u])
		if (v != p) {
			acu[v] = acu[u] ^ w;
			dfs(v, u);
		}
}

int f;
void go (int u, int p) {
	f |= st.count(acu[u] ^ acu[a]);
	for (auto [v, _] : adj[u])
		if (v != p && v != b)
			go(v, u);
}

void main_() {
	cin >> n >> a >> b;
	
	forr (i, 1, n) {
		adj[i].clear();
	}
	st.clear();
	
	forn (i, n - 1) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].pb({v, w});
		adj[v].pb({u, w});
	}
	
	acu[1] = 0;
	dfs(1, 1);
	
	if ((acu[a] ^ acu[b]) == 0) {
		cout << "YES" << endl;
		return;
	}
	
	forr (i, 1, n) {
		if (i != b) {
			st.insert(acu[i] ^ acu[b]);
		}
	}
	
	f = 0;
	go(a, a);
	
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