#include <cstdio>
#include <iostream>

int u[101000], v[101000], tot = 0;
int n, a[101000];
int k[101000], tt = 0;
int o[101000], t = 0;

int main()
{
	scanf("%d", &n);
	int id1 = 0, id2 = 0;
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		if(a[i] == 1)
		{
			if(!id1) id1 = i;
			else if(!id2) id2 = i;
			else o[++t] = i;
		}
		else k[++tt] = i;
	}
	if(tt == 0) return 0 * puts("NO");
	if(!id1) id1 = k[tt--];
	if(!id2) id2 = k[tt--];
	for(int i = 2; i <= tt; i++)
	{
		++tot;
		u[tot] = k[i - 1];
		v[tot] = k[i];
	}
	for(int i = 1; i <= tt; i++) a[k[i]] -= 2;
	int Ans = tt + 1;
	++tot; u[tot] = id1, v[tot] = k[1];
	++tot; u[tot] = id2, v[tot] = k[tt];
	int j = 1;
	for(int i = 1; i <= t; i++)
	{
		while(j <= tt && a[k[j]] == 0) j++;
		if(j == tt + 1) return 0 * puts("NO");
		++tot; u[tot] = k[j], v[tot] = o[i]; a[k[j]]--;
	}
	printf("YES %d\n%d\n", Ans, tot);
	for(int i = 1; i <= tot; i++) printf("%d %d\n", u[i], v[i]);
	return 0;
}