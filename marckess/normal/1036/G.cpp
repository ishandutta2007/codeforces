#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define FORR(i,a,b) for (int i = a; i <= b; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 1000005;
int n, m, u, v, d[MX], in[MX], cn = 0;
vi adj[MX], s;

void dfs (int u) {
	if (adj[u].empty())
		d[u] = 1 << cn++;

	for (int v : adj[u]) {
		if (!d[v]) dfs(v);
		d[u] |= d[v];
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	while (m--) {
		cin >> u >> v;
		adj[u].pb(v);
		in[v]++;
	}

	for (int i = 1; i <= n; i++)
		if (!in[i]) {
			dfs(i);
			s.pb(i);
		}

	n = s.size();
	for (int i = 1; i < (1 << n) - 1; i++) {
		int mk = 0;
		for (int j = 0; j < n; j++)
			if (i & (1 << j))
				mk |= d[s[j]];

		if (__builtin_popcount(i) ==  __builtin_popcount(mk)) {
			cout << "NO" << endl;
			return 0;
		}
	}
	
	cout << "YES" << endl;

	return 0;
}