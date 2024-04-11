#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 155;
typedef vector<bitset<MX>> vbs;

int n, m, a[MX], b[MX], d[MX], q[MX], dist[MX];
vbs bs, res;
vi adj[MX];

void init (vbs &v) {
	for (int i = 0; i < n; i++)
		v[i][i] = 1;
}

void cpy (vbs &v, vbs &w) {
	for (int i = 0; i < n; i++)
		v[i] = w[i];
}

void setMat (vbs &v, int i) {
	for (int j = 0; j < n; j++)
		v[j].reset();

	for (int j = 0; j < m && d[q[j]] <= i; j++)
		v[a[q[j]]][b[q[j]]] = 1;
}

vbs mul (vbs &a, vbs &b) {
	vbs c(n), res(n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			c[i][j] = b[j][i];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			res[i][j] = (a[i] & c[j]).any();

	return res;
}

vbs pot (vbs &base, int p) {
	vbs res(n); init(res);
	vbs b(n); cpy(b, base);

	while (p) {
		if (p & 1) res = mul(res, b);
		b = mul(b, b);
		p /= 2;
	}

	return res;
}

void bfs (int d) {
	queue<int> q;

	for (int i = 0; i < n; i++) dist[i] = -1;

	for (int i = 0; i < n; i++)
		if (res[0][i]) {
			q.push(i);
			dist[i] = d;
		}

	while (q.size()) {
		int u = q.front();
		q.pop();

		for (int v : adj[u])
			if (dist[v] == -1) {
				dist[v] = dist[u] + 1;
				q.push(v);
			}
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	bs.resize(n);
	res.resize(n); init(res);

	for (int i = 0; i < m; i++) {
		cin >> a[i] >> b[i] >> d[i];
		a[i]--, b[i]--;
	}

	iota(q, q+m, 0);
	sort(q, q+m, [&] (int i, int j) {
		return d[i] < d[j];
	});

	if (d[q[0]]) {
		cout << "Impossible" << endl;
		return 0;
	}

	int i = 0, j;

	while (i < m) {
		j = i;

		while (j < m && d[q[i]] == d[q[j]]) {
			adj[a[q[j]]].pb(b[q[j]]);
			j++;
		}

		bfs(d[q[i]]);
		if (dist[n-1] != -1) {
			cout << dist[n-1] << endl;
			return 0;
		}

		if (j < m) {
			setMat(bs, d[q[i]]);
			bs = pot(bs, d[q[j]] - d[q[i]]);
			res = mul(res, bs);
		}

		i = j;
	}

	cout << "Impossible" << endl;

	return 0;
}