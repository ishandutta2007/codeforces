#include<bits/stdc++.h>
using namespace std;

const int maxn=5010;
int p[maxn],b[maxn];
int a[maxn],c[maxn];
int ans[maxn];
int cnt;
int n,ti;
int num[maxn];
void doit()
{
	for (int i=0;i<n;i++)
	{
		p[i]=a[i]^b[i];
		if (i!=n-1)	b[i+1]=c[i]^p[i];
	}
	if (c[n-1]!=(b[0]^p[n-1]))	return;
	ti++;
	for (int i=0;i<n;i++)
		if (p[i]>=n || p[i]<0 || b[i]>=n ||b[i]<0)	return;
	for (int i=0;i<n;i++)
		num[p[i]]=ti;
	for (int i=0;i<n;i++)
	if (num[i]!=ti)	return;
	ti++;
	for (int i=0;i<n;i++)
		num[b[i]]=ti;
	for (int i=0;i<n;i++)
	if (num[i]!=ti)	return;
	for (int i=0;i<n;i++)
		if (b[p[i]]!=i)	return;
	for (int i=0;i<n;i++)
		if (p[b[i]]!=i)	return;
	cnt++;
	for (int i=0;i<n;i++)
		ans[i]=p[i];
}
int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		printf("? %d %d\n",i,i);
		fflush(stdout);
		int x;
		scanf("%d",&x);
		a[i]=x;
	}
	for (int i=0;i<n-1;i++)
	{
		printf("? %d %d\n",i,i+1);
		fflush(stdout);
		int x;
		scanf("%d",&x);
		c[i]=x;
	}
	printf("? %d %d\n",n-1,0);
	fflush(stdout);
	int x;
	scanf("%d",&x);
	c[n-1]=x;
	for (int i=0;i<n;i++)
	{
		b[0]=i;
		doit();
	}
	printf("!\n%d\n",cnt);
	if (cnt>0)
	{
	for (int i=0;i<n;i++)
	{
		if (i!=0)	printf(" ");
		printf("%d",ans[i]);
	}
	}
	return 0;
}