#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb emplace_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 400005, SIG = 26;
int nex[MX][SIG], fail[MX], out[MX], sz = 1, ocu[MX], finish[MX], go[MX][SIG];
int n, q, res[MX];
vii adj[MX];
string s[MX];
vi pos[MX];
map<string, int> mp;

void insert (string &s, int ind) {
	int u = 0;

	for (char c : s) {
		c -= 'a';

		if (!nex[u][c]) {
			nex[u][c] = sz;
			finish[sz] = -1;
			sz++;
		}

		u = nex[u][c];
	}

	finish[u] = ind;
}

int getFail (int u, int c) {
	if (go[u][c] != -1) return go[u][c];
	if (!u || nex[u][c]) return go[u][c] = nex[u][c];
	return go[u][c] = getFail(fail[u], c);
}

void build () {
	queue<int> q;
	
	for (int i = 0; i < 26; i++)
		if (nex[0][i])
			q.push(nex[0][i]);

	while (q.size()) {
		int u = q.front();
		q.pop();

		for (int i = 0; i < SIG; i++) {
			int v = nex[u][i];
			if (v && u) {
				fail[v] = getFail(fail[u], i);
				q.push(v);
				out[v] = finish[fail[v]] != -1 ? fail[v] : out[fail[v]];
			}
		}
	}
}

void dfs (int i, int u = 0) {
	int v = u;
	while (v) {
		if (finish[v] != -1)
			ocu[finish[v]]++;
		v = out[v];
	}

	for (int j : pos[i])
		res[j] = ocu[mp[s[j]]];

	for (ii &to : adj[i]) {
		int c = to.se - 'a';
		int w = getFail(u, c);
		dfs(to.fi, w);
	}

	v = u;
	while (v) {
		if (finish[v] != -1)
			ocu[finish[v]]--;
		v = out[v];
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(go, -1, sizeof(go));
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int op, x;
		char c;
		cin >> op;
		if (op == 1) {
			cin >> c;
			adj[0].pb(i, c);
		} else {
			cin >> x >> c;
			adj[x].pb(i, c);
		}
	}

	cin >> q;
	for (int i = 0; i < q; i++) {
		int in;
		cin >> in >> s[i];
		if (!mp.count(s[i])) {
			insert(s[i], mp.size());
			mp[s[i]] = mp.size() - 1;
		}
		pos[in].pb(i);
	}

	build();
	dfs(0);

	for (int i = 0; i < q; i++)
		cout << res[i] << endl;

	return 0;
}