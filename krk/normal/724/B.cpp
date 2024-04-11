#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int Maxn = 22;

int n, m;
int B[Maxn][Maxn];

void swapCols(int a, int b)
{
	for (int i = 0; i < n; i++)
		swap(B[i][a], B[i][b]);
}

bool Check()
{
	for (int i = 0; i < n; i++) {
		int notin = 0;
		for (int j = 0; j < m; j++)
			if (B[i][j] != j + 1) notin++;
		if (notin > 2) return false;
	}
	return true;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &B[i][j]);
	for (int j1 = 0; j1 < m; j1++)
		for (int j2 = j1; j2 < m; j2++) {
			swapCols(j1, j2);
			if (Check()) { printf("YES\n"); return 0; }
			swapCols(j1, j2);
		}
	printf("NO\n");
	return 0;
}