#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

double f[1001][1001], v[1001][1001];
int n, m;

int main(){

	scanf("%d%d", &n, &m);
	memset(f, 0, sizeof(f));
	memset(v, 0, sizeof(v));
	double ans = 0;
	f[n][m] = 1.0;
	for (int i = n; i >= 0; --i) 
		for (int j = m; j >= 0; --j) 
		{
			if (i >= 1) ans += 1.0 * i / (i + j) * f[i][j];
			if (j >= 1) v[i][j - 1] += 1.0 * j / (i + j) * f[i][j];
			if (j >= 1 && i >= 1) f[i - 1][j - 1] += 1.0 * j / (i + j) * i / (i + j - 1) * v[i][j];
			if (j >= 2) f[i][j - 2] += 1.0 * j / (i + j) * (j - 1) / (i + j - 1) * v[i][j];
		}
	printf("%.10lf\n", ans);
}