#include <bits/stdc++.h>
#define endl '\n'
#define forn(i, n) for(int i = 0; i < n; i++)
#define rep(i, a, b) for(int i = a; i < b; i++)
#define pb push_back
#define fi first
#define se second
#define all(v) v.begin(), v.end()
using namespace std;

using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using vi = vector<int>;

const int MX = 100005, SQ = 316, SIG = 26;
int sig[MX][SIG], f[MX], sz = 1, val[MX];
vi fin[MX], pre[MX], adj[MX];

void insert (string &s, int ind) {
	int u = 0;
	pre[u].pb(ind);

	for (char c : s) {
		c -= 'a';
		if (!sig[u][c]) sig[u][c] = sz++;
		u = sig[u][c];
		pre[u].pb(ind);
	}

	fin[u].pb(ind);
}

int getFail (int u, int c) {
	while (u && !sig[u][c])
		u = f[u];
	return sig[u][c];
}

void build () {
	queue<int> q;

	for (int i = 0; i < SIG; i++)
		if (sig[0][i])
			q.push(sig[0][i]);

	while (q.size()) {
		int u = q.front();
		q.pop();

		for (int i = 0; i < SIG; i++)
			if (sig[u][i]) {
				int v = sig[u][i];
				f[v] = getFail(f[u], i);
				q.push(v);
			}
	}

	for (int i = 1; i < sz; i++)
		adj[f[i]].pb(i);
}

int n, q, l[MX], r[MX], k[MX];
string s[MX];
vi p1[MX], p2[MX];
ll res[MX], a[MX], acu[MX];

void update (int i, int k) {
	while (i <= n && i % SQ)
		a[i++] += k;

	while (i < n) {
		acu[i / SQ] += k;
		i += SQ; 
	}
}

ll query (int i) {
	return a[i] + acu[i / SQ];
}

void dfs (int u) {
	for (int v : fin[u])
		if (s[v].size() < SQ)
			update(v, 1);

	for (int v : pre[u])
		for (int j : p1[v])
			res[j] += query(r[j]) - query(l[j] - 1);

	for (int v : adj[u])
		dfs(v);

	for (int v : fin[u])
		if (s[v].size() < SQ)
			update(v, -1);
}

void update (string &s, int k) {
	int u = 0;
	val[u] = k;

	for (char c : s) {
		c -= 'a';
		u = sig[u][c];
		val[u] = k;
	}
}

int dfs (int u, int i) {
	int cn = val[u];

	for (int v : adj[u])
		cn += dfs(v, i);

	for (int v : fin[u])
		a[v] += cn;

	return cn;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
    	cin >> s[i];
    	insert(s[i], i);
    }
    build();

    for (int i = 0; i < q; i++) {
    	cin >> l[i] >> r[i] >> k[i];
    	if (s[k[i]].size() < SQ) p1[k[i]].pb(i);
    	else p2[k[i]].pb(i);
    }

    dfs(0);

    for (int i = 1; i <= n; i++)
    	if (p2[i].size()) {
    		memset(a, 0, sizeof(a));

    		update(s[i], 1);
    		dfs(0, i);
    		update(s[i], 0);
    		
    		for (int i = 2; i <= n; i++)
    			a[i] += a[i - 1];

    		for (int j : p2[i])
    			res[j] = a[r[j]] - a[l[j] - 1];
    	}

    for (int i = 0; i < q; i++)
    	cout << res[i] << endl;

    return 0;
}