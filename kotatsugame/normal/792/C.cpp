#include<iostream>
#include<algorithm>
using namespace std;
string N;
int dp[1<<17][3];
int pr[1<<17][3];
int ep[3],er[3];
main()
{
	cin>>N;
	for(int i=0;i<=N.size();i++)for(int j=0;j<3;j++)
	{
		dp[i][j]=-1;
		pr[i][j]=-1;
	}
	for(int j=0;j<3;j++)ep[j]=er[j]=-1;
	for(int i=0;i<N.size();i++)
	{
		int now=N[i]-'0';
		for(int j=0;j<3;j++)if(ep[j]>=0)
		{
			int nj=(j+now)%3;
			if(dp[i+1][nj]<ep[j]+1)
			{
				dp[i+1][nj]=ep[j]+1;
				pr[i+1][nj]=er[j];
			}
		}
		if(now!=0&&dp[i+1][now%3]<1)
		{
			dp[i+1][now%3]=1;
			pr[i+1][now%3]=-1;
		}
		for(int j=0;j<3;j++)if(dp[i+1][j]>ep[j])
		{
			ep[j]=dp[i+1][j];
			er[j]=i+1;
		}
	}
	int mi=er[0];
	if(mi==-1)
	{
		for(int i=0;i<N.size();i++)if(N[i]=='0')
		{
			cout<<0<<endl;
			return 0;
		}
		cout<<-1<<endl;
	}
	else
	{
		string ans="";
		int j=0;
		while(mi>=0)
		{
			char c=N[mi-1];
			ans+=c;
			mi=pr[mi][j];
			j=(j-(c-'0')%3+3)%3;
		}
		for(int i=ans.size();i--;)cout<<ans[i];
		cout<<endl;
	}
}