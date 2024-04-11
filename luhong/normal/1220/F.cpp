#include <iostream>
#include <algorithm>
#include <cstdio>
#define MN 401000

int st[MN], dep[MN], top = 0;
int n;
int a[MN], ans1[MN], ans2[MN];

void solve(int *a, int *ans)
{
	int id; top = 0;
	for(int i = 1; i <= n; i++)
		if(a[i] == 1) {id = i; break;}
	
	int now = 0;
	for(int i = id; i <= n; i++)
	{
		int Max = 0;
		while(top && a[i] < st[top])
		{
			Max = std::max(Max, dep[top]);
			top--; Max++;
		}
		st[++top] = a[i]; dep[top] = Max;
		now = std::max(now, top + Max);
		ans[i % n] = now;
	}
	
	for(int i = 1; i < id; i++)
	{
		int Max = 0;
		while(top && a[i] < st[top])
		{
			Max = std::max(Max, dep[top]);
			top--; Max++;
		}
		st[++top] = a[i]; dep[top] = Max;
		now = std::max(now, top + Max);
		ans[i] = now;
	}
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	solve(a, ans1); std::reverse(a + 1, a + n + 1); solve(a, ans2);
	int Ans = std::max(ans1[0], ans2[0]), id = 0;
	for(int i = 1; i < n; i++)
	{
		if(std::max(ans1[i], ans2[n - i]) < Ans)
			Ans = std::max(ans1[i], ans2[n - i]), id = i;
	}
	printf("%d %d\n", Ans, id);
}