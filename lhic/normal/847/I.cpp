#include <bits/stdc++.h>

typedef long long ll;
typedef long long llong;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/

int n, m, q, p;

ll ans[300][300];
int tm1;
int tt[300][300];
int qb, qe;
pair<int, int> qu[300 * 300];
int go[300][300];
char s[300][300];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void bfs(int x, int y, int k) {
	++tm1;
	qe = 1;
	qb = 0;
	qu[0] = make_pair(x, y);
	ans[x][y] += k;
	go[x][y] = k;
	tt[x][y] = tm1;
	while (qb != qe) {
		int x, y;
		tie(x, y) = qu[qb++];
		int gg = go[x][y] / 2;
		if (gg == 0)
			break;
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m || s[nx][ny] == '*' || tt[nx][ny] == tm1)
				continue;
			tt[nx][ny] = tm1;
			go[nx][ny] = gg;
			qu[qe++] = make_pair(nx, ny);
			ans[nx][ny] += gg;
		}
	}
}

int main() {
	scanf("%d%d%d%d", &n, &m, &q, &p);
	for (int i = 0; i < n; ++i)
		scanf(" %s", s[i]);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			if (s[i][j] != '*' && s[i][j] != '.') {
				int x = s[i][j] - 'A' + 1;
				bfs(i, j, x * q);
			}
		}
	int an = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (ans[i][j] > p)
				++an;
	cout << an << "\n";
	return 0;
}