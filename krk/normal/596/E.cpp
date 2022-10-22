#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 205;
const int Maxd = 10;
const int Inf = 1000000000;
const int Maxl = 1000005;

int n, m, q;
char B[Maxn][Maxn];
int a[Maxd], b[Maxd];
int from[Maxn][Maxn], f[Maxn][Maxn];
int best[Maxn][Maxn];
ii par[Maxn][Maxn];
bool my[Maxn][Maxn][Maxd], inloop[Maxn][Maxn];
int tk[Maxn][Maxn];
char str[Maxl];
int slen;
bool has[Maxl][Maxd];

void Calc(int r, int c, ii p = ii(0, 0))
{
	if (tk[r][c] == -1) {
		bool has[Maxd] = {};
		ii cur = p;
		inloop[cur.first][cur.second] = true;
		has[B[cur.first][cur.second] - '0'] = true;
		do {
			cur = par[cur.first][cur.second];
			inloop[cur.first][cur.second] = true;
			has[B[cur.first][cur.second] - '0'] = true;
		} while (cur != ii(r, c));

		cur = p;
		for (int i = 0; i < Maxd; i++) my[cur.first][cur.second][i] = has[i];
		do {
			cur = par[cur.first][cur.second];
			for (int i = 0; i < Maxd; i++) my[cur.first][cur.second][i] = has[i];
		} while (cur != ii(r, c));
	} else {
		par[r][c] = p; tk[r][c] = -1;
		int val = B[r][c] - '0';
		ii u = ii(r + a[val], c + b[val]);
		if (1 <= u.first && u.first <= n && 1 <= u.second && u.second <= m) {
			from[u.first][u.second]++;
			if (tk[u.first][u.second] <= 0) Calc(u.first, u.second, ii(r, c));
		} else {
			inloop[r][c] = true; my[r][c][B[r][c] - '0'] = true;
		}
		tk[r][c] = 1;
	}
}

bool Check()
{
	fill(has[slen], has[slen] + Maxd, false);
	for (int i = slen - 1; i >= 0; i--) {
		for (int j = 0; j < Maxd; j++)
			has[i][j] = has[i + 1][j];
		has[i][str[i] - '0'] = true;
	}
	queue <ii> Q;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			f[i][j] = from[i][j]; best[i][j] = 0;
			if (f[i][j] == 0) Q.push(ii(i, j));
		}
	while (!Q.empty()) {
		ii v = Q.front(); Q.pop();
		int be = best[v.first][v.second];
		int val = B[v.first][v.second] - '0';
		if (be < slen && str[be] - '0' == val) be++;
		if (be == slen) return true;
		ii u = ii(v.first + a[val], v.second + b[val]);
		if (1 <= u.first && u.first <= n && 1 <= u.second && u.second <= m) {
			best[u.first][u.second] = max(best[u.first][u.second], be);
			if (--f[u.first][u.second] == 0) Q.push(u);
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (inloop[i][j]) {
				int be = best[i][j], k;
				for (k = 0; k < Maxd; k++)
					if (has[be][k] && !my[i][j][k]) break;
				if (k == Maxd) return true;
			}
	return false;
}

int main()
{
	scanf("%d %d %d", &n, &m, &q);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf(" %c", &B[i][j]);
	for (int i = 0; i < Maxd; i++)
		scanf("%d %d", &a[i], &b[i]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (!tk[i][j]) Calc(i, j);
	while (q--) {
		scanf("%s", str); slen = strlen(str);
		printf("%s\n", Check()? "YES": "NO");
	}
	return 0;
}