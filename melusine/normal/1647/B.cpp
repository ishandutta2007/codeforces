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
char s[105];
int a[105][105];
bool vis[105][105];
int het,minx,maxx,miny,maxy;
int n,m;
void dfs(int x,int y)
{
	if(x>n||x<1||y>m||y<1)return;
	if(a[x][y]==0)return;
	if(vis[x][y]==true)return;
	vis[x][y]=true;
	het++;
	minx=min(minx,x);
	maxx=max(maxx,x);
	miny=min(miny,y);
	maxy=max(maxy,y);
	dfs(x,y+1);
	dfs(x+1,y);
	dfs(x,y-1);
	dfs(x-1,y);
}
int main()
{
	int t;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		m=read();
		for(int i=1;i<=n;i++)
		{
			scanf("%s",s+1);
			for(int j=1;j<=m;j++)a[i][j]=s[j]-'0';
		}
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)vis[i][j]=false;
		flag=true;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(vis[i][j]==true)continue;
				if(a[i][j]==0)continue;
				het=0;
				minx=n+1;
				maxx=0;
				miny=m+1;
				maxy=0;
				dfs(i,j);
				//printf("orz%d %d\n",i,j);
				//printf("%d %d %d %d %d\n",minx,maxx,miny,maxy,het);
				if((maxx-minx+1)*(maxy-miny+1)!=het)
				{
					flag=false;
					break;
				}
			}
			if(flag==false)break;
		}
		if(flag==true)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}