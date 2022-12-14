#include<bits/stdc++.h>
using namespace std;
int val[15][4444],test,n,m,cnt,ctr,arr[15][4444],cur,msk,p[15],sum,dp[15][4444];
pair<int,pair<int,int> > a[222222];
bool used[4444];
vector<int> v[4444];
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d",&n,&m);
		cnt=ctr=0;
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=m;j++)
			{
				scanf("%d",&arr[i][j]);
				a[++cnt]=make_pair(arr[i][j],make_pair(i,j));
			}
		}
		memset(used,0,sizeof(used));
		sort(a+1,a+cnt+1);
		reverse(a+1,a+cnt+1);
		for (int i=1;i<=m;i++) v[i].clear();
		for (int i=1;i<=cnt;i++)
		{
			if (!used[a[i].second.second]) 
			{
				used[a[i].second.second]=1;
				ctr++;
			}
			v[a[i].second.second].push_back(a[i].second.first-1);
			if (ctr==n) break;
		}
		for (int i=1;i<=n;i++)
		{
			for (int j=0;j<(1<<n);j++) 
			val[i][j]=-1e9;
		}
		cur=0;
		for (int i=1;i<=m;i++)
		{
			if (v[i].empty()) continue;
			cur++;val[cur][0]=0;
			for (int j=0;j<n;j++)
			{
				msk=0;
				for (int k=0;k<v[i].size();k++)
				{
					p[(v[i][k]+j)%n]=arr[v[i][k]+1][i];
					msk|=(1<<((v[i][k]+j)%n));
				}
				for (int k=msk;k;k=(k-1)&msk)
				{
					sum=0;
					for (int h=0;h<n;h++)
					{
						if (k&(1<<h)) sum+=p[h];
					}
					val[cur][k]=max(val[cur][k],sum);
				}
			}
		}
		assert(cur==ctr);
		for (int i=1;i<(1<<n);i++) dp[0][i]=-1e9;
		for (int i=1;i<=cur;i++)
		{
			for (int j=0;j<(1<<n);j++)
			{
				dp[i][j]=val[i][j];
				for (int k=j;k;k=(k-1)&j)
				{
					dp[i][j]=max(dp[i][j],dp[i-1][k]+val[i][k^j]);
				}
			}
		}
		printf("%d\n",dp[cur][(1<<n)-1]);
	}
	return 0;
}