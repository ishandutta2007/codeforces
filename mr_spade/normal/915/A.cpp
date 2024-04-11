#include<cstdio>
signed main()
{
	int n,k,ans=1000000;
	int a[10000];
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		if(k%a[i]==0)
			if(k/a[i]<ans)
				ans=k/a[i];
	}
	printf("%d\n",ans);
}