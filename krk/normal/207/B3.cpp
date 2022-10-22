#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 500005;
const int Maxm = 20;
const int Maxt = 2097152;

int n;
int P[Maxn][Maxm], F[Maxn][Maxm];
int ind[Maxt];
ll res;

void Create(int v, int l, int r)
{
	if (l == r) ind[v] = l;
	else {
		int m = l + r >> 1;
		Create(2 * v, l, m); Create(2 * v + 1, m + 1, r);
		if (P[ind[2 * v]][0] <= P[ind[2 * v + 1]][0]) ind[v] = ind[2 * v];
		else ind[v] = ind[2 * v + 1];
	}
}

int Get(int v, int l, int r, int a, int b)
{
	if (l == a && b == r) return ind[v];
	else {
		int m = l + r >> 1;
		if (b <= m) return Get(2 * v, l, m, a, b);
		if (m + 1 <= a) return Get(2 * v + 1, m + 1, r, a, b);
		int x = Get(2 * v, l, m, a, m), y = Get(2 * v + 1, m + 1, r, m + 1, b);
		return P[x][0] <= P[y][0]? x: y;
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int ax; scanf("%d", &ax);
		P[i][0] = max(1, i - ax); P[n + i][0] = max(1, n + i - ax);
	}
	Create(1, 1, 2 * n);
	F[1][0] = 1;
	for (int i = 2; i <= 2 * n; i++)
		F[i][0] = Get(1, 1, 2 * n, P[i][0], i - 1);
	for (int j = 1; j < Maxm; j++)
		for (int i = 1; i <= 2 * n; i++) {
			F[i][j] = F[F[i][j - 1]][j - 1];
			P[i][j] = P[F[i][j - 1]][j - 1];
		}
	for (int i = n + 1; i <= 2 * n; i++) {
		int nd = i - (n - 1), cur = i;
		for (int j = Maxm - 1; j >= 0; j--)
			if (P[cur][j] > nd) { cur = F[cur][j]; res += 1 << j; }
		res++;
	}
	printf("%I64d\n", res);
	return 0;
}