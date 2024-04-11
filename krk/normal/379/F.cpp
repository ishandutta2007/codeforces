#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 1000005;
const int Maxm = 21;

int n;
int q;
int V[Maxn];
int L[Maxn], P[Maxn][Maxm];
int a, b, dist;

int Dist(int a, int b)
{
	if (L[a] < L[b]) swap(a, b);
	int res = 0;
	for (int i = Maxm - 1; i >= 0; i--)
		if (L[a] - (1 << i) >= L[b]) { res += 1 << i; a = P[a][i]; }
	if (a == b) return res;
	for (int i = Maxm - 1; i >= 0; i--)
		if (P[a][i] != P[b][i]) { res += 2 * (1 << i); a = P[a][i]; b = P[b][i]; }
	return res + 2;
}

void Check(int c, int d)
{
	int cand = Dist(c, d);
	if (cand > dist) { dist = cand; a = c; b = d; }
}

int main()
{
	L[2] = L[3] = L[4] = 1; P[2][0] = P[3][0] = P[4][0] = 1; n = 4;
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		scanf("%d", &V[i]);
		L[n + 1] = L[n + 2] = L[V[i]] + 1; P[n + 1][0] = P[n + 2][0] = V[i];
		n += 2;
	}
	for (int j = 1; j < Maxm; j++)
		for (int i = 1; i <= n; i++)
			P[i][j] = P[P[i][j - 1]][j - 1];
	n = 4;
	a = 2; b = 3; dist = 2;
	for (int i = 0; i < q; i++) {
		Check(a, n + 1); Check(b, n + 1); n += 2;
		printf("%d\n", dist);
	}
	return 0;
}