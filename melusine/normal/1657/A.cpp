#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
int dp[20005];
bool vis[20005];
int isp[100005];
queue<int>que;
int main()
{
	for(int i=0;i<=200;i++)isp[i*i]=1;
	dp[0]=0;
	vis[0]=true;
	que.push(0);
	while(!que.empty())
	{
		int sth=que.front();
		que.pop();
		int nx=sth/101,ny=sth%101;
		//printf("vis:%d %d %d\n",nx,ny,dp[nx*101+ny]);
		for(int i=-100;i<=100;i++)
		{
			for(int j=-100;j<=100;j++)
			{
				if(nx+i<0||nx+i>100||ny+j<0||ny+j>100)continue;
				if(isp[i*i+j*j]==0)continue;
				if(vis[(nx+i)*101+ny+j]==false)
				{
					vis[(nx+i)*101+ny+j]=true;
					dp[(nx+i)*101+ny+j]=dp[nx*101+ny]+1;
					que.push((nx+i)*101+ny+j);
				}
			}
		}
	}
	int t,x,y;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		x=read();
		y=read();
		printf("%d\n",dp[x*101+y]);
	}
	return 0;
}