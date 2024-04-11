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

const int MX = 1005, mod = 998244353;
int n, m, a[MX], dp[MX];
vi adj[MX], rev[MX];

ll res = 0;
int dfs (int u) {
	int &res = dp[u];
	if (res != -1) return res;
	res = a[u];
	
	for (int v : rev[u])
		(res += dfs(v)) %= mod;
	
	return res;
}

int f = 0;
int sim (int u) {
	int &res = dp[u];
	if (res != -1) return res;
	res = 0;
	
	if (a[u]) {
		a[u]--;
		res = 1;
		f = 1;
	}
	
	for (int v : rev[u])
		a[u] += sim(v);
	
	return res;
}

void main_() {
	cin >> n >> m;
	
	forr (i, 1, n) {
		cin >> a[i];
		adj[i].clear();
		rev[i].clear();
		dp[i] = -1;
	}
	
	forn (i, m) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		rev[v].pb(u);
	}
	
	ll res = 0;
	int root;
	forr (i, 1, n)
		if (!adj[i].size()) {
			root = i;
			res = dfs(i);
		}
	
	forn (t, n + 5) {
		forr (i, 1, n)
			dp[i] = -1;
		
		f = 0;
		res += sim(root) == 0;
		
		if (!f) {
			res--;
			break;
		}
	}
	
	cout << res % mod << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}