#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

int n, a[100005], b[100005], c[100005], d[100005], q[100005], dist[100005], p[100005];

struct ST {
	vi a, mn, ind;

	ST (int n) : a(n+1), mn(4*n), ind(4*n) {}

	void constr (int i, int j, int pos) {
		if (i == j) {
			mn[pos] = a[i];
			ind[pos] = i;
			return;
		}

		int m = (i+j)/2;
		constr(i, m, pos*2);
		constr(m+1, j, pos*2+1);

		if (mn[pos*2] < mn[pos*2+1]) {
			mn[pos] = mn[pos*2];
			ind[pos] = ind[pos*2];
		} else {
			mn[pos] = mn[pos*2+1];
			ind[pos] = ind[pos*2+1];
		}
	}

	int query (int i, int j, int x, int pos) {
		if (i > x)
			return -1;

		if (j <= x)
			return ind[pos];

		int m = (i+j)/2;
		int f = query(i, m, x, pos*2);
		int g = query(m+1, j, x, pos*2+1);

		if (g == -1 || (f != -1 && a[f] < a[g]))
			return f;
		return g;
	}

	void update (int i, int j, int x, int pos) {
		if (i > x || j < x)
			return;

		if (i == j) {
			a[x] = 2e9;
			mn[pos] = 2e9;
			return;
		}

		int m = (i+j)/2;
		update(i, m, x, pos*2);
		update(m+1, j, x, pos*2+1);

		if (mn[pos*2] < mn[pos*2+1]) {
			mn[pos] = mn[pos*2];
			ind[pos] = ind[pos*2];
		} else {
			mn[pos] = mn[pos*2+1];
			ind[pos] = ind[pos*2+1];
		}
	}
};

void bfs (ST &st) {
	queue<int> qb;

	for (int i = 0; i < n; i++) {
		int u = q[i];

		if (a[u] == 0 && b[u] == 0) {
			dist[u] = 1;
			qb.push(u);
			p[u] = -1;
			st.update(1, n, i+1, 1);
		}
	}

	while (qb.size()) {
		int y = qb.front(); qb.pop();
		int x = upper_bound(q, q+n, c[y], [&] (const int x, int y) {
			return a[y] > x;
		}) - q, h;
		
		while (st.a[(h = st.query(1, n, x, 1))] <= d[y]) {

			dist[q[h-1]] = dist[y] + 1;
			p[q[h-1]] = y;

			qb.push(q[h-1]);
			st.update(1, n, h, 1);
		}
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	iota(q, q+n, 0);

	sort (q, q+n, [&] (int x, int y) {
		return a[x] < a[y];
	});

	ST st(n);
	for (int i = 0; i < n; i++)
		st.a[i+1] = b[q[i]];
	st.constr(1, n, 1);

	fill(dist, dist+n+1, -1);
	bfs(st);

	cout << dist[n-1] << endl;
	if (dist[n-1] > -1) {
		stack<int> res;

		n--;
		while (n != -1) {
			res.push(n+1);
			n = p[n];
		}

		while (res.size()) {
			cout << res.top() << " ";
			res.pop();
		}

		cout << endl;
	}

	return 0;
}