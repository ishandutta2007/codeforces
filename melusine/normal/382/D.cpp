#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
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
char s[2005][2005];
struct bbian
{
	int v,nex;
}a[8000004];
int head[4000004],tmp;
void addb(int x,int y)
{
	a[++tmp].v=y;
	a[tmp].nex=head[x];
	head[x]=tmp;
	a[++tmp].v=x;
	a[tmp].nex=head[y];
	head[y]=tmp;
	//printf("%lld %lld\n",x,y);
}
int dep[4000004],mdep[4000004];
void dfs(int x,int f)
{
	dep[x]=dep[f]+1;
	if(f==0)dep[x]=0;
	mdep[x]=dep[x];
	for(int i=head[x];i;i=a[i].nex)
	{
		if(a[i].v==f)continue;
		dfs(a[i].v,x);
		mdep[x]=max(mdep[x],mdep[a[i].v]);
	}
}
signed main()
{
	int n,m;
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s[i]+1);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(s[i][j]=='#')continue;
			if(s[i][j]=='^')
			{
				if(s[i-1][j]=='#')addb((i-1)*m+j,n*m+1);
				else addb((i-1)*m+j,(i-2)*m+j);
			}
			else if(s[i][j]=='v')
			{
				if(s[i+1][j]=='#')addb((i-1)*m+j,n*m+1);
				else addb((i-1)*m+j,(i)*m+j);
			}
			else if(s[i][j]=='<')
			{
				if(s[i][j-1]=='#')addb((i-1)*m+j,n*m+1);
				else addb((i-1)*m+j,(i-1)*m+j-1);
			}
			else
			{
				if(s[i][j+1]=='#')addb((i-1)*m+j,n*m+1);
				else addb((i-1)*m+j,(i-1)*m+j+1);
			}
		}
	}
	dfs(n*m+1,0);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(s[i][j]=='#')continue;
			if(dep[(i-1)*m+j]==0)
			{
				printf("-1\n");
				return 0;
			}
		}
	}
	int ans=2*mdep[n*m+1]-1,sl=0;
	if(mdep[n*m+1]==0)
	{
		printf("0\n");
		return 0;
	}
	for(int i=head[n*m+1];i;i=a[i].nex)
	{
		if(mdep[a[i].v]==mdep[n*m+1])sl++;
	}
	if(sl>=2)ans++;
	printf("%d\n",ans);
	return 0;
}
/*
7 5
#####
##v##
##v##
#####
##^##
##^##
#####
7 5
#####
##v##
##v##
##<##
##^##
##^##
#####
3 4
####
#>^#
####
*/