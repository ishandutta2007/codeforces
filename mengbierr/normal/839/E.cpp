#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[45][45];
int d[45],b[45];
int maxn,n;
void dfs(int k,int r)
{
	bool flag;
	if(r+n-k+1<=maxn) return;
	if(k==n+1)
	{
		if(r>maxn) maxn=r;
		return;
	}
	flag=1;
	if(d[k]<=maxn-1) flag=0;
	else
	{
		for(int i=1;i<=r;i++)
		{
			if(a[b[i]][k]==0)
			{
				flag=0;
				break;
			}
		}
	}
	if(flag)
	{
		b[r+1]=k;
		dfs(k+1,r+1);
	}
	dfs(k+1,r);
}
int main()
{
	int k;
	double ans;
	cin>>n>>k;
	memset(d,0,sizeof(d));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
			if(a[i][j]==1) d[i]++;
		}
	}
	maxn=1,dfs(1,0);
	ans=(maxn-1)*k*k*1.0/(2*maxn);
	printf("%.12lf",ans);
}