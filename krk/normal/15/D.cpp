#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Inf = 2000000000;
const int Maxn = 1005;
const int Maxm = 4096;
const int Maxs = 8400000;

struct pos {
	ll st;
	int r, c;
	pos(ll st = 0ll, int r = 0, int c = 0): st(st), r(r), c(c) { }
	bool operator <(const pos &p) const {
		if (st != p.st) return st < p.st;
		if (r != p.r) return r < p.r;
		return c < p.c;
	}
};

int n, m, a, b;
int B[Maxn][Maxn];
ll sum[Maxn][Maxn];
int mn[Maxn][Maxm];
map <int, int> M;
vector <pos> V;
bool taken[Maxn][Maxn];
vector <pos> res;

void Create(int c, int v, int l, int r)
{
	if (l == r) mn[c][v] = B[l][c];
	else {
		int m = l + r >> 1;
		Create(c, 2 * v, l, m); Create(c, 2 * v + 1, m + 1, r);
		mn[c][v] = min(mn[c][2 * v], mn[c][2 * v + 1]);
	}
}

int Get(int c, int v, int l, int r, int a, int b)
{
	if (l == a && r == b) return mn[c][v];
	else {
		int res = Inf;
		int m = l + r >> 1;
		if (a <= m) res = min(res, Get(c, 2 * v, l, m, a, min(m, b)));
		if (m + 1 <= b) res = min(res, Get(c, 2 * v + 1, m + 1, r, max(m + 1, a), b));
		return res;
	}
}

ll getDig(int r, int c, int mn)
{
	return sum[r + a - 1][c + b - 1] - sum[r - 1][c + b - 1] - sum[r + a - 1][c - 1] + sum[r - 1][c - 1] - ll(mn) * ll(a) * ll(b);
}

int main()
{
	scanf("%d %d %d %d", &n, &m, &a, &b);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			scanf("%d", &B[i][j]); sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + B[i][j];
		}
	for (int j = 1; j <= m; j++) Create(j, 1, 1, n);
	for (int i = 1; i + a <= n + 1; i++) {
		M.clear();
		for (int j = 1; j <= b; j++)
			M[Get(j, 1, 1, n, i, i + a - 1)]++;
		V.push_back(pos(getDig(i, 1, M.begin()->first), i, 1));
		for (int j = 2; j + b <= m + 1; j++) {
			int val = Get(j - 1, 1, 1, n, i, i + a - 1);
			if (--M[val] == 0) M.erase(val);
			M[Get(j + b - 1, 1, 1, n, i, i + a - 1)]++;
			V.push_back(pos(getDig(i, j, M.begin()->first), i, j));
		}
	}
	sort(V.begin(), V.end());
	for (int i = 0; i < V.size(); i++) {
		pos p = V[i];
		if (!taken[p.r][p.c] && !taken[p.r][p.c + b - 1] && !taken[p.r + a - 1][p.c] && !taken[p.r + a - 1][p.c + b - 1]) {
			res.push_back(p);
			for (int j = p.r; j < p.r + a; j++)
				for (int k = p.c; k < p.c + b; k++)
					taken[j][k] = true;
		}
	}
	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); i++)
		printf("%d %d %I64d\n", res[i].r, res[i].c, res[i].st);
	return 0;
}