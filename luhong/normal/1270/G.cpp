#include <iostream>
#include <cstdio>
#define MN 1010000

int st[MN], top = 0, inq[MN];
int ans[MN], tot = 0;
int a[MN];

void dfs(int x)
{
	if(inq[x])
	{
		do {
			ans[++tot] = st[top];
		} while(st[top--] != x);
		return;
	}
	inq[x] = 1; st[++top] = x;
	dfs(x - a[x]);
}

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		int n; scanf("%d", &n);
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
		dfs(1 - a[1]);
		printf("%d\n", tot);
		for(int i = 1; i <= tot; i++) printf("%d ", ans[i]); puts("");
		for(int i = 1; i <= n; i++) inq[i] = 0; top = 0; tot = 0;
	}
}