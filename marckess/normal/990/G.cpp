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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;

int gcd (int a, int b) {
	return b ? gcd(b, a%b) : a;
}

int n, a[MX], u[MX], v[MX], g[MX];
ll res[MX], cn = 0;
vi adj[MX], pos[MX];
bitset<MX> bs;

void dfs (int u) {
	bs[u] = 1;
	cn++;
	for (int v : adj[u])
		if (!bs[v])
			dfs(v);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];

	for (int i = 0; i < n-1; i++) {
		cin >> u[i] >> v[i];
		g[i] = gcd(a[u[i]], a[v[i]]);
		pos[g[i]].pb(i);
	}

	for (int i = MX-1; i > 0; i--) {
		for (int j = i; j < MX; j += i) {
			for (int x : pos[j]) {
				adj[u[x]].pb(v[x]);
				adj[v[x]].pb(u[x]);
				//if (i == 1) cout << u[x] << " " <<v[x] << endl;
			}
		}

		for (int j = i; j < MX; j += i)
			for (int x : pos[j]) {
				if (!bs[u[x]]) {
					dfs(u[x]);
					res[i] += cn * (cn - 1) / 2;
					cn = 0;
				}
			}

		for (int j = i; j < MX; j += i) {
			for (int x : pos[j]) {
				adj[u[x]].clear();
				adj[v[x]].clear();
				bs[u[x]] = 0;
				bs[v[x]] = 0;
			}
			if (i != j) res[i] -= res[j];
		}
	}

	for (int i = 1; i <= n; i++)
		res[a[i]]++;

	for (int i = 1; i < MX; i++)
		if (res[i])
			cout << i << " " << res[i] << endl;

	return 0;
}