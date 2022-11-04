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

const int MX = 1005;
int n, m, d[3][MX][MX], e[3][3];
int mx[] = {1, -1, 0, 0};
int my[] = {0, 0, 1, -1};
char a[MX][MX];

void bfs (char o, int d[MX][MX]) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			d[i][j] = -1;

	queue<ii> q;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (a[i][j] == o) {
				q.emplace(i, j);
				d[i][j] = 0;
			}

	while (q.size()) {
		int i, j;
		tie(i, j) = q.front();
		q.pop();

		for (int l = 0; l < 4; l++) {
			int x = i + mx[l];
			int y = j + my[l];

			if (x < 0 || y < 0 || x >= n || y >= m || d[x][y] != -1 || a[x][y] == '#') continue;
			d[x][y] = d[i][j] + 1;
			q.emplace(x, y);
		}
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	bfs('1', d[0]);
	bfs('2', d[1]);
	bfs('3', d[2]);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			for (int l = 0; l < 3; l++)
				if (d[l][i][j] == -1)
					d[l][i][j] = 2e9;

	for (int i = 0; i < 3; i++)
		fill(e[i], e[i]+3, int(2e9));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (a[i][j] == '1') {
				e[0][1] = min(e[0][1], d[1][i][j]);
				e[0][2] = min(e[0][2], d[2][i][j]);
			}

			if (a[i][j] == '2') {
				e[1][0] = min(e[1][0], d[0][i][j]);
				e[1][2] = min(e[1][2], d[2][i][j]);
			}

			if (a[i][j] == '3') {
				e[2][0] = min(e[2][0], d[0][i][j]);
				e[2][1] = min(e[2][1], d[1][i][j]);
			}
		}

	ll res = 1e9;
	int o[] = {0, 1, 2};

	do res = min(res, (ll)e[o[0]][o[1]] + e[o[1]][o[2]] - 2ll);
	while (next_permutation(o, o+3));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (a[i][j] == '.')
				res = min(res, (ll)d[0][i][j] + d[1][i][j] + d[2][i][j] - 2);

	if (res == 1e9) cout << -1 << endl;
	else cout << res << endl;

	return 0;
}