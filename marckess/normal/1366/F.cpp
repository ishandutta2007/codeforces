#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 2005, mod = 1000000007;
const ll inf = 1e18, inv2 = (mod + 1) / 2;
int n, m, q, a[MX], b[MX], w[MX];
ll dis[MX][MX], res, d[MX];
vii adj[MX];

ll tri (ll n) {
	return n * (n + 1) % mod * inv2 % mod;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(dis, -1, sizeof(dis));

	cin >> n >> m >> q;

	forn (i, m) {
		cin >> a[i] >> b[i] >> w[i];
		adj[a[i]].emplace_back(b[i], w[i]);
		adj[b[i]].emplace_back(a[i], w[i]);
	}

	dis[0][1] = 0;

	for (int i = 1; i <= m; i++) {
		ll mx = 0;

		for (int u = 1; u <= n; u++) {
			for (ii &v : adj[u])
				if (dis[i - 1][v.fi] != -1)
					dis[i][u] = max(dis[i][u], dis[i - 1][v.fi] + v.se);

			mx = max(mx, dis[i][u]);
		}

		(res += mx) %= mod;
	}

	forn (i, m)
		d[i] = max(dis[m][a[i]], dis[m][b[i]]);

	#define cost(e,i) (d[e] + (i - m) * w[e])

	for (ll act = m + 1; act <= q;) {
		int ind = 0;

		forn (i, m)
			if (cost(i, act) > cost(ind, act))
				ind = i;

		ll nex = q + 1;

		forn (i, m)
			if (w[i] > w[ind]) {
				ll to = (d[ind] - d[i]) / (w[i] - w[ind]) + 1 + m;
				nex = min(nex, to);
			}

		(res += (tri(nex - m - 1) - tri(act - m - 1)) * w[ind] + (nex - act) * d[ind]) %= mod;
		act = nex;
	}

	cout << MOD(res, mod) << endl;

	return 0;
}