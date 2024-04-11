#include<iostream>
#include<cmath>
using namespace std;
long long n,m,k,ans,x,y,z,dp[1111111],msk,a[15];
bool road[15][15];
int main()
{
	cin>>n>>m>>k;
	for (long long i=1;i<=m;i++)
	{
		cin>>x>>y;
		x--;y--;
		road[x][y]=road[y][x]=1;
	}
	for (long long i=0;i<n;i++) 
	{
		dp[(long long)pow(3,i)]=1;
	}
	for (long long i=0;i<pow(3,n);i++)
	{
		msk=i;x=y=z=0;
		for (long long j=0;j<n;j++)
		{
			a[j]=msk%3;
			if (msk%3==0) x++;
			else if (msk%3==1) y++;
			else z++;
			msk/=3;
		}
		if (y) dp[i]/=y;
		if (!x)
		{
			if (y==k) ans+=dp[i];
			continue;
		}
		for (long long j=0;j<n;j++)
		{
			if (a[j]==1)
			{
				for (long long kk=0;kk<n;kk++)
				{
					if (road[j][kk] && !a[kk]) 
					{
						if (z==0 && y==1) dp[i+(long long)pow(3,kk)]+=dp[i];
						else dp[i+(long long)pow(3,j)+(long long)pow(3,kk)]+=dp[i];
					}
				}
			}
			else if (a[j]==2)
			{
				for (long long kk=0;kk<n;kk++)
				{
					if (road[j][kk] && !a[kk]) dp[i+(long long)pow(3,kk)]+=dp[i];
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}