#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
int n, l, r, xx, ans, a[50];
void dfs(int x, int sum, int mi, int mx)
{
	if(x > n)
	{
		if(l <= sum && r >= sum && mx - mi >= xx) ans ++;
		return;
	}
	if(sum == 0) dfs(x + 1, a[x], a[x], a[x]);
	else dfs(x + 1, sum + a[x], mi, a[x]);
	dfs(x + 1, sum, mi, mx);
}

int main()
{
	scanf("%d%d%d%d",&n,&l,&r,&xx);
	for(int i = 1; i <= n; i ++) 
		scanf("%d",&a[i]);
	sort(a + 1, a + 1 + n);
	dfs(1,0,0,0);
	printf("%d\n",ans);
	return 0;
}