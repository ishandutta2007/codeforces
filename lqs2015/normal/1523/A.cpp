#include <bits/stdc++.h>
using namespace std;
bool flg;
int n, m, test, a[1111], b[1111], pre;
char s[1111];
int main()
{
	scanf("%d", &test);
	while(test--)
	{
		scanf("%d%d", &n, &m);
		flg = 0;
		scanf("%s", s);
		for (int i = 1; i <= n; i++) 
		{
			a[i] = s[i - 1] - '0';
			if (a[i]) flg = 1;
		}
		a[n + 1] = 0;
		if (!flg)
		{
			for (int i = 1; i <= n; i++) printf("0");
			printf("\n");
			continue;
		}
		if (m <= n)
		{
			for (int i = 1; i <= m; i++)
			{
				for (int j = 1; j <= n; j++)
				{
					if (a[j] || a[j + 1] + a[j - 1] == 1) b[j] = 1;
					else b[j] = 0;
				}
				for (int j = 1; j <= n; j++) a[j] = b[j];
			}
			for (int i = 1; i <= n; i++) printf("%d", a[i]);
			printf("\n");
		}
		else
		{
			pre = 0;
			for (int i = 1; i <= n; i++)
			{
				if (a[i] == 1)
				{
					if (pre == 0 || ((i - pre) & 1))
					{
						for (int j = pre + 1; j < i; j++) a[j] = 1;
					}
					else
					{
						for (int j = pre + 1; j < i; j++) 
						{
							if (j != (i + pre) / 2) a[j] = 1;
						}
					}
					pre = i;
				}
			}
			for (int i = pre + 1; i <= n; i++) a[i] = 1;
			for (int i = 1; i <= n; i++) printf("%d", a[i]);
			printf("\n");
		}
	}
	return 0;
}