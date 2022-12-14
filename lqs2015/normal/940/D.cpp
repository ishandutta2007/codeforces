#include<iostream>
#include<cstdio>
using namespace std;
int l,r,n,a[111111],b[111111],mn,mx;
char c;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	l=-1e9;r=1e9;
	getchar();
	for (int i=1;i<=n;i++)
	{
		c=getchar();
		b[i]=c-'0';
	}
	for (int i=5;i<=n;i++)
	{
		if (b[i]!=b[i-1])
		{
			if (!b[i])
			{
				mn=1e9;
				for (int j=0;j<=4;j++)
				{
					mn=min(mn,a[i-j]);
				}
				r=min(r,mn-1);
			}
			else
			{
				mx=-1e9;
				for (int j=0;j<=4;j++)
				{
					mx=max(mx,a[i-j]);
				}
				l=max(l,mx+1);
			}
		}
	}
	printf("%d %d\n",l,r);
	return 0;
}