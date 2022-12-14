#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long bit[2][4444],sz,n,a[2222][2222],D[2222][2222],d[2222],pw[2222],jc[2222],ans,all,ass,curm;
bool used[2222];
void update(long long p,long long x,long long del)
{
	while(p<=sz)
	{
		bit[x][p]+=del;
		p+=p&(-p);
	}
}
long long query(long long p,long long x)
{
	long long res=0;
	while(p>=1)
	{
		res+=bit[x][p];
		p-=p&(-p);
	}
	return res;
}
int main()
{
	scanf("%lld",&n);
	for (long long i=1;i<=n;i++)
	{
		for (long long j=1;j<=n;j++)
		{
			scanf("%lld",&a[i][j]);
		}
	}
	d[0]=1;d[1]=0;d[2]=1;
	for (long long i=3;i<=n;i++)
	{
		d[i]=(i-1)*(d[i-1]+d[i-2])%mod;
	}
	jc[0]=1;
	for (long long i=1;i<=n;i++) jc[i]=jc[i-1]*i%mod;
	for (long long i=0;i<=n;i++)
	{
		for (long long j=0;j<=i;j++)
		{
			if (i==j) D[i][j]=d[i];
			else if (!j) D[i][j]=jc[i];
			else D[i][j]=(j*D[i-1][j-1]+(i-j)*D[i-1][j])%mod;
		}
	}
	pw[0]=1;
	for (long long i=1;i<=n;i++) pw[i]=pw[i-1]*d[n]%mod;
	memset(used,0,sizeof(used));
	sz=1;
	while(sz<n) sz*=2;
	for (long long i=1;i<=n;i++)
	{
		for (long long j=1;j<a[1][i];j++)
		{
			if (!used[j]) 
			{
				ans=(ans+jc[n-i]*pw[n-1])%mod;
			}
		}
		used[a[1][i]]=1;
	}
	for (long long i=2;i<=n;i++)
	{
		memset(bit,0,sizeof(bit));
		for (long long j=2;j<=n;j++)
		{
			update(a[i-1][j],1,1);
		}
		curm=n-1;
		for (long long j=1;j<=n;j++)
		{
			if (a[i-1][j]<a[i][j]) 
			{
				all=a[i][j]-2-query(a[i][j]-1,0)+query(a[i-1][j],0)-query(a[i-1][j]-1,0);
				ass=query(a[i][j]-1,1)-query(a[i-1][j],1)+query(a[i-1][j]-1,1);
			}
			else 
			{
				all=a[i][j]-1-query(a[i][j]-1,0);ass=query(a[i][j]-1,1);
			}
			ans=(ans+(ass*D[n-j][curm-1]+(all-ass)*D[n-j][curm])%mod*pw[n-i])%mod;
			if (j==n) break;
			update(a[i][j],0,1);
			if (query(a[i][j],1)-query(a[i][j]-1,1)) update(a[i][j],1,-1);
			if (query(a[i-1][j+1],1)-query(a[i-1][j+1]-1,1)) update(a[i-1][j+1],1,-1);
			curm=query(n,1);
		}
	}
	printf("%lld\n",ans);
	return 0;
}