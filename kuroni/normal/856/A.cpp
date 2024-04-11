#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int a[105], b[105], d[10005], i, j, n, t, cnt;
bool chk[1000005];

int main()
{
	scanf("%d", &t);
	while (t--)
	{
		memset(chk, 0, sizeof(chk)); cnt = 0;
		scanf("%d", &n);
		for (i = 1; i <= n; i++)
			scanf("%d", a + i);
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				d[++cnt] = abs(a[i] - a[j]);
		cnt = 1; i = 1;
		while (i <= n)
		{
			while (chk[cnt] && cnt <= 1000000)
				cnt++;
			if (cnt == 1000000)
				break;
			b[i++] = cnt;
			for (j = 1; j <= n * n; j++)
				if (cnt + d[j] <= 1000000)
					chk[cnt + d[j]] = true;
		}
		if (i == n + 1)
		{
			printf("YES\n");
			for (i = 1; i <= n; i++)
				printf("%d ", b[i]);
			printf("\n");
		}
		else printf("NO\n");
	}
}