#include <cstdio>
#include <iostream>
#define MN 201000

int n, a[MN];
int w[MN], l[MN], r[MN];
int st[MN], top = 0;

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]), w[a[i]] = i;
	a[n + 1] = 1e9;
	for(int i = 1; i <= n + 1; i++)
	{
		while(top && a[st[top]] < a[i]) r[st[top--]] = i - 1;
		l[i] = st[top] + 1; st[++top] = i;
	}
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		int l1 = l[i], r1 = i - 1, l2 = i + 1, r2 = r[i];
		if(i - l[i] > r[i] - i) std::swap(l1, l2), std::swap(r1, r2);
		for(int j = l1; j <= r1; j++)
		{
			int v = a[i] - a[j];
			if(1 <= v && v <= n && l2 <= w[v] && w[v] <= r2) ans++;
		}
	}
	printf("%d\n", ans);
}