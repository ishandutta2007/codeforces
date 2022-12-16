#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int read()
{
	char ch=getchar();int f=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') {f=f*10+(ch^48);ch=getchar();}
	return f;
}
char a[105][105];bool vis[55];
int main()
{
	int n=read(),m=read();
	for(int i=1;i<=n;i++)
	{
		scanf("%s",a[i]+1);
	}
	if(n%3==0)
	{
		bool ac=1;
		int x=n/3;
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=x;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(i==1&&j==1)
				vis[a[i][j]-'A']=1;
				else
				{
					if(!vis[a[i][j]-'A'])
					ac=0;
				}
			}
		}
  		memset(vis,0,sizeof(vis));
		for(int i=x+1;i<=2*x;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(i==x+1&&j==1)
				vis[a[i][j]-'A']=1;
				else
				{
					if(!vis[a[i][j]-'A'])
					ac=0;
				}
			}
		}
		memset(vis,0,sizeof(vis));
		for(int i=2*x+1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(i==2*x+1&&j==1)
				vis[a[i][j]-'A']=1;
				else
				{
					if(!vis[a[i][j]-'A'])
					ac=0;
				}
			}
		}
		if(ac)
		{
			if(a[1][1]!=a[x+1][1]&&a[1][1]!=a[2*x+1][1]&&a[x+1][1]!=a[2*x+1][1])
			{printf("YES");
			return 0;
			}
		}
	}
	if(m%3==0)
	{
		int x=m/3;bool ac=1;
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=x;j++)
			{
				if(i==1&&j==1)
				vis[a[i][j]-'A']=1;
				else if(!vis[a[i][j]-'A'])
				ac=0;
			}
		}
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++)
		{
			for(int j=x+1;j<=2*x;j++)
			{
				if(i==1&&j==x+1)
				vis[a[i][j]-'A']=1;
				else if(!vis[a[i][j]-'A'])
				ac=0;
			}
		}
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++)
		{
			for(int j=2*x+1;j<=m;j++)
			{
				if(i==1&&j==2*x+1)
				vis[a[i][j]-'A']=1;
				else if(!vis[a[i][j]-'A'])
				ac=0;
			}
		}
		if(ac)
		{
			if(a[1][1]!=a[1][x+1]&&a[1][1]!=a[1][2*x+1]&&a[1][x+1]!=a[1][2*x+1])
			{
				printf("YES");
				return 0;
			}
		}
	}
	printf("NO");
	return 0;
}