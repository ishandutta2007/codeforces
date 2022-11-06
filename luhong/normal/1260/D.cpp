#include <iostream>
#include <cstdio>
#include <algorithm>
#define MN 201000
 
int m, n, k, T;
int l[MN], r[MN], d[MN], a[MN];
struct xxx{
	int l, r;
}t[MN];
 
bool cmp(xxx a, xxx b) {return a.l < b.l;}
 
bool check(int x)
{
	int tot = 0;
	for(int i = 1; i <= k; i++)
	{
		if(d[i] > x) 
		{
			++tot;
			t[tot].l = l[i] - 1;
			t[tot].r = r[i];
		}
	}
	std::sort(t + 1, t + tot + 1, cmp);
	int Max = 0, ans = n + 1;
	for(int i = 1; i <= tot; i++)
	{
		if(t[i].l > Max) Max = t[i].l;
		if(t[i].r > Max) ans += 2 * (t[i].r - Max), Max = t[i].r;
	}
	if(ans > T) return 0;
	else return 1;
}
 
int main()
{
	scanf("%d%d%d%d", &m, &n, &k, &T);
	for(int i = 1; i <= m; i++) scanf("%d", &a[i]);
	for(int i = 1; i <= k; i++) scanf("%d%d%d", &l[i], &r[i], &d[i]); 
	std::sort(a + 1, a + m + 1);
	int l = 1, r = m + 1;
	while(l < r)
	{
		int mid = l + r >> 1;
		if(check(a[mid])) r = mid;
		else l = mid + 1; 
	}
	printf("%d\n", m - r + 1);
}