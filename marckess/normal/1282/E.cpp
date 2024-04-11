#include <bits/stdc++.h>
 
//#define endl '\n'
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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 100005;
int n, s[MX][3], x[MX], y[MX], d[MX];
vi pos[MX], p, r;
bitset<MX> ex, vis;
queue<int> q;

void reset () {
	for (int i = 1; i <= n; i++) {
		x[i] = y[i] = 0;
		pos[i].clear();
		ex[i] = 1;
		vis[i] = 0;
	}
	p.clear();
	r.clear();
}

bool isAdj (int u, int v) {
	return x[u] == v || y[u] == v;
}

void erase (int u, int v) {
	if (x[u] == v) x[u] = 0;
	if (y[u] == v) y[u] = 0;
	if (x[v] == u) x[v] = 0;
	if (y[v] == u) y[v] = 0;
}

void add (int u, int v) {
	if (x[u]) y[u] = v;
	else x[u] = v;

	if (x[v]) y[v] = u;
	else x[v] = u;
}

void dfs (int u) {
	if (vis[u]) return;
	vis[u] = 1;
	p.pb(u);

	dfs(x[u]);
	dfs(y[u]);
}

void solve () {
	cin >> n;
	reset();

	for (int i = 1; i <= n - 2; i++)
		for (int j = 0; j < 3; j++) {
			cin >> s[i][j];
			d[s[i][j]]++;
			pos[s[i][j]].pb(i);
		}

	for (int i = 1; i <= n; i++)
		if (d[i] == 1)
			q.push(i);

	while (q.size()) {
		int u = q.front();
		q.pop();

		for (int j : pos[u])
			if (ex[j]) {
				for (int k = 0; k < 3; k++) {
					d[s[j][k]]--;
					if (d[s[j][k]] == 1) 
						q.push(s[j][k]);
				}
				ex[j] = 0;
				r.pb(j);
			}
	}

	reverse(all(r));
	for (int j : r) {
		int ind = -1;
		for (int k = 0; k < 3; k++)
			if (isAdj(s[j][k], s[j][(k+1)%3])) {
				erase(s[j][k], s[j][(k+1)%3]);
				ind = k;
			}

		for (int k = 0; k < 3; k++)
			if (k != ind)
				add(s[j][k], s[j][(k+1)%3]);
	}
	reverse(all(r));
	dfs(1);

	for (int x : p) cout << x << " ";
	cout << endl;
	for (int x : r) cout << x << " ";
	cout << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}