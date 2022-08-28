#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;


const int maxn = 105;
long long ans[maxn][maxn];


bool isSqr(long long a)
{
	double sq = sqrt((double) a);
	long long x = sq;
	while (x * x < a)
		x++;
	while (x * x > a)
		x--;
	return x * x == a;
}


int getA(int x)
{
	if (x < 1)
		return 1;
	return (x - 1) / 2;
}


bool check(int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		long long sum = 0;
		for (int j = 0; j < m; j++)
		{
			if (ans[i][j] > 1e8 || ans[i][j] <= 0)
				throw 42;
			sum += ans[i][j] * 1LL * ans[i][j];
		}
		if (!isSqr(sum) )
		{
		//	throw 42;
		//	fprintf(stderr, "BAD");
			return false;
		}
	}
	for (int i = 0; i < m; i++)
	{
		long long sum = 0;
		for (int j = 0; j < n; j++)
			sum += ans[j][i] * 1LL * ans[j][i];
		if (!isSqr(sum) )
		{
		//	throw 42;
		//	fprintf(stderr, "BAD");
			return false;
		}
	}
	return true;
}

bool tryFill(int n, int m)
{
	int fl = 1;
	memset(ans, 0, sizeof ans);
	if (n == 2 || m == 2)
		fl = 9;
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			ans[i][j] = 1;
			if (fl == 9 && (i != n - 1 || j != m - 1) )
				ans[i][j] = 3;
		}
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < m - 1; j++)
		{
			ans[i][j] = fl;
		}
	int sa = (m - 1);
	int sb = (n - 1);
	if (n % 2 == 1)
	{
		sb += 3;
		for (int i = 0; i < m; i++)
			ans[0][i] *= 2;
	}
	if (m % 2 == 1)
	{
		sa += 3;
		for (int i = 0; i < n; i++)
			ans[i][0] *= 2;
	}
	int a = getA(sa * 1LL * fl);
	int b = getA(sb * 1LL * fl);
	for (int i = 0; i < m; i++)
		ans[n - 1][i] *= b;
	for (int i = 0; i < n; i++)
		ans[i][m - 1] *= a;
	if (!check(n, m) )
		return false;
	//fprintf(stderr, "OK\n");
	return true;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

/*	for (int n = 1; n <= 100; n++)
	{
		for (int m = 1; m <= 100; m++)
		{
			if (!tryFill(n, m) )
				fprintf(stderr, "bad %d %d\n", n, m);
		}
	}

	return 0;*/
	int n, m;
	scanf("%d%d", &n, &m);
	tryFill(n, m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			printf("%d ", ans[i][j] );
		printf("\n");
	}

	return 0;
}