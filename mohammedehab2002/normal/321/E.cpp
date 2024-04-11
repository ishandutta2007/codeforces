#include <iostream>
using namespace std;
int cum[4005][4005],dp[4005][805];
int calc(int l,int r,int k)
{
	return dp[l][k]+(cum[r][r]-cum[l][r]-cum[r][l]+cum[l][l])/2;
}
void solve(int k,int l,int r,int optl,int optr)
{
	if (l>r)
	return;
	int mid=(l+r)/2,opt=optl;
	dp[mid][k]=calc(opt,mid,k-1);
	for (int i=optl+1;i<=min(optr,mid-1);i++)
	{
		int tmp=calc(i,mid,k-1);
		if (tmp<=dp[mid][k])
		{
			dp[mid][k]=tmp;
			opt=i;
		}
	}
	solve(k,l,mid-1,optl,opt);
	solve(k,mid+1,r,opt,optr);
}
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
	{
		int s=0;
		for (int x=1;x<=n;x++)
		{
			char c=getchar();
			while (c<'0' || c>'9')
			c=getchar();
			int a=c-'0';
			s+=a;
			cum[i][x]=cum[i-1][x]+s;
		}
	}
	for (int i=0;i<=n;i++)
	{
		for (int x=0;x<=k;x++)
		dp[i][x]=(1<<30);
	}
	dp[0][0]=0;
	for (int i=1;i<=k;i++)
	solve(i,1,n,0,n);
	printf("%d",dp[n][k]);
}