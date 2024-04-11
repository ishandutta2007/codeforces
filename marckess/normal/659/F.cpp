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

struct DS {
	vi p, rk, tam;

	DS (int n) : p(n+1), rk(n+1), tam(n+1, 1) {
		for (int i = 1; i <= n; i++)
			p[i] = i;
	}

	int parent (int a) {
		return a == p[a] ? a : p[a] = parent(p[a]);
	}

	void joint (int a, int b) {
		a = parent(a), b = parent(b);

		if (a == b)
			return;

		if (rk[a] > rk[b]) {
			p[b] = a;
			tam[a] += tam[b];
		} else {
			p[a] = b;
			tam[b] += tam[a];
			if (rk[a] == rk[b])
				rk[b]++;
		}
	}

	ll size (int a) {
		return tam[parent(a)];
	}
};

int n, m, a[1005][1005], x[1000005], y[1000005], v[1000005];
int mv[] = {1, 0, -1, 0, 0, 1, 0, -1};
ll k, c;
vvi res;

void dfs (int i, int j, int w) {
	if (!c || i < 0 || j < 0 || i >= n || j >= m || a[i][j] < w)
		return;

	res[i][j] = w;
	a[i][j] = -1;
	c--;

	for (int l = 0; l < 4; l++) {
		int x = i + mv[l*2];
		int y = j + mv[l*2+1];

		dfs(x, y, w);
	}
}

bool obtRes () {
	DS ds(n*m);

	for (int i = 0; i < n*m; i++) {
		int u = v[i];
		ll w = a[x[u]][y[u]];
		
		for (int l = 0; l < 4; l++) {
			int g = x[u] + mv[l*2];
			int h = y[u] + mv[l*2+1];

			if (g < 0 || h < 0 || g >= n || h >= m)
				continue;

			if (a[g][h] >= w)
				ds.joint(u, g*m+h);
		}

		if (k % w == 0 && ds.size(u) >= k / w) {
			c = k / w;
			dfs(x[u], y[u], w);
			if (c != 0)
				exit(-1);
			return true;
		}
	}

	return false;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int u = i * m + j;

			cin >> a[i][j];
			x[u] = i;
			y[u] = j;
			v[u] = u;
		}
	}
	sort(v, v+n*m, [&](int i, int j) {
		return a[x[i]][y[i]] > a[x[j]][y[j]];
	});

	res = vvi(n, vi(m));
	if (obtRes()) {
		cout << "YES" << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << res[i][j] << " ";
			}
			cout << endl;
		}
	} else {
		cout << "NO" << endl;
	}

	return 0;
}