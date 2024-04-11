#include <cstdio>
#include <iostream>
#define MN 201000

int a[MN], b[MN], w[MN];
char c[MN];

int main()
{
	int n, k; scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++)
	{
		int p; scanf("%d", &p);
		a[p] = i; b[i] = p;
	}
	
	int now = 0;
	for(int i = 1; i <= n; i++)
	{
		int p; scanf("%d", &p);
		now = std::max(now, a[p]);
		w[a[p]] = now;
	}
	
	int lst = 0, Max = 0;
	for(int i = 1; i <= n; i++)
	{
		if(i > Max) lst++, lst = std::min(lst, 26);
		if(w[i] > Max)
		{
			for(int j = Max + 1; j <= w[i]; j++)
			c[b[j]] = lst + 'a' - 1;
			Max = w[i];
		}
	}
	
	if(lst < k) puts("NO");
	else printf("YES\n%s", c + 1);
}