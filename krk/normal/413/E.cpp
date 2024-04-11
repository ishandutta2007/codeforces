#include <cstdio>
#include <algorithm>
using namespace std;

const int Inf = 100000000;
const int Maxr = 2;
const int Maxc = 200005;
const int Maxk = 20;

int n, m;
char B[Maxr][Maxc];
int R[Maxc], comp;
int incomp[Maxc];
int dist[Maxc][Maxk];

int countBad(int col)
{
	return (B[0][col] == 'X') + (B[1][col] == 'X');
}

int Dist(int r1, int c1, int r2, int c2)
{
	return abs(r1 - r2) + abs(c1 - c2);
}

int getPath(int a, int b)
{
	int res = Inf;
	if (a + 1 == b) {
		for (int i = 0; i < Maxr; i++) 
			if (B[i][a] != 'X' && B[i][b] != 'X')
				res = min(res, 1);
		return res;
	}
	for (int i = 0; i < Maxr; i++) if (B[i][a] != 'X')
		for (int j = 0; j < Maxr; j++) if (B[j][b] != 'X')
			res = min(res, Dist(i, a, j, b));
	return res;
}

int Query(int l, int r)
{
	int res = 0;
	for (int i = Maxk - 1; i >= 0; i--)
		while (l + (1 << i) <= r + 1) {
			res = min(Inf, res + dist[l][i]);
			l += 1 << i;
			if (l == r + 1) return res;
			l--;
		}
	return res;
}

void Get(int id, int &r, int &c)
{
	id--;
	r = id / n; c = id % n;
}

int getPath2(int r, int c, int cmp)
{
	int rr = 0;
	while (rr < 2 && B[rr][R[cmp]] == 'X') rr++;
	if (rr == 2) return Inf;
	return Dist(r, c, rr, R[cmp]);
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < Maxr; i++)
		scanf("%s", B[i]);
	for (int i = 0; i < n; i++) {
		incomp[i] = comp;
		R[comp] = i;
		if (countBad(i)) comp++;
	}

	for (int i = 0; i + 1 < comp; i++)
		if (countBad(R[i]) == 2 || countBad(R[i + 1]) == 2) dist[i][1] = Inf;
		else { dist[i][1] = getPath(R[i], R[i + 1]); }

	for (int j = 2; j < Maxk; j++)
		for (int i = 0; i + (1 << j) <= comp; i++)
			dist[i][j] = min(Inf, dist[i][j - 1] + dist[i + (1 << j - 1)][j - 1] + getPath(R[i + (1 << j - 1) - 1], R[i + (1 << j - 1)]));

	while (m--) {
		int v, u; scanf("%d %d", &v, &u);
		int r1, c1, r2, c2;
		Get(v, r1, c1); Get(u, r2, c2);
		if (c1 > c2) { swap(r1, r2); swap(c1, c2); }
		if (incomp[c1] == incomp[c2]) printf("%d\n", Dist(r1, c1, r2, c2));
		else {
			int comp1 = incomp[c1];
			int comp2 = R[incomp[c2]] == c2 && incomp[c2] < comp? incomp[c2]: incomp[c2] - 1;
			int res = getPath2(r1, c1, incomp[c1]) + Query(incomp[c1], comp2) + getPath2(r2, c2, comp2);
			printf("%d\n", res >= Inf? -1: res);
		}
	}
	return 0;
}