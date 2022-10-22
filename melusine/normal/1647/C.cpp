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
int ansx[100005],ansy[100005],ansx2[100005],ansy2[100005],cnt;
int main()
{
	int t,n,m;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		m=read();
		for(int i=1;i<=n;i++)
		{
			scanf("%s",s+1);
			for(int j=1;j<=m;j++)
			{
				a[i][j]=s[j]-'0';
			}
		}
		if(a[1][1]==1)
		{
			printf("-1\n");
			continue;
		}
		cnt=0;
		for(int i=n;i>=1;i--)
		{
			for(int j=m;j>=1;j--)
			{
				if(a[i][j]==0)continue;
				if(i>1)
				{
					ansx[++cnt]=i-1;
					ansy[cnt]=j;
					ansx2[cnt]=i;
					ansy2[cnt]=j;
				}
				else
				{
					ansx[++cnt]=i;
					ansy[cnt]=j-1;
					ansx2[cnt]=i;
					ansy2[cnt]=j;
				}
			}
		}
		printf("%d\n",cnt);
		for(int i=1;i<=cnt;i++)
		{
			printf("%d %d %d %d\n",ansx[i],ansy[i],ansx2[i],ansy2[i]);
		}
	}
	return 0;
}