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
typedef vector<ii> vii;

const int MX = 200005;
int n, p[MX], u, v;
vi adj[MX], gra[MX], a, b;
bitset<MX> bs;

void dfs (int u) {
	for (int v : adj[u])
		if (v != p[u]) {
			p[v] = u;
			dfs(v);
		}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	p[1] = 1;
	dfs(1);

	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i) gra[p[a[i]]].pb(a[i]);
	}

	queue<int> q;
	q.push(1);
	bs[1] = 1;

	while (q.size()) {
		int u = q.front();
		q.pop();
		b.pb(u);
		bs[u] = 1;

		for (int v : gra[u]) {
			if (bs[v]) {
				cout << "No" << endl;
				return 0;
			}
			q.push(v);
		}
	}

	if (a[0] == 1 && a == b) cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}