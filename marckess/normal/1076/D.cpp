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
typedef pair<ll, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 300005;
int n, m, k, q[MX];
ll x[MX], y[MX], w[MX], d[MX], p[MX];
vi adj[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	fill(d, d+MX, -1);

	cin >> n >> m >> k;

	for (int i = 1; i <= m; i++) {
		cin >> x[i] >> y[i] >> w[i];
		adj[x[i]].pb(i);
		adj[y[i]].pb(i);
	}

	priority_queue<ii, vii, greater<ii>> pq;
	pq.emplace(0, 1);
	d[1] = 0;

	while (pq.size()) {
		ll e, u;
		tie(e, u) = pq.top();
		pq.pop();

		if (e > d[u]) continue;

		for (int i : adj[u]) {
			if (y[i] == u) swap(x[i], y[i]);

			if (d[y[i]] == -1 || d[u] + w[i] < d[y[i]]) {
				d[y[i]] = d[u] + w[i];
				pq.emplace(d[u] + w[i], y[i]);
				p[y[i]] = i;
			}
		}
	}

	iota(q, q+n-1, 2);
	sort(q, q+n-1, [&] (int i, int j) {
		return d[i] < d[j];
	});

	cout << min(n-1, k) << endl;
	for (int i = 0; i < min(n-1, k); i++)
		cout << p[q[i]] << " ";

	return 0;
}