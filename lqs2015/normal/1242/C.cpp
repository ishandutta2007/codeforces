#include<bits/stdc++.h>
using namespace std;
int k,n[55],a[55][5555],id[55][5555],cnt,path[555555];
int pp[555555],bb[555555],cc[222222][17],dd[222222][17],c[17],d[17],ansc[17],ansd[17];
long long sum,sm[22],cur;
map<int,int> mp;
int to[555555];
bool used[555555],flg,fucked[555555],dp[555555];
void dfs(int i,int msk,int s)
{
	if (msk&(1<<pp[i])) return;
	if (to[i]==s)
	{
		c[pp[i]]=i;
		d[pp[to[i]]]=pp[i];
		msk|=(1<<pp[i]);
		if (!fucked[msk])
		{
			fucked[msk]=1;
			for (int j=0;j<k;j++)
			{
				cc[msk][j]=c[j];
				dd[msk][j]=d[j];
			}
		}
		return;
	}
	else
	{
		c[pp[i]]=i;
		d[pp[to[i]]]=pp[i];
		dfs(to[i],msk|(1<<pp[i]),s);
	}
}
int main()
{
	scanf("%d",&k);
	for (int i=0;i<k;i++)
	{
		scanf("%d",&n[i]);
		for (int j=1;j<=n[i];j++)
		{
			scanf("%d",&a[i][j]);
			id[i][j]=++cnt;
			pp[cnt]=i;mp[a[i][j]]=cnt;bb[cnt]=a[i][j];
			sum+=a[i][j];sm[i]+=a[i][j];
		}
	}
	sum/=k;
	for (int i=0;i<k;i++)
	{
		for (int j=1;j<=n[i];j++)
		{
			cur=sum-(sm[i]-a[i][j]);
			if (cur>2000000000ll || cur<-2000000000ll) continue;
			if (mp.find((int)cur)!=mp.end()) 
			{
				to[id[i][j]]=mp[cur];
			}
		}
	}
	for (int i=1;i<=cnt;i++)
	{
		memset(c,-1,sizeof(c));
		memset(d,-1,sizeof(d));
		dfs(i,0,i);
	}
	dp[0]=1;
	for (int i=1;i<(1<<k);i++)
	{
		for (int j=i;j;j=(j-1)&i)
		{
			if (fucked[j] && dp[i^j])
			{
				dp[i]=1;
				path[i]=j;
			}
		}
	}
	if (!dp[(1<<k)-1])
	{
		printf("No\n");
		return 0;
	}
	int mk=(1<<k)-1;
	while(mk)
	{
		for (int j=0;j<k;j++)
		{
			if (path[mk]&(1<<j)) 
			{
				ansc[j+1]=bb[cc[path[mk]][j]];
				ansd[j+1]=dd[path[mk]][j]+1;
			}
		}
		mk^=path[mk];
	}
	printf("Yes\n");
	for (int i=1;i<=k;i++) 
	{
		printf("%d %d\n",ansc[i],ansd[i]);
	}
	return 0;
}