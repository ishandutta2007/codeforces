#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;
const int Maxs = 524288;
const int Maxm = 20;
const int Inf = 2000000007;

int n, s, L;
int a[Maxn];
ii mnmx[Maxn][Maxm];
int st[Maxs];
int res[Maxn];

int getDif(int l, int r)
{
	ii res = ii(Inf, -Inf);
	for (int i = Maxm - 1; i >= 0; i--)
		if (l + (1 << i) <= r + 1) {
			res.first = min(res.first, mnmx[l][i].first);
			res.second = max(res.second, mnmx[l][i].second);
			l += 1 << i;
		}
	return res.second - res.first;
}

void Update(int v, int l, int r, int x, int val)
{
	if (l == r) st[v] = val;
	else {
		int m = l + r >> 1;
		if (x <= m) Update(2 * v, l, m, x, val);
		else Update(2 * v + 1, m + 1, r, x, val);
		st[v] = min(st[2 * v], st[2 * v + 1]);
	}
}

int Get(int v, int l, int r, int a, int b)
{
	if (l == a && r == b) return st[v];
	else {
		int res = Inf;
		int m = l + r >> 1;
		if (a <= m) res = min(res, Get(2 * v, l, m, a, min(m, b)));
		if (m + 1 <= b) res = min(res, Get(2 * v + 1, m + 1, r, max(m + 1, a), b));
		return res;
	}
}

int main()
{
	scanf("%d %d %d", &n, &s, &L);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		mnmx[i][0] = ii(a[i], a[i]);
	}
	for (int j = 1; j < Maxm; j++)
		for (int i = 1; i + (1 << j) <= n + 1; i++) {
			int mn = min(mnmx[i][j - 1].first, mnmx[i + (1 << j - 1)][j - 1].first);
			int mx = max(mnmx[i][j - 1].second, mnmx[i + (1 << j - 1)][j - 1].second);
			mnmx[i][j] = ii(mn, mx);
		}
	for (int i = n; i >= 1; i--) {
		int l = 2, r = n + 1 - i;
		int sav = 1;
		while (l <= r && r >= L) {
			int m = l + r >> 1;
			if (getDif(i, i + m - 1) <= s) { sav = m; l = m + 1; }
			else r = m - 1;
		}
		res[i] = sav >= L? 1 + Get(1, 1, n + 1, i + L, i + sav): Inf;
		res[i] = min(res[i], Inf);
		Update(1, 1, n + 1, i, res[i]);
	}
	printf("%d\n", res[1] != Inf? res[1]: -1);
	return 0;
}