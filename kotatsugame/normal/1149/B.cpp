#include<iostream>
#include<algorithm>
using namespace std;
int dp[255][255][255];
string s;
int N,Q;
int nxt[26][1<<17];
int m[26];
int a[255],b[255],c[255],ia,ib,ic;
main()
{
	cin>>N>>Q>>s;
	for(int i=0;i<255;i++)for(int j=0;j<255;j++)for(int k=0;k<255;k++)dp[i][j][k]=-1;
	dp[0][0][0]=0;
	for(int i=0;i<26;i++)m[i]=nxt[i][N]=-1;
	for(int i=N;i--;)
	{
		m[s[i]-'a']=i;
		for(int j=0;j<26;j++)nxt[j][i]=m[j];
	}
	for(;Q--;)
	{
		char t;int id;
		cin>>t>>id;
		if(t=='-')
		{
			for(int j=0;j<255;j++)for(int k=0;k<255;k++)
			{
				(id==1?dp[ia][j][k]:id==2?dp[j][ib][k]:dp[j][k][ic])=-1;
			}
			(id==1?ia:id==2?ib:ic)--;
		}
		else
		{
			char g;cin>>g;
			(id==1?a[ia++]:id==2?b[ib++]:c[ic++])=g-='a';
			for(int i=id==1?ia-1:0;i<=ia;i++)for(int j=id==2?ib-1:0;j<=ib;j++)for(int k=id==3?ic-1:0;k<=ic;k++)
			{
				int now=dp[i][j][k];
				if(now<0)
				{
					continue;
				}
				if(i<ia&&nxt[a[i]][now]>=0)
				{
					if(dp[i+1][j][k]<0)dp[i+1][j][k]=nxt[a[i]][now]+1;
					else dp[i+1][j][k]=min(dp[i+1][j][k],nxt[a[i]][now]+1);
				}
				if(j<ib&&nxt[b[j]][now]>=0)
				{
					if(dp[i][j+1][k]<0)dp[i][j+1][k]=nxt[b[j]][now]+1;
					else dp[i][j+1][k]=min(dp[i][j+1][k],nxt[b[j]][now]+1);
				}
				if(k<ic&&nxt[c[k]][now]>=0)
				{
					if(dp[i][j][k+1]<0)dp[i][j][k+1]=nxt[c[k]][now]+1;
					else dp[i][j][k+1]=min(dp[i][j][k+1],nxt[c[k]][now]+1);
				}
			}
		}
		cout<<(dp[ia][ib][ic]<0?"NO":"YES")<<endl;
	}
}