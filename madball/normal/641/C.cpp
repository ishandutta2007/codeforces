#include <stdio.h>

int mt[128][128];

int t[10005], t1[10005], t2[10005], t3[10005];

int stack[2000005];

int ans[1000005];
int ans2[1000005];

int main()
{
	int n, q;
	scanf("%d%d\n", &n, &q);
	int shift = 0, ss=0;
	for (int i = 0; i <q; i++)
	{
		int t;
		scanf("%d", &t);
		if (t == 1)
		{
			int sh;
			scanf("%d", &sh);
			shift += sh;
			if (shift >= n)
			{
				shift -= n;
			}
			else if (shift <= -n)
			{
				shift += n;
			}
		}
		else
		{
			stack[ss] = (shift % 2 + 2) % 2;
			ss++;
			if (ss > 1 && stack[ss - 1] == stack[ss - 2])
			{
				ss -= 2;
			}
		}
	}
	ss = ss%n;
	if (stack[0] == 0)
	{
		for (int i = 0; i < n; i += 2)
		{
			ans[(i + ss) % n] = i;
			ans[(i + 1 - ss + n) % n] = i + 1;
		}
	}
	else
	{
		for (int i = 0; i < n; i += 2)
		{
			ans[(i + 1 + ss) % n] = i + 1;
			ans[(i - ss + n) % n] = i;
		}
	}
	for (int i = 0; i < n; i++)
	{
		ans2[(i + shift + n) % n] = ans[i];
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d ", ans2[i]+1);
	}
}