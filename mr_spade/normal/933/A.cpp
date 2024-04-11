#include<cstdio>
#include<iostream>
using std::max;
const int N=2005;
int n,res,ans;
int a[N];
int f[N][3];
signed main()
{
	register int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
	{
		res=0;
		if(a[1]==1)
			f[1][1]=f[1][2]=1;
		else
			f[1][1]=0,f[1][2]=1;
		for(j=2;j<i;j++)
			if(a[j]==1)
			{
				f[j][1]=f[j-1][1]+1;
				f[j][2]=max(f[j-1][1]+1,f[j-1][2]);
			}
			else
			{
				f[j][1]=f[j-1][1];
				f[j][2]=max(f[j-1][1]+1,f[j-1][2]+1);
			}
		res+=max(f[i-1][1],f[i-1][2]);
		if(a[i]==1)
			f[i][1]=f[i][2]=1;
		else
			f[i][1]=0,f[i][2]=1;
		for(j=i+1;j<=n;j++)
			if(a[j]==1)
			{
				f[j][1]=f[j-1][1]+1;
				f[j][2]=max(f[j-1][1]+1,f[j-1][2]);
			}
			else
			{
				f[j][1]=f[j-1][1];
				f[j][2]=max(f[j-1][1]+1,f[j-1][2]+1);
			}
		res+=max(f[n][1],f[n][2]);
		if(res>ans)
			ans=res;
	}
	printf("%d\n",ans);
	return 0;
}