#include<bits/stdc++.h>
using namespace std;
int n,a[222222],b[222222],es,l,r,mid;
bool f;
bool check(int x)
{
	if (x<0) return 0;
	for (int i=x+1;i<=n;i++)
	{
		if (b[i] && b[i]<=i-x) return 0;
	}
	return 1;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) scanf("%d",&b[i]);
	for (int i=1;i<=n;i++)
	{
		if (b[i]==1)
		{
			for (int j=i+1;j<=n;j++)
			{
				if (b[j]!=b[j-1]+1) 
				{
					f=1;
					break;
				}
			}
			if (!f)
			{
				es=b[n];
				for (int j=1;j<i;j++)
				{
					if (b[j] && b[j]<=es+j) f=1;
				}
			}
			if (!f)
			{
				printf("%d\n",i-1);
				return 0;
			}
		}
	}
	l=0;r=n;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if (check(mid)) r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",l+n);
	return 0;
}