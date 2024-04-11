#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 1005, MQ = 100005;
int n, m, k, q, a[MX][MX], dis[MX][MX], vis[MX];
int r1[MQ], c1[MQ], r2[MQ], c2[MQ], res[MQ];
int mx[] = {1, -1, 0, 0};
int my[] = {0, 0, 1, -1};
vii pos[45];

bool valid (int i, int j) {
	return 1 <= i && i <= n && 1 <= j && j <= m;
}

void bfs (int i) {
	memset(vis, 0, sizeof(vis));
	memset(dis, -1, sizeof(dis));
	queue<ii> q;

	for (ii &u : pos[i]) {
		q.emplace(u.fi, u.se);
		dis[u.fi][u.se] = 0;
	}
	vis[i] = 1;

	while (q.size()) {
		int i = q.front().fi, j = q.front().se;
		q.pop();

		if (!vis[a[i][j]]) {
			for (ii &u : pos[a[i][j]])
				if (dis[u.fi][u.se] == -1) {
					dis[u.fi][u.se] = dis[i][j] + 1;
					q.emplace(u.fi, u.se);
				}
			vis[a[i][j]] = 1;
		}

		for (int l = 0; l < 4; l++) {
			int x = i + mx[l];
			int y = j + my[l];

			if (valid(x, y) && dis[x][y] == -1) {
				dis[x][y] = dis[i][j] + 1;
				q.emplace(x, y);
			}
		}
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
			pos[a[i][j]].emplace_back(i, j);
		}

	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> r1[i] >> c1[i] >> r2[i] >> c2[i];
		res[i] = abs(r1[i] - r2[i]) + abs(c1[i] - c2[i]);
	}

	for (int i = 1; i <= k; i++) {
		bfs(i);
		for (int j = 0; j < q; j++)
			res[j] = min(res[j], dis[r1[j]][c1[j]] + 1 + dis[r2[j]][c2[j]]);
	}

	for (int i = 0; i < q; i++)
		cout << res[i] << endl;

	return 0;
}