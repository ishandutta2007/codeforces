#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 22;
const int Inf = 1000000000;

int n;
int A[Maxn][Maxn], B[Maxn][Maxn];
int cost[Maxn][Maxn];
int lx[Maxn], ly[Maxn];
int xy[Maxn], yx[Maxn];
int P[Maxn];
bool S[Maxn], T[Maxn];
int num[Maxn], numx[Maxn];
int res;
int best;

void Relabel(int lvl)
{
	int delt = Inf;
	for (int y = 0; y < n; y++)
		if (!T[y]) delt = min(delt, num[y]);
	for (int x = 0; x <= lvl; x++)
		if (S[x]) lx[x] -= delt;
	for (int y = 0; y < n; y++)
		if (T[y]) ly[y] += delt;
		else num[y] -= delt;
}

void addEdge(int x, int p)
{
	S[x] = true; P[x] = p;
	for (int y = 0; y < n; y++) {
		int cand = lx[x] + ly[y] - cost[x][y];
		if (cand < num[y]) { num[y] = cand; numx[y] = x; }
	}
}

void Augment(int root)
{
	int x = root, y = 0;
	int Q[Maxn], st = 0, en = 0;
	lx[x] = -Inf;
	for (y = 0; y < n; y++)
		lx[x] = max(lx[x], cost[x][y] - ly[y]);
 	fill(S, S + n, false); fill(T, T + n, false);
 	S[x] = true; P[x] = -1;
 	Q[en++] = x;
 	for (y = 0; y < n; y++) {
 		num[y] = lx[x] + ly[y] - cost[x][y];
 		numx[y] = x;
 	}
 	while (true) {
 		while (st < en) {
 			x = Q[st++];
 			for (y = 0; y < n; y++)
 				if (lx[x] + ly[y] == cost[x][y] && !T[y]) {
 					if (yx[y] == -1) break;
 					T[y] = true;
 					Q[en++] = yx[y];
 					addEdge(yx[y], x);
 				}
 			if (y < n) break;
 		}
 		if (y < n) break;
 		Relabel(root);
 		for (y = 0; y < n; y++)
 			if (num[y] == 0 && !T[y]) {
 				if (yx[y] == -1) { x = numx[y]; break; }
 				T[y] = true;
 				if (!S[yx[y]]) {
 					Q[en++] = yx[y];
 					addEdge(yx[y], numx[y]);
 				}
 			}
 		if (y < n) break;
 	}
 	for (int cx = x, cy = y, fy; cx != -1; cx = P[cx], cy = fy) {
 		fy = xy[cx];
 		xy[cx] = cy; yx[cy] = cx;
 	}
}

void Gen(int lvl, int lfa, int lfb)
{
	if (lvl == n) best = max(best, res);
	else {
		if (lfa) {
			for (int j = 0; j < n; j++)
				cost[lvl][j] = A[lvl][j];
			Augment(lvl);
			res = 0;
			for (int i = 0; i <= lvl; i++)
				res += cost[i][xy[i]];
			Gen(lvl + 1, lfa - 1, lfb);
			yx[xy[lvl]] = -1; xy[lvl] = -1;
		}
		if (lfb) {
			for (int j = 0; j < n; j++)
				cost[lvl][j] = B[lvl][j];
			Augment(lvl);
			res = 0;
			for (int i = 0; i <= lvl; i++)
				res += cost[i][xy[i]];
			Gen(lvl + 1, lfa, lfb - 1);
			yx[xy[lvl]] = -1; xy[lvl] = -1;
		}
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &A[i][j]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &B[i][j]);
	fill(xy, xy + n, -1); fill(yx, yx + n, -1);
	Gen(0, n / 2, n / 2);
	printf("%d\n", best);
	return 0;
}