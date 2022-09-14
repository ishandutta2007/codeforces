#include<iostream>
#include<algorithm>
#include<utility>
#include<stack>
using namespace std;
int T,N,M;
int dp[2000][2000];
string S[2000];
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>N>>M;
		for(int i=0;i<N;i++)
		{
			cin>>S[i];
			for(int j=0;j<M;j++)dp[i][j]=0;
		}
		int ax,ay,ad=-1;
		for(int i=0;i<N;i++)for(int j=0;j<M;j++)
		{
			if(dp[i][j]==0)
			{
				pair<int,int>ret;
				stack<pair<int,int> >St;
				St.push(make_pair(i,j));
				while(!St.empty())
				{
					int x=St.top().first,y=St.top().second;
					int d=St.size();
					dp[x][y]=-d;
					int tx=x,ty=y;
					if(S[x][y]=='L')ty--;
					else if(S[x][y]=='R')ty++;
					else if(S[x][y]=='U')tx--;
					else tx++;
					if(tx<0||ty<0||tx>=N||ty>=M)
					{
						dp[x][y]=1;
						ret=make_pair(1,1e9);
						St.pop();
						break;
					}
					if(dp[tx][ty]>0)
					{
						dp[x][y]=dp[tx][ty]+1;
						ret=make_pair(dp[x][y],1e9);
						St.pop();
						break;
					}
					if(dp[tx][ty]<0)
					{
						dp[x][y]=d+1+dp[tx][ty];
						ret=make_pair(dp[x][y],-dp[tx][ty]);
						St.pop();
						break;
					}
					St.push(make_pair(tx,ty));
				}
				while(!St.empty())
				{
					int x=St.top().first,y=St.top().second;
					int d=St.size();
					if(d<ret.second)ret.first++;
					dp[x][y]=ret.first;
					St.pop();
				}
				if(ad<dp[i][j])
				{
					ad=dp[i][j];
					ax=i;
					ay=j;
				}
			}
		}
		cout<<ax+1<<" "<<ay+1<<" "<<ad<<endl;
	}
}