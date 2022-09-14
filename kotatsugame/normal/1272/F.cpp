#include<iostream>
#include<queue>
using namespace std;
string s,t;
int dp[202][202][202];
int p1[202][202][202];
int p2[202][202][202];
int p3[202][202][202];
main()
{
	cin>>s>>t;
	for(int i=0;i<=s.size();i++)for(int j=0;j<=t.size();j++)for(int k=0;k<=200;k++)dp[i][j][k]=1e9;
	dp[0][0][0]=0;
	queue<pair<pair<int,int>,int> >P;
	P.push(make_pair(make_pair(0,0),0));
	while(!P.empty())
	{
		int i=P.front().first.first,j=P.front().first.second,k=P.front().second;
		P.pop();
		if(k>0)
		{
			if(dp[i][j][k-1]>dp[i][j][k]+1)
			{
				dp[i][j][k-1]=dp[i][j][k]+1;
				p1[i][j][k-1]=i;
				p2[i][j][k-1]=j;
				p3[i][j][k-1]=k;
				P.push(make_pair(make_pair(i,j),k-1));
			}
		}
		if(k<200)
		{
			if(dp[i][j][k+1]>dp[i][j][k]+1)
			{
				dp[i][j][k+1]=dp[i][j][k]+1;
				p1[i][j][k+1]=i;
				p2[i][j][k+1]=j;
				p3[i][j][k+1]=k;
				P.push(make_pair(make_pair(i,j),k+1));
			}
		}
		if(i<s.size()&&j<t.size()&&s[i]==t[j])
		{
			int nk=k;
			if(s[i]=='(')nk++;
			else nk--;
			if(nk>=0&&nk<=200&&dp[i+1][j+1][nk]>dp[i][j][k]+1)
			{
				dp[i+1][j+1][nk]=dp[i][j][k]+1;
				p1[i+1][j+1][nk]=i;
				p2[i+1][j+1][nk]=j;
				p3[i+1][j+1][nk]=k;
				P.push(make_pair(make_pair(i+1,j+1),nk));
			}
		}
		if(i<s.size())
		{
			int nk=k;
			if(s[i]=='(')nk++;
			else nk--;
			if(nk>=0&&nk<=200&&dp[i+1][j][nk]>dp[i][j][k]+1)
			{
				dp[i+1][j][nk]=dp[i][j][k]+1;
				p1[i+1][j][nk]=i;
				p2[i+1][j][nk]=j;
				p3[i+1][j][nk]=k;
				P.push(make_pair(make_pair(i+1,j),nk));
			}
		}
		if(j<t.size())
		{
			int nk=k;
			if(t[j]=='(')nk++;
			else nk--;
			if(nk>=0&&nk<=200&&dp[i][j+1][nk]>dp[i][j][k]+1)
			{
				dp[i][j+1][nk]=dp[i][j][k]+1;
				p1[i][j+1][nk]=i;
				p2[i][j+1][nk]=j;
				p3[i][j+1][nk]=k;
				P.push(make_pair(make_pair(i,j+1),nk));
			}
		}
	}
	int ni=s.size(),nj=t.size(),nk=0;
	string ans="";
	while(ni||nj||nk)
	{
		int i=p1[ni][nj][nk];
		int j=p2[ni][nj][nk];
		int k=p3[ni][nj][nk];
		if(k>nk)ans+=')';
		else ans+='(';
		ni=i;
		nj=j;
		nk=k;
	}
	for(int i=ans.size();i--;)cout<<ans[i];
	cout<<endl;
}