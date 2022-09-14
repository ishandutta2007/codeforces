#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int N,A[5050];
int dp[5050][5050];
queue<int>idx7[7],idx[1<<17];
main()
{
	cin>>N;
	for(int i=1;i<=N;i++)
	{
		cin>>A[i];
		idx7[A[i]%7].push(i);
		idx[A[i]].push(i);
	}
	int ans=1;
	for(int i=1;i<=N;i++)
	{
		idx7[A[i]%7].pop();
		idx[A[i]].pop();
		for(int j=0;j<i;j++)
		{
			if(dp[i][j]<2-!j)dp[i][j]=2-!j;
			if(ans<dp[i][j])ans=dp[i][j];
			if(!idx7[A[i]%7].empty())
			{
				int id=idx7[A[i]%7].front();
				dp[id][j]=max(dp[id][j],dp[i][j]+1);
			}
			if(!idx[A[i]-1].empty())
			{
				int id=idx[A[i]-1].front();
				dp[id][j]=max(dp[id][j],dp[i][j]+1);
			}
			if(!idx[A[i]+1].empty())
			{
				int id=idx[A[i]+1].front();
				dp[id][j]=max(dp[id][j],dp[i][j]+1);
			}
			if(j==0)
			{
				for(int k=i+1;k<=N;k++)dp[k][i]=max(dp[k][i],dp[i][0]+1);
			}
			else
			{
				if(!idx7[A[j]%7].empty())
				{
					int id=idx7[A[j]%7].front();
					dp[id][i]=max(dp[id][i],dp[i][j]+1);
				}
				if(!idx[A[j]-1].empty())
				{
					int id=idx[A[j]-1].front();
					dp[id][i]=max(dp[id][i],dp[i][j]+1);
				}
				if(!idx[A[j]+1].empty())
				{
					int id=idx[A[j]+1].front();
					dp[id][i]=max(dp[id][i],dp[i][j]+1);
				}
			}
		}
	}
	cout<<ans<<endl;
}