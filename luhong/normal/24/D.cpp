#include <iostream>
#include <cstdio>

double a[1010], b[1010];
double f[1010][1010];

int main()
{
	int n, m; scanf("%d%d", &n, &m);
	int x, y; scanf("%d%d", &x, &y);
	
	if(m == 1)
	{
		printf("%d\n", (n - x) * 2);
		return 0;
	}
	
	for(int j = 1; j <= m; j++) f[n][j] = 0;
	for(int i = n - 1; i >= x; i--)
	{
		for(int j = 1; j <= m; j++)
		{
			if(j == 1 || j == m) b[j] = (3 + f[i + 1][j]) / 2.0;
			else b[j] = (4 + f[i + 1][j]) / 3.0;
		}
		a[1] = -1 / 2.0;
		for(int j = 2; j < m; j++)
		{
			a[j] = -1 / 3.0;
			double x = a[j - 1] / 3.0;
			b[j] = b[j] + b[j - 1] / 3.0;
			x = 1.0 / (x + 1);
			a[j] = a[j] * x;
			b[j] = b[j] * x;
		}
		f[i][m] = (b[m] + b[m - 1] / 2.0) / (1 + a[m - 1] / 2.0);
		for(int j = m - 1; j >= 1; j--)
		{
			f[i][j] = b[j] - a[j] * f[i][j + 1];
		}
	}
	printf("%.10lf\n", f[x][y]);
}

//O(m)