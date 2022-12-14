#include<iostream>
#include<cmath>
using namespace std;
long long dp[333333][111],n,m,a[111],cnt,p;
bool used[333333],u[13];
int main()
{
	cin>>n>>m;
	while(n)
	{
		a[cnt++]=n%10;
		if (n%10==0) used[1<<(cnt-1)]=1;
		n/=10;
	}
	dp[0][0]=1;
	for (long long i=1;i<(1<<cnt);i++)
	{
		if (used[i]) continue;
		for (int j=0;j<=9;j++) u[j]=0; 
		for (long long j=0;j<cnt;j++)
		{
			if (!u[a[j]] && i&(1<<j)) 
			{
				u[a[j]]=1;
				p=i^(1<<j);
				for (long long k=0;k<m;k++)
				{
					dp[i][(k*10+a[j])%m]+=dp[p][k];
				} 
			}
		}
	}
	cout<<dp[(1<<cnt)-1][0]<<endl;
	return 0;
}