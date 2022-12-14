#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int test,n,m,k,a[4444],f[4444],mn[4444][4444],ans;
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d%d",&n,&m,&k);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		for (int i=0;i<m;i++)
		{
			f[i]=max(a[i+1],a[n-(m-1-i)]);
		}
		for (int i=0;i<m;i++)
		{
			mn[i][i]=f[i];
			for (int j=i+1;j<m;j++)
			{
				mn[i][j]=min(mn[i][j-1],f[j]);
			}
		}
		k=min(k,m-1);ans=-1e9;
		for (int i=0;i<=k;i++)
		{
			ans=max(ans,mn[i][i+(m-1-k)]);
		}
		printf("%d\n",ans);
	}
	return Accepted;
}