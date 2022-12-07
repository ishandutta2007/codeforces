#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 105
using namespace std;
int n,sum,all,a[N],b[N],f[N][N*N],ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]),sum+=a[i];
	for(int i=1;i<=n;i++)
	scanf("%d",&b[i]),all+=b[i];
	for(int i=0;i<=n;i++)
	for(int j=0;j<=all;j++)
	f[i][j]=-1e9;
	f[0][0]=0;
	for(int i=1;i<=n;i++)
	for(int j=n;j;j--)
	for(int k=all;k>=b[i];k--)
	f[j][k]=max(f[j][k],f[j-1][k-b[i]]+a[i]);
	for(int i=1;i<=n;i++)
	{
		ans=-1e9;
		for(int j=sum;j<=all;j++)
		ans=max(ans,f[i][j]);
		if(ans>=0)
		{
			printf("%d %d\n",i,sum-ans);
			return 0;
		}
	}
}