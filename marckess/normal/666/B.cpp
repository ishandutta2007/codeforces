#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

int n, m, u, v;
int in[3005][3], out[3005][3];
int x[3005][3], y[3005][3];
vvi adj, dis;

bitset<3005> vis;
void bfs (int o) {
	queue<int> q;
	q.push(o);

	vis.reset();
	dis[o][o] = 0;
	vis[o] = 1;
	
	while (q.size()) {
		int u = q.front();
		q.pop();

		for (int v : adj[u]) {
			if (!vis[v]) {
				dis[o][v] = dis[o][u] + 1;
				vis[v] = 1;
				q.push(v);
			}
		}
	}
}

void insertIO (int mx, int u, int a[], int b[]) {
	if (mx > a[0]) {
		a[2] = a[1], b[2] = b[1];
		a[1] = a[0], b[1] = b[0];
		a[0] = mx, b[0] = u;
	} else if (mx > a[1]) {
		a[2] = a[1], b[2] = b[1];
		a[1] = mx, b[1] = u;
	} else if (mx > a[2]) {
		a[2] = mx, b[2] = u;
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	adj = vvi(n+1);
	dis = vvi(n+1, vi(n+1, -1));

	while (m--) {
		cin >> u >> v;
		adj[u].push_back(v);
	}

	for (int i = 1; i <= n; i++)
		bfs(i);
	
	for (int i = 1; i <= n; i++) {
		for (int l = 0; l < 3; l++) {
			in[i][l] = 0;
			out[i][l] = 0;
		}

		for (int j = 1; j <= n; j++) {
			insertIO(dis[i][j], j, out[i], x[i]);
			insertIO(dis[j][i], j, in[i], y[i]);
		}
	}

	int ra, rb, rc, rd, mx = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j || dis[i][j] == -1)
				continue;

			int d = dis[i][j];

			for (int a = 0 ; a < 3; a++) {
				if (in[i][a] == 0 || y[i][a] == j)
					continue;

				for (int b = 0; b < 3; b++) {
					if (out[j][b] == 0 || x[j][b] == i || x[j][b] == y[i][a])
						continue;

					if (d + in[i][a] + out[j][b] > mx) {

						mx = d + in[i][a] + out[j][b];
						ra = y[i][a];
						rb = i;
						rc = j;
						rd = x[j][b];

					}
				}
			}

		}
	}

	cout << ra << " " << rb << " " << rc << " " << rd << endl;

	return 0;
}