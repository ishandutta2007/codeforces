#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

const int Maxn = 2005;
const int Inf = 1000000000;

int n, m, k;
bool sw;
int L[Maxn][Maxn], R[Maxn][Maxn];
bool taken[Maxn][Maxn];
int dist, bx, by;

int Get(int P[][Maxn], int r, int c)
{
	if (!taken[r][c]) return c;
	return P[r][c] = Get(P, r, P[r][c]);
}

void Check(int ndist, int nbx, int nby)
{
	if (ndist > dist) return;
	if (ndist < dist) { dist = ndist; bx = nbx; by = nby; return; }
	if (!sw && (nbx < bx || nbx == bx && nby < by)) { bx = nbx; by = nby; }
	if (sw && (nby < by || nby == by && nbx < bx)) { by = nby; bx = nbx; }
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	if (n > m) { sw = true; swap(n, m); }
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			L[i][j] = j - 1, R[i][j] = j + 1;
	while (k--) {
		int x, y; scanf("%d %d", &x, &y);
		if (sw) swap(x, y);
		dist = Inf;
		for (int i = 0; i <= dist; i++) {
			if (x - i >= 1) {
				int pos = Get(L, x - i, y);
				if (pos >= 1) Check(i + y - pos, x - i, pos);
				pos = Get(R, x - i, y);
				if (pos <= m) Check(i + pos - y, x - i, pos);
			}
			if (x + i <= n) {
				int pos = Get(L, x + i, y);
				if (pos >= 1) Check(i + y - pos, x + i, pos);
				pos = Get(R, x + i, y);
				if (pos <= m) Check(i + pos - y, x + i, pos);
			}
		}
		if (sw) printf("%d %d\n", by, bx);
		else printf("%d %d\n", bx, by);
		taken[bx][by] = true;
	}
	return 0;
}