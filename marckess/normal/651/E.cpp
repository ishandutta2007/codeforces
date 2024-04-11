#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define SET(p,k) memset(p, k, sizeof(p));
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

struct DS {
	vi p, rk;

	DS (int n) :  p(n+1), rk(n+1) {
		for (int i = 1; i <= n; i++)
			p[i] = i;
	}

	int parent (int a) {
		return a == p[a] ? a : p[a] = parent(p[a]);
	}

	void joint (int a, int b) {
		a = parent(a), b = parent(b);

		if (rk[a] > rk[b]) {
			p[b] = a;
		} else {
			p[a] = b;
			if (rk[a] == rk[b])
				rk[b]++;
		}
	}
};

int n, m, x[1000005], y[1000005], a[1000005], q[1000005], p[1000005];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;

	vvi res(n, vi(m));
	DS ds(n*m+1);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			int v = i*m+j+1;

			cin >> a[v];

			x[v] = i;
			y[v] = j;
			q[v] = v;
		}

	sort(q+1, q+n*m+1, [&](int _a, int _b) {
		return a[_a] < a[_b];
	});


	int ant = -1, mx;
	map<int, int> sx, sy;
	for (int i = 1; i <= n*m; i++) {
		int v = q[i];

		if (a[v] != ant) {
			ant = a[v];
			sx.clear();
			sy.clear();
		}

		if (sx[x[v]])
			ds.joint(sx[x[v]], v);
		if (sy[y[v]])
			ds.joint(sy[y[v]], v);

		sx[x[v]] = v;
		sy[y[v]] = v;
	}

	for (int i = 1; i <= n*m; i++)
		p[i] = ds.parent(i);

	sort(q+1, q+n*m+1, [&](int _a, int _b) {
		if (a[_a] != a[_b])
			return a[_a] < a[_b];
		return p[_a] < p[_b];
	});

	vi m_x(n), m_y(m);

	stack<int> st;
	ant = -1, mx = -1;
	for (int i = 1; i <= n*m; i++) {
		int v = q[i];

		if (p[v] != ant) {
			ant = p[v];
			mx++;

			while (st.size()) {
				int u = st.top();
				st.pop();
				res[x[u]][y[u]] = mx;
				
				m_x[x[u]] = mx;
				m_y[y[u]] = mx;
			}

			mx = -1;
		}

		st.push(v);
		mx = max(mx, max(m_x[x[v]], m_y[y[v]]));
	}

	mx++;
	while (st.size()) {
		int u = st.top();
		st.pop();
		res[x[u]][y[u]] = mx;
		
		m_x[x[u]] = mx;
		m_y[y[u]] = mx;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << res[i][j] << " ";
		cout << endl;
	}

	return 0;
}