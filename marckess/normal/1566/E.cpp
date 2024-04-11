
// Problem : E. Buds Re-hanging
// Contest : Codeforces - Codeforces Global Round 16
// URL : https://codeforces.com/contest/1566/problem/E
// Memory Limit : 256 MB
// Time Limit : 1000 ms
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
int n, x[MX], nh, acu, res;
vi adj[MX];

bool dfs (int u, int p) {
	int cn = 0;
	for (int v : adj[u])
		if (v != p)
			cn += dfs(v, u);
	
	if (u != 1) {
		if (adj[u].size() == 1)
			nh++;
		
		if (cn) {
			acu += x[u] = 1;
			return 0;
		} else if (adj[u].size() != 1) {
			acu += x[u] = -1;
		}
	}
	return 1;
}

void dfs (int u, int p, int s) {
	if (u != 1 && adj[u].size() == 1)
 		res = min(res, nh - (acu - s));
	
	s += x[u];
	for (int v : adj[u])
		if (v != p)
			dfs(v, u, s);
}

void main_() {
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		adj[i].clear();
		x[i] = 0;
	}
	acu = nh = 0;
	
	forn (i, n - 1) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	dfs(1, 1);
	res = nh;
	
	dfs(1, 1, 0);
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}