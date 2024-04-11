#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define SET(p,k) memset(p, k, sizeof(p));
#define MOD(n,k) ((((n) % (k)) + (k)) % (k))
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

vvi adj;
bitset<100005> col;
vi p;
int n, a, b;

void obtcol (int u, int c) {
	for (int v : adj[u]) {
		if (v != p[u]) {
			col[v] = 1 - c;
			p[v] = u;
			obtcol(v, 1-c);
		}
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	adj = vvi(n+1);

	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	p = vi(n+1);
	obtcol(1, 0);

	ll res = 0;
	for (int i = 1; i <= n; i++) {
		if (!col[i]) {
			res += col.count() - adj[i].size();
		}
	}

	cout << res << endl;

	return 0;
}