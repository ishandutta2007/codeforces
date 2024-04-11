#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;

const int maxn = 1e6 + 10;
int n,col[3][maxn],tot,q,sl[maxn],sr[maxn],al[maxn],ar[maxn];
#define f(i, j) (mp[i][j] == '1')
char mp[3][maxn];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
pii dfs(int x, int y) {
	pii res = make_pair(y, y);
	for (int k = 0; k < 4; ++k) {
		int nx = x + dx[k], ny = y + dy[k];
		if (nx < 0 || nx > 2 || ny < 1 || ny > n || !f(nx, ny) || col[nx][ny]) continue;
		col[nx][ny] = col[x][y]; pii p = dfs(nx, ny);
		res.first = min(res.first, p.first), res.second = max(res.second, p.second);
	}
	return res;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < 3; ++i) scanf("%s", mp[i] + 1);
	for (int i = 0; i < 3; ++i)
		for (int j = 1; j <= n; ++j)
			if (f(i, j) && !col[i][j]) {
				col[i][j] = ++tot;
				pii p = dfs(i, j);
				sl[p.second]++, sr[p.first]++;
			}
	for (int i = 1, lst = 0; i <= n; ++i) {
		sl[i] += sl[i - 1];
		if (f(0, i) && f(2, i)) { if (f(1, i)) lst = i; }
		else lst = 0;
		al[i] = lst;
	}
	for (int i = n, lst = n + 1; i >= 1; --i) {
		sr[i] += sr[i + 1];
		if (f(0, i) && f(2, i)) { if (f(1, i)) lst = i; }
		else lst = n + 1;
		ar[i] = lst;
	}
	scanf("%d", &q);
	while (q--) {
		int l, r, x;
		scanf("%d%d", &l, &r);
		x = tot - sl[l - 1] - sr[r + 1];
		if (f(0, l) && f(2, l) && !f(1, l) && col[0][l] == col[2][l] && ar[l] > r) x++;
		if (f(0, r) && f(2, r) && !f(1, r) && col[0][r] == col[2][r] && al[r] < l) x++;
		if (f(0, l) && f(2, l) && !f(1, l) && col[0][l] == col[2][l] &&
			f(0, r) && f(2, r) && !f(1, r) && col[0][r] == col[2][r] &&
			al[l] == al[r] && ar[l] == ar[r]) x--;
		printf("%d\n", x);
	}
	return 0;
}