#include<iostream>
#include<cstdio>
#include<cstring>
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
struct bbian
{
	int u,v,nex;
}a[1000004];
int head[500005],tmp;
void addb(int x,int y)
{
	a[++tmp].u=x;
	a[tmp].v=y;
	a[tmp].nex=head[x];
	head[x]=tmp;
}
int qz[500005],pos[500005];
int sta[500005],ttop;
int yd[500005],yx[500005];
int fa[500005][20],fb[500005][20];
int logg[500005];
int querymax(int l,int r)
{
	int k=logg[r-l+1];
	return max(fa[l][k],fa[r-(1<<k)+1][k]);
}
int querymin(int l,int r)
{
	int k=logg[r-l+1];
	return min(fb[l][k],fb[r-(1<<k)+1][k]);
}
queue<int>que;
int dis[500005];
int main()
{
	int t,n;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		tmp=0;
		for(int i=1;i<=n;i++)head[i]=0;
		for(int i=1;i<=n;i++)
		{
			qz[i]=read();
			pos[qz[i]]=i;
		}
		for(int i=1;i<=n;i++)yd[i]=yx[i]=n+1;
		bool flag;
		ttop=0;
		for(int i=1;i<=n;i++)
		{
			flag=true;
			while(ttop>=1&&qz[sta[ttop]]>=qz[i])
			{
				yx[sta[ttop]]=i;
				ttop--;
			}
			sta[++ttop]=i;
		}
		ttop=0;
		for(int i=1;i<=n;i++)
		{
			flag=true;
			while(ttop>=1&&qz[sta[ttop]]<=qz[i])
			{
				yd[sta[ttop]]=i;
				ttop--;
			}
			sta[++ttop]=i;
		}
		logg[1]=0;
		for(int i=2;i<=n;i++)logg[i]=logg[i>>1]+1;
		for(int i=1;i<=n;i++)fa[i][0]=qz[i],fb[i][0]=qz[i];
		for(int j=1;j<=19;j++)
		{
			for(int i=1;i<=n-(1<<j)+1;i++)
			{
				fa[i][j]=max(fa[i][j-1],fa[i+(1<<(j-1))][j-1]);
				fb[i][j]=min(fb[i][j-1],fb[i+(1<<(j-1))][j-1]);
			}
		}
		for(int i=1;i<=n;i++)
		{
			//printf("%d %d\n",yx[i],yd[i]);
			if(yx[i]!=i+1)addb(i,pos[querymax(i+1,yx[i]-1)]);
			if(yd[i]!=i+1)addb(i,pos[querymin(i+1,yd[i]-1)]);
		}
		//for(int i=1;i<=tmp;i++)printf("%d %d\n",a[i].u,a[i].v);
		for(int i=1;i<=n;i++)dis[i]=1000000000;
		que.push(1);
		dis[1]=0;
		while(!que.empty())
		{
			int x=que.front();
			que.pop();
			for(int i=head[x];i;i=a[i].nex)
			{
				if(dis[a[i].v]==1000000000)
				{
					dis[a[i].v]=dis[x]+1;
					que.push(a[i].v);
				}
			}
		}
		printf("%d\n",dis[n]);
	}
	return 0;
}