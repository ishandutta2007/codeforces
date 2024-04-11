#include<cstdio>
#include<cstring>
const int N=1005;
int n,ans;
int a[N];
signed main()
{
	register int i,j;
	scanf("%d",&n);
	for(i=1;i<=n*2;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=n*2;i+=2)
	{
		for(j=i+1;j<=n*2;j++)
			if(a[j]==a[i])
			{
				memcpy(a+i+2,a+i+1,sizeof(int)*(j-i-1));
				ans+=j-i-1;a[i+1]=a[i];
				break;
			}
	}
	printf("%d\n",ans);
	return 0;
}