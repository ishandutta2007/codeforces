#include <bits/stdc++.h>
using namespace std;

const int Maxq = 100005;
const int Maxn = 5005;
const int Maxm = 10015;
const int rl[4] = {2, 3, 1, 0};

int n, q;
int BIT[Maxm], lab[Maxm];
int BITX[Maxm][Maxn];
char labX[Maxm][Maxn];
int BITY[Maxm][Maxn];
char labY[Maxm][Maxn];
int qtyp[Maxq], qa[Maxq], qb[Maxq], qc[Maxq], qd[Maxq];
int res[Maxq];

void Add(int x, int y, int id)
{
	while (x != y && min(x, y) < Maxm)
		if (x < y) {
			if (lab[x] != id) BIT[x] = 0;
			BIT[x]++; lab[x] = id;
			x += x & -x;
		} else {
			if (lab[y] != id) BIT[y] = 0;
			BIT[y]--; lab[y] = id;
			y += y & -y;
		}
}

int Get(int x, int id)
{
	int res = 0;
	for (int i = x; i > 0; i -= i & -i) if (lab[i] == id)
		res += BIT[i];
	return res;
}

void Add(int BIT[][Maxn], char lab[][Maxn], int x, int y, int id, int from)
{
	while (x != y && min(x, y) < Maxm)
		if (x < y) {
			for (int i = from; i < Maxn; i += i & -i) {
				if (lab[x][i] != id) BIT[x][i] = 0;
				BIT[x][i]--; lab[x][i] = id;
			}
			x += x & -x;
		} else {
			for (int i = from; i < Maxn; i += i & -i) {
				if (lab[y][i] != id) BIT[y][i] = 0;
				BIT[y][i]++; lab[y][i] = id;
			}
			y += y & -y;
		}
}

int Get(int BIT[][Maxn], char lab[][Maxn], int x, int y, int id)
{
	int res = 0;
	for (int i = x; i > 0; i -= i & -i)
		for (int j = y; j > 0; j -= j & -j) if (lab[i][j] == id)
			res += BIT[i][j];
	return res;
}

void Rotate(int &x, int &y)
{
	int nx = n - y + 1;
	int ny = x;
	x = nx;
	y = ny;
}

int main()
{
	scanf("%d %d", &n, &q);
	for (int i = 0; i < q; i++) {
		scanf("%d", &qtyp[i]);
		if (qtyp[i] == 1) {
			scanf("%d %d %d %d", &qa[i], &qb[i], &qc[i], &qd[i]);
			qa[i] = rl[qa[i] - 1];
		} else scanf("%d %d", &qa[i], &qb[i]);
	}
	for (int t = 0; t < 4; t++) {
		for (int i = 0; i < q; i++)
			if (qtyp[i] == 1) {
				if (qa[i] == t) {
					int A = qb[i] + qc[i] - qd[i];
					int B = qb[i] + qc[i] + 1;
					Add(A, B, t);
					Add(BITX, labX, A, B, t, qb[i] + 1);
					Add(BITY, labY, A, B, t, qc[i] + 1);
				}
				Rotate(qb[i], qc[i]);
			} else {
				int diag = qa[i] + qb[i];
				res[i] += Get(qa[i] + qb[i], t) + Get(BITX, labX, diag, qa[i], t) + Get(BITY, labY, diag, qb[i], t);
				Rotate(qa[i], qb[i]);
			}
	}
	for (int i = 0; i < q; i++)
		if (qtyp[i] != 1)
			printf("%d\n", res[i]);
    return 0;
}