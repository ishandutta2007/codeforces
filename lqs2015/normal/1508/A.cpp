#include <bits/stdc++.h>
using namespace std;
int test, n, flg, a[4][222222], ans[555555], cnt, p1, p2, num[4];
char s[222222];
void check1(int a[], int b[])
{
	cnt = 0;
	p1 = p2 = 1;
	while(p1 <= 2 * n && p2 <= 2 * n)
	{
		while(p1 <= 2 * n && !a[p1])
		{
			ans[++cnt] = a[p1];
			p1++;
		}
		while(p2 <= 2 * n && !b[p2])
		{
			ans[++cnt] = b[p2];
			p2++;
		}
		if (p1 > 2 * n || p2 > 2 * n) break;
		ans[++cnt] = 1;
		p1++; p2++;
	}
	while(p1 <= 2 * n) 
	{
		ans[++cnt] = a[p1];
		p1++;
	}
	while(p2 <= 2 * n) 
	{
		ans[++cnt] = b[p2];
		p2++;
	}
}
void check0(int a[], int b[])
{
	cnt = 0;
	p1 = p2 = 1;
	while(p1 <= 2 * n && p2 <= 2 * n)
	{
		while(p1 <= 2 * n && a[p1])
		{
			ans[++cnt] = a[p1];
			p1++;
		}
		while(p2 <= 2 * n && b[p2])
		{
			ans[++cnt] = b[p2];
			p2++;
		}
		if (p1 > 2 * n || p2 > 2 * n) break;
		ans[++cnt] = 0;
		p1++; p2++;
	}
	while(p1 <= 2 * n) 
	{
		ans[++cnt] = a[p1];
		p1++;
	}
	while(p2 <= 2 * n) 
	{
		ans[++cnt] = b[p2];
		p2++;
	}
}
int main()
{
	scanf("%d", &test);
	while(test--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= 3; i++)
		{
			scanf("%s", s);
			num[i] = 0;
			for (int j = 1; j <= 2 * n; j++)
			{
				a[i][j] = s[j - 1] - '0';
				if (a[i][j]) num[i]++;
			}
		}
		flg = 0;
		for (int i = 1; i <= 3; i++)
		{
			for (int j = i + 1; j <= 3; j++)
			{
				if (min(num[i], num[j]) >= n) check1(a[i], a[j]);
				if (max(num[i], num[j]) <= n) check0(a[i], a[j]);
			}
		}
		for (int i = 1; i <= cnt; i++)
		{
			printf("%d", ans[i]);
		}
		printf("\n");
	}
	return 0;
}