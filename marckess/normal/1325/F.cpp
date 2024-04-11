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
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int MX = 100005;
int n, m, lvl[MX], p[MX], sq, vis[MX];
vi adj[MX];
bitset<MX> bs;

void dfs (int u) {
	int cn = 0;
	vis[u] = 1;

	for (int v : adj[u]) {
		if (vis[v]) cn++;
		else {
			lvl[v] = lvl[u] + 1;
			p[v] = u;
			dfs(v);
		}
	}

	if (cn >= sq - 1) {
		int ind = adj[u][0];
		for (int v : adj[u])
			if (lvl[v] < lvl[ind])
				ind = v;

		cout << 2 << endl << lvl[u] - lvl[ind] + 1 << endl;
		do {
			cout << u << " ";
			if (u == ind) break;
			u = p[u];
		} while (u);
		cout << endl;

		exit(0);
	} else if (bs[u]) {
		for (int v : adj[u])
			if (lvl[v] < lvl[u])
				bs[v] = 0;
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	bs.set();

	cin >> n >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	for (int i = max(1, (int)sqrt(n) - 10); i <= (int)sqrt(n) + 10; i++)
		if (i * i >= n) {
			sq = i;
			break;
		}

	dfs(1);

	cout << 1 << endl;
	for (int i = 1; i <= n && sq; i++)
		if (bs[i]) {
			cout << i << " ";
			sq--;
		}
	cout << endl;

	return 0;
}