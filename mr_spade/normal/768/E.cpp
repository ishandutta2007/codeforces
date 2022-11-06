#include<cstdio>
int n,ans;
signed main()
{
	int x;
	register int i;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&x);
		for(i=1;i*(i+1)/2<=x;i++);
		ans^=i-1;
	}
	puts(ans?"NO":"YES");
	return 0;
}