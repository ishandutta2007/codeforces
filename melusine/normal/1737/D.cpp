#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#define int long long
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
int bu[250005],bv[250005],bw[250005];
vector<int>v[505];
int dis[505][505];
queue<int>que;
signed main()
{
	int t,n,m,x,y,ans;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		m=read();
		for(int i=1;i<=n;i++)v[i].clear();
		for(int i=1;i<=m;i++)
		{
			bu[i]=read();
			bv[i]=read();
			bw[i]=read();
			v[bu[i]].push_back(bv[i]);
			v[bv[i]].push_back(bu[i]); 
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)dis[i][j]=1000000000;
			dis[i][i]=0;
			que.push(i);
			while(!que.empty())
			{
				x=que.front();
				que.pop();
				for(int j=0;j<v[x].size();j++)
				{
					if(dis[i][v[x][j]]==1000000000)
					{
						dis[i][v[x][j]]=dis[i][x]+1;
						que.push(v[x][j]);
					}
				}
			}
		}
		ans=1121131433448687LL;
		for(int i=1;i<=m;i++)
		{
			if(dis[bu[i]][1]!=1000000000&&dis[bv[i]][n]!=1000000000)ans=min(ans,(dis[bu[i]][1]+dis[bv[i]][n]+1)*bw[i]);
			if(dis[bv[i]][1]!=1000000000&&dis[bu[i]][n]!=1000000000)ans=min(ans,(dis[bv[i]][1]+dis[bu[i]][n]+1)*bw[i]);
			for(int j=1;j<=n;j++)
			{
				if(dis[bu[i]][j]!=1000000000&&dis[j][1]!=1000000000&&dis[j][n]!=1000000000)
				{
					ans=min(ans,(dis[bu[i]][j]+dis[j][1]+dis[j][n]+2)*bw[i]);
				}
				if(dis[bv[i]][j]!=1000000000&&dis[j][1]!=1000000000&&dis[j][n]!=1000000000)
				{
					ans=min(ans,(dis[bv[i]][j]+dis[j][1]+dis[j][n]+2)*bw[i]);
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}