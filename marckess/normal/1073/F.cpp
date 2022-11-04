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

const int MX = 200005;
int n, u, v, a[MX], b[MX], d[MX], na[MX], nb[MX];
ii dis[MX], rec[MX];
ii res, x, y;
vi adj[MX];
bitset<MX> bs;

ii operator + (ii a, ii b) {
	return ii(a.fi + b.fi, a.se + b.se);
}

void insert (int u, int k, int l) {
	if (k >= a[u]) {
		b[u] = a[u];
		a[u] = k;
		nb[u] = na[u];
		na[u] = l;
	} else if (k >= b[u]) {
		b[u] = k;
		nb[u] = l;
	}
}

void bfs () {
	queue<int> q;

	for (int i = 1; i <= n; i++)
		if (adj[i].size() >= 3 && d[i] + 1 == adj[i].size()) {
			bs[i] = 1;
			q.push(i);

			rec[i] = ii(na[i], nb[i]);
			dis[i] = ii(1, a[i]+b[i]);
		}

	while (q.size()) {
		int u = q.front();
		ii dd = dis[u] + ii(1, 0);
		q.pop();

		for (int v : adj[u]) {
			if (rec[u] != rec[v] && res < dd + dis[v]) {
				res = dd + dis[v];
				x = rec[u];
				y = rec[v];
			}

			if (!bs[v]) {
				d[v]++;
				if (d[v] + 1 == adj[v].size()) {
					q.push(v);
					bs[v] = 1;
				}

				if (dis[v] < dd) {
					dis[v] = dd;
					rec[v] = rec[u];
				}
			}
		}
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

	for (int i = 1; i <= n; i++)
		if (adj[i].size() == 1) {
			int u = i, cn = 0;

			while (1) {
				if (adj[u].size() >= 3) {
					d[u]++;
					insert(u, cn, i);
					break;
				}

				cn++;
				bs[u] = 1;
				for (int v : adj[u])
					if (!bs[v]) {
						u = v;
						break;
					}
			}
		}

	bfs();

	cout << x.fi << " " << y.se << endl;
	cout << y.fi << " " << x.se << endl;

	return 0;
}