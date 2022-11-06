#include <cstdio>
#include <iostream>
#define MN 301000

int n;
int c[MN];
int col[MN];
int q[MN], h = 1, t = 0;
int a[MN];

void modify(int x, int v) {for(int i = x; i <= n; i += i & -i) c[i] += v;}
int query(int x) {int ans = 0; for(int i = x; i; i -= i & -i) ans += c[i]; return ans;}

void add(int l, int r, int v)
{
	if(l > n) return;
	r = std::min(r, n);
	modify(l, v);
	if(r != n) modify(r + 1, -v);
}

void Add(int x, int v) {add(q[x - 1] + 1 + a[q[x]] - 1, q[x] + a[q[x]] - 1, v);}

int main()
{
	scanf("%d", &n);
	int lst = 0;
	long long ans = 0;
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		if(col[a[i]] > lst)
		{
			while(h <= t && q[h] <= col[a[i]]) Add(h, -1), h++;
			if(h <= t) Add(h, -1);
			lst = col[a[i]];
			q[h - 1] = lst;
			if(h <= t) Add(h, 1);
		}
		while(h <= t && a[i] >= a[q[t]]) Add(t, -1), t--;
		q[++t] = i; Add(t, 1);
		ans += query(i);
		col[a[i]] = i;
	}
	printf("%lld\n", ans);
}