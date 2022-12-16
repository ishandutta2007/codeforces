#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int read()
{
	char ch=getchar();int f=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') {f=f*10+(ch^48);ch=getchar();}
	return f;
}
int num[5005][5005],a[5005],b[5005],ans[5005];bool vis[5005];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("? %d %d\n",0,i);
		fflush(stdout);
		int x;
		scanf("%d",&x);
		num[0][i]=x;
	}
	for(int i=1;i<n;i++)
	{
		printf("? %d %d\n",i,0);
		fflush(stdout);
		int x;
		scanf("%d",&x);
		num[i][0]=x;
	}
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<n;j++)
		{
			num[i][j]=num[0][0]^num[i][0]^num[0][j];
		}
	}
	int first=-1,sum=0;
	for(int i=0;i<n;i++)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		a[0]=i;bool ac=1;
		for(int j=0;j<n;j++)
		{
			b[j]=(num[0][j]^a[0]);
		}
		for(int j=1;j<n;j++)
		{
			a[j]=(num[j][0]^b[0]);
		}
		memset(vis,0,sizeof(vis));
		for(int j=0;j<n;j++)
		{
			if(!vis[a[j]]&&a[j]<n)
			{
				vis[a[j]]=1;
			}
			else
			{
				ac=0;
				break;
			}
		}
		if(ac)
		{
			for(int j=0;j<n;j++)
			{
				if(b[j]<n&&a[b[j]]!=j)
				{
					ac=0;
					break;
				}
			}
		}
		if(ac)
		{
			sum++;
			if(first==-1)
			{
				first=i;
				for(int j=0;j<n;j++)
				{
					ans[j]=a[j];
				}
			}
			
		}
	}
	printf("!\n");
	printf("%d\n",sum);
	for(int i=0;i<n;i++)
	{
		printf("%d ",ans[i]);
	}
	fflush(stdout);
}