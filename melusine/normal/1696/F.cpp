#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#define mod 1000000007
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
int fa[205][205];
char ts[205][205][205];
int findf(int tid,int n)
{
	if(fa[tid][n]==n)return n;
	return fa[tid][n]=findf(tid,fa[tid][n]);
}
char s[205];
bool vis[205];
int md[205];
vector<int>v[205];
bool cz[205][205];
struct bbian
{
	int u,v,nex;
}a[800004];
int head[205],tmp;
void addb(int x,int y)
{
	a[++tmp].u=x;
	a[tmp].v=y;
	a[tmp].nex=head[x];
	head[x]=tmp;
}
int dis[205],pos[205];
bool bi(int x,int y)
{
	return md[x]<md[y];
}
void dfs(int x,int f)
{
	dis[x]=dis[f]+1;
	for(int i=head[x];i;i=a[i].nex)
	{
		if(a[i].v==f)continue;
		dfs(a[i].v,x);
	}
}
int main()
{
	//freopen("sth.out","r",stdin);
	int t,n;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)fa[i][j]=j,cz[i][j]=false;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				scanf("%s",s+1);
				for(int k=1;k<=n;k++)
				{
					ts[i][j][k]=s[k];
					if(s[k]=='1')
					{
						int tx=findf(k,i),ty=findf(k,j);
						if(tx!=ty)fa[k][tx]=ty;
					}
				}
			}
		}
		int minn=n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)vis[j]=false;
			md[i]=0; 
			for(int j=1;j<=n;j++)
			{
				int sth=findf(i,j);
				if(vis[sth]==false)
				{
					vis[sth]=true;
					md[i]++;
				}
			}
			minn=min(minn,md[i]);
		}
		int msl=0;
		for(int i=1;i<=n;i++)if(md[i]==minn)msl++;
		if(msl>2)
		{
			printf("No\n");
			continue;
		}
	//	printf("%d %d\n",minn,msl);
		for(int i=1;i<=n;i++)pos[i]=i;
		sort(pos+1,pos+n+1,bi);
		for(int fi=1;fi<=n;fi++)
		{
			int i=pos[fi];
			if(md[i]==minn&&msl==1)
			{
				for(int j=1;j<=n;j++)
				{
					if(md[j]==md[i]+1)cz[i][j]=cz[j][i]=true;
				}
				continue;
			}
			if(md[i]==minn&&msl==2)
			{
				for(int j=1;j<=n;j++)v[j].clear();
				for(int j=1;j<=n;j++)v[findf(i,j)].push_back(j);
				int sth=0;
				for(int j=1;j<=n;j++)
				{
					if(md[j]==md[i]&&j!=i)
					{
						sth=j;
						break;
					}
				}
				sth=findf(i,sth);
				for(int j=0;j<v[sth].size();j++)cz[i][v[sth][j]]=cz[v[sth][j]][i]=true;
				continue;
			}
			for(int j=1;j<=n;j++)v[j].clear();
			for(int j=1;j<=n;j++)v[findf(i,j)].push_back(j);
			for(int j=1;j<=n;j++)
			{
				if(v[j].empty())continue;
				int tsl=0,tpos=0;
				for(int k=0;k<v[j].size();k++)
				{
					if(md[v[j][k]]==md[i]-1)tsl++,tpos=v[j][k];
				}
				if(tsl==1)
				{
					if(cz[tpos][i]==false)continue;
					for(int k=0;k<v[j].size();k++)
					{
						if(md[v[j][k]]!=md[i]-1)cz[i][v[j][k]]=cz[v[j][k]][i]=true;
					}
				}
			}
		}
		tmp=0;
		for(int i=1;i<=n;i++)head[i]=0,fa[n+1][i]=i;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(cz[i][j])
				{
					addb(i,j);
					addb(j,i);
					//printf("orz%d %d\n",i,j);
					int tx=findf(n+1,i),ty=findf(n+1,j);
					if(tx!=ty)fa[n+1][tx]=ty;
				}
			}
		}
		for(int i=1;i<=n;i++)vis[i]=false;
		int lt=0; 
		for(int i=1;i<=n;i++)
		{
			if(vis[findf(n+1,i)]==false)
			{
				vis[findf(n+1,i)]=true;
				lt++;
			}
		}
		if(lt>1)
		{
			printf("No\n");
			continue;
		}
		if(tmp!=2*n-2)
		{
			printf("No\n");
			continue;
		}
		bool flag=true;
		for(int i=1;i<=n;i++)
		{
			dfs(i,0);
			for(int j=1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					bool flag1,flag2;
					if(ts[j][k][i]=='1')flag1=true;
					else flag1=false;
					if(dis[j]==dis[k])flag2=true;
					else flag2=false;
					if(flag1!=flag2)
					{
						printf("No\n");
						flag=false;
						break;
					}
				}
				if(flag==false)break;
			}
			if(flag==false)break;
		}
		if(flag==false)
		{
			continue;
		}
		printf("Yes\n");
		for(int i=1;i<=n-1;i++)
		{
			printf("%d %d\n",a[2*i-1].u,a[2*i-1].v);
		}
	}
	return 0;
}