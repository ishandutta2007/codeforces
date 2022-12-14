#include <bits/stdc++.h>
using namespace std;
const int maxn = 1 << 15;
int n, m, p, res, ans[555], pos[555], ct, x, msk[222222], a[maxn + 10], pcnt[maxn + 10], crt;
bool u[222222][66], rr[66];
char s[111];
int Get(int x)
{
	return ((rand() << 10) + rand()) % x + 1;
}
void FWT_and(int a[])
{
	for (int i = 2; i <= (1 << ct); i <<= 1)
	{
		int p = i >> 1;
		for (int j = 0; j < (1 << ct); j += i)
		{
			for (int k = j; k < j + p; k++)
			{
				a[k] += a[k + p];
			}
		}
	}
}
int main()
{
	srand(time(0));
	scanf("%d%d%d", &n, &m, &p);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", s);
		for (int j = 0; j < m; j++)
		{
			u[i][j] = s[j] - '0';
		}
	}
	for (int i = 0; i < maxn; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			if (i & (1 << j)) pcnt[i]++;
		}
	}
	for (int i = 1; i <= 20; i++)
	{
		ct = 0;
		x = Get(n);
		for (int j = 0; j < m; j++)
		{
			if (u[x][j]) pos[ct++] = j;
		}
		for (int j = 1; j <= n; j++)
		{
			msk[j] = 0;
			for (int k = 0; k < ct; k++)
			{
				if (u[j][pos[k]]) msk[j] |= (1 << k);
			}
		}
		memset(a, 0, sizeof(a));
		for (int j = 1; j <= n; j++) a[msk[j]]++;
		FWT_and(a);
		for (int j = 0; j < (1 << ct); j++)
		{
			if (a[j] >= (n + 1) / 2) 
			{
				if (pcnt[j] > res)
				{
					res = pcnt[j];
					crt = 0;
					for (int k = 0; k < ct; k++)
					{
						if (j & (1 << k)) ans[++crt] = pos[k];
					}
				}
			}
		}
	}
	for (int i = 1; i <= crt; i++) 
	{
		rr[ans[i]] = 1;
	}
	for (int i = 0; i < m; i++) printf("%d", rr[i]);
	printf("\n");
	return 0;
}