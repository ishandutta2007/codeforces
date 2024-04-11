#include<cstdio>
#include<iostream>
using namespace std;

#define maxn 100010
int n,m;
int a[maxn],b[maxn],last[maxn];
bool ans[maxn];

int main()
{
	int test;
	scanf("%d",&test);
	while (test--)
	{
		scanf("%d%d",&n,&m);
		int cnt=0,cnt1=0,fb=0;
		for (int i=1;i<=m;i++)
		{
			scanf("%d",&a[i]);
			b[i]=0;
			last[i]=0;
			ans[i]=0;
		}
		for (int i=1;i<n;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			if (x==0)	cnt++;else last[x]=i,b[x]++;
			if (y==1 && !fb)	fb=i;
			if (x==0 && !fb)	cnt1++;
		}
		if (!fb)
		{
			for (int i=1;i<=m;i++)
			if (a[i]-b[i]<=cnt)	ans[i]=1;
		}	else
		{
			int q=1<<30;
			for (int i=1;i<=m;i++)
			if (last[i]<fb && a[i]-b[i]<=cnt1)
			{
				ans[i]=1;
				q=min(a[i]-b[i],q);
			}
			for (int i=1;i<=m;i++)
			if (!ans[i] && a[i]-b[i]<=cnt-q)	ans[i]=1;
		}
		for (int i=1;i<=m;i++)
			if (ans[i])	printf("Y");else printf("N");
		printf("\n");
	}
}