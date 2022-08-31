#include<cstdio>
#include<iostream>

using namespace std;

const int MaxN=200010;

int n,m,p,pa,pb;
int a[MaxN],b[MaxN],c[MaxN],d[MaxN],v[MaxN];

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>n;
	for (int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for (int i=n;i>=1;--i)
		if (a[i]!=a[i+1]) pa++;
	cin>>m;
	for (int i=1;i<=m;++i)
		scanf("%d",&b[i]);
	for (int i=m;i>=1;--i)
		if (b[i]!=b[i+1]) pb++;
	if (pa>=pb)
	{
		int j=1;
		for (int i=1;i<=n;++i)
		{
			c[++p]=i;
			while (j<=m&&b[j]==a[i])
			{
				c[++p]=n+j;
				++j;
			}
		}
		while (j<=m)
		{
			c[++p]=n+j;
			++j;
		}
	}
	else
	{
		int i=1;
		for (int j=1;j<=m;++j)
		{
			c[++p]=n+j;
			while (i<=n&&a[i]==b[j])
			{
				c[++p]=i;
				++i;
			}
		}
		while (i<=n)
		{
			c[++p]=i;
			++i;
		}
	}
	for (int i=1;i<=p;++i)
	{
		if (i>1) putchar(' ');
		printf("%d",c[i]);
		if (c[i]<=n) d[i]=a[c[i]];
			else d[i]=b[c[i]-n];
	}
	puts("");
	int ans=0;
	for (int i=p;i>=1;--i)
		if (d[i]!=d[i+1]) v[++ans]=i;
	cout<<ans<<endl;
	for (int i=ans;i>=1;--i)
	{
		if (i<ans) putchar(' ');
		printf("%d",v[i]);
	}
	puts("");
	return 0;
}