#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

const int Maxn = 21;
const int Maxc = 8;
const int MaxC = 1 << Maxc;

struct pos {
	int r, c, mask;
	pos(int r = 0, int c = 0, int mask = 0): r(r), c(c), mask(mask) {}
};

int n, m;
char B[Maxn][Maxn];
int mask[Maxn][Maxn];
int sr, sc, mb;
int cost[Maxc];
int dist[Maxn][Maxn][MaxC];
int res = 0;

pos toPos(int id)
{
	pos p; p.r = id / (Maxn * MaxC); id -= p.r * Maxn * MaxC;
	p.c = id / MaxC; id -= p.c * MaxC;
	p.mask = id;
	return p;
}

int toId(const pos &p)
{
	return p.r * Maxn * MaxC + p.c * MaxC + p.mask;
}

void BFS()
{
	dist[sr][sc][0] = 1;
	queue <int> Q; Q.push(toId(pos(sr, sc, 0)));
	pos p, np;
	while (!Q.empty()) {
		int v = Q.front(); Q.pop();
		p = toPos(v); int d = dist[p.r][p.c][p.mask];
		if (p.c > 1 && B[p.r][p.c - 1] == '.') {
			np = pos(p.r, p.c - 1, p.mask ^ mask[p.c][p.r - 1]);
			if (!dist[np.r][np.c][np.mask]) { dist[np.r][np.c][np.mask] = d + 1; Q.push(toId(np)); }
		}
		if (p.c < m && B[p.r][p.c + 1] == '.') {
			np = pos(p.r, p.c + 1, p.mask ^ mask[p.c + 1][p.r - 1]);
			if (!dist[np.r][np.c][np.mask]) { dist[np.r][np.c][np.mask] = d + 1; Q.push(toId(np)); }
		}
		if (p.r > 1 && B[p.r - 1][p.c] == '.') {
			p.r--;
			if (!dist[p.r][p.c][p.mask]) { dist[p.r][p.c][p.mask] = d + 1; Q.push(toId(p)); }
			p.r++;
		}
		if (p.r < n && B[p.r + 1][p.c] == '.') {
			p.r++;
			if (!dist[p.r][p.c][p.mask]) { dist[p.r][p.c][p.mask] = d + 1; Q.push(toId(p)); }
			p.r--;
		}
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			scanf(" %c", &B[i][j]);
			if (B[i][j] == 'S') {
				sr = i; sc = j; B[i][j] = '.';
			} else if ('1' <= B[i][j] && B[i][j] <= '8') {
				int ind = B[i][j] - '1'; mb = max(mb, ind + 1);
				for (int l = i; l <= n; l++)
					mask[j][l] |= 1 << ind;
			}
		}
	int cur = mb;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (B[i][j] == 'B') {
				for (int l = i; l <= n; l++)
					mask[j][l] |= 1 << cur;
				cur++;
			}
	for (int i = 0; i < mb; i++)
		scanf("%d", &cost[i]);
	BFS();
	for (int msk = 0; msk < 1 << mb; msk++) if (dist[sr][sc][msk]) {
		int got = -(dist[sr][sc][msk] - 1);
		for (int i = 0; i < mb; i++)
			if (msk & 1 << i) got += cost[i];
		res = max(res, got);
	}
	printf("%d\n", res);
	return 0;
}