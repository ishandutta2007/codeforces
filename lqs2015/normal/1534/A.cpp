#include<bits/stdc++.h>
using namespace std;
int n, m, test, flg;
char s[55][55];
int main()
{
	scanf("%d", &test);
	while(test--)
	{
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++)
		{
			scanf("%s", s[i]);
		}
		flg = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if ((i + j) & 1)
				{
					if (s[i][j] == 'W') flg = 1;
				}
				else
				{
					if (s[i][j] == 'R') flg = 1;
				}
			}
		}
		if (!flg)
		{
			printf("YES\n");
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					if ((i + j) & 1) putchar('R');
					else putchar('W');
				}
				putchar('\n');
			}
		}
		else
		{
			flg = 0;
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					if ((i + j) & 1)
					{
						if (s[i][j] == 'R') flg = 1;
					}
					else
					{
						if (s[i][j] == 'W') flg = 1;
					}
				}
			}
			if (!flg)
			{
				printf("YES\n");
				for (int i = 0; i < n; i++)
				{
					for (int j = 0; j < m; j++)
					{
						if ((i + j) & 1) putchar('W');
						else putchar('R');
					}
					putchar('\n');
				}
			}
			else
			{
				printf("NO\n");
			}
		}
	}
	return 0;
}