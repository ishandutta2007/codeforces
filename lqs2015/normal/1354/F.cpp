#include<bits/stdc++.h>
using namespace std;
int test,n,k,a[88],b[88],path[88][88],x,y,ap[88],ans[888],cnt,sz,nt;
vector<int> v;
long long dp[88][88],mx,cc;
pair<pair<int,int>,int> arr[88];
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d",&n,&k);
		for (int i=1;i<=n;i++)
		{
			scanf("%d%d",&a[i],&b[i]);
			arr[i]=make_pair(make_pair(b[i],a[i]),i);
		}
		sort(arr+1,arr+n+1);
		for (int i=0;i<=n;i++)
		{
			for (int j=0;j<=k;j++)
			dp[i][j]=-1e18;
		}
		dp[0][0]=0;
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<=k;j++)
			{
				if (dp[i+1][j]<dp[i][j]+1ll*(k-1)*arr[i+1].first.first)
				{
					dp[i+1][j]=dp[i][j]+1ll*(k-1)*arr[i+1].first.first;
					path[i+1][j]=0;
				}
				if (dp[i+1][j+1]<dp[i][j]+1ll*j*arr[i+1].first.first+arr[i+1].first.second)
				{
					dp[i+1][j+1]=dp[i][j]+1ll*j*arr[i+1].first.first+arr[i+1].first.second;
					path[i+1][j+1]=1;
				}
			}
		}
		x=n;y=k;
		while(x>=1)
		{
			if (x==nt) 
			{
				x--;
				continue;
			}
			ap[x]=y;
			y-=path[x][y];
			x--;
		}
		ap[0]=0;
		cnt=0;sz=0;int ps=0;
		for (int i=1;i<=n;i++)
		{
			if (ap[i]==ap[i-1]+1)
			{
				sz++;
				if (sz==k)
				{
					ps=i;
					break;
				}
				ans[++cnt]=arr[i].second;
			}
		}
		for (int i=1;i<=n;i++)
		{
			if (ap[i]==ap[i-1]) 
			{
				ans[++cnt]=arr[i].second;
				ans[++cnt]=-arr[i].second;
			}
		}
		ans[++cnt]=arr[ps].second;
		printf("%d\n",cnt);
		for (int i=1;i<=cnt;i++) printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}