#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
int n,m,k,a[20],c[20][20],d[1<<18];
LL f[20][1<<18],ans;
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<(1<<n);i++) d[i]=d[i>>1]+(i&1);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	for(int i=1,x,y,z;i<=k;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		x--,y--;
		c[x][y]=z;
	}
	for(int i=0;i<n;i++) f[i][1<<i]=a[i];
	for(int S=1;S<(1<<n)-1;S++)
		for(int i=0;i<n;i++)
		{
			if(!(S&(1<<i))) continue;
			for(int k=0;k<n;k++)
			{
				if(S&(1<<k)) continue;
				f[k][S|(1<<k)]=max(f[k][S|(1<<k)],f[i][S]+c[i][k]+a[k]);
			}
		}
	for(int S=0;S<(1<<n);S++)
		if(d[S]==m)
		{
			for(int i=0;i<n;i++)
				ans=max(ans,f[i][S]);
		}
	printf("%I64d\n",ans);
	return 0;
}