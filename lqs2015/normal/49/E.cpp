#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
using namespace std;
char c,c1,c2;
int dp[55][55],dp1[55][55][27],dp2[55][55][27],l,r;
vector<pair<char,char> > rl[27];
string s1,s2;
int n,sz1,sz2;
int main()
{
	cin>>s1>>s2;
	cin>>n;
	sz1=s1.size();sz2=s2.size();
	for (int i=1;i<=n;i++)
	{
		cin>>c;getchar();getchar();
		cin>>c1>>c2;
		getchar();
		rl[c-'a'].push_back(make_pair(c1-'a',c2-'a')); 
	}
	for (int i=0;i<sz1;i++)
	{
		dp1[i+1][i+1][s1[i]-'a']=1;
	}
	for (int i=1;i<sz1;i++)
	{
		for (int j=1;j<=sz1-i;j++)
		{
			l=j;r=j+i;
			for (int k=0;k<26;k++)
			{
				for (int h=l;h<r;h++)
				{
					for (int p=0;p<rl[k].size();p++)
					{
						if (dp1[l][h][rl[k][p].first] && dp1[h+1][r][rl[k][p].second])
						{
							dp1[l][r][k]=1;
							break;
						}
					}
					if (dp1[l][r][k]) break;
				}
			}
		}
	}
	for (int i=0;i<sz2;i++)
	{
		dp2[i+1][i+1][s2[i]-'a']=1;
	}
	for (int i=1;i<sz2;i++)
	{
		for (int j=1;j<=sz2-i;j++)
		{
			l=j;r=j+i;
			for (int k=0;k<26;k++)
			{
				for (int h=l;h<r;h++)
				{
					for (int p=0;p<rl[k].size();p++)
					{
						if (dp2[l][h][rl[k][p].first] && dp2[h+1][r][rl[k][p].second])
						{
							dp2[l][r][k]=1;
							break;
						}
					}
					if (dp2[l][r][k]) break;
				}
			}
		}
	}
	for (int i=0;i<=sz1;i++)
	{
		for (int j=0;j<=sz2;j++)
		dp[i][j]=1e9;
	}
	dp[0][0]=0;
	for (int i=1;i<=sz1;i++)
	{
		for (int j=1;j<=sz2;j++)
		{
			for (int x=0;x<i;x++)
			{
				for (int y=0;y<j;y++)
				{
					for (int k=0;k<26;k++)
					{
						if (dp1[x+1][i][k] && dp2[y+1][j][k]) dp[i][j]=min(dp[i][j],dp[x][y]+1);
					}
				}
			}
		}
	}
	if (dp[sz1][sz2]==1e9) cout<<-1<<endl;
	else cout<<dp[sz1][sz2]<<endl;
	return 0;
}