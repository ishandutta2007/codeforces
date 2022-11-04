#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 300005;
int n, m, res[MX];
vi adj[MX];

void dfs (int u) {
	for (int v : adj[u])
		if (res[v] == -1) {
			res[v] = 1 - res[u];
			dfs(v);
		}

	int cn = 0;
	for (int v : adj[u])
		cn += res[u] == res[v];

	if (cn > 1) res[u] = 1 - res[u]; 
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	
	while (m--) {
		int a, b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	memset(res, -1, sizeof(res));
	for (int i = 1; i <= n; i++)
		if (res[i] == -1) {
			res[i] = 0;
			dfs(i);
		}

	for (int i = 1; i <= n; i++)
		cout << res[i];
	cout << endl;

	return 0;
}