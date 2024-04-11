#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

struct DSU {
	vi rk, p, tam;

	DSU () : rk(1e6+5), p(1e6+5), tam(1e6+5, 1) {
		iota(p.begin(), p.end(), 0);
	}

	void init () {
		fill(rk.begin(), rk.end(), 0);
		fill(tam.begin(), tam.end(), 1);
		iota(p.begin(), p.end(), 0);
	}

	int parent (int a) {
		return a == p[a] ? a : p[a] = parent(p[a]);
	}

	bool joint (int a, int b) {
		a = parent(a), b = parent(b);
		if (a == b)
			return 0;

		if (rk[a] > rk[b]) {
			tam[a] += tam[b];
			p[b] = a;
		} else {
			tam[b] += tam[a];
			p[a] = b;
			if (rk[a] == rk[b])
				rk[b]++;
		}

		return 1;
	}
};

int n, a[1000010], x, y, q[1000010];
vi adj[1000010];
DSU ds;
ll res = 0;
bitset<1000010> bs;
ll st[1000010];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		q[i] = i;
	}

	for (int i = 1; i < n; i++) {
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	sort(q+1, q+n+1, [&] (int x, int y) {
		return a[x] < a[y];
	});

	for (int i = 1; i <= n; i++) {
		int u = q[i];

		ll sum = 0;
		int j = 0;

		for (int v : adj[u]) {
			if (!bs[v])
				continue;
			sum += ds.tam[ds.parent(v)];
			st[j++] = ds.tam[ds.parent(v)];
			ds.joint(u, v);
		}

		res += a[u] * sum + a[u];
		for (int k = 0; k < j; k++) {
			ll d = st[k];
			sum -= d;
			res += a[u] * d * sum;
		}

		bs[u] = 1;
	}

	ds.init();
	bs.reset();
	for (int i = n; i; i--) {
		int u = q[i];

		ll sum = 0;
		int j = 0;

		for (int v : adj[u]) {
			if (!bs[v])
				continue;
			sum += ds.tam[ds.parent(v)];
			st[j++] = ds.tam[ds.parent(v)];
			ds.joint(u, v);
		}

		res -= a[u] * sum + a[u];
		for (int k = 0; k < j; k++) {
			ll d = st[k];
			sum -= d;
			res -= a[u] * d * sum;
		}

		bs[u] = 1;
	}

	cout << res << endl;

	return 0;
}