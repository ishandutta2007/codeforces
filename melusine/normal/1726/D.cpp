#include<iostream>
#include<cstdio>
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
char s[200005];
struct bbian
{
	int u,v,nex;
}a[800004];
int head[200005],tmp;
void addb(int x,int y)
{
	a[++tmp].u=x;
	a[tmp].v=y;
	a[tmp].nex=head[x];
	head[x]=tmp;
}
bool vis[200005];
int bu[15],bv[15],cnt;
int tf[200005];
int dep[200005];
void dfs(int x,int f)
{
	vis[x]=true;
	tf[x]=f;
	dep[x]=dep[f]+1;
	for(int i=head[x];i;i=a[i].nex)
	{
		if(a[i].v==f)continue;
		if(vis[a[i].v]==true&&dep[a[i].v]<dep[x])
		{
			//printf("!!!%d %d\n",x,a[i].v);
			bu[++cnt]=x;
			bv[cnt]=a[i].v;
			continue;
		}
		else if(vis[a[i].v]==true)continue;
		dfs(a[i].v,x);
	}
}
int fa[200005];
int findf(int n)
{
	if(fa[n]==n)return n;
	return fa[n]=findf(fa[n]);
}
int su[200005],sv[200005];
int main()
{
	int t,n,m,x,y,tx,ty;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		m=read();
		cnt=0;
		for(int i=1;i<=n;i++)head[i]=0,fa[i]=i,vis[i]=false;
		tmp=0;
		for(int i=1;i<=m;i++)
		{
			x=read();
			y=read();
			su[i]=x;
			sv[i]=y;
			addb(x,y);
			addb(y,x);
		}
		dfs(1,0);
		//printf("???%d\n",cnt);
		if(cnt==3)
		{
			tx=findf(bu[1]);
			ty=findf(bv[1]);
			fa[tx]=ty;
			tx=findf(bu[2]);
			ty=findf(bv[2]);
			fa[tx]=ty;
			tx=findf(bu[3]);
			ty=findf(bv[3]);
			if(tx==ty)
			{
				if(dep[bu[1]]<dep[bv[1]])swap(bu[1],bv[1]);
				bv[1]=tf[bu[1]];
			}
		}
		for(int i=1;i<=m;i++)
		{
			bool flag=false;
			for(int j=1;j<=cnt;j++)
			{
				if(su[i]==bu[j]&&sv[i]==bv[j])
				{
					flag=true;
					break;
				}
				if(su[i]==bv[j]&&sv[i]==bu[j])
				{
					flag=true;
					break;
				}
			}
			if(flag==false)printf("0");
			else printf("1");
		}
		printf("\n");
	}
	return 0;
}