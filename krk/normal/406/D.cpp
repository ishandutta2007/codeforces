#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 100005;
const int Maxm = 20;

int n;
ll x[Maxn], y[Maxn];
int P[Maxm][Maxn], L[Maxn];
int m;

bool Traverse(int a, int b, int c)
{
	ll ax = x[b] - x[a], ay = y[b] - y[a];
	ll bx = x[c] - x[b], by = y[c] - y[b];
	return ax * by - ay * bx > 0;
}

int LCA(int a, int b)
{
	if (L[a] > L[b]) swap(a, b);
	for (int i = Maxm - 1; i >= 0; i--)
		if (L[b] - (1 << i) >= L[a]) b = P[i][b];
	if (a == b) return a;
	for (int i = Maxm - 1; i >= 0; i--)
		if (P[i][a] != P[i][b]) a = P[i][a], b = P[i][b];
	return P[0][a];
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%I64d %I64d", &x[i], &y[i]);
	P[0][n] = n; L[n] = 0;
	for (int i = n - 1; i >= 1; i--) {
		P[0][i] = i + 1;
		while (P[0][i] != n && Traverse(i, P[0][i], P[0][P[0][i]]))
			P[0][i] = P[0][P[0][i]];
		L[i] = L[P[0][i]] + 1;
	}
	for (int i = 1; i < Maxm; i++)
		for (int j = 1; j <= n; j++)
			P[i][j] = P[i - 1][P[i - 1][j]];
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int a, b; scanf("%d %d", &a, &b);
		printf("%d%c", LCA(a, b), i + 1 < m? ' ': '\n');
	}
	return 0;
}