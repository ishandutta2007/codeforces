#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = (a); i <= (b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 150005, SIG = 27;
int n, q, lvl[MX], p[MX], sig[MX], mx[MX][SIG], h = -1, f[MX], s[MX];
int cn[MX][SIG], no;
char w[MX], in[MX];
vi adj[MX];
bitset<MX> bs;

int dfs (int u, int s) {
	sig[u] = s;

	if (adj[u].empty()) {
		if (h != -1 && h != lvl[u]) {
			while (q--) cout << "Fou" << endl;
			exit(0);
		}
		h = lvl[u];
	}

	if (adj[u].size() != 1) {
		for (int v : adj[u]) {
			lvl[v] = lvl[u] + 1;
			dfs(v, u);
		}
		
		f[u] = u;
		return u;
	}

	int ind;
	for (int v : adj[u]) {
		lvl[v] = lvl[u] + 1;
		ind = dfs(v, s);
	}

	f[u] = ind;
	return ind;
}

void update (int u, int c, int k) {
	w[u] = k > 0 ? c : 0;
	cn[f[u]][c] += k;

	while (u) {
		if (u == f[u]) {
			no -= bs[u];
			bs[u] = 0;
			s[u] -= mx[u][c];

			mx[u][c] = 0;
			for (int v : adj[u])
				mx[u][c] = max(mx[u][c], mx[f[v]][c] + cn[f[v]][c]);

			s[u] += mx[u][c];
			bs[u] = s[u] > lvl[u];
			no += bs[u];
		}

		u = sig[u];
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> q;
	for (int i = 2; i <= n; i++) {
		cin >> p[i] >> in[i];
		in[i] = in[i] == '?' ? 0 : in[i] - 'a' + 1;
		adj[p[i]].pb(i);
	}

	dfs(1, 1);
	f[1] = 1;
	sig[1] = 0;

	for (int i = 1; i <= n; i++)
		lvl[i] = h - lvl[i];

	for (int i = 2; i <= n; i++)
		if (in[i])
			update(i, in[i], 1);

	while (q--) {
		char c;
		int v;

		cin >> v >> c;
		c = c == '?' ? 0 : c - 'a' + 1;

		if (w[v]) update(v, w[v], -1);
		if (c) update(v, c, 1);

		if (no) cout << "Fou" << endl;
		else {
			int s = 0;
			for (int c = 1; c < SIG; c++)
				s += mx[1][c];

			ll res = 0;
			for (int c = 1; c < SIG; c++)
				res += c * (mx[1][c] + lvl[1] - s);
			cout << "Shi " << res << endl;
		}
	}

	return 0;
}