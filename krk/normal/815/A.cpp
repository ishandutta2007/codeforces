#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

const int Maxn = 105;
const int Maxm = 505;
const int Inf = 1000000000;

int n, m;
int B[Maxn][Maxn];
int res = Inf, bi;
int row[Maxn], col[Maxn];

int Get(int tk)
{
	row[1] = tk; col[1] = B[1][1] - tk;
	for (int i = 2; i <= n; i++)
		row[i] = B[i][1] - col[1];
	for (int j = 2; j <= m; j++)
		col[j] = B[1][j] - row[1];
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		if (row[i] < 0) return Inf;
		sum += row[i];
	}
	for (int i = 1; i <= m; i++) {
		if (col[i] < 0) return Inf;
		sum += col[i];
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (B[i][j] != row[i] + col[j]) return Inf;
	return sum;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &B[i][j]);
	for (int i = 0; i <= Maxm; i++) {
		int cand = Get(i);
		if (cand < res) { res = cand; bi = i; }
	}
	if (res >= Inf) { printf("-1\n"); return 0; }
	Get(bi);
	printf("%d\n", res);
	for (int i = 1; i <= n; i++)
		while (row[i]--)
			printf("row %d\n", i);
	for (int j = 1; j <= m; j++)
		while (col[j]--)
			printf("col %d\n", j);
	return 0;
}