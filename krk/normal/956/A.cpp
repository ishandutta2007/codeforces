#include <bits/stdc++.h>
using namespace std;

const int Maxn = 115;

int n, m;
char B[Maxn][Maxn];
int par[Maxn], siz[Maxn];

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

void unionSet(int a, int b)
{
	a = getPar(a), b = getPar(b);
	if (a == b) return;
	if (siz[a] < siz[b]) swap(a, b);
	siz[a] += siz[b]; par[b] = a;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n + m; i++)
		par[i] = i, siz[i] = 1;
	for (int i = 0; i < n; i++) {
		scanf("%s", B[i]);
		for (int j = 0; j < m; j++)
			if (B[i][j] == '#') unionSet(i, n + j);
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (getPar(i) == getPar(n + j) && B[i][j] != '#' ||
				getPar(i) != getPar(n + j) && B[i][j] == '#') {
				printf("No\n"); return 0;
			}
	printf("Yes\n");
	return 0;
}