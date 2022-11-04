#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define find(v,x) (lower_bound(ALL(v), x) - v.begin())

typedef long long ll;
typedef long double ld;
typedef pair<ll, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 500005;
int n, u, v, lvl[MX], ml;
vi adj[MX];

void dfs (int u, int p, int l) {
	if (adj[u].size() == 1) {
		lvl[l]++;
		ml = max(l, ml);
		return;
	}

	for (int v : adj[u])
		if (v != p)
			dfs(v, u, l+1);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int res = 0, acu = 0, l = 0;

	for (int v : adj[1]) {
		acu = 0, l = 0, ml = 0;
		dfs(v, 1, 1);

		while (acu || l <= ml) {
			if (l <= ml) {
				acu += lvl[l];
				lvl[l] = 0;
			}
			if (acu) {
				res = max(res, l);
				acu--;
			}
			l++;
		}
	}

	cout << res << endl;

	return 0;
}