#include<iostream>
#include<cstdio>
#include<cstring>
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
char s[105][105];
int main()
{
	int t,n,m,mx,my;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		m=read();
		for(int i=1;i<=n;i++)
		{
			scanf("%s",s[i]+1);
		}
		mx=n+1;
		my=m+1;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(s[i][j]=='R')
				{
					mx=min(mx,i);
					my=min(my,j);
				}
			}
		}
		if(mx>n)
		{
			printf("NO\n");
			continue;
		}
		if(s[mx][my]=='R')printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}