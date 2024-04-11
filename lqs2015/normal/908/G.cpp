#include<bits/stdc++.h>
using namespace std;
string s;
int n,dp[777][11][777][2],nk,nh,ans,cur,pp;
const int mod=1e9+7;
void add(int &x,int y)
{
	x+=y;
	if (x>=mod) x-=mod;
}
int main()
{
	cin>>s;
	n=s.size();
	for (int i=1;i<=9;i++)
	{
		dp[0][i][0][0]=1;
	}
	for (int i=0;i<n;i++)
	{
		for (int j=1;j<=9;j++)
		{
			for (int k=0;k<=i;k++)
			{
				for (int h=0;h<2;h++)
				{
					for (int p=0;p<=9;p++)
					{
						if (!h && p>s[i]-'0') continue;
						nk=k+(p>=j);nh=h|(p<s[i]-'0');
						add(dp[i+1][j][nk][nh],dp[i][j][k][h]);
					}
				}
			}
		}
	}
	for (int i=1;i<=9;i++)
	{
		pp=1;cur=1;
		for (int j=1;j<=n;j++)
		{
			add(ans,1ll*pp*(dp[n][i][j][0]+dp[n][i][j][1])%mod);
			cur=1ll*cur*10%mod;
			add(pp,cur);
		}
	}
	printf("%d\n",ans);
	return 0;
}