#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 300005;
int n, a[MX], u, v;
vi adj[MX];

ll s[MX], mx[MX], cn[MX];

void d (int u, int p) {
	mx[u] = s[u] = a[u];

	for (int v : adj[u])
		if (v != p) {
			d(v, u);
			if (s[v] > 0) s[u] += s[v];
			mx[u] = max(mx[u], mx[v]);
		}

	mx[u] = max(mx[u], s[u]);
}

void e (int u, int p, ll res) {
	s[u] = a[u];

	for (int v : adj[u])
		if (v != p) {
			e(v, u, res);
			if (s[v] > 0) s[u] += s[v];
			cn[u] += cn[v]; 
		}

	if (s[u] == res) {
		s[u] = -1;
		cn[u]++;
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	for (int i = 1; i < n; i++) {
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	d(1, 1);
	e(1, 1, mx[1]);

	cout << mx[1] * cn[1] << " " << cn[1] << endl;

	return 0;
}